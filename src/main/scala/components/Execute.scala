
package nucleusrv.components
import chisel3._
import chisel3.util.MuxCase
import nucleusrv.components.fpu._
import chisel3.util.MuxLookup

class Execute(M :Boolean = false, F :Boolean) extends Module {
  val io = IO(new Bundle {
    val immediate = Input(UInt(32.W))
    val readData1 = Input(UInt(32.W))
    val readData2 = Input(UInt(32.W))
    val pcAddress = Input(UInt(32.W))
    val func7 = Input(UInt(7.W))
    val func3 = Input(UInt(3.W))
    val mem_result = Input(UInt(32.W))
    val wb_result = Input(UInt(32.W))

    val ex_mem_regWrite = Input(Bool())
    val mem_wb_regWrite = Input(Bool())
    val id_ex_ins = Input(UInt(32.W))
    val ex_mem_ins = Input(UInt(32.W))
    val mem_wb_ins = Input(UInt(32.W))

    val ctl_aluSrc = Input(Bool())
    val ctl_aluOp = Input(UInt(2.W))
    val ctl_aluSrc1 = Input(UInt(2.W))

    val fAluCtl = if (F) Some(Input(UInt((5 + 2 + 7).W))) else None
    val rm = if (F) Some(Input(UInt(3.W))) else None
    val frs2 = if (F) Some(Input(UInt(5.W))) else None
    val frs3 = if (F) Some(Input(UInt(5.W))) else None
    val readData3 = if (F) Some(Input(UInt(32.W))) else None
    val fInst = if (F) Some(Input(Vec(3, Bool()))) else None
    val fstall = if (F) Some(Output(Bool())) else None

    val writeData = Output(UInt(32.W))
    val ALUresult = Output(UInt(32.W))

    val stall = Output(Bool())
  })

  val alu = Module(new ALU(F))
  val aluCtl = Module(new AluControl)
  val fu = Module(new ForwardingUnit(F)).io

  val fAluCtl = if (F) Some(Module(new FControl)) else None

  // Forwarding Unit

  fu.ex_regWrite := io.ex_mem_regWrite
  fu.mem_regWrite := io.mem_wb_regWrite
  fu.ex_reg_rd := io.ex_mem_ins(11, 7)
  fu.mem_reg_rd := io.mem_wb_ins(11, 7)
  fu.reg_rs1 := io.id_ex_ins(19, 15)
  fu.reg_rs2 := io.id_ex_ins(24, 20)

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

  if (F) {
    fu.reg_rs3.get := io.frs3.get
    fu.fInst.get <> io.fInst.get

    val inputMux3 = MuxLookup(fu.forwardC.get, 0.U, Seq(
      0.U -> io.readData3.get,
      1.U -> io.mem_result,
      2.U -> io.wb_result
    ))

    fAluCtl.get.io.fAluCtl := io.fAluCtl.get
    fAluCtl.get.io.rm := io.rm.get
    fAluCtl.get.io.rs2 := io.frs2.get
    alu.io.aluCtl := Mux(io.fInst.get(0), fAluCtl.get.io.aluCtl, aluCtl.io.out)
    alu.io.input3.get := inputMux3
    alu.io.rm.get := io.rm.get
    fu.reg_rs3.get := io.id_ex_ins(31, 27)
    io.fstall.get := alu.io.fstall.get
  } else {
    alu.io.aluCtl := aluCtl.io.out
  }

  io.stall := false.B
  if(M){
    val mdu = Module (new MDU)
    mdu.io.src_a := aluIn1
    mdu.io.src_b := aluIn2
    mdu.io.op    := io.func3
    // mdu.io.valid := true.B
    // io.stall := false.B
    
    val src_a_reg = RegInit(0.U(32.W))
    val src_b_reg = RegInit(0.U(32.W))
    val op_reg    = RegInit(0.U(3.W))
    val div_en    = RegInit(false.B)
    val f7_reg    = RegInit(0.U(6.W))
    val counter   = RegInit(0.U(6.W))

    when(io.func7 === 1.U && (io.func3 === 0.U || io.func3 === 1.U || io.func3 === 2.U || io.func3 === 3.U)){
      mdu.io.valid := true.B
    }otherwise{
      mdu.io.valid := false.B
    }
    dontTouch(io.stall)
    when(io.func7 === 1.U && ~div_en && (io.func3 === 4.U || io.func3 === 5.U || io.func3 === 6.U || io.func3 === 7.U)){
      mdu.io.valid := RegNext(true.B)
      div_en := true.B
      src_a_reg := aluIn1
      src_b_reg := aluIn2
      op_reg := io.func3
      f7_reg := io.func7
      io.stall := true.B
      dontTouch(f7_reg)
    }

    when(div_en){
      // io.stall := true.B
      when (counter < 32.U){
        io.stall := true.B
        mdu.io.src_a := src_a_reg
        mdu.io.src_b := src_b_reg
        mdu.io.op    := op_reg
        // mdu.io.valid := true.B
        counter := counter + 1.U
      }.otherwise{
        mdu.io.valid := false.B
        div_en       := false.B
        mdu.io.src_a := src_a_reg
        mdu.io.src_b := src_b_reg
        mdu.io.op    := op_reg
        counter := 0.U
      }
    }//.otherwise{io.stall := false.B}

    when(div_en && f7_reg === 1.U && mdu.io.ready){
      io.ALUresult := Mux(mdu.io.output.valid, mdu.io.output.bits, 0.U)
    }
    .elsewhen (io.func7 === 1.U && mdu.io.ready){
      io.ALUresult := Mux(mdu.io.output.valid, mdu.io.output.bits, 0.U)
    }
    .otherwise{io.ALUresult := alu.io.result}
  } else {
    io.ALUresult := alu.io.result
  }


  io.writeData := inputMux2
}
