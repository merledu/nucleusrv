package nucleusrv.components

import chisel3._
import chisel3.util._

class InstructionDecode(
  F: Boolean,
  Zicsr: Boolean,
  TRACE: Boolean
) extends Module {
  val io = IO(new Bundle {
    val id_instruction = Input(UInt(32.W))
    val writeData = Input(UInt(32.W))
    val writeReg = Input(UInt(5.W))
    val pcAddress = Input(UInt(32.W))
    val ctl_writeEnable = Input(Vec(if (F) 2 else 1, Bool()))
    val id_ex_mem_read = Input(Bool())
//    val ex_mem_mem_write = Input(Bool())
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

    val ex_stall = Input(Bool())

    //Outputs
    val immediate = Output(UInt(32.W))
    val writeRegAddress = Output(UInt(5.W))
    val readData1 = Output(UInt(32.W))
    val readData2 = Output(UInt(32.W))
    val func7 = Output(UInt(7.W))
    val func3 = Output(UInt(3.W))
    val ctl_aluSrc = Output(Bool())
    val ctl_memToReg = Output(UInt(2.W))
    val ctl_regWrite = Output(Vec(if (F) 2 else 1, Bool()))
    val ctl_memRead = Output(Bool())
    val ctl_memWrite = Output(Bool())
    val ctl_branch = Output(Bool())
    val ctl_aluOp = Output(UInt(2.W))
    val ctl_jump = Output(UInt(2.W))
    val ctl_aluSrc1 = Output(UInt(2.W))
    val hdu_pcWrite = Output(Bool())
    val hdu_if_reg_write = Output(Bool())
    val pcSrc = Output(Bool())
    val pcPlusOffset = Output(UInt(32.W))
    val ifid_flush = Output(Bool())

    val stall = Output(Bool())

    // CSR pins
    val csr_i_misa        = if (Zicsr) Some(Input(UInt(32.W))) else None
    val csr_i_mhartid     = if (Zicsr) Some(Input(UInt(32.W))) else None
    val csr_o_data        = if (Zicsr) Some(Output(UInt(32.W))) else None
    val is_csr            = if (Zicsr) Some(Output(Bool())) else None
    val fcsr_o_data       = if (Zicsr) Some(Output(UInt(32.W))) else None

    // F pins
    val f_read_reg = if (F) Some(Input(Vec(3, Vec(2, Bool())))) else None
    val f_except = if (F) Some(Input(Vec(3, Vec(5, Bool())))) else None
    val is_f_in = if (F) Some(Input(Vec(3, Bool()))) else None
    val f_read = if (F) Some(Output(Vec(3, Bool()))) else None
    val readData3 = if (F) Some(Output(UInt(32.W))) else None
    val is_f = if (F) Some(Output(Bool())) else None

    // RVFI pins
    val raddr = if (TRACE) Some(Output(Vec(3, UInt(5.W)))) else None
    val rd_wdata = if (TRACE) Some(Output(UInt(32.W))) else None
  })

  val is_f = if (F) Some(WireInit(0.B)) else None
  if (F) {
    is_f.get := Vector(
      "b0000111",
      "b0100111",
      "b1000011",
      "b1000111",
      "b1001011",
      "b1001111",
      "b1010011"
    ).map(io.id_instruction(6, 0) === _.U).reduce(_ || _)
    io.is_f.get := is_f.get
  }

  // CSR
  val csr = if (Zicsr) Some(Module(new CSR())) else None
  if (Zicsr) {
    csr.get.io.i_misa_value         := io.csr_i_misa.get
    csr.get.io.i_mhartid_value      := io.csr_i_mhartid.get
    csr.get.io.i_imm                := io.id_instruction(19,15)
    csr.get.io.i_opr                := io.id_instruction(14,12)
    csr.get.io.i_addr               := io.id_instruction(31,20)
    csr.get.io.i_w_en               := io.is_csr.get && (io.id_instruction(19, 15) =/= 0.U)
    csr.get.io.f_except             <> io.f_except.get(2)

    io.is_csr.get                   := io.id_instruction(6, 0) === "b1110011".U
    io.csr_o_data.get               := MuxCase(csr.get.io.o_data, Vector(
                                         ((io.id_instruction(31, 20) === 1.U) || (io.id_instruction(31, 20) === 3.U)) -> (csr.get.io.o_data | (0 until 3).map(
                                           f => Mux(io.is_f_in.get(f), io.f_except.get(f).asUInt, 0.U)
                                         ).reduce(_ | _))
                                       ))
    io.fcsr_o_data.get              := csr.get.io.fcsr_o_data
  }

  val csrController = if (Zicsr) Some(Module(new CSRController())) else None
  if (Zicsr) {
    csrController.get.io.regWrExecute    := io.id_ex_regWr
    csrController.get.io.rdSelExecute    := io.id_ex_rd
    csrController.get.io.csrWrExecute    := io.csr_Ex
    csrController.get.io.regWrMemory     := io.ex_mem_regWr
    csrController.get.io.rdSelMemory     := io.ex_mem_rd
    csrController.get.io.csrWrMemory     := io.csr_Mem
    csrController.get.io.regWrWriteback  := io.ctl_writeEnable(0)
    csrController.get.io.rdSelWriteback  := io.writeReg
    csrController.get.io.csrWrWriteback  := io.csr_Wb
    csrController.get.io.rs1SelDecode    := io.id_instruction(19,15)
    csrController.get.io.csrInstDecode   := io.id_instruction(6, 0) === "b1110011".U
    csrController.get.io.csrInstIsImmd   := 0.B
  }

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
  val control = Module(new Control(F))
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
    io.ctl_regWrite(0) := control.io.regWrite
  }.otherwise {
    io.ctl_memWrite := false.B
    io.ctl_regWrite(0) := false.B
  }
  if (F) {
    io.ctl_regWrite(1) := Mux(
      hdu.io.ctl_mux && io.id_instruction =/= "h13".U,
      control.io.f_wr.get,
      0.B
    )
    io.f_read.get <> control.io.f_read.get
  }

  //Register File
  val registers = Module(new Registers(F))
  val registerRd = io.writeReg
  val registerRs1 = dontTouch(io.id_instruction(19, 15))
  val registerRs2 = io.id_instruction(24, 20)
  val registerRs3 = if (F) Some(io.id_instruction(31, 27)) else None
  val readData1 = WireInit(0.U(32.W))
  val readData2 = WireInit(0.U(32.W))
  val writeData = dontTouch(Mux(io.csr_Wb, io.csr_Wb_data, io.writeData))
  registers.io.readAddress(0) := registerRs1
  registers.io.readAddress(1) := registerRs2
  registers.io.writeEnable(0) := io.ctl_writeEnable(0) || (!io.ex_stall && io.csr_Wb)
  registers.io.writeAddress := registerRd
  registers.io.writeData := writeData
  if (F) {
    registers.io.readAddress(2) := registerRs3.get
    registers.io.f_read.get <> control.io.f_read.get
    registers.io.writeEnable(1) := io.ctl_writeEnable(1)
  }

  //Forwarding to fix structural hazard
  when (
    (io.writeReg === registerRs1)
    && (
      if (F) (io.ctl_writeEnable(0) && !control.io.f_read.get(0)) || (io.ctl_writeEnable(1) && control.io.f_read.get(0))
      else io.ctl_writeEnable(0)
    )
  ) {
    when (
      (registerRs1 === 0.U)
      && (if (F) !control.io.f_read.get(0) else 1.B)
    ) {
      readData1 := 0.U
    }.otherwise{
      readData1 := io.writeData
    }
  }.otherwise {
    readData1 := registers.io.readData(0)
  }
  io.readData1 := readData1
  when (
    (io.writeReg === registerRs2)
    && (
      if (F) (io.ctl_writeEnable(0) && !control.io.f_read.get(1)) || (io.ctl_writeEnable(1) && control.io.f_read.get(1))
      else io.ctl_writeEnable(0)
    )
  ) {
    when (
      (registerRs2 === 0.U)
      && (if (F) !control.io.f_read.get(1) else 1.B)
    ) {
      readData2 := 0.U
    }.otherwise{
      readData2 := io.writeData
    }
  }.otherwise{
    readData2 := registers.io.readData(1)
  }
  io.readData2 := readData2
  if (F) {
    io.readData3.get := Mux(
      (io.writeReg === registerRs3.get) && (io.ctl_writeEnable(1) && control.io.f_read.get(2)),
      io.writeData,
      registers.io.readData(2)
    )
  }
  

  val immediate = Module(new ImmediateGen(F))
  immediate.io.instruction := io.id_instruction
  io.immediate := immediate.io.out

  // Branch Forwarding
  val input1 = Wire(UInt(32.W))
  val input2 = Wire(UInt(32.W))

  when (
    (registerRs1 === io.ex_mem_ins(11, 7))
    && (if (F) !io.f_read_reg.get(1)(0) else 1.B)
  ) {
    input1 := io.ex_mem_result
  }.elsewhen (
    (registerRs1 === io.mem_wb_ins(11, 7))
    && (if (F) !io.f_read_reg.get(2)(0) else 1.B)
  ) {
    input1 := io.mem_wb_result
  }.otherwise {
    input1 := readData1
  }
  when (
    (registerRs2 === io.ex_mem_ins(11, 7))
    && (if (F) !io.f_read_reg.get(1)(1) else 1.B)
  ) {
    input2 := io.ex_mem_result
  }.elsewhen (
    (registerRs2 === io.mem_wb_ins(11, 7))
    && (if (F) !io.f_read_reg.get(2)(1) else 1.B)
  ) {
    input2 := io.mem_wb_result
  }.otherwise {
    input2 := readData2
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
  when(
    (registerRs1 === io.ex_ins(11, 7))
    && (if (F) !io.f_read_reg.get(0)(0) else 1.B)
  ) {
    j_offset := io.ex_result
  }.elsewhen (
    (registerRs1 === io.ex_mem_ins(11, 7))
    && (if (F) !io.f_read_reg.get(1)(0) else 1.B)
  ) {
    j_offset := io.ex_mem_result
  }.elsewhen (
    (registerRs1 === io.mem_wb_ins(11, 7))
    && (if (F) !io.f_read_reg.get(2)(0) else 1.B)
  ) {
    j_offset := io.mem_wb_result
  }.otherwise {
    j_offset := readData1
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

  when(bu.io.taken || (io.ctl_jump =/= 0.U)) {
    io.pcSrc := true.B
  }.otherwise {
    io.pcSrc := false.B
  }

  //Instruction Flush
  io.ifid_flush := hdu.io.ifid_flush

  io.writeRegAddress := io.id_instruction(11, 7)
  io.func3 := io.id_instruction(14, 12)
  when(
    (io.id_instruction(6,0) === "b0110011".U) | (
      (io.id_instruction(6,0) === "b0010011".U) & (io.func3 === 5.U)
    ) | (io.id_instruction(6, 0) === "b1010011".U)
  ){
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

  if (Zicsr) {
    csr.get.io.i_data := MuxLookup(csrController.get.io.forwardRS1, registers.io.readData(0), csr_iData_cases)
  }

  // RVFI
  if (TRACE) {
    Vector(
      registerRs1,
      registerRs2,
      registerRd
    ).zipWithIndex.foreach(
      tr => io.raddr.get(tr._2) := tr._1
    )
    io.rd_wdata.get := writeData
  }
}
