package nucleusrv.components
import chisel3._
import chisel3.util.MuxCase
import vu._

class Execute(M:Boolean = false) extends Module {
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

    val func6 = Input(UInt(6.W))
    val v_ctl_aluop = Input(UInt(3.W))
    val v_ctl_exsel = Input(UInt(4.W))
    val v_ctl_regwrite = Input(Bool())
    val v_ctl_opBsel = Input(Bool())
    val v_ctl_v_load = Input(Bool())
    val v_ctl_v_ins = Input(Bool())
    val v_ctl_vset = Input(Bool())
    val vs1_data = Input(SInt(128.W))
    val vs2_data = Input(SInt(128.W))
    val vl = Input(SInt(32.W))
    val vstart = Input(SInt(32.W))
    val vs3_data = Input(SInt(128.W))
    val vma = Input(UInt(1.W))
    val vta = Input(UInt(1.W))
    val vm = Input(UInt(1.W))
    val vs0 = Input(SInt(128.W))
    val vd_addr = Input(UInt(5.W))
    val v_sew = Input(UInt(3.W))
    val zimm = Input(SInt(32.W))
    val v_addi_imm = Input(SInt(32.W))
    val vec_mem_res = Input(SInt(128.W))
    val vec_wb_res = Input(SInt(128.W))
    //val id_reg_vs3data = Input(SInt(128.W))

    val fu_ex_reg_vd = Input(UInt(5.W))
    val fu_mem_reg_vd = Input(UInt(5.W))
    val fu_reg_vs1 = Input(UInt(5.W))
    val fu_reg_vs2 = Input(UInt(5.W))
    val fu_reg_vs3 = Input(UInt(5.W))
    val fu_ex_reg_write = Input(Bool())
    val fu_mem_reg_write = Input(Bool())
    val v_MemWrite = Input(Bool())
    val vec_alu_res = Output(SInt(128.W))
    val vec_vl = Output(SInt(32.W))
    val vec_rd_out = Output(UInt(5.W))
    val vec_avl_o = Output(SInt(32.W))
    val vec_valmax_o = Output(SInt(32.W))
    val vs3_data_o = Output(SInt(128.W))
    val writeData = Output(UInt(32.W))
    val ALUresult = Output(UInt(32.W))
    val vs0_o = Output(SInt(128.W))

    val stall = Output(Bool())
  })

  val alu = Module(new ALU)
  val aluCtl = Module(new AluControl)
  val fu = Module(new ForwardingUnit).io

  // Forwarding Unt

  fu.ex_regWrite := io.ex_mem_regWrite
  fu.mem_regWrite := io.mem_wb_regWrite
  fu.ex_reg_rd := io.ex_mem_ins(11, 7)
  fu.mem_reg_rd := io.mem_wb_ins(11, 7)
  fu.reg_rs1 := io.id_ex_ins(19, 15)
  fu.reg_rs2 := io.id_ex_ins(24, 20)

  fu.ex_reg_vd := io.fu_ex_reg_vd
  fu.mem_reg_vd := io.fu_mem_reg_vd
  fu.reg_vs1 := io.fu_reg_vs1
  fu.reg_vs2 := io.fu_reg_vs2
  fu.reg_vs3 := io.fu_reg_vs3
  fu.ex_reg_write := io.fu_ex_reg_write
  fu.mem_reg_write := io.fu_mem_reg_write

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

  val Vec_aluCtl = Module(new vu.Alu_Control)
  dontTouch(Vec_aluCtl.io)
  Vec_aluCtl.io.func3 := io.func3
  Vec_aluCtl.io.func6 := io.func6
  Vec_aluCtl.io.aluOp := io.v_ctl_aluop

  alu.io.input1 := aluIn1
  alu.io.input2 := aluIn2
  alu.io.aluCtl := aluCtl.io.out

  // Vector ALU
  val vec_alu = Module(new VALU)
  dontTouch(vec_alu.io)

     // Vector forwarding unit
  when(fu.forwardA === 1.U){
    vec_alu.io.in_A := io.mem_result.asSInt
  }.elsewhen(fu.forwardA === 2.U){
    vec_alu.io.in_A := io.wb_result.asSInt
  }.otherwise{
    vec_alu.io.in_A := io.readData1.asSInt
  }

  when(fu.forwardA === 1.U){
    vec_alu.io.vs1 := io.vec_mem_res
  }.elsewhen(fu.forwardA === 2.U){
    vec_alu.io.vs1 := io.vec_wb_res
  }.otherwise{
    vec_alu.io.vs1 := io.vs1_data
  }
  
  when(fu.forwardC === 1.U){
    vec_alu.io.vd := io.vec_mem_res
    io.vs3_data_o := io.vec_mem_res
  }.elsewhen(fu.forwardC === 2.U){
    vec_alu.io.vd := io.vec_wb_res
    io.vs3_data_o := io.vec_wb_res
  }.otherwise{
    vec_alu.io.vd := io.vs3_data
    io.vs3_data_o := io.vs3_data
  }
  
  when(io.v_ctl_exsel === "b0011".U && io.v_ctl_opBsel === 1.U){
    vec_alu.io.in_B := io.zimm.asSInt
  }.elsewhen(io.v_ctl_exsel === "b0100".U && io.v_ctl_opBsel === 1.U){
    vec_alu.io.in_B := io.v_addi_imm.asSInt
  }.otherwise{
    when(fu.forwardB === 1.U){
      vec_alu.io.in_B := io.mem_result.asSInt
    }.elsewhen(fu.forwardB === 2.U){
      vec_alu.io.in_B := io.wb_result.asSInt
    }.otherwise{
      vec_alu.io.in_B := io.readData2.asSInt
    }
  }

  when(fu.forwardB === 1.U){
    vec_alu.io.vs2 := io.vec_mem_res
  }.elsewhen(fu.forwardB === 2.U){
    vec_alu.io.vs2 := io.vec_wb_res
  }.otherwise{
    vec_alu.io.vs2 := io.vs2_data
  }
  vec_alu.io.aluc := Vec_aluCtl.io.aluc
  vec_alu.io.vd_addr := io.vd_addr
  vec_alu.io.sew := io.v_sew
  vec_alu.io.v_ins := io.v_ctl_v_ins
  vec_alu.io.vl := io.vl.asUInt
  vec_alu.io.vta := io.vta
  vec_alu.io.vma := io.vma
  vec_alu.io.vm := io.vm
  vec_alu.io.vd := io.vs3_data
  vec_alu.io.vs0 := io.vs0
  vec_alu.io.vstart := io.vstart.asUInt
  io.vec_alu_res := vec_alu.io.v_output
  io.vs0_o := vec_alu.io.vs0_o

  // Vector Config Module
  val vec_config = Module(new vu.configure)

  when(io.v_ctl_vset === 1.B) {
    vec_config.io.zimm := io.id_ex_ins(30, 20)
    vec_config.io.rs1 := io.id_ex_ins(19, 15)
    vec_config.io.rd := io.id_ex_ins(11, 7)
    when(fu.forwardA === 1.U){
      vec_config.io.rs1_readdata := io.mem_result.asSInt
    }.elsewhen((fu.forwardA === 2.U)){
      vec_config.io.rs1_readdata := io.wb_result.asSInt
    }.otherwise{
      vec_config.io.rs1_readdata := io.readData1.asSInt
    }
    vec_config.io.current_vl := io.vl.asSInt
  }.otherwise{
    vec_config.io.zimm := 0.U
    vec_config.io.rs1 := 0.U
    vec_config.io.rd := 0.U
    vec_config.io.rs1_readdata := 0.S
    vec_config.io.current_vl := io.vl.asSInt
  }

  io.vec_vl := vec_config.io.vl
  // io.vec_vl := io.vl.asSInt
  io.vec_rd_out := vec_config.io.rd_out
  io.vec_avl_o := vec_config.io.avl_o
  io.vec_valmax_o := vec_config.io.valmax_o



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
  } 
  else {
    io.ALUresult := alu.io.result
  }

  // io.ALUresult := alu.io.result

  io.writeData := inputMux2
}