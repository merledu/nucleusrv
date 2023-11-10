package nucleusrv.components

import chisel3._
import chisel3.util._
import nucleusrv.components.vu.vregfile
class InstructionDecode(TRACE:Boolean) extends Module {
  val io = IO(new Bundle {
    val id_instruction = Input(UInt(32.W))
    val writeData = Input(UInt(32.W))
    val writeReg = Input(UInt(5.W))
    val pcAddress = Input(UInt(32.W))
    val ctl_writeEnable = Input(Bool())
    val id_ex_mem_read = Input(Bool())
    val ex_mem_mem_read = Input(Bool())
    val dmem_resp_valid = Input(Bool())
    val id_ex_rd = Input(UInt(5.W))
    val ex_mem_rd = Input(UInt(5.W))
    val id_ex_branch = Input(Bool())
    //for forwarding
    val ex_mem_ins = Input(UInt(32.W))
    val mem_wb_ins = Input(UInt(32.W))
    val ex_ins = Input(UInt(32.W))
    val ex_result = Input(UInt(32.W))
    val ex_mem_result = Input(UInt(32.W))
    val mem_wb_result = Input(UInt(32.W))

    val id_ex_regWr = Input(Bool())
    val ex_mem_regWr = Input(Bool())
    val csr_Ex = Input(Bool())
    val csr_Mem = Input(Bool())
    val csr_Wb = Input(Bool())
    val csr_Ex_data = Input(UInt(32.W))
    val csr_Mem_data = Input(UInt(32.W))
    val csr_Wb_data = Input(UInt(32.W))
    val dmem_data = Input(UInt(32.W))
    
    //Outputs
    val immediate = Output(UInt(32.W))
    val writeRegAddress = Output(UInt(5.W))
    val readData1 = Output(UInt(32.W))
    val readData2 = Output(UInt(32.W))
    val func7 = Output(UInt(7.W))
    val func3 = Output(UInt(3.W))
    val func6 = Output(UInt(6.W))
    val ctl_aluSrc = Output(Bool())
    val ctl_memToReg = Output(UInt(2.W))
    val ctl_regWrite = Output(Bool())
    val ctl_memRead = Output(Bool())
    
    val ctl_memWrite = Output(Bool())
    val ctl_branch = Output(Bool())
    val ctl_aluOp = Output(UInt(2.W))
    val ctl_jump = Output(UInt(2.W))

    // Vector control Unit
    val ctl_v_RegWrite = Output(Bool())
    val ctl_v_opBsel = Output(Bool())
    val ctl_v_Ex_sel = Output(UInt(4.W))
    val ctl_v_aluop = Output(UInt(5.W))
    val ctl_v_vset = Output(Bool())
    val ctl_v_load = Output(UInt(4.W))
    val ctl_v_ins = Output(Bool())

    // vector register file
    val write_data = Input(SInt(128.W))
    val wb_addr = Input(UInt(5.W))
    val wb_RegWrite = Input(Bool())
    val id_lmul_count = Input(UInt(4.W))
    val id_lmul_vs1in_vs2in = Input(UInt(4.W))
    val vs0_data = Output(SInt(128.W))
    val vs1_data = Output(SInt(128.W))
    val vs2_data = Output(SInt(128.W))
    val reg_write = Output(Bool())
    val vs1_addr = Output(UInt(5.W))
    val vs2_addr = Output(UInt(5.W))
    val vd_addr = Output(UInt(5.W))
    val vd_data = Output(SInt(128.W))

    // Vector Immd Gen
    val v_z_imm = Output(SInt(32.W))
    val v_addi_imm = Output(SInt(32.W))

    // Vector Csr
    val vtypei = Input(SInt(11.W))
    val vtypei_out = Output(SInt(11.W))
    val vl = Input(SInt(32.W))
    val ctl_vset = Input(Bool())
    val vl_out = Output(SInt(32.W))
    val vstart_out = Output(SInt(32.W)) 

    val ctl_aluSrc1 = Output(UInt(2.W))
    val hdu_pcWrite = Output(Bool())
    val hdu_if_reg_write = Output(Bool())
    val pcSrc = Output(Bool())
    val pcPlusOffset = Output(UInt(32.W))
    val ifid_flush = Output(Bool())

    val stall = Output(Bool())

    // CSR pins
    val csr_i_misa        = Input(UInt(32.W))
    val csr_i_mhartid     = Input(UInt(32.W))
    val csr_o_data        = Output(UInt(32.W))
    val is_csr            = Output(Bool())
    val fscr_o_data       = Output(UInt(32.W))

    // RVFI pins
    val rs_addr = if (TRACE) Some(Output(Vec(2, UInt(5.W)))) else None
  })

  // CSR
  val csr = Module(new CSR())
  csr.io.i_misa_value         := io.csr_i_misa
  csr.io.i_mhartid_value      := io.csr_i_mhartid
  csr.io.i_imm                := io.id_instruction(19,15)
  csr.io.i_opr                := io.id_instruction(14,12)
  csr.io.i_addr               := io.id_instruction(31,20)
  csr.io.i_w_en               := io.is_csr && (io.id_instruction(19, 15) =/= 0.U)

  io.is_csr                   := io.id_instruction(6, 0) === "b1110011".U
  io.csr_o_data               := csr.io.o_data
  io.fscr_o_data              := csr.io.fcsr_o_data

  val csrController = Module(new CSRController())
  csrController.io.regWrExecute    := io.id_ex_regWr
  csrController.io.rdSelExecute    := io.id_ex_rd
  csrController.io.csrWrExecute    := io.csr_Ex
  csrController.io.regWrMemory     := io.ex_mem_regWr
  csrController.io.rdSelMemory     := io.ex_mem_rd
  csrController.io.csrWrMemory     := io.csr_Mem
  csrController.io.regWrWriteback  := io.ctl_writeEnable
  csrController.io.rdSelWriteback  := io.writeReg
  csrController.io.csrWrWriteback  := io.csr_Wb
  csrController.io.rs1SelDecode    := io.id_instruction(19,15)
  csrController.io.csrInstDecode   := io.id_instruction(6, 0) === "b1110011".U
  csrController.io.csrInstIsImmd   := 0.B

  //Hazard Detection Unit
  val hdu = Module(new HazardUnit)
  hdu.io.dmem_resp_valid := io.dmem_resp_valid
  hdu.io.id_ex_memRead := io.id_ex_mem_read
  hdu.io.ex_mem_memRead := io.ex_mem_mem_read
  hdu.io.id_ex_rd := io.id_ex_rd
  hdu.io.id_ex_branch := io.id_ex_branch
  hdu.io.ex_mem_rd := io.ex_mem_rd
  hdu.io.id_rs1 := io.id_instruction(19, 15)
  hdu.io.id_rs2 := io.id_instruction(24, 20)
  hdu.io.jump := io.ctl_jump
  hdu.io.branch := io.ctl_branch
  io.hdu_pcWrite := hdu.io.pc_write
  io.hdu_if_reg_write := hdu.io.if_reg_write

  //Control Unit
  val control = Module(new Control)
  control.io.in := io.id_instruction
  io.ctl_aluOp := control.io.aluOp
  io.ctl_aluSrc := control.io.aluSrc
  io.ctl_aluSrc1 := control.io.aluSrc1
  io.ctl_branch := control.io.branch
  io.ctl_memRead := control.io.memRead
  io.ctl_memToReg := control.io.memToReg
  io.ctl_jump := control.io.jump
  when(hdu.io.ctl_mux && io.id_instruction =/= "h13".U) {
    io.ctl_memWrite := control.io.memWrite
    io.ctl_regWrite := control.io.regWrite
  }.otherwise {
    io.ctl_memWrite := false.B
    io.ctl_regWrite := false.B
  }

  val Vcontrol = Module(new vu.controldec)
  dontTouch(Vcontrol.io)
  Vcontrol.io.Instruction := io.id_instruction
  io.ctl_v_RegWrite := Vcontrol.io.RegWrite
  io.ctl_v_opBsel := Vcontrol.io.opBsel
  io.ctl_v_Ex_sel := Vcontrol.io.Ex_sel
  io.ctl_v_aluop := Vcontrol.io.aluop
  io.ctl_v_vset := Vcontrol.io.vset
  io.ctl_v_load := Vcontrol.io.v_load
  io.ctl_v_ins := Vcontrol.io.v_ins

  //Register File
  val registers = Module(new Registers)
  val registerRd = io.writeReg
  val registerRs1 = io.id_instruction(19, 15)
  val registerRs2 = io.id_instruction(24, 20)
  registers.io.readAddress(0) := registerRs1
  registers.io.readAddress(1) := registerRs2
  when(io.ctl_vset === 1.B){
    registers.io.writeEnable := io.ctl_vset
    registers.io.writeData := io.vl.asUInt
    registers.io.writeAddress := io.wb_addr
  }.otherwise{
    registers.io.writeData := Mux(io.csr_Wb, io.csr_Wb_data, io.writeData)
    registers.io.writeEnable := io.ctl_writeEnable || io.csr_Wb
    registers.io.writeAddress := registerRd
  }

  val v_registers = Module(new vregfile)
  dontTouch(v_registers.io)
  v_registers.io.vd_data := io.write_data
  v_registers.io.vs1_addr := io.id_instruction(19, 15)
  v_registers.io.vs2_addr := io.id_instruction(24, 20)
  v_registers.io.vd_addr := io.wb_addr
  v_registers.io.reg_write := io.wb_RegWrite
  v_registers.io.reg_read := Vcontrol.io.RegRead

  io.vs0_data := v_registers.io.vs0_data
  io.vs1_data := v_registers.io.vs1_data
  io.vs2_data := v_registers.io.vs2_data
  io.vd_data := v_registers.io.vddata_o
  io.reg_write := Vcontrol.io.RegWrite
  io.vs1_addr := io.id_instruction(19, 15)
  io.vs2_addr := io.id_instruction(24, 20)
  io.vd_addr := io.id_instruction(11, 7)
  v_registers.io.lmul_count := io.id_lmul_count //grouping counter after write back stage
  v_registers.io.lmul_vs1in_vs2in := io.id_lmul_vs1in_vs2in //grouping counter after decode stage



  



  //Forwarding to fix structural hazard
  when(io.ctl_writeEnable && (io.writeReg === registerRs1)){
    when(registerRs1 === 0.U){
      io.readData1 := 0.U
    }.otherwise{
      io.readData1 := io.writeData
    }
  }.otherwise{
    io.readData1 := registers.io.readData(0)
  }
  when(io.ctl_writeEnable && (io.writeReg === registerRs2)){
    when(registerRs2 === 0.U){
      io.readData2 := 0.U
    }.otherwise{
      io.readData2 := io.writeData
    }
  }.otherwise{
    io.readData2 := registers.io.readData(1)
  }
  

  val immediate = Module(new ImmediateGen)
  immediate.io.instruction := io.id_instruction
  io.immediate := immediate.io.out

  val v_immediate = Module(new vu.ImmdValGen1)
  dontTouch(v_immediate.io)
  v_immediate.io.instruction := io.id_instruction
  io.v_addi_imm := v_immediate.io.addi_imm

  // vector Csr
  val vec_csr = Module(new vu.v_csr)
  dontTouch(vec_csr.io)
  vec_csr.io.vl := io.vl
  vec_csr.io.vtypei := io.vtypei
  vec_csr.io.vset := io.ctl_vset

  io.v_z_imm := io.id_instruction(30, 20).asSInt
  io.vl_out := vec_csr.io.vl_out
  io.vtypei_out := vec_csr.io.vtype_out
  io.vstart_out := vec_csr.io.vstart_out

  // Branch Forwarding
  val input1 = Wire(UInt(32.W))
  val input2 = Wire(UInt(32.W))

  when(registerRs1 === io.ex_mem_ins(11, 7)) {
    input1 := io.ex_mem_result
  }.elsewhen(registerRs1 === io.mem_wb_ins(11, 7)) {
      input1 := io.mem_wb_result
    }
    .otherwise {
      input1 := io.readData1
    }
  when(registerRs2 === io.ex_mem_ins(11, 7)) {
    input2 := io.ex_mem_result
  }.elsewhen(registerRs2 === io.mem_wb_ins(11, 7)) {
      input2 := io.mem_wb_result
    }
    .otherwise {
      input2 := io.readData2
    }

  //Branch Unit
  val bu = Module(new BranchUnit)
  bu.io.branch := io.ctl_branch
  bu.io.funct3 := io.id_instruction(14, 12)
  bu.io.rd1 := input1
  bu.io.rd2 := input2
  bu.io.take_branch := hdu.io.take_branch
  hdu.io.taken := bu.io.taken  

  //Forwarding for Jump
  val j_offset = Wire(UInt(32.W))
    when(registerRs1 === io.ex_ins(11, 7)){
      j_offset := io.ex_result
    }.elsewhen(registerRs1 === io.ex_mem_ins(11, 7)) {
    j_offset := io.ex_mem_result
  }.elsewhen(registerRs1 === io.mem_wb_ins(11, 7)) {
    j_offset := io.mem_wb_result
  }.elsewhen(registerRs1 === io.ex_ins(11, 7)){
    j_offset := io.ex_result
  }.otherwise {
      j_offset := io.readData1
    }

  //Offset Calculation (Jump/Branch)
  when(io.ctl_jump === 1.U) {
    io.pcPlusOffset := io.pcAddress + io.immediate
  }.elsewhen(io.ctl_jump === 2.U) {
      io.pcPlusOffset := j_offset + io.immediate
    }
    .otherwise {
      io.pcPlusOffset := io.pcAddress + immediate.io.out
    }

  when(bu.io.taken || io.ctl_jump =/= 0.U) {
    io.pcSrc := true.B
  }.otherwise {
    io.pcSrc := false.B
  }

  //Instruction Flush
  io.ifid_flush := hdu.io.ifid_flush

  io.writeRegAddress := io.id_instruction(11, 7)
  io.func3 := io.id_instruction(14, 12)
  io.func6 := io.id_instruction(31,26)
  when((io.id_instruction(6,0) === "b0110011".U) | ((io.id_instruction(6,0) === "b0010011".U) & (io.func3 === 5.U))){
    io.func7 := io.id_instruction(31,25)
  }.otherwise{
    io.func7 := 0.U
  }

  io.stall := io.func7 === 1.U && (io.func3 === 4.U || io.func3 === 5.U || io.func3 === 6.U || io.func3 === 7.U)

  val csr_iData_cases = Array(
    1.U -> io.ex_result,
    2.U -> Mux(io.ex_mem_mem_read, io.dmem_data, io.ex_mem_result),
    3.U -> io.writeData,
    4.U -> io.csr_Ex_data,
    5.U -> io.csr_Mem_data,
    6.U -> io.csr_Wb_data
  )

  csr.io.i_data := MuxLookup(csrController.io.forwardRS1, registers.io.readData(1), csr_iData_cases)

  // RVFI
  if (TRACE) {
    Seq(
      registerRs1,
      registerRs2
    ).zipWithIndex.map(
      tr => io.rs_addr.get(tr._2) := tr._1
    )
  }
}
