package nucleusrv.components

import chisel3._
import chisel3.util._

class Core(implicit val config:Configs) extends Module{

  val M      = config.M
  val C      = config.C
  val XLEN   = config.XLEN
  val TRACE  = config.TRACE

  val io = IO(new Bundle {
    val pin: UInt = Output(UInt(32.W))
    val stall: Bool = Input(Bool())

    val dmemReq = Decoupled(new MemRequestIO)
    val dmemRsp = Flipped(Decoupled(new MemResponseIO))

    val imemReq = Decoupled(new MemRequestIO)
    val imemRsp = Flipped(Decoupled(new MemResponseIO))

    // RVFI Pins
    val rvfiUInt    = if (TRACE) Some(Output(Vec(4, UInt(32.W)))) else None
    val rvfiSInt    = if (TRACE) Some(Output(Vec(5, SInt(32.W)))) else None
    val rvfiBool    = if (TRACE) Some(Output(Vec(1, Bool()))) else None
    val rvfiRegAddr = if (TRACE) Some(Output(Vec(3, UInt(5.W)))) else None
    val rvfiMode    = if (TRACE) Some(Output(UInt(2.W))) else None
  })

  // IF-ID Registers
  val if_reg_pc = RegInit(0.U(32.W))
  val if_reg_ins = RegInit(0.U(32.W))

  // ID-EX Registers
  val id_reg_pc = RegInit(0.U(32.W))
  val id_reg_rd1 = RegInit(0.U(32.W))
  val id_reg_rd2 = RegInit(0.U(32.W))
  val id_reg_imm = RegInit(0.U(32.W))
  val id_reg_wra = RegInit(0.U(5.W))
  val id_reg_f7 = RegInit(0.U(7.W))
  val id_reg_f3 = RegInit(0.U(3.W))
  val id_reg_ins = RegInit(0.U(32.W))
  val id_reg_ctl_aluSrc = RegInit(false.B)
  val id_reg_ctl_aluSrc1 = RegInit(0.U(2.W))
  val id_reg_ctl_memToReg = RegInit(0.U(2.W))
  val id_reg_ctl_regWrite = RegInit(false.B)
  val id_reg_ctl_memRead = RegInit(false.B)
  val id_reg_ctl_memWrite = RegInit(false.B)
  val id_reg_ctl_branch = RegInit(false.B)
  val id_reg_ctl_aluOp = RegInit(0.U(2.W))
  val id_reg_ctl_jump = RegInit(0.U(2.W))
  
  // CSR pipeline registers
  val id_reg_csr_read = RegInit(false.B)
  val id_reg_csr_write = RegInit(false.B)
  val id_reg_csr_op = RegInit(0.U(3.W))
  val id_reg_csr_addr = RegInit(0.U(12.W))
  val id_reg_is_ecall = RegInit(false.B)
  val id_reg_is_ebreak = RegInit(false.B)
  val id_reg_is_mret = RegInit(false.B)
  val id_reg_is_system = RegInit(false.B)

  // EX-MEM Registers
  val ex_reg_branch = RegInit(0.U(32.W))
  val ex_reg_zero = RegInit(0.U(32.W))
  val ex_reg_result = RegInit(0.U(32.W))
  val ex_reg_wd = RegInit(0.U(32.W))
  val ex_reg_wra = RegInit(0.U(5.W))
  val ex_reg_ins = RegInit(0.U(32.W))
  val ex_reg_ctl_memToReg = RegInit(0.U(2.W))
  val ex_reg_ctl_regWrite = RegInit(false.B)
  val ex_reg_ctl_memRead = RegInit(false.B)
  val ex_reg_ctl_memWrite = RegInit(false.B)
  val ex_reg_ctl_branch_taken = RegInit(false.B)
  val ex_reg_pc = RegInit(0.U(32.W))
  
  // CSR EX-MEM pipeline registers
  val ex_reg_csr_data = RegInit(0.U(32.W))
  val ex_reg_csr_write = RegInit(false.B)
  val ex_reg_csr_addr = RegInit(0.U(12.W))
  val ex_reg_exception = RegInit(false.B)
  val ex_reg_exception_pc = RegInit(0.U(32.W))
  val ex_reg_mret_pc = RegInit(0.U(32.W))
  val ex_reg_take_trap = RegInit(false.B)
  val ex_reg_take_mret = RegInit(false.B)

  // MEM-WB Registers
  val mem_reg_rd = RegInit(0.U(32.W))
  val mem_reg_ins = RegInit(0.U(32.W))
  val mem_reg_result = RegInit(0.U(32.W))
  val mem_reg_branch = RegInit(0.U(32.W))
  val mem_reg_wra = RegInit(0.U(5.W))
  val mem_reg_ctl_memToReg = RegInit(0.U(2.W))
  val mem_reg_ctl_regWrite = RegInit(false.B)
  val mem_reg_pc = RegInit(0.U(32.W))

  //Pipeline Units
  val IF = Module(new InstructionFetch).io
  val ID = Module(new InstructionDecode(TRACE)).io
  val EX = Module(new Execute(M = M)).io
  val MEM = Module(new MemoryFetch)
  
  // CSR Unit
  val CSR_UNIT = Module(new CSRUnit).io

  /*****************
   * Fetch Stage *
   ******************/

  val pc = Module(new PC)

  io.imemReq <> IF.coreInstrReq
  IF.coreInstrResp <> io.imemRsp

  val instruction = Wire(UInt(32.W))
  val ral_halt_o  = WireInit(false.B)
  val is_comp     = WireInit(false.B)


  if (C) {

    /*****************
    * Realingner *
    ******************/
    val RA = Module(new Realigner).io

    RA.ral_address_i     := pc.io.in.asUInt()
    RA.ral_instruction_i := IF.instruction
    RA.ral_jmp           := ID.pcSrc

    IF.address           := RA.ral_address_o
    val instruction_cd    = RA.ral_instruction_o

    ral_halt_o           := RA.ral_halt_o

    /*************************************************
    * Compressed Decoder (Fully Combinational) *
    *************************************************/
    val CD = Module(new CompressedDecoder).io

    CD.instruction_i := instruction_cd
    instruction  := CD.instruction_o

    is_comp := CD.is_comp

  }
  else {

    IF.address := pc.io.in.asUInt()
    instruction := IF.instruction

  }

  val func3 = instruction(14, 12)
  val func7 = Wire(UInt(6.W))
  when(instruction(6,0) === "b0110011".U){
    func7 := instruction(31,25)
  }.otherwise{
    func7 := 0.U
  }

  val IF_stall = func7 === 1.U && (func3 === 4.U || func3 === 5.U || func3 === 6.U || func3 === 7.U)

  IF.stall := io.stall || EX.stall || ID.stall || IF_stall //stall signal from outside
  
  // pc.io.halt := Mux(io.imemReq.valid || ~EX.stall || ~ID.stall, 0.B, 1.B)
  pc.io.halt := Mux(((EX.stall || ID.stall || IF_stall || ~io.imemReq.valid) | ral_halt_o), 1.B, 0.B)
  
  // PC control with trap and MRET handling
  val npc = Wire(SInt(32.W))
  when(ex_reg_take_trap) {
    // Exception/interrupt occurred - jump to trap vector
    npc := ex_reg_exception_pc.asSInt()
  }.elsewhen(ex_reg_take_mret) {
    // MRET instruction - return from trap
    npc := ex_reg_mret_pc.asSInt()
  }.elsewhen(ID.hdu_pcWrite) {
    // Normal PC control (branches, jumps)
    npc := Mux(ID.pcSrc, ID.pcPlusOffset.asSInt(), Mux(is_comp, pc.io.pc2, pc.io.pc4))
  }.otherwise {
    // Default PC increment
    npc := pc.io.out
  }
  
  pc.io.in := npc

  when(ID.hdu_if_reg_write) {
    if_reg_pc := pc.io.out.asUInt()
    if_reg_ins := instruction 
  }
  when(ID.ifid_flush) {
    if_reg_ins := 0.U
  }


  /****************
   * Decode Stage *
   ****************/

  id_reg_rd1 := ID.readData1
  id_reg_rd2 := ID.readData2
  id_reg_imm := ID.immediate
  id_reg_wra := ID.writeRegAddress
  id_reg_f3 := ID.func3
  id_reg_f7 := ID.func7
  id_reg_ins := if_reg_ins
  id_reg_pc := if_reg_pc
  id_reg_ctl_aluSrc := ID.ctl_aluSrc
  id_reg_ctl_memToReg := ID.ctl_memToReg
  id_reg_ctl_regWrite := ID.ctl_regWrite
  id_reg_ctl_memRead := ID.ctl_memRead
  id_reg_ctl_memWrite := ID.ctl_memWrite
  id_reg_ctl_branch := ID.ctl_branch
  id_reg_ctl_aluOp := ID.ctl_aluOp
  id_reg_ctl_jump := ID.ctl_jump
  id_reg_ctl_aluSrc1 := ID.ctl_aluSrc1
  
  // CSR control signals
  id_reg_csr_read := ID.csr_read
  id_reg_csr_write := ID.csr_write
  id_reg_csr_op := ID.csr_op
  id_reg_csr_addr := ID.csr_addr
  id_reg_is_ecall := ID.is_ecall
  id_reg_is_ebreak := ID.is_ebreak
  id_reg_is_mret := ID.is_mret
  id_reg_is_system := ID.is_system
//  IF.PcWrite := ID.hdu_pcWrite
  ID.id_instruction := if_reg_ins
  ID.pcAddress := if_reg_pc
  ID.dmem_resp_valid := io.dmemRsp.valid
//  IF.PcSrc := ID.pcSrc
//  IF.PCPlusOffset := ID.pcPlusOffset
  ID.ex_ins := id_reg_ins
  ID.ex_mem_ins := ex_reg_ins
  ID.mem_wb_ins := mem_reg_ins
  ID.ex_mem_result := ex_reg_result


  /*****************
   * Execute Stage *
  ******************/

  //ex_reg_branch := EX.branchAddress
//  ex_reg_wd := EX.writeData
//  ex_reg_result := EX.ALUresult
  //ex_reg_ctl_branch_taken := EX.branch_taken
  EX.immediate := id_reg_imm
  EX.readData1 := id_reg_rd1
  EX.readData2 := id_reg_rd2
  EX.pcAddress := id_reg_pc
  EX.func3 := id_reg_f3
  EX.func7 := id_reg_f7
  EX.ctl_aluSrc := id_reg_ctl_aluSrc
  EX.ctl_aluOp := id_reg_ctl_aluOp
  EX.ctl_aluSrc1 := id_reg_ctl_aluSrc1
  //EX.ctl_branch := id_reg_ctl_branch
  //EX.ctl_jump := id_reg_ctl_jump
  ex_reg_pc := id_reg_pc
  ex_reg_wra := id_reg_wra
  ex_reg_ins := id_reg_ins
  ex_reg_ctl_memToReg := id_reg_ctl_memToReg
  ex_reg_ctl_regWrite := id_reg_ctl_regWrite
//  ex_reg_ctl_memRead := id_reg_ctl_memRead
//  ex_reg_ctl_memWrite := id_reg_ctl_memWrite
  
  // CSR Unit connections
  CSR_UNIT.csr_op := id_reg_csr_op
  CSR_UNIT.csr_read := id_reg_csr_read
  CSR_UNIT.csr_write := id_reg_csr_write
  CSR_UNIT.is_ecall := id_reg_is_ecall
  CSR_UNIT.is_ebreak := id_reg_is_ebreak
  CSR_UNIT.is_mret := id_reg_is_mret
  CSR_UNIT.csr_addr := id_reg_csr_addr
  CSR_UNIT.rs1_data := id_reg_rd1
  CSR_UNIT.rs1_addr := id_reg_ins(19, 15)
  CSR_UNIT.pc := id_reg_pc
  CSR_UNIT.inst_retired := true.B // For now, assume every instruction retires
  
  // Capture CSR outputs in pipeline registers
  ex_reg_csr_data := CSR_UNIT.csr_data
  ex_reg_exception := CSR_UNIT.exception
  ex_reg_exception_pc := CSR_UNIT.exception_pc
  ex_reg_mret_pc := CSR_UNIT.mret_pc
  ex_reg_take_trap := CSR_UNIT.take_trap
  ex_reg_take_mret := CSR_UNIT.take_mret
  
  ID.id_ex_mem_read := id_reg_ctl_memRead
  ID.ex_mem_mem_read := ex_reg_ctl_memRead
//  ID.ex_mem_mem_write := ex_reg_ctl_memWrite
  //EX.ex_mem_regWrite := ex_reg_ctl_regWrite
  //EX.mem_wb_regWrite := mem_reg_ctl_regWrite
  EX.id_ex_ins := id_reg_ins
  EX.ex_mem_ins := ex_reg_ins
  EX.mem_wb_ins := mem_reg_ins
  ID.id_ex_rd := id_reg_ins(11, 7)
  ID.id_ex_branch := Mux(id_reg_ins(6,0) === "b1100011".asUInt(), true.B, false.B )
  ID.ex_mem_rd := ex_reg_ins(11, 7)
  ID.ex_result := EX.ALUresult

  when(EX.stall){
    id_reg_wra := id_reg_wra
    id_reg_ctl_regWrite := id_reg_ctl_regWrite
  }

  /****************
   * Memory Stage *
   ****************/

  io.dmemReq <> MEM.io.dccmReq
  MEM.io.dccmRsp <> io.dmemRsp
//  val stall = Wire(Bool())
//  stall := (ex_reg_ctl_memWrite || ex_reg_ctl_memRead) && !io.dmemRsp.valid
//  when(MEM.io.stall){
//    mem_reg_rd := mem_reg_rd
//    mem_reg_result := mem_reg_result
////    mem_reg_wra := mem_reg_wra
//    ex_reg_wra := ex_reg_wra
//    ex_reg_ctl_memToReg := ex_reg_ctl_memToReg
////    mem_reg_ctl_memToReg := mem_reg_ctl_memToReg
//    ex_reg_ctl_regWrite := ex_reg_ctl_regWrite
//    mem_reg_ctl_regWrite := ex_reg_ctl_regWrite
//    mem_reg_ins := mem_reg_ins
//    mem_reg_pc := mem_reg_pc
//
//    ex_reg_ctl_memRead := ex_reg_ctl_memRead
//    ex_reg_ctl_memWrite := ex_reg_ctl_memWrite
////    ex_reg_wd := ex_reg_wd
////    ex_reg_result := 0.U
//
//  } otherwise{
    mem_reg_rd := MEM.io.readData
    mem_reg_result := ex_reg_result
//    mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
    mem_reg_ctl_regWrite := ex_reg_ctl_regWrite
    mem_reg_ins := ex_reg_ins
    mem_reg_pc := ex_reg_pc
    mem_reg_wra := ex_reg_wra
    ex_reg_ctl_memRead := id_reg_ctl_memRead
    ex_reg_ctl_memWrite := id_reg_ctl_memWrite
    ex_reg_wd := EX.writeData
    ex_reg_result := EX.ALUresult
//  }
  mem_reg_wra := ex_reg_wra
  mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
  EX.ex_mem_regWrite := ex_reg_ctl_regWrite
  MEM.io.aluResultIn := ex_reg_result
  MEM.io.writeData := ex_reg_wd
  MEM.io.readEnable := ex_reg_ctl_memRead
  MEM.io.writeEnable := ex_reg_ctl_memWrite
  MEM.io.f3 := ex_reg_ins(14,12)
  EX.mem_result := ex_reg_result

  /********************
   * Write Back Stage *
   ********************/

  val wb_data = Wire(UInt(32.W))
  val wb_addr = Wire(UInt(5.W))

  when(mem_reg_ctl_memToReg === 1.U) {
    wb_data := MEM.io.readData
    wb_addr := mem_reg_wra
  }.elsewhen(mem_reg_ctl_memToReg === 2.U) {
      wb_data := mem_reg_pc+4.U
      wb_addr := mem_reg_wra
  }.elsewhen(mem_reg_ctl_memToReg === 3.U) {
      // CSR data path
      wb_data := ex_reg_csr_data
      wb_addr := mem_reg_wra
    }
    .otherwise {
      wb_data := mem_reg_result
      wb_addr := mem_reg_wra
    }

  ID.mem_wb_result := wb_data
  ID.writeData := wb_data
  EX.wb_result := wb_data
  EX.mem_wb_regWrite := mem_reg_ctl_regWrite
  ID.writeReg := wb_addr
  ID.ctl_writeEnable := mem_reg_ctl_regWrite
  io.pin := wb_data

  /**************
  ** RVFI PINS **
  **************/
  if (TRACE) {
    val npcDelay = Reg(Vec(4, UInt(32.W)))
    val rsAddrDelay = for (i <- 0 until 2) yield Reg(Vec(3, UInt(5.W)))
    val rsDataDelay = for (i <- 0 until 2) yield Reg(Vec(2, SInt(32.W)))
    val memAddrDelay = RegInit(0.U(32.W))
    val memWdataDelay = RegInit(0.S(32.W))
    val stallDelay = Reg(Vec(4, Bool()))

    for (i <- 0 until 2) {
      for (j <- 0 until 2) {
        rsAddrDelay(i)(j + 1) := rsAddrDelay(i)(j)
      }
      rsAddrDelay(i)(0) := ID.rs_addr.get(i)
      io.rvfiRegAddr.get(i + 1) := rsAddrDelay(i)(2)

      rsDataDelay(i)(1) := rsDataDelay(i)(0)
      io.rvfiSInt.get(i + 1) := rsDataDelay(i)(1)
    }
    for (i <- 0 until 3) {
      npcDelay(i + 1) := npcDelay(i)
      stallDelay(i + 1) := stallDelay(i)
    }


    Seq(
      (npcDelay(0), npc.asUInt),
      (memAddrDelay, ex_reg_result),
      (rsDataDelay(0)(0), id_reg_rd1.asSInt),
      (rsDataDelay(1)(0), id_reg_rd2.asSInt),
      (memWdataDelay, ex_reg_wd.asSInt),
      (stallDelay(0), ID.hdu_if_reg_write),

      (io.rvfiUInt.get(0), mem_reg_pc),
      (io.rvfiUInt.get(1), npcDelay(3)),
      (io.rvfiUInt.get(2), mem_reg_ins),
      (io.rvfiUInt.get(3), memAddrDelay),

      (io.rvfiMode.get, 3.U),

      (io.rvfiRegAddr.get(0), wb_addr),

      (io.rvfiSInt.get(0), wb_data.asSInt),
      (io.rvfiSInt.get(3), MEM.io.readData.asSInt),
      (io.rvfiSInt.get(4), memWdataDelay),

      (io.rvfiBool.get(0), stallDelay(3))
    ).map(
      tr => tr._1 := tr._2
    )
  }
}
