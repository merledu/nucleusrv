package nucleusrv.components

import chisel3._
import chisel3.util._
import nucleusrv.tracer.{TracerI, delays}

class Core(implicit val config:Configs) extends Module{

  val M      = config.M
  val A      = config.A
  val F      = config.F
  val D      = config.D
  val C      = config.C
  val Zicsr  = config.Zicsr
  val XLEN   = config.XLEN
  val TRACE  = config.TRACE
  val HARTID = config.HARTID
  val ARCHID = config.ARCHID

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
  val if_reg_is_comp = if (C) Some(RegInit(false.B)) else None

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
  val id_reg_is_csr = if (Zicsr) Some(RegInit(false.B)) else None
  val id_reg_csr_data = if (Zicsr) Some(RegInit(0.U)) else None

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
  val ex_reg_is_csr = if (Zicsr) Some(RegInit(false.B)) else None
  val ex_reg_csr_data = if (Zicsr) Some(RegInit(0.U)) else None

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
  val mem_reg_is_csr = if (Zicsr) Some(RegInit(false.B)) else None
  val mem_reg_csr_data = if (Zicsr) Some(RegInit(0.U)) else None

  val mem_reg_f_read = if (F) Some(Reg(Vec(3, Bool()))) else None
  val mem_reg_f_except = if (F) Some(RegInit(VecInit(Vector.fill(5)(0.B)))) else None
  val mem_reg_is_f = if (F) Some(RegInit(0.B)) else None

  // Atomic signals MEM-WB
  val mem_reg_isAMO = RegInit(false.B)
  val mem_reg_isLR  = RegInit(false.B)
  val mem_reg_isSC  = RegInit(false.B)

  // AMO state tracking
  val amo_read_done = RegInit(false.B)
  val amo_old_value = RegInit(0.U(32.W))
  val sc_issued = RegInit(false.B)

  //Pipeline Units
  val IF = Module(new InstructionFetch).io
  val ID = Module(new InstructionDecode(F, Zicsr, C, TRACE)).io
  val EX = Module(new Execute(F, M = M, TRACE = TRACE)).io
  val MEM = Module(new MemoryFetch(TRACE))

  val reservationFile = Module(new ReservationFile).io
  
  /*****************
   * Fetch Stage *
   ******************/

  val pc = Module(new PC)

  io.imemReq <> IF.coreInstrReq
  IF.coreInstrResp <> io.imemRsp

  val instruction = Wire(UInt(32.W))
  val is_comp     = dontTouch(WireInit(false.B))
  val halt = EX.stall || ID.stall || io.imemReq.valid || MEM.io.stall

  val RA = if (C) Some(Module(new Realigner).io) else None
  if (C) {
    RA.get.ral_address_i     := pc.io.out.asUInt
    RA.get.ral_instruction_i := Mux(io.imemRsp.valid, IF.instruction, 0.U)
    RA.get.ral_jmp           := ID.pcSrc
    RA.get.stall             := halt
    RA.get.is_comp           := is_comp
    val instruction_cd    = RA.get.ral_instruction_o

    val CD = Module(new CompressedDecoder).io
    CD.instruction_i := instruction_cd
    CD.addri := RA.get.addri
    instruction  := CD.instruction_o
    is_comp := CD.is_comp
  }
  else {
    instruction := IF.instruction
  }
  IF.address := pc.io.out.asUInt

  val func3 = instruction(14, 12)
  val func7 = Wire(UInt(7.W))
  when((instruction(6,0) === "b0110011".U) || (instruction(6, 0) === "b1010011".U)){
    func7 := instruction(31,25)
  }.otherwise{
    func7 := 0.U
  }

  val IF_stall = (
    func7 === 1.U && (
      func3 === 4.U || func3 === 5.U || func3 === 6.U || func3 === 7.U
    )
  ) || ((func7 === "b0001100".U) || (func7 === "b0101100".U))

  IF.stall := io.stall || EX.stall || ID.stall || /*IF_stall ||*/ ID.pcSrc || MEM.io.stall
  
  pc.io.halt := dontTouch(halt)
  val npc = Mux(
    ID.hdu_pcWrite,
    Mux(
      ID.pcSrc,
      ID.pcPlusOffset.asSInt,
      Mux(
        is_comp || pc.io.out(1) || (if (C) RA.get.misaligned_word else 0.B),
        pc.io.pc2,
        pc.io.pc4
      )
    ),
    pc.io.out
  )
  pc.io.in := dontTouch(npc)

  when(ID.hdu_if_reg_write && !MEM.io.stall && (
    if (C) !RA.get.misaligned_word_uh else true.B
  )) {
    if_reg_pc := pc.io.out.asUInt
  }
  when(ID.hdu_if_reg_write && !MEM.io.stall && (
    if (C) !RA.get.nop_sel else true.B
  )) {
    if_reg_ins := instruction 
    if (C) {
      if_reg_is_comp.get := is_comp
    }
  }
  when(ID.ifid_flush) {
    if_reg_ins := 0.U
    if (C) {
      if_reg_is_comp.get := 0.B
    }
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
    if (Zicsr) {
      id_reg_is_csr.get := ID.is_csr.get
      id_reg_csr_data.get := ID.csr_o_data.get
    }
    
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

  val misa = (1 << 30).U | (1 << 8).U | 
              Mux(M.B, (1 << 12).U, 0.U) | 
              Mux(C.B, (1 << 2).U, 0.U)
  if (Zicsr) {
    ID.csr_i_misa.get    := misa
    ID.csr_i_marchid.get := ARCHID.U
    ID.csr_i_mhartid.get := HARTID.U
  }
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

  if (C) {
    ID.is_comp.get := if_reg_is_comp.get
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

  // AMO alu connections
  EX.amo_memData := amo_old_value
  EX.amo_src2    := ex_reg_wd
  EX.amo_op_code := ex_reg_amoOp
  
  when(!MEM.io.stall) {
    ex_reg_pc := id_reg_pc
    ex_reg_wra := id_reg_wra
    ex_reg_ins := id_reg_ins
    ex_reg_ctl_memToReg := id_reg_ctl_memToReg
    ex_reg_ctl_regWrite <> id_reg_ctl_regWrite
    if (Zicsr) {
      ex_reg_is_csr.get := id_reg_is_csr.get
      ex_reg_csr_data.get := id_reg_csr_data.get
    }
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
  
  ID.dmem_data := MEM.io.readData
  // ID.ex_result := EX.ALUresult // assigned below
  ID.ex_mem_result := ex_reg_result
  ID.mem_wb_result := mem_reg_result
  
  EX.wb_result := mem_reg_result
  EX.mem_result := ex_reg_result
  ID.ex_result := EX.ALUresult
  if (Zicsr) {
    ID.csr_Ex.get := id_reg_is_csr.get
    ID.csr_Ex_data.get := id_reg_csr_data.get
  }
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


 
  MEM.io.readEnable := ex_reg_ctl_memRead || (ex_reg_isAMO && !amo_read_done) || ex_reg_isLR
  // ex_reg_ctl_memWrite enable it here for SC and for AMO 
  // Disable default memWrite for SC/AMO to ensure we only write when allowed
  MEM.io.writeEnable := (ex_reg_ctl_memWrite && !ex_reg_isSC && !ex_reg_isAMO) || (ex_reg_isAMO && amo_read_done) || (ex_reg_isSC && sc_success && !sc_issued)

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
  if (Zicsr) {
    ID.csr_Mem.get := ex_reg_is_csr.get
    ID.csr_Mem_data.get := ex_reg_csr_data.get
  }
  ID.ex_is_amo  := id_reg_isAMO
  ID.mem_is_amo := ex_reg_isAMO
  // ID.addr_id is internal (readData1).
  ID.addr_ex  := EX.ALUresult
  ID.addr_mem := ex_reg_result

  // AMO state machine track read completion and capture old value
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

 
  // SC Execution 
  // We use sc_issued to track if wehve already tried to execute this specific SC instruction
  when(ex_reg_isSC && !MEM.io.stall) {  
     sc_issued := true.B
  }
  
  // Reset sc_issued only when we advance to a NEW instruction (ex_reg changes)
  // We detect a "new" instruction when we are no longer stalled
  when(!MEM.io.stall && !EX.stall) {
      sc_issued := false.B
  }

  // SC Match Latch: failure to latch success means we might return 1 (fail) 
  // after the reservation is cleared but before stall ends.
  val sc_matched = RegInit(false.B)
  when(ex_reg_isSC && reservationFile.matchAddr) {
    sc_matched := true.B
  }
  when(!MEM.io.stall) {
    sc_matched := false.B
  }

  // MEM-WB REGISTE
  // sc_success is true if we have a match currently OR if we already matched
  val sc_success_latched = (ex_reg_isSC && reservationFile.matchAddr) || sc_matched
  val sc_result = Mux(sc_success_latched, 0.U, 1.U)
  
  when(!MEM.io.stall) {
    mem_reg_rd := Mux(ex_reg_isAMO, amo_old_value, MEM.io.readData)
    mem_reg_result := Mux(ex_reg_isSC, sc_result, ex_reg_result)
    mem_reg_ctl_regWrite <> ex_reg_ctl_regWrite
    mem_reg_ins := ex_reg_ins
    mem_reg_pc := ex_reg_pc
    mem_reg_wra := ex_reg_wra
    mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
    if (Zicsr) {
      mem_reg_is_csr.get := ex_reg_is_csr.get
      mem_reg_csr_data.get := ex_reg_csr_data.get
    }
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
  }.elsewhen(mem_reg_ctl_memToReg === 3.U) {
    wb_data := mem_reg_pc + 2.U
    wb_addr := mem_reg_wra
  }.otherwise {
    wb_data := mem_reg_result
    wb_addr := mem_reg_wra
  }

  ID.mem_wb_result := wb_data
  
  ID.writeData := wb_data
  EX.wb_result := wb_data
  EX.mem_wb_regWrite <> mem_reg_ctl_regWrite
  ID.writeReg := wb_addr
  ID.ctl_writeEnable <> mem_reg_ctl_regWrite
  if (Zicsr) {
    ID.csr_Wb.get := mem_reg_is_csr.get
    ID.csr_Wb_data.get := mem_reg_csr_data.get
  }
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

    /*****************************
    ** instruction retire logic **
    *****************************/
    if (Zicsr) {
      val instruction_retired = WireInit(false.B)
      instruction_retired := mem_reg_ins =/= 0.U && !ID.ifid_flush && !(MEM.io.stall || io.stall) && (!mem_reg_ctl_memToReg === 1.U || io.dmemRsp.valid)
      ID.csr_i_instr_retired.get := instruction_retired
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
