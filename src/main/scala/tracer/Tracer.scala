package nucleusrv.tracer

import chisel3._


class TracerIO extends Bundle {
  val rvfiUInt   : Vec[UInt] = Input(Vec(4, UInt(32.W)))
  val rvfiSInt   : Vec[SInt] = Input(Vec(5, SInt(32.W)))
  val rvfiBool   : Vec[Bool] = Input(Vec(1, Bool()))
  val rvfiRegAddr: Vec[UInt] = Input(Vec(3, UInt(5.W)))
  val rvfiMode   : UInt      = Input(UInt(2.W))
}


class Tracer extends Module {
  val io: TracerIO = IO(new TracerIO)

  val clkCycle: UInt = RegInit(0.U(32.W))
  clkCycle := clkCycle + 1.U

  val uintWires: Map[String, UInt] = Map(
    "pc_rdata" -> io.rvfiUInt(0),
    "pc_wdata" -> io.rvfiUInt(1),
    "insn"     -> io.rvfiUInt(2),
    "mem_addr" -> io.rvfiUInt(3),
    "mode"     -> io.rvfiMode,
    "rs1_addr" -> io.rvfiRegAddr(1),
    "rs2_addr" -> io.rvfiRegAddr(2),
    "rd_addr"  -> io.rvfiRegAddr(0),
  )

  val sintWires: Map[String, SInt] = Map(
    "rd_wdata"  -> io.rvfiSInt(0),
    "rs1_rdata" -> io.rvfiSInt(1),
    "rs2_rdata" -> io.rvfiSInt(2),
    "mem_rdata" -> io.rvfiSInt(3),
    "mem_wdata" -> io.rvfiSInt(4)
  )

  val boolWires: Map[String, Bool] = Map(
    "valid" -> io.rvfiBool(0)
  )

  when (boolWires("valid") && (uintWires("insn") =/= 0.U)) {
    printf(
      "ClkCycle: %d, pc_rdata: %x, pc_wdata: %x, insn: %x, mode: %d, rs1_addr: %d, rs1_rdata: %x, rs2_addr: %d, rs2_rdata: %x, rd_addr: %d, rd_wdata: %x, mem_addr: %x, mem_rdata: %x, mem_wdata: %x\n",
      clkCycle, uintWires("pc_rdata"), uintWires("pc_wdata"), uintWires("insn"), uintWires("mode"),
      uintWires("rs1_addr"), sintWires("rs1_rdata"), uintWires("rs2_addr"), sintWires("rs2_rdata"), uintWires("rd_addr"),
      sintWires("rd_wdata"), uintWires("mem_addr"), sintWires("mem_rdata"), sintWires("mem_wdata")
    )
  }
}