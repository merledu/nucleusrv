package nucleusrv.components

import chisel3._
import chisel3.util._
import nucleusrv.tracer.{TracerI, delays}

class Core(implicit val config:Configs) extends Module{

  val M      = config.M
  val F      = config.F
  val C      = config.C
  val Zicsr  = config.Zicsr
  val A      = config.A
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
    val rvfi = if (TRACE) Some(Flipped(new TracerI)) else None
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
  val id_reg_ctl_regWrite = RegInit(VecInit(Vector.fill(if (F) 2 else 1)(0.B)))
  val id_reg_ctl_memRead = RegInit(false.B)
  val id_reg_ctl_memWrite = RegInit(false.B)
  val id_reg_ctl_branch = RegInit(false.B)
  val id_reg_ctl_aluOp = RegInit(0.U(2.W))
  val id_reg_ctl_jump = RegInit(0.U(2.W))
  val id_reg_is_csr = RegInit(false.B)
  val id_reg_csr_data = RegInit(0.U)

  val id_reg_f_read = if (F) Some(Reg(Vec(3, Bool()))) else None
  val id_reg_rd3 = if (F) Some(RegInit(0.U(32.W))) else None
  val id_reg_fcsr_o_data = if (F) Some(RegInit(0.U(32.W))) else None
  val id_reg_is_f = if (F) Some(RegInit(0.B)) else None

  // Atomic signals ID-EX 
  val id_reg_isAMO = RegInit(false.B)
  val id_reg_isLR  = RegInit(false.B)
  val id_reg_isSC  = RegInit(false.B)
  val id_reg_amoOp = RegInit(0.U(5.W))

  // EX-MEM Registers
  val ex_reg_branch = RegInit(0.U(32.W))
  val ex_reg_zero = RegInit(0.U(32.W))
  val ex_reg_result = RegInit(0.U(32.W))
  val ex_reg_wd = RegInit(0.U(32.W))
  val ex_reg_wra = RegInit(0.U(5.W))
  val ex_reg_ins = RegInit(0.U(32.W))
  val ex_reg_ctl_memToReg = RegInit(0.U(2.W))
  val ex_reg_ctl_regWrite = RegInit(VecInit(Vector.fill(if (F) 2 else 1)(0.B)))
  val ex_reg_ctl_memRead = RegInit(false.B)
  val ex_reg_ctl_memWrite = RegInit(false.B)
  val ex_reg_ctl_branch_taken = RegInit(false.B)
  val ex_reg_pc = RegInit(0.U(32.W))
  val ex_reg_is_csr = RegInit(false.B)
  val ex_reg_csr_data = RegInit(0.U)

  val ex_reg_f_read = if (F) Some(Reg(Vec(3, Bool()))) else None
  val ex_reg_f_except = if (F) Some(RegInit(VecInit(Vector.fill(5)(0.B)))) else None
  val ex_reg_is_f = if (F) Some(RegInit(0.B)) else None
  
  // Atomic signals EX-MEM
  val ex_reg_isAMO  = RegInit(false.B)
  val ex_reg_isLR   = RegInit(false.B)
  val ex_reg_isSC   = RegInit(false.B)
  val ex_reg_amoOp  = RegInit(0.U(5.W))
  
  // MEM-WB Registers
  val mem_reg_rd = RegInit(0.U(32.W))
  val mem_reg_ins = RegInit(0.U(32.W))
  val mem_reg_result = RegInit(0.U(32.W))
  val mem_reg_branch = RegInit(0.U(32.W))
  val mem_reg_wra = RegInit(0.U(5.W))
  val mem_reg_ctl_memToReg = RegInit(0.U(2.W))
  val mem_reg_ctl_regWrite = RegInit(VecInit(Vector.fill(if (F) 2 else 1)(0.B)))
  val mem_reg_pc = RegInit(0.U(32.W))
  val mem_reg_is_csr = RegInit(false.B)
  val mem_reg_csr_data = RegInit(0.U)

  val mem_reg_f_read = if (F) Some(Reg(Vec(3, Bool()))) else None
  val mem_reg_f_except = if (F) Some(RegInit(VecInit(Vector.fill(5)(0.B)))) else None
  val mem_reg_is_f = if (F) Some(RegInit(0.B)) else None

  // Atomic signals MEM-WB
  val mem_reg_isAMO = RegInit(false.B)
  val mem_reg_isLR  = RegInit(false.B)
  val mem_reg_isSC  = RegInit(false.B)

  // AMO state tracking
  // AMO state tracking
  val amo_read_done = RegInit(false.B)
  val amo_old_value = RegInit(0.U(32.W))
  val sc_issued = RegInit(false.B)

  //Pipeline Units
  val IF = Module(new InstructionFetch).io
  val ID = Module(new InstructionDecode(F, Zicsr, TRACE)).io
  val EX = Module(new Execute(F, M = M, TRACE = TRACE)).io
  val MEM = Module(new MemoryFetch(TRACE))

  // Reservationfile for LR/SC
  val reservationFile = Module(new ReservationFile).io
  
  /*****************
   * Fetch Stage *
   ******************/

  val pc = Module(new PC)

  io.imemReq <> IF.coreInstrReq
  IF.coreInstrResp <> io.imemRsp

  val instruction = Wire(UInt(32.W))
  val ral_halt_o  = WireInit(false.B)
  val is_comp     = dontTouch(WireInit(false.B))

  if (C) {
    val RA = Module(new Realigner).io
    RA.ral_address_i     := pc.io.out.asUInt
    RA.ral_instruction_i := IF.instruction
    RA.ral_jmp           := ID.pcSrc
    IF.address           := RA.ral_address_o
    val instruction_cd    = RA.ral_instruction_o
    ral_halt_o           := RA.ral_halt_o

    val CD = Module(new CompressedDecoder).io
    CD.instruction_i := instruction_cd
    instruction  := CD.instruction_o
    is_comp := CD.is_comp
  }
  else {
    IF.address := pc.io.out.asUInt
    instruction := IF.instruction
  }

  val func3 = instruction(14, 12)
  val func7 = Wire(UInt(7.W))
  when((instruction(6,0) === "b0110011".U) || (instruction(6, 0) === "b1010011".U)){
    func7 := instruction(31,25)
  }.otherwise{
    func7 := 0.U
  }

  val IF_stall = (
    func7 === 1.U && (func3 === 4.U || func3 === 5.U || func3 === 6.U || func3 === 7.U)
  ) || ((func7 === "b0001100".U) || (func7 === "b0101100".U))

  IF.stall := io.stall || EX.stall || ID.stall || IF_stall || ID.pcSrc || MEM.io.stall
  
  val halt = Mux(((EX.stall || ID.stall || io.imemReq.valid) | ral_halt_o || MEM.io.stall), 1.B, 0.B)
  pc.io.halt := halt
  val npc = Mux(
    ID.hdu_pcWrite,
    Mux(
      ID.pcSrc,
      ID.pcPlusOffset.asSInt,
      Mux(is_comp, pc.io.pc2, pc.io.pc4)
    ),
    pc.io.out
  )
  pc.io.in := dontTouch(npc)

  when(ID.hdu_if_reg_write && !MEM.io.stall) {
    if_reg_pc := pc.io.out.asUInt
    if_reg_ins := instruction 
  }
  when(ID.ifid_flush) {
    if_reg_ins := 0.U
  }
   
  /****************
   * Decode Stage *
   ****************/

  when(!MEM.io.stall) {
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
    id_reg_ctl_regWrite <> ID.ctl_regWrite
    id_reg_ctl_memRead := ID.ctl_memRead
    id_reg_ctl_memWrite := ID.ctl_memWrite
    id_reg_ctl_branch := ID.ctl_branch
    id_reg_ctl_aluOp := ID.ctl_aluOp
    id_reg_ctl_jump := ID.ctl_jump
    id_reg_ctl_aluSrc1 := ID.ctl_aluSrc1
    id_reg_is_csr := ID.is_csr.get
    id_reg_csr_data := ID.csr_o_data.get
    
    id_reg_isAMO := ID.isAMO
    id_reg_isLR  := ID.isLR
    id_reg_isSC  := ID.isSC
    id_reg_amoOp := ID.amoOp
  }

  ID.id_instruction := if_reg_ins
  ID.pcAddress := if_reg_pc
  ID.dmem_resp_valid := io.dmemRsp.valid
  ID.ex_ins := id_reg_ins
  ID.ex_mem_ins := ex_reg_ins
  ID.mem_wb_ins := mem_reg_ins
  ID.ex_mem_result := ex_reg_result

  ID.csr_i_misa.get    := DontCare
  ID.csr_i_mhartid.get := DontCare
  ID.id_ex_regWr := id_reg_ctl_regWrite(0)
  ID.ex_mem_regWr := ex_reg_ctl_regWrite(0)

  if (F) {
    id_reg_f_read.get <> ID.f_read.get
    id_reg_rd3.get := ID.readData3.get
    id_reg_fcsr_o_data.get := ID.fcsr_o_data.get
    id_reg_is_f.get := ID.is_f.get
    for (i <- 0 until 2) {
      ID.f_read_reg.get(0)(i) := id_reg_f_read.get(i)
      ID.f_read_reg.get(1)(i) := ex_reg_f_read.get(i)
      ID.f_read_reg.get(2)(i) := mem_reg_f_read.get(i)
    }
  }

  /*****************
   * Execute Stage *
  ******************/
  
  EX.isAMO := id_reg_isAMO
  EX.isLR := id_reg_isLR
  EX.isSC := id_reg_isSC

  EX.immediate := id_reg_imm
  EX.readData1 := id_reg_rd1
  EX.readData2 := id_reg_rd2
  EX.pcAddress := id_reg_pc
  EX.func3 := id_reg_f3
  EX.func7 := id_reg_f7
  EX.ctl_aluSrc := id_reg_ctl_aluSrc
  EX.ctl_aluOp := id_reg_ctl_aluOp
  EX.ctl_aluSrc1 := id_reg_ctl_aluSrc1

  // AMO new connections
  EX.amo_memData := amo_old_value
  EX.amo_src2    := ex_reg_wd
  EX.amo_op_code := ex_reg_amoOp
  
  when(!MEM.io.stall) {
    ex_reg_pc := id_reg_pc
    ex_reg_wra := id_reg_wra
    ex_reg_ins := id_reg_ins
    ex_reg_ctl_memToReg := id_reg_ctl_memToReg
    ex_reg_ctl_regWrite <> id_reg_ctl_regWrite
    ex_reg_is_csr := id_reg_is_csr
    ex_reg_csr_data := id_reg_csr_data
    ex_reg_ctl_memRead := id_reg_ctl_memRead
    ex_reg_ctl_memWrite := id_reg_ctl_memWrite
    ex_reg_wd := EX.writeData
    ex_reg_result := EX.ALUresult
    ex_reg_isAMO := id_reg_isAMO
    ex_reg_isLR  := id_reg_isLR
    ex_reg_isSC  := id_reg_isSC
    ex_reg_amoOp := id_reg_amoOp
  }
  
  ID.id_ex_mem_read := id_reg_ctl_memRead
  ID.ex_mem_mem_read := ex_reg_ctl_memRead
  EX.id_ex_ins := id_reg_ins
  EX.ex_mem_ins := ex_reg_ins
  EX.mem_wb_ins := mem_reg_ins
  ID.id_ex_rd := id_reg_ins(11, 7)
  ID.id_ex_branch := Mux(id_reg_ins(6,0) === "b1100011".U, true.B, false.B )
  ID.ex_mem_rd := ex_reg_ins(11, 7)
  
  ID.ex_stall := EX.stall
  ID.dmem_data := MEM.io.readData
  // ID.ex_result := EX.ALUresult // assigned below
  ID.ex_mem_result := ex_reg_result
  ID.mem_wb_result := mem_reg_result
  
  EX.wb_result := mem_reg_result
  EX.mem_result := ex_reg_result
  ID.ex_result := EX.ALUresult
  ID.csr_Ex := id_reg_is_csr
  ID.csr_Ex_data := id_reg_csr_data
  ID.ex_stall := EX.stall

  when(EX.stall || MEM.io.stall){
    id_reg_wra := id_reg_wra
    id_reg_ctl_regWrite <> id_reg_ctl_regWrite
  }

  if (F) {
    ex_reg_f_read.get <> id_reg_f_read.get
    EX.f_read.get <> id_reg_f_read.get
    EX.readData3.get := id_reg_rd3.get
    EX.fcsr_o_data.get := id_reg_fcsr_o_data.get
    EX.is_f_i.get := id_reg_is_f.get
    ex_reg_f_except.get <> EX.exceptions.get
    ex_reg_is_f.get := EX.is_f_o.get
    ID.f_except.get(0) <> EX.exceptions.get
  }

  /****************
   * Memory Stage *
   ****************/

  io.dmemReq <> MEM.io.dccmReq
  MEM.io.dccmRsp <> io.dmemRsp

  // RESERVATIONFILE
  reservationFile.set := ex_reg_isLR && io.dmemRsp.valid
  val sc_success = ex_reg_isSC && reservationFile.matchAddr
  reservationFile.clear := (ex_reg_isSC && (io.dmemReq.fire || (!sc_success && !sc_issued))) || 
                           (ex_reg_ctl_memWrite && !ex_reg_isSC && !ex_reg_isAMO)
  reservationFile.addrIn := ex_reg_result

  if (TRACE) {
    when(reservationFile.set) {
      printf("[Core] Reservation SET: addr=%x\n", reservationFile.addrIn)
    }
    when(reservationFile.clear) {
      printf("[Core] Reservation CLEAR\n")
    }
    when(ex_reg_isSC) {
      printf("[Core] SC Exec: addr=%x success=%d match=%d\n", 
        ex_reg_result, sc_success, reservationFile.matchAddr)
    }
  }

 
  MEM.io.readEnable := ex_reg_ctl_memRead || (ex_reg_isAMO && !amo_read_done) || ex_reg_isLR
  // ex_reg_ctl_memWrite enable it here for SC and for AMO 
  MEM.io.writeEnable := ex_reg_ctl_memWrite || (ex_reg_isAMO && amo_read_done) || (ex_reg_isSC && sc_success && !sc_issued)

  MEM.io.writeData := ex_reg_wd

  // atomic signals to Mem
  MEM.io.isAMO := ex_reg_isAMO
  MEM.io.isLR := ex_reg_isLR
  MEM.io.isSC := ex_reg_isSC
  MEM.io.amoOp := ex_reg_amoOp
  MEM.io.amo_alu_result_in := EX.amo_result


  MEM.io.aluResultIn := ex_reg_result
  MEM.io.f3 := ex_reg_ins(14,12)

  EX.mem_result := ex_reg_result
  ID.csr_Mem := ex_reg_is_csr
  ID.csr_Mem_data := ex_reg_csr_data
  ID.ex_is_amo  := id_reg_isAMO
  ID.mem_is_amo := ex_reg_isAMO
  // ID.addr_id is internal (readData1).
  ID.addr_ex  := EX.ALUresult
  ID.addr_mem := ex_reg_result

  // AMO state machine: track read completion and capture old value
  when(ex_reg_isAMO && !amo_read_done && io.dmemRsp.valid) {
    // First cycle: read completes, capture old value
    amo_read_done := true.B
    amo_old_value := io.dmemRsp.bits.dataResponse
  }.elsewhen(ex_reg_isAMO && amo_read_done && io.dmemRsp.valid) {
    // Second cycle: write completes, reset state
    amo_read_done := false.B
    amo_old_value := amo_old_value // Keep value stable
  }.elsewhen(!ex_reg_isAMO) {
    amo_read_done := false.B
  }

 
  when(ex_reg_isSC && io.dmemReq.fire) {  // SC state tracking to handle stalls
    sc_issued := true.B
  }
  when(!MEM.io.stall) {
    sc_issued := false.B
  }

  // MEM-WB REGISTE
  // sc_success is true if we have a match currently OR if we already issued successfully
  val sc_success_latched = (ex_reg_isSC && reservationFile.matchAddr) || sc_issued
  val sc_result = Mux(sc_success_latched, 0.U, 1.U)
  
  when(!MEM.io.stall) {
    mem_reg_rd := Mux(ex_reg_isAMO, amo_old_value, MEM.io.readData)
    mem_reg_result := Mux(ex_reg_isSC, sc_result, ex_reg_result)
    mem_reg_ctl_regWrite <> ex_reg_ctl_regWrite
    mem_reg_ins := ex_reg_ins
    mem_reg_pc := ex_reg_pc
    mem_reg_wra := ex_reg_wra
    mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
    mem_reg_is_csr := ex_reg_is_csr
    mem_reg_csr_data := ex_reg_csr_data
    mem_reg_isAMO := ex_reg_isAMO
    mem_reg_isLR  := ex_reg_isLR
    mem_reg_isSC  := ex_reg_isSC
  }

  if (F) {
    mem_reg_f_read.get <> ex_reg_f_read.get
    mem_reg_f_except.get <> ex_reg_f_except.get
    mem_reg_is_f.get := ex_reg_is_f.get
    ID.f_except.get(1) <> ex_reg_f_except.get
  }

  EX.ex_mem_regWrite <> ex_reg_ctl_regWrite

  /********************
   * Write Back Stage *
   ********************/

  val wb_data = dontTouch(Wire(UInt(32.W)))
  val wb_addr = Wire(UInt(5.W))

  when(mem_reg_ctl_memToReg === 1.U) {
    wb_data := mem_reg_rd  // For loads and AMO (old value)
    wb_addr := mem_reg_wra
  }.elsewhen(mem_reg_ctl_memToReg === 2.U) {
    wb_data := mem_reg_pc + 4.U
    wb_addr := mem_reg_wra
  }.otherwise {
    wb_data := mem_reg_result
    wb_addr := mem_reg_wra
  }

  ID.mem_wb_result := wb_data
  
  if (TRACE) {
    // Print every cycle what the writeback signals are
    printf("[Core] WB Stage: RegWrite=%d Addr=%d Data=%x SC=%d RegWriteIO=%d\n", 
           mem_reg_ctl_regWrite(0), wb_addr, wb_data, mem_reg_isSC, ID.ctl_writeEnable(0))
    
    when(mem_reg_ctl_regWrite(0) && wb_addr =/= 0.U) {
      // Confirmed write
      printf("[Core] Writeback ACTUAL: rd=%d data=%x\n", wb_addr, wb_data)
      when(mem_reg_isSC) {
          printf("[Core] SC WB: rd=%d result=%x (mem_reg_wra=%d)\n", wb_addr, wb_data, mem_reg_wra)
      }
    }
  }
  ID.writeData := wb_data
  EX.wb_result := wb_data
  EX.mem_wb_regWrite <> mem_reg_ctl_regWrite
  ID.writeReg := wb_addr
  ID.ctl_writeEnable <> mem_reg_ctl_regWrite
  ID.csr_Wb := mem_reg_is_csr
  ID.csr_Wb_data := mem_reg_csr_data
  ID.dmem_data := io.dmemRsp.bits.dataResponse
  io.pin := wb_data

  if (F) {
    ID.f_except.get(2) <> mem_reg_f_except.get
    Vector(
      EX.is_f_o.get,
      ex_reg_is_f.get,
      mem_reg_is_f.get
    ).zipWithIndex.foreach(
      f => ID.is_f_in.get(f._2) := f._1
    )
  }

  // Debug prints
  if (TRACE) {
    when(id_reg_isAMO || id_reg_isLR || id_reg_isSC) {
      printf("[ID-EX] AMO=%d LR=%d SC=%d amoOp=%x rs1=%x rs2=%x\n",
        id_reg_isAMO, id_reg_isLR, id_reg_isSC, id_reg_amoOp, id_reg_rd1, id_reg_rd2)
    }
    when(ex_reg_isAMO) {
      printf("[EX-MEM] AMO: addr=%x rs2=%x read_done=%d old_val=%x\n",
        ex_reg_result, ex_reg_wd, amo_read_done, amo_old_value)
    }
  }

  /**************
  ** RVFI PINS **
  **************/
  if (TRACE) {
    io.rvfi.get.bool := (mem_reg_ins =/= 0.U) && !clock.asBool
    io.rvfi.get.uint2 := 3.U
    io.rvfi.get.uint4 := delays(1, MEM.io.wmask.get)

    Vector(3, 3, 0).zipWithIndex.foreach(
      r => io.rvfi.get.uint5(r._2) := delays(r._1, ID.raddr.get(r._2))
    )

    Vector(
      mem_reg_ins,
      delays(2, EX.rs1_rdata.get),
      delays(1, ex_reg_wd),
      ID.rd_wdata.get,
      mem_reg_pc,
      delays(4, npc.asUInt),
      Mux(
        delays(1, MEM.io.dccmReq.valid).asBool,
        delays(1, ex_reg_result),
        0.U
      ),
      Mux(
        delays(1, ex_reg_ctl_memRead).asBool,
        mem_reg_rd,
        0.U
      ),
      Mux(
        delays(1, ex_reg_ctl_memWrite).asBool,
        delays(1, MEM.io.dccmReq.bits.dataRequest),
        0.U
      )
    ).zipWithIndex.foreach(
      r => io.rvfi.get.uint32(r._2) := r._1
    )
  }
}