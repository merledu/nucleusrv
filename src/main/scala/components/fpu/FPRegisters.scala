package nucleusrv.components.fpu

import chisel3._,
       chisel3.util._
import nucleusrv.components.fpu._


class FPRegistersIO extends Bundle with Parameters {
  val rAddr: Vec[UInt]   = Input(Vec(4, UInt(regAddrWidth.W)))
  val wData: Valid[UInt] = Flipped(Valid(UInt(flen.W)))

  val rData: Vec[UInt] = Output(Vec(3, UInt(flen.W)))
}


class FPRegisters extends Module with Parameters {
  val io: FPRegistersIO = IO(new FPRegistersIO)

  // Register File
  val reg: Vec[UInt] = Reg(Vec(flen, UInt(flen.W)))

  // Write
  when (io.wData.valid) {
    reg(io.rAddr(0)) := io.wData.bits
  }

  // Read
  for (i <- 0 until io.rData.length) {
    io.rData(i) := reg(io.rAddr(i + 1))
  }
}
