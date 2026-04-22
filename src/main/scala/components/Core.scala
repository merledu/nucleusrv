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
  val id_reg_isAMO = if (A) Some(RegInit(false.B)) else None
  val id_reg_isLR  = if (A) Some(RegInit(false.B)) else None
  val id_reg_isSC  = if (A) Some(RegInit(false.B)) else None
  val id_reg_amoOp = if (A) Some(RegInit(0.U(5.W))) else None

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
  val ex_reg_isAMO  = if (A) Some(RegInit(false.B)) else None
  val ex_reg_isLR   = if (A) Some(RegInit(false.B)) else None
  val ex_reg_isSC   = if (A) Some(RegInit(false.B)) else None
  val ex_reg_amoOp  = if (A) Some(RegInit(0.U(5.W))) else None
  
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
  val mem_reg_isAMO = if (A) Some(RegInit(false.B)) else None
  val mem_reg_isLR  = if (A) Some(RegInit(false.B)) else None
  val mem_reg_isSC  = if (A) Some(RegInit(false.B)) else None

  // AMO state tracking
  val amo_read_done = if (A) Some(RegInit(false.B)) else None
  val amo_old_value = if (A) Some(RegInit(0.U(32.W))) else None
  val sc_issued = if (A) Some(RegInit(false.B)) else None

  //Pipeline Units
  val IF = Module(new InstructionFetch).io
  val ID = Module(new InstructionDecode(A, F, Zicsr, TRACE)).io
  val EX = Module(new Execute(F, M = M, A, TRACE = TRACE)).io
  val MEM = Module(new MemoryFetch(A, TRACE))

  val reservationFile = if (A) Some(Module(new ReservationFile).io) else None
  
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
    //IF.address := pc.io.out.asUInt
    IF.address := Mux(ID.hdu_pcWrite, pc.io.out.asUInt, if_reg_pc)
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
  
  val halt = dontTouch(Mux(((EX.stall || ID.stall || !io.imemReq.valid) | ral_halt_o || MEM.io.stall), 1.B, 0.B))
  pc.io.halt := halt
  val npc = Mux(
    ID.hdu_pcWrite || !halt,
    Mux(
      ID.pcSrc,
      ID.pcPlusOffset.asSInt,
      Mux(is_comp, pc.io.pc2, pc.io.pc4)
    ),
    pc.io.out
  )
  pc.io.in := dontTouch(npc)

  when(ID.hdu_if_reg_write && (if (A) !MEM.io.amo_stall.get else 1.B)) {
    if_reg_pc := pc.io.out.asUInt
    if_reg_ins := instruction 
  }
  when(ID.ifid_flush) {
    if_reg_ins := 0.U
  }
   
  /****************
   * Decode Stage *
   ****************/

  when (!EX.stall && !MEM.io.stall && (if (A) !MEM.io.amo_stall.get else 1.B)) {
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
      id_reg_is_csr := ID.is_csr.get
      id_reg_csr_data := ID.csr_o_data.get
    }
    
    if (A) {
      id_reg_isAMO.get := ID.isAMO.get
      id_reg_isLR.get  := ID.isLR.get
      id_reg_isSC.get  := ID.isSC.get
      id_reg_amoOp.get := ID.amoOp.get
    }

    if (F) {
      id_reg_f_read.get <> ID.f_read.get
      id_reg_rd3.get := ID.readData3.get
      if (Zicsr) {
        id_reg_fcsr_o_data.get := ID.fcsr_o_data.get
      }
      id_reg_is_f.get := ID.is_f.get
    }
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
    //id_reg_f_read.get <> ID.f_read.get
    //id_reg_rd3.get := ID.readData3.get
    //id_reg_fcsr_o_data.get := ID.fcsr_o_data.get
    //id_reg_is_f.get := ID.is_f.get
    for (i <- 0 until 2) {
      ID.f_read_reg.get(0)(i) := id_reg_f_read.get(i)
      ID.f_read_reg.get(1)(i) := ex_reg_f_read.get(i)
      ID.f_read_reg.get(2)(i) := mem_reg_f_read.get(i)
    }
  }

  /*****************
   * Execute Stage *
  ******************/
  
  if (A) {
    EX.isAMO.get := id_reg_isAMO.get
    EX.isLR.get := id_reg_isLR.get
    EX.isSC.get := id_reg_isSC.get
  }

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
  if (A) {
    EX.amo_memData.get := amo_old_value.get
    EX.amo_src2.get    := ex_reg_wd
    EX.amo_op_code.get := ex_reg_amoOp.get
  }
  
  when (!MEM.io.stall && (if (A) !MEM.io.amo_stall.get else 1.B)) {
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


    if (A) {
      ex_reg_isAMO.get := id_reg_isAMO.get
      ex_reg_isLR.get  := id_reg_isLR.get
      ex_reg_isSC.get  := id_reg_isSC.get
      ex_reg_amoOp.get := id_reg_amoOp.get
    }

    if (F) {
      ex_reg_f_read.get <> id_reg_f_read.get
      ex_reg_f_except.get <> EX.exceptions.get
      ex_reg_is_f.get := EX.is_f_o.get
    }
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
  
  //EX.wb_result := mem_reg_result
  EX.mem_result := MuxCase(ex_reg_result, List(
    ex_reg_ctl_memRead -> MEM.io.readData,
    (ex_reg_is_csr && ex_reg_ctl_regWrite(0)) -> ex_reg_csr_data
  ))
  ID.ex_result := EX.ALUresult
  ID.csr_Ex := id_reg_is_csr
  ID.csr_Ex_data := id_reg_csr_data
  ID.ex_stall := EX.stall

  //when(EX.stall || MEM.io.stall){
  //  id_reg_wra := id_reg_wra
  //  id_reg_ctl_regWrite <> id_reg_ctl_regWrite
  //}

  if (F) {
    //ex_reg_f_read.get <> id_reg_f_read.get
    EX.f_read.get <> id_reg_f_read.get
    EX.readData3.get := id_reg_rd3.get
    EX.fcsr_o_data.get := id_reg_fcsr_o_data.get
    EX.is_f_i.get := id_reg_is_f.get
    //ex_reg_f_except.get <> EX.exceptions.get
    //ex_reg_is_f.get := EX.is_f_o.get
    ID.f_except.get(0) <> EX.exceptions.get
  }

  /****************
   * Memory Stage *
   ****************/

  io.dmemReq <> MEM.io.dccmReq
  MEM.io.dccmRsp <> io.dmemRsp

  // RESERVATIONFILE
  val sc_success = if (A) Some(ex_reg_isSC.get && reservationFile.get.matchAddr) else None
  if (A) {
    reservationFile.get.set := ex_reg_isLR.get && io.dmemRsp.valid
    //val sc_success = ex_reg_isSC.get && reservationFile.get.matchAddr
    reservationFile.get.clear := (ex_reg_isSC.get && (io.dmemReq.fire || (!sc_success.get && !sc_issued.get))) || 
                             (ex_reg_ctl_memWrite && !ex_reg_isSC.get && !ex_reg_isAMO.get)
    reservationFile.get.addrIn := ex_reg_result
  }
  //reservationFile.set := ex_reg_isLR && io.dmemRsp.valid
  //val sc_success = ex_reg_isSC && reservationFile.matchAddr
  //reservationFile.clear := (ex_reg_isSC && (io.dmemReq.fire || (!sc_success && !sc_issued))) || 
  //                         (ex_reg_ctl_memWrite && !ex_reg_isSC && !ex_reg_isAMO)
  //reservationFile.addrIn := ex_reg_result


 
  MEM.io.readEnable := ex_reg_ctl_memRead || (
    if (A) (ex_reg_isAMO.get && !amo_read_done.get) || ex_reg_isLR.get else 0.B
  )
  //MEM.io.readEnable := ex_reg_ctl_memRead || (ex_reg_isAMO && !amo_read_done) || ex_reg_isLR
  // ex_reg_ctl_memWrite enable it here for SC and for AMO 
  // Disable default memWrite for SC/AMO to ensure we only write when allowed
  MEM.io.writeEnable := (
    if (A)
      (ex_reg_ctl_memWrite && !ex_reg_isSC.get && !ex_reg_isAMO.get) || (ex_reg_isAMO.get && amo_read_done.get) || (ex_reg_isSC.get && sc_success.get && !sc_issued.get)
    else
      ex_reg_ctl_memWrite
  )
  //MEM.io.writeEnable := (ex_reg_ctl_memWrite && !ex_reg_isSC && !ex_reg_isAMO) || (ex_reg_isAMO && amo_read_done) || (ex_reg_isSC && sc_success && !sc_issued)

  MEM.io.writeData := ex_reg_wd

  // atomic signals to Mem
  if (A) {
    MEM.io.isAMO.get := ex_reg_isAMO.get
    MEM.io.isLR.get := ex_reg_isLR.get
    MEM.io.isSC.get := ex_reg_isSC.get
    MEM.io.amoOp.get := ex_reg_amoOp.get
    MEM.io.amo_alu_result_in.get := EX.amo_result.get
  }


  MEM.io.aluResultIn := ex_reg_result
  MEM.io.f3 := ex_reg_ins(14,12)

  //EX.mem_result := ex_reg_result
  ID.csr_Mem := ex_reg_is_csr
  ID.csr_Mem_data := ex_reg_csr_data
  val sc_matched = if (A) Some(RegInit(false.B)) else None
  if (A) {
    ID.ex_is_amo.get  := id_reg_isAMO.get
    ID.mem_is_amo.get := ex_reg_isAMO.get
    // ID.addr_id is internal (readData1).
    ID.addr_ex.get  := EX.ALUresult
    ID.addr_mem.get := ex_reg_result

    // AMO state machine track read completion and capture old value
    when(ex_reg_isAMO.get && !amo_read_done.get && io.dmemRsp.valid) {
      // First cycle: read completes, capture old value
      amo_read_done.get := true.B
      amo_old_value.get := io.dmemRsp.bits.dataResponse
    }.elsewhen(ex_reg_isAMO.get && amo_read_done.get && io.dmemRsp.valid) {
      // Second cycle: write completes, reset state
      amo_read_done.get := false.B
      amo_old_value.get := amo_old_value.get // Keep value stable
    }.elsewhen(!ex_reg_isAMO.get) {
      amo_read_done.get := false.B
    }

 
    // SC Execution 
    // We use sc_issued to track if wehve already tried to execute this specific SC instruction
    when(ex_reg_isSC.get && !MEM.io.stall) {  
       sc_issued.get := true.B
    }
  
    // Reset sc_issued only when we advance to a NEW instruction (ex_reg changes)
    // We detect a "new" instruction when we are no longer stalled
    when(!MEM.io.stall && !EX.stall) {
        sc_issued.get := false.B
    }

    // SC Match Latch: failure to latch success means we might return 1 (fail) 
    // after the reservation is cleared but before stall ends.
    when(ex_reg_isSC.get && reservationFile.get.matchAddr) {
      sc_matched.get := true.B
    }
    when(!MEM.io.stall) {
      sc_matched.get := false.B
    }

  }
  // MEM-WB REGISTE
  // sc_success is true if we have a match currently OR if we already matched
  val sc_success_latched = if (A) Some((ex_reg_isSC.get && reservationFile.get.matchAddr) || sc_matched.get) else None
  val sc_result = if (A) Some(Mux(sc_success_latched.get, 0.U, 1.U)) else None
  //val sc_success_latched = (ex_reg_isSC && reservationFile.matchAddr) || sc_matched
  //val sc_result = Mux(sc_success_latched, 0.U, 1.U)
  
  when (!MEM.io.stall && (if (A) !MEM.io.amo_stall.get else 1.B)) {
    mem_reg_rd := (if (A) Mux(ex_reg_isAMO.get, amo_old_value.get, MEM.io.readData) else MEM.io.readData)
    mem_reg_ins := ex_reg_ins
    mem_reg_result := (if (A) Mux(ex_reg_isSC.get, sc_result.get, ex_reg_result) else ex_reg_result)
    mem_reg_wra := ex_reg_wra
    mem_reg_ctl_memToReg := ex_reg_ctl_memToReg
    mem_reg_ctl_regWrite(0) := ex_reg_ctl_regWrite(0)
    if (F) {
      mem_reg_ctl_regWrite(1) := ex_reg_ctl_regWrite(1)
    }
    mem_reg_pc := ex_reg_pc
    mem_reg_is_csr := ex_reg_is_csr
    mem_reg_csr_data := ex_reg_csr_data

    if (A) {
      mem_reg_isAMO.get := ex_reg_isAMO.get
      mem_reg_isLR.get  := ex_reg_isLR.get
      mem_reg_isSC.get  := ex_reg_isSC.get
    }

    if (F) {
      mem_reg_f_read.get <> ex_reg_f_read.get
      mem_reg_f_except.get <> ex_reg_f_except.get
      mem_reg_is_f.get := ex_reg_is_f.get
    }
  }

  if (F) {
    //mem_reg_f_read.get <> ex_reg_f_read.get
    //mem_reg_f_except.get <> ex_reg_f_except.get
    //mem_reg_is_f.get := ex_reg_is_f.get
    ID.f_except.get(1) <> ex_reg_f_except.get
  }

  EX.ex_mem_regWrite <> ex_reg_ctl_regWrite
  ID.mem_stall := MEM.io.stall

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
  }.elsewhen (mem_reg_is_csr && mem_reg_ctl_regWrite(0)) {
    wb_data := mem_reg_csr_data
    wb_addr := mem_reg_wra
  }.otherwise {
    wb_data := mem_reg_result
    wb_addr := mem_reg_wra
  }

  ID.mem_wb_result := wb_data
  
  ID.writeData := wb_data
  EX.wb_result := wb_data
  EX.mem_wb_regWrite <> mem_reg_ctl_regWrite
  ID.writeReg := dontTouch(wb_addr)
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

    /*****************************
    ** instruction retire logic **
    *****************************/
    val instruction_retired = WireInit(false.B)
    if (Zicsr) {
      instruction_retired := mem_reg_ins =/= 0.U && !ID.ifid_flush && !(MEM.io.stall || io.stall) && (!mem_reg_ctl_memToReg === 1.U || io.dmemRsp.valid)
      ID.csr_i_instr_retired.get := instruction_retired
    }

  /**************
  ** RVFI PINS **
  **************/
  if (TRACE) {
    io.rvfi.get.bool := (mem_reg_ins =/= 0.U) && RegNext(!MEM.io.stall) && (if (A) RegNext(!MEM.io.amo_stall.get) else 1.B) && !clock.asBool
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
        delays(2, ex_reg_ctl_memRead).asBool,
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
