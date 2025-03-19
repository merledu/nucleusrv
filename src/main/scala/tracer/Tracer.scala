package nucleusrv.tracer

import chisel3._

trait RVFIParams {
  val XLEN = 32
  val NRET = 1
  val ILEN = 32
}

// Needs to be modified for adding support of not implemented ports
class TracerI extends Bundle {
  val bool = Input(Bool())
  val uint2 = Input(UInt(2.W))
  val uint4 = Input(UInt(4.W))
  val uint5 = Input(Vec(3, UInt(5.W)))
  val uint32 = Input(Vec(9, UInt(32.W)))
}

class TracerO extends Bundle with RVFIParams {
  // Instruction Metadata
  val valid = Output(Vec(NRET, Bool()))
  //val order = Output(Vec(NRET, UInt(64.W)))  // Not implemented yet
  val insn = Output(Vec(NRET, UInt(ILEN.W)))
  //val trap = Output(Vec(NRET, Bool()))  // Not implemented yet
  //val halt = Output(Vec(NRET, Bool()))  // Not implemented yet
  //val instr = Output(Vec(NRET, Bool()))  // Not implemented yet
  val mode = Output(Vec(NRET, UInt(2.W)))
  //val ixl = Output(Vec(NRET, UInt(2.W)))  // Not implemented yet

  // Integer Register Read/Write
  val rs1_addr = Output(Vec(NRET, UInt(5.W)))
  val rs2_addr = Output(Vec(NRET, UInt(5.W)))
  val rs1_rdata = Output(Vec(NRET, UInt(XLEN.W)))  // Not implemented yet
  val rs2_rdata = Output(Vec(NRET, UInt(XLEN.W)))  // Not implemented yet
  val rd_addr = Output(Vec(NRET, UInt(5.W)))
  val rd_wdata = Output(Vec(NRET, UInt(XLEN.W)))

  // Program Counter
  val pc_rdata = Output(Vec(NRET, UInt(XLEN.W)))
  val pc_wdata = Output(Vec(NRET, UInt(XLEN.W)))

  // Memory Access
  val mem_addr = Output(Vec(NRET, UInt(XLEN.W)))
  //val mem_rmask = Output(Vec(NRET, UInt((XLEN / 8).W)))  // Not implemented yet
  val mem_wmask = Output(Vec(NRET, UInt((XLEN / 8).W)))
  val mem_rdata = Output(Vec(NRET, UInt(XLEN.W)))
  val mem_wdata = Output(Vec(NRET, UInt(XLEN.W)))
}

class Tracer extends RawModule {
  val rvfi_i = IO(new TracerI)
  val rvfi_o = IO(new TracerO)

  rvfi_o.valid(0) := rvfi_i.bool
  rvfi_o.mode(0) := rvfi_i.uint2
  rvfi_o.mem_wmask(0) := rvfi_i.uint4

  Vector(
    rvfi_o.rs1_addr,
    rvfi_o.rs2_addr,
    rvfi_o.rd_addr
  ).zipWithIndex.foreach {
    r => r._1(0) := rvfi_i.uint5(r._2)
  }

  Vector(
    rvfi_o.insn,
    rvfi_o.rs1_rdata,
    rvfi_o.rs2_rdata,
    rvfi_o.rd_wdata,
    rvfi_o.pc_rdata,
    rvfi_o.pc_wdata,
    rvfi_o.mem_addr,
    rvfi_o.mem_rdata,
    rvfi_o.mem_wdata
  ).zipWithIndex.foreach {
    r => r._1(0) := rvfi_i.uint32(r._2)
  }
}

object delays {
  def apply(n: Int, src: Bits): Bits = {
    if (n == 0) {
      src
    } else if (n == 1) {
      RegNext(src)
    } else {
      RegNext(delays(n - 1, src))
    }
  }
}
