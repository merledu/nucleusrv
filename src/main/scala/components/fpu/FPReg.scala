package nucleusrv.components.fpu

import chisel3._,
  chisel3.util._

class FPRegIO extends Bundle with Parameters {
  val rAddr = Input(Vec(4, UInt(regAddrWidth.W)))
  val wData = Flipped(Valid(UInt(flen.W)))

  val rData = Output(Vec(3, UInt(flen.W)))
}

class FPRegisters extends Module with Parameters {
  val io = IO(new FPRegIO)

  // Register File
  val reg = Reg(Vec(32, UInt(flen.W)))

  // Write
  when (io.wData.valid) {
    reg(io.rAddr(0)) := io.wData.bits
  }

  // Read
  for (i <- 0 until io.rData.length) {
    io.rData(i) := reg(io.rAddr(i + 1))
  }
}
