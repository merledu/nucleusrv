package nucleusrv.components

import chisel3._
import chisel3.util._

import nucleusrv.components.fpu._

class InstructionDecode(XLEN:Int, F:Boolean, TRACE:Boolean) extends Module {
  val io = IO(new Bundle {
    val id_instruction = Input(UInt(32.W))
    val writeData = Input(UInt(32.W))
    val writeReg = Input(UInt(5.W))
    val pcAddress = Input(UInt(32.W))
    val ctl_writeEnable = Input(Bool())
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
    
    //Outputs
    val immediate = Output(UInt(32.W))
    val writeRegAddress = Output(UInt(5.W))
    val readData1 = Output(UInt(32.W))
    val readData2 = Output(UInt(32.W))
    val func7 = Output(UInt(7.W))
    val func3 = Output(UInt(3.W))
    val ctl_aluSrc = Output(Bool())
    val ctl_memToReg = Output(UInt(2.W))
    val ctl_regWrite = Output(Bool())
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

    // F pins
    val fWrite     = if (F) Some(Input(Vec(3, Bool()))) else None
    val iWrite     = if (F) Some(Input(Vec(3, Bool()))) else None
    val fpCUfWrite = if (F) Some(Output(Bool())) else None
    val fpCUiWrite = if (F) Some(Output(Bool())) else None
    val fpCURead   = if (F) Some(Output(Bool())) else None
    val fAluCtl    = if (F) Some(Output(UInt(5.W))) else None
    val readData3  = if (F) Some(Output(UInt(32.W))) else None
    val rm         = if (F) Some(Output(UInt(3.W))) else None
    val rs3        = if (F) Some(Output(UInt(5.W))) else None

    // CSR pins
    val csr_i_misa    = Input(UInt(32.W))
    val csr_i_mhartid = Input(UInt(32.W))
    val csr_o_data    = Output(UInt(32.W))
    val is_csr        = Output(Bool())
    val fscr_o_data   = Output(UInt(32.W))

    // RVFI pins
    val rs_addr = if (TRACE) Some(Output(Vec(2, UInt(5.W)))) else None
  })

  // F Extension
  val fpDecoder  = if (F) Some(Module(new FPDecoder(XLEN)).io) else None
  val fpRegFile  = if (F) Some(dontTouch(Module(new FPRegisters).io)) else None
  val fpCU       = if (F) Some(Module(new FPControl).io) else None
  val fWrite     = if (F) VecInit(
    Seq(fpCU.get.fWrite) ++ (0 until io.fWrite.get.length).toSeq.map(
      f => io.fWrite.get(f)
    )
  ) else VecInit(
    for (i <- 0 until 4)
      yield 0.B
  )
  val fRead      = if (F) fpCU.get.fRead else WireInit(0.B)
  val fLoad      = if (F) fpCU.get.fLoad else WireInit(0.B)
  val fStore     = if (F) fpCU.get.fStore else WireInit(0.B)
  val iWrite     = if (F) VecInit(
    Seq(fpCU.get.iWrite) ++ (0 until io.iWrite.get.length).toSeq.map(
      f => io.iWrite.get(f)
    )
  ) else VecInit(
    for (i <- 0 until 4)
      yield 0.B
  )

  if (F) {
    fpDecoder.get.inst := io.id_instruction

    fpCU.get.opcode := io.id_instruction(6, 0)
    fpCU.get.fmt    := fpDecoder.get.fmt
    fpCU.get.funct5 := fpDecoder.get.funct5
    fpCU.get.rm     := fpDecoder.get.rm
    fpCU.get.rs2    := io.id_instruction(24, 20)

    io.fpCUfWrite.get := fpCU.get.fWrite
    io.fpCUiWrite.get := fpCU.get.iWrite
    io.fAluCtl.get    := fpCU.get.aluCtl
    io.rs3.get        := fpDecoder.get.funct5
    io.fpCURead.get   := fpCU.get.fRead
    io.rm.get         := fpDecoder.get.rm
  }

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
  val hdu = Module(new HazardUnit(F))
  hdu.io.dmem_resp_valid := io.dmem_resp_valid
  hdu.io.id_ex_memRead := io.id_ex_mem_read
//  hdu.io.ex_mem_memWrite := io.ex_mem_mem_write
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

  if (F) {
    for (i <- 0 until hdu.io.fWrite.get.length) {
      hdu.io.fWrite.get(i) := fWrite(i)
    }
  }

  //Control Unit
  val control = Module(new Control)
  control.io.in := io.id_instruction
  io.ctl_aluOp := control.io.aluOp
  io.ctl_aluSrc := control.io.aluSrc || fRead
  io.ctl_aluSrc1 := control.io.aluSrc1
  io.ctl_branch := control.io.branch
  io.ctl_memRead := control.io.memRead || fLoad
  io.ctl_memToReg := Mux(fLoad, 1.U, control.io.memToReg)
  io.ctl_jump := control.io.jump
  when(hdu.io.ctl_mux && io.id_instruction =/= "h13".U) {
    io.ctl_regWrite := control.io.regWrite || iWrite(0)
    io.ctl_memWrite := control.io.memWrite || fStore

    if (F) {
      io.fpCUfWrite.get := fpCU.get.fWrite
      io.fpCUiWrite.get := fpCU.get.iWrite
    }
  }.otherwise {
    io.ctl_memWrite := false.B
    io.ctl_regWrite := false.B

    if (F) {
      io.fpCUfWrite.get := 0.B
      io.fpCUiWrite.get := 0.B
    }
  }

  //Register File
  val registers = Module(new Registers)
  val registerRd = io.writeReg
  val registerRs1 = io.id_instruction(19, 15)
  val registerRs2 = io.id_instruction(24, 20)
  registers.io.readAddress(0) := registerRs1
  registers.io.readAddress(1) := registerRs2
  registers.io.writeEnable := io.ctl_writeEnable || io.csr_Wb || iWrite(3)
  registers.io.writeAddress := registerRd
  registers.io.writeData := Mux(io.csr_Wb, io.csr_Wb_data, io.writeData)

  // Floating point Register File
  val ffwd = fWrite(3) && fRead
  if (F) {
    Seq(
      registerRd,           // rd
      registerRs1,          // rs1
      registerRs2,          // rs2
      fpDecoder.get.funct5  // rs3
    ).zipWithIndex.foreach(
      f => dontTouch(fpRegFile.get.rAddr(f._2)) := f._1
    )
    
    fpRegFile.get.wData.valid := fWrite(3)
    fpRegFile.get.wData.bits  := io.writeData

    when ((io.writeReg === fpDecoder.get.funct5) && ffwd) {
      io.readData3.get := io.writeData
    } otherwise {
      io.readData3.get := fpRegFile.get.rData(2)
    }
  }

  //Forwarding to fix structural hazard
  when((io.ctl_writeEnable || ffwd) && (io.writeReg === registerRs1)){
    when(registerRs1 === 0.U){
      io.readData1 := Mux(ffwd, io.writeData, 0.U)
    }.otherwise{
      io.readData1 := io.writeData
    }
  }.otherwise{
    io.readData1 := Mux(
      fRead && !fStore,
      if (F) fpRegFile.get.rData(0) else 0.U,
      registers.io.readData(0)
    )
  }
  when((io.ctl_writeEnable || ffwd) && (io.writeReg === registerRs2)){
    when(registerRs2 === 0.U){
      io.readData2 := Mux(ffwd, io.writeData, 0.U)
    }.otherwise{
      io.readData2 := io.writeData
    }
  }.otherwise{
    io.readData2 := Mux(
      fRead,
      if (F) fpRegFile.get.rData(1) else 0.U,
      registers.io.readData(1)
    )
  }

  

  val immediate = Module(new ImmediateGen(F))
  immediate.io.instruction := io.id_instruction
  io.immediate := immediate.io.out

  // Branch Forwarding
  val input1 = Wire(UInt(32.W))
  val input2 = Wire(UInt(32.W))

  val fJmpFwd = VecInit(
    fRead === fWrite(1),  // id_ex
    fRead === fWrite(2),  // ex_mem
    fRead === fWrite(3)   // mem_wb
  )

  when((registerRs1 === io.ex_mem_ins(11, 7)) && !fJmpFwd(1)) {
    input1 := io.ex_mem_result
  }.elsewhen((registerRs1 === io.mem_wb_ins(11, 7)) && !fJmpFwd(2)) {
      input1 := io.mem_wb_result
    }
    .otherwise {
      input1 := io.readData1
    }
  when((registerRs2 === io.ex_mem_ins(11, 7)) && !fJmpFwd(1)) {
    input2 := io.ex_mem_result
  }.elsewhen((registerRs2 === io.mem_wb_ins(11, 7)) && !fJmpFwd(2)) {
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
    when((registerRs1 === io.ex_ins(11, 7)) && !fJmpFwd(0)) {
      j_offset := io.ex_result
    }.elsewhen((registerRs1 === io.ex_mem_ins(11, 7)) && !fJmpFwd(1)) {
    j_offset := io.ex_mem_result
  }.elsewhen((registerRs1 === io.mem_wb_ins(11, 7)) && !fJmpFwd(2)) {
    j_offset := io.mem_wb_result
  }.elsewhen((registerRs1 === io.ex_ins(11, 7)) && !fJmpFwd(0)) {
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
