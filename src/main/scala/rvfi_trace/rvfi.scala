package rvfi_trace

import chisel3._

class RVFI_IO(RVFI:Boolean, XLEN:Int, NRET:Int, ILEN:Int) extends Bundle {
  // Input ports

  // - Instruction metadata
  val mem_reg_ins = if (RVFI) Some(Input(UInt(XLEN.W))) else None

  // - Register read/write
  val id_reg_rd1  = if (RVFI) Some(Input(SInt(XLEN.W))) else None
  val id_reg_rd2  = if (RVFI) Some(Input(SInt(XLEN.W))) else None
  val wb_rd       = if (RVFI) Some(Input(UInt(5.W))) else None
  val rs1_addr    = if (RVFI) Some(Input(UInt(5.W))) else None
  val rs2_addr    = if (RVFI) Some(Input(UInt(5.W))) else None
  val wb_data     = if (RVFI) Some(Input(SInt(XLEN.W))) else None
  val writeEnable = if (RVFI) Some(Input(Bool())) else None

  // - Program Counter
  val mem_reg_pc = if (RVFI) Some(Input(UInt(XLEN.W))) else None
  val nextPC     = if (RVFI) Some(Input(UInt(XLEN.W))) else None

  // - Memory Access
  val ex_reg_result = if (RVFI) Some(Input(UInt(XLEN.W))) else None
  val readEnable    = if (RVFI) Some(Input(Bool())) else None
  val memWriteEnable   = if (RVFI) Some(Input(Bool())) else None
  val ex_reg_wd     = if (RVFI) Some(Input(SInt(XLEN.W))) else None
  val readData      = if (RVFI) Some(Input(SInt(XLEN.W))) else None

  // Output ports

  // - Instruction metadata
  //val rvfi_valid = if (RVFI) Some(Output(UInt(NRET.W))) else None
  //val rvfi_order = if (RVFI) Some(Output(UInt((NRET * 64).W))) else None
  val rvfi_insn  = if (RVFI) Some(Output(UInt((NRET * ILEN).W))) else None
  //val rvfi_trap  = if (RVFI) Some(Output(UInt(NRET.W))) else None
  //val rvfi_halt  = if (RVFI) Some(Output(UInt(NRET.W))) else None
  //val rvfi_intr  = if (RVFI) Some(Output(UInt(NRET.W))) else None
  //val rvfi_mode  = if (RVFI) Some(Output(UInt((NRET * 2).W))) else None
  //val rvfi_ixl   = if (RVFI) Some(Output(UInt((NRET * 2).W))) else None

  // - Register read/write
  val rvfi_rs1_addr  = if (RVFI) Some(Output(UInt((NRET * 5).W))) else None
  val rvfi_rs2_addr  = if (RVFI) Some(Output(UInt((NRET * 5).W))) else None
  val rvfi_rs1_rdata = if (RVFI) Some(Output(SInt((NRET * XLEN).W))) else None
  val rvfi_rs2_rdata = if (RVFI) Some(Output(SInt((NRET * XLEN).W))) else None
  val rvfi_rd_addr   = if (RVFI) Some(Output(UInt((NRET * 5).W))) else None
  val rvfi_rd_wdata  = if (RVFI) Some(Output(SInt((NRET * XLEN).W))) else None

  // - Program Counter
  val rvfi_pc_rdata = if (RVFI) Some(Output(UInt((NRET * XLEN).W))) else None
  val rvfi_pc_wdata = if (RVFI) Some(Output(UInt((NRET * XLEN).W))) else None

  // - Memory Access
  val rvfi_mem_addr  = if (RVFI) Some(Output(UInt((NRET * XLEN).W))) else None
  //val rvfi_mem_rmask = if (RVFI) Some(Output(UInt((NRET * XLEN / 8).W)) else None
  //val rvfi_mem_wmask = if (RVFI) Some(Output(UInt((NRET * XLEN / 8).W)) else None
  val rvfi_mem_rdata = if (RVFI) Some(Output(SInt((NRET * XLEN).W))) else None
  val rvfi_mem_wdata = if (RVFI) Some(Output(SInt((NRET * XLEN).W))) else None
}

class RVFIUnit(RVFI:Boolean=false, XLEN:Int=32, NRET:Int=1, ILEN:Int=32) extends Module {
  // Initializing IO ports
  val io: RVFI_IO = IO(new RVFI_IO(RVFI, XLEN, NRET, ILEN))

  // Delay Registers
  //
  // - Instruction metadata
  //
  // - Register read/write
  val ex_reg_rd1      = if (RVFI) Some(RegInit(0.S(XLEN.W))) else None
  val ex_reg_rd2      = if (RVFI) Some(RegInit(0.S(XLEN.W))) else None
  val mem_reg_rd1     = if (RVFI) Some(RegInit(0.S(XLEN.W))) else None
  val mem_reg_rd2     = if (RVFI) Some(RegInit(0.S(XLEN.W))) else None
  val id_reg_rs1Addr  = if (RVFI) Some(RegInit(0.U(5.W))) else None
  val id_reg_rs2Addr  = if (RVFI) Some(RegInit(0.U(5.W))) else None
  val ex_reg_rs1Addr  = if (RVFI) Some(RegInit(0.U(5.W))) else None
  val ex_reg_rs2Addr  = if (RVFI) Some(RegInit(0.U(5.W))) else None
  val mem_reg_rs2Addr = if (RVFI) Some(RegInit(0.U(5.W))) else None
  val mem_reg_rs1Addr = if (RVFI) Some(RegInit(0.U(5.W))) else None

  // - Program Counter
  val if_reg_nPC  = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None
  val id_reg_nPC  = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None
  val ex_reg_nPC  = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None
  val mem_reg_nPC = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None

  // - Memory Access
  val mem_reg_result      = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None
  //val mem_reg_readData    = if (RVFI) Some(RegInit(0.U(XLEN.W))) else None
  val mem_reg_wd          = if (RVFI) Some(RegInit(0.S(XLEN.W))) else None
  val mem_reg_readEnable  = if (RVFI) Some(RegInit(0.B)) else None
  val mem_reg_writeEnable = if (RVFI) Some(RegInit(0.B)) else None

  // Wiring to output ports
  if (RVFI) Seq(
    // RVFI output ports
    //
    // - Instruction metadata
    io.rvfi_insn,

    // - Register read
    io.rvfi_rs1_addr, io.rvfi_rs2_addr, io.rvfi_rs1_rdata, io.rvfi_rs2_rdata,

    // - Program Counter
    io.rvfi_pc_rdata, io.rvfi_pc_wdata,

    // Delay Registers
    //
    // - Instruction metadata
    //
    // - Register read
    ex_reg_rd1,     ex_reg_rd2,     mem_reg_rd1,    mem_reg_rd2,     id_reg_rs1Addr,
    id_reg_rs2Addr, ex_reg_rs1Addr, ex_reg_rs2Addr, mem_reg_rs1Addr, mem_reg_rs2Addr,

    // - Program Counter
    if_reg_nPC, id_reg_nPC, ex_reg_nPC, mem_reg_nPC,

    // - Memory Access
    mem_reg_result, mem_reg_wd, mem_reg_readEnable, mem_reg_writeEnable

  ) zip Seq(
    // RVFI output ports
    //
    // - Instruction metadata
    io.mem_reg_ins, 

    // - Register read
    mem_reg_rs1Addr, mem_reg_rs2Addr, mem_reg_rd1, mem_reg_rd2,

    // - Program Counter
    io.mem_reg_pc, mem_reg_nPC,

    // Delay Registers
    //
    // - Instruction metadata
    //
    // - Register read
    io.id_reg_rd1, io.id_reg_rd2,     ex_reg_rd1,     ex_reg_rd2,     io.rs1_addr,
    io.rs2_addr,   id_reg_rs1Addr, id_reg_rs2Addr, ex_reg_rs1Addr, ex_reg_rs2Addr,

    // - Program Counter
    io.nextPC, if_reg_nPC, id_reg_nPC, ex_reg_nPC,

    // - Memory Access
    io.ex_reg_result, io.ex_reg_wd, io.readEnable, io.writeEnable

  ) foreach {
    x => x._1.get := x._2.get
  } else None

  if (RVFI) Seq(
    // - Register write
    io.rvfi_rd_addr,
    io.rvfi_rd_wdata,

    // - Memory Access
    io.rvfi_mem_addr,
    io.rvfi_mem_rdata,
    io.rvfi_mem_wdata

  ) zip Seq(
    // - Register write
    (io.memWriteEnable.get, io.wb_rd,   0.U),
    (io.memWriteEnable.get, io.wb_data, 0.S),

    // - Memory Access
    (mem_reg_readEnable.get || mem_reg_writeEnable.get, mem_reg_result, 0.U),
    (mem_reg_readEnable.get,                            io.readData,    0.S),
    (mem_reg_writeEnable.get,                           mem_reg_wd,     0.S)

  ) foreach {
    x => x._1.get := Mux(x._2._1, x._2._2.get, x._2._3)
  } else None
}
