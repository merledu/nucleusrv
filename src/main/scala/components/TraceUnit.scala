package nucleusrv.components

import chisel3._


class TracerIO(Params:Map[String,Int]) extends Bundle {
    // Inputs
    val rvfiUIntVec    : Vec[UInt] = Input(Vec(4, UInt(Params("XLEN").W)))
    val rvfiRegAddrVec : Vec[UInt] = Input(Vec(3, UInt(Params("RegAddrLen").W)))
    val rvfiSIntVec    : Vec[SInt] = Input(Vec(5, SInt(Params("XLEN").W)))
    val rvfiBoolVec    : Vec[Bool] = Input(Vec(1, Bool()))
    val rvfi_mode      : UInt      = Input(UInt(2.W))
}


class TraceUnit(Params:Map[String,Int]) extends Module {
    val io: TracerIO = IO(new TracerIO(Params))
    val clkCycle: UInt = RegInit(0.U(Params("XLEN").W))
    clkCycle := clkCycle + 1.U

    val rvfiUIntWires: Map[String, UInt] = Map(
        "insn"     -> io.rvfiUIntVec(0),
        "pc_rdata" -> io.rvfiUIntVec(1),
        "pc_wdata" -> io.rvfiUIntVec(2),
        "mem_addr" -> io.rvfiUIntVec(3),
        "rd_addr"  -> io.rvfiRegAddrVec(0),
        "rs1_addr" -> io.rvfiRegAddrVec(1),
        "rs2_addr" -> io.rvfiRegAddrVec(2),
        "mode"     -> io.rvfi_mode
    )
    val rvfiSIntWires: Map[String, SInt] = Map(
        "rd_wdata"  -> io.rvfiSIntVec(0),
        "rs1_rdata" -> io.rvfiSIntVec(1),
        "rs2_rdata" -> io.rvfiSIntVec(2),
        "mem_rdata" -> io.rvfiSIntVec(3),
        "mem_wdata" -> io.rvfiSIntVec(4)
    )
    val rvfiBoolWires: Map[String, Bool] = Map(
        "valid" -> io.rvfiBoolVec(0)
    )

    when (rvfiBoolWires("valid")) {
        printf(
            "ClkCycle: %d, pc_rdata: %x, pc_wdata: %x, insn: %x, mode: %d, rs1_addr: %d, rs1_rdata: %x, rs2_addr: %d, rs2_rdata: %x, rd_addr: %d, rd_wdata: %x, mem_addr: %x, mem_rdata: %x, mem_wdata: %x\n",
            clkCycle, rvfiUIntWires("pc_rdata"), rvfiUIntWires("pc_wdata"), rvfiUIntWires("insn"), rvfiUIntWires("mode"),
            rvfiUIntWires("rs1_addr"), rvfiSIntWires("rs1_rdata"), rvfiUIntWires("rs2_addr"), rvfiSIntWires("rs2_rdata"), rvfiUIntWires("rd_addr"),
            rvfiSIntWires("rd_wdata"), rvfiUIntWires("mem_addr"), rvfiSIntWires("mem_rdata"), rvfiSIntWires("mem_wdata")
        )
    }
}
