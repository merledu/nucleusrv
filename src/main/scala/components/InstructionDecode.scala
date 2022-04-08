
package nucleusrv.components
import chisel3._

class InstructionDecode extends Module {
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
    
    //Outputs
    val immediate = Output(UInt(32.W))
    val writeRegAddress = Output(UInt(5.W))
    val readData1 = Output(UInt(32.W))
    val readData2 = Output(UInt(32.W))
    val func7 = Output(UInt(1.W))
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
  })

  //Hazard Detection Unit
  val hdu = Module(new HazardUnit)
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

  //Register File
  val registers = Module(new Registers)
  val registerRd = io.writeReg
  val registerRs1 = io.id_instruction(19, 15)
  val registerRs2 = io.id_instruction(24, 20)
  registers.io.readAddress(0) := registerRs1
  registers.io.readAddress(1) := registerRs2
  registers.io.writeEnable := io.ctl_writeEnable
  registers.io.writeAddress := registerRd
  registers.io.writeData := io.writeData

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
  io.func7 := io.id_instruction(30)
}
