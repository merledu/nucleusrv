package nucleusrv.components
import chisel3._
import chisel3.util.MuxCase
import chisel3.util.MuxLookup
import FBitPats._

class Execute(
  F: Boolean,
  M: Boolean = false,
  TRACE: Boolean
) extends Module {
  val io = IO(new Bundle {
    val immediate = Input(UInt(32.W))
    val readData1 = Input(UInt(32.W))
    val readData2 = Input(UInt(32.W))
    val pcAddress = Input(UInt(32.W))
    val func7 = Input(UInt(7.W))
    val func3 = Input(UInt(3.W))
    val mem_result = Input(UInt(32.W))
    val wb_result = Input(UInt(32.W))

    val ex_mem_regWrite = Input(Vec(if (F) 2 else 1, Bool()))
    val mem_wb_regWrite = Input(Vec(if (F) 2 else 1, Bool()))
    val id_ex_ins = Input(UInt(32.W))
    val ex_mem_ins = Input(UInt(32.W))
    val mem_wb_ins = Input(UInt(32.W))

    val ctl_aluSrc = Input(Bool())
    val ctl_aluOp = Input(UInt(2.W))
    val ctl_aluSrc1 = Input(UInt(2.W))

    val writeData = Output(UInt(32.W))
    val ALUresult = Output(UInt(32.W))

    val stall = Output(Bool())

    val rs1_rdata = if (TRACE) Some(Output(UInt(32.W))) else None

    val f_read = if (F) Some(Input(Vec(3, Bool()))) else None
    val readData3 = if (F) Some(Input(UInt(32.W))) else None
    val fcsr_o_data = if (F) Some(Input(UInt(32.W))) else None
    val is_f_i = if (F) Some(Input(Bool())) else None
    val is_f_o = if (F) Some(Output(Bool())) else None
    val exceptions = if (F) Some(Output(Vec(5, Bool()))) else None
  })

  val alu = Module(new ALU)
  val aluCtl = Module(new AluControl)
  val fu = Module(new ForwardingUnit(F)).io

  // Forwarding Unt

  fu.ex_regWrite <> io.ex_mem_regWrite
  fu.mem_regWrite <> io.mem_wb_regWrite
  fu.ex_reg_rd := io.ex_mem_ins(11, 7)
  fu.mem_reg_rd := io.mem_wb_ins(11, 7)
  fu.reg_rs1 := io.id_ex_ins(19, 15)
  fu.reg_rs2 := io.id_ex_ins(24, 20)
  if (F) {
    fu.f_read.get <> io.f_read.get
    fu.reg_rs3.get := io.id_ex_ins(31, 27)
  }

  val inputMux1 = MuxCase(
    0.U,
    Array(
      (fu.forwardA === 0.U) -> (io.readData1),
      (fu.forwardA === 1.U) -> (io.mem_result),
      (fu.forwardA === 2.U) -> (io.wb_result)
    )
  )
  val inputMux2 = MuxCase(
    0.U,
    Array(
      (fu.forwardB === 0.U) -> (io.readData2),
      (fu.forwardB === 1.U) -> (io.mem_result),
      (fu.forwardB === 2.U) -> (io.wb_result)
    )
  )
  val inputMux3 = if (F) Some(MuxLookup(fu.forwardC.get, 0.U, Vector(
    io.readData3.get,
    io.mem_result,
    io.wb_result
  ).zipWithIndex.map(f => f._2.U -> f._1))) else None

  val aluIn1 = MuxCase(
    inputMux1,
    Array(
      (io.ctl_aluSrc1 === 1.U) -> io.pcAddress,
      (io.ctl_aluSrc1 === 2.U) -> 0.U
    )
  )
  val aluIn2 = Mux(io.ctl_aluSrc, inputMux2, io.immediate)

  aluCtl.io.f3 := io.func3
  aluCtl.io.f7 := io.func7(5)
  aluCtl.io.aluOp := io.ctl_aluOp
  aluCtl.io.aluSrc := io.ctl_aluSrc

  alu.io.input1 := aluIn1
  alu.io.input2 := aluIn2
  alu.io.aluCtl := aluCtl.io.out

  //io.ALUresult := alu.io.result
  //dontTouch(io.stall) := false.B

  val mdu = if (M) Some(Module (new MDU)) else None
  val src_a_reg = if (M) Some(RegInit(0.U(32.W))) else None
  val src_b_reg = if (M) Some(RegInit(0.U(32.W))) else None
  val op_reg    = if (M) Some(RegInit(0.U(3.W))) else None
  val div_en    = if (M) Some(RegInit(false.B)) else None
  val f7_reg    = if (M) Some(RegInit(0.U(6.W))) else None
  val counter   = if (M) Some(RegInit(0.U(6.W))) else None
  if (M) {
    mdu.get.io.src_a := aluIn1
    mdu.get.io.src_b := aluIn2
    mdu.get.io.op    := io.func3
    // mdu.io.valid := true.B
    

    when(io.func7 === 1.U && (io.func3 === 0.U || io.func3 === 1.U || io.func3 === 2.U || io.func3 === 3.U)){
      mdu.get.io.valid := true.B
    }otherwise{
      mdu.get.io.valid := false.B
    }
    dontTouch(io.stall)
    when(io.func7 === 1.U && ~div_en.get && (io.func3 === 4.U || io.func3 === 5.U || io.func3 === 6.U || io.func3 === 7.U)){
      mdu.get.io.valid := RegNext(true.B)
      div_en.get := true.B
      src_a_reg.get := aluIn1
      src_b_reg.get := aluIn2
      op_reg.get := io.func3
      f7_reg.get := io.func7
      //io.stall := true.B
      dontTouch(f7_reg.get)
    }

    when(div_en.get){
      when (counter.get < 32.U){
        //io.stall := true.B
        mdu.get.io.src_a := src_a_reg.get
        mdu.get.io.src_b := src_b_reg.get
        mdu.get.io.op    := op_reg.get
        // mdu.io.valid := true.B
        counter.get := counter.get + 1.U
      }.otherwise{
        mdu.get.io.valid := false.B
        div_en.get       := false.B
        mdu.get.io.src_a := src_a_reg.get
        mdu.get.io.src_b := src_b_reg.get
        mdu.get.io.op    := op_reg.get
        counter.get := 0.U
      }
    }

    //when(div_en && f7_reg === 1.U && mdu.io.ready){
    //  io.ALUresult := Mux(mdu.io.output.valid, mdu.io.output.bits, 0.U)
    //}
    //  io.ALUresult := Mux(mdu.io.output.valid, mdu.io.output.bits, 0.U)
    //}
    //.otherwise{io.ALUresult := alu.io.result}
  }

  val fpu = if (F) Some(dontTouch(Module(new FPU(8, 24)).io)) else None
  val f_mono_cycle_inst = if (F) Some(WireInit(Vector(
    fmadd_s,
    fmsub_s,
    fnmsub_s,
    fnmadd_s,
    fadd_s,
    fsub_s,
    fmul_s,
    fsgnj_s,
    fsgnjn_s,
    fsgnjx_s,
    fmin_s,
    fmax_s,
    fcvt_w_s,
    fcvt_wu_s,
    fmv_x_w,
    feq_s,
    flt_s,
    fle_s,
    fclass_s,
    fcvt_s_w,
    fcvt_s_wu,
    fmv_w_x
  ).map(
    f => f === io.id_ex_ins
  ).reduce(
    (x, y) => x || y
  ))) else None
  val f_multi_cycle_inst = if (F) Some(dontTouch(Vector(fdiv_s, fsqrt_s).map(
    f => f === io.id_ex_ins
  ).reduce(_ || _))) else None
  val f_stall = if (F) Some((io.func7 === "b0001100".U) || (io.func7 === "b0101100".U) || (!fpu.get.div_sqrt_ready)) else None
  if (F) {
    fpu.get.rm := Mux(
      io.func3 === 7.U,
      io.fcsr_o_data.get(7, 5),
      io.func3
    )
    Vector(inputMux1, inputMux2, inputMux3.get).zipWithIndex foreach (
      f => fpu.get.in(f._2) := f._1
    )
    fpu.get.aluOp := MuxCase(0.U, Vector(
      fmadd_s,
      fmsub_s,
      fnmsub_s,
      fnmadd_s,
      fadd_s,
      fsub_s,
      fmul_s,
      fdiv_s,
      fsqrt_s,
      fsgnj_s,
      fsgnjn_s,
      fsgnjx_s,
      fmin_s,
      fmax_s,
      fcvt_w_s,
      fcvt_wu_s,
      fmv_x_w,
      feq_s,
      flt_s,
      fle_s,
      fclass_s,
      fcvt_s_w,
      fcvt_s_wu,
      fmv_w_x
    ).zipWithIndex.map(
      f => (f._1 === io.id_ex_ins) -> (f._2 + 1).U
    ))
    fpu.get.div_sqrt_valid := f_multi_cycle_inst.get
    io.exceptions.get <> fpu.get.exceptions
    io.is_f_o.get := io.is_f_i.get | RegNext(f_stall.get)
  }

  io.ALUresult := MuxCase(alu.io.result, (
    if (M) Vector(
      (div_en.get && f7_reg.get === 1.U && mdu.get.io.ready) -> Mux(mdu.get.io.output.valid, mdu.get.io.output.bits, 0.U),
      (io.func7 === 1.U && mdu.get.io.ready) -> Mux(mdu.get.io.output.valid, mdu.get.io.output.bits, 0.U)
    ) else Vector()
  ) ++ (
    if (F) Vector(
      f_mono_cycle_inst.get -> fpu.get.out,
      fpu.get.div_sqrt_valid_out -> fpu.get.out
    ) else Vector()
  ))

  io.stall := (
    if (M) (
      io.func7 === 1.U && ~div_en.get && (io.func3 === 4.U || io.func3 === 5.U || io.func3 === 6.U || io.func3 === 7.U)
    ) || (div_en.get && counter.get < 32.U)
    else false.B
  ) || (
    if (F) f_stall.get else false.B
  )

  io.writeData := inputMux2

  if (TRACE) {
    io.rs1_rdata.get := inputMux1
  }
}
