package nucleusrv.components.fpu

import chisel3._, chisel3.util._
import nucleusrv.components.fpu._


class FPRegistersIO extends Bundle with Parameters {
  val rAddr: Vec[UInt]   = Input(Vec(4, UInt(regAddrWidth.W)))
  val wData: Valid[UInt] = Flipped(Valid(UInt(flen.W)))

  val rData: Vec[UInt] = Output(Vec(3, UInt(regAddrWidth.W)))
}


class FPRegisters extends Module with Parameters {
  val io: FPRegistersIO = IO(new FPRegistersIO)

  val rAddrMap: Map[String, UInt] = (
    for (i <- 0 until (io.rAddr.length - 1))
      yield s"rs${i + 1}" -> io.rAddr(i + 1)
  ).toMap ++ Map("rd" -> io.rAddr(0))

  val reg: Vec[UInt] = Reg(Vec(flen, UInt(flen.W)))

  when (io.wData.valid) {
    reg(rAddrMap("rd")) := io.wData.bits
  }

  for (i <- 0 until (io.rData.length)) {
    io.rData(i) := reg(rAddrMap(s"rs${i + 1}"))
  }
}
