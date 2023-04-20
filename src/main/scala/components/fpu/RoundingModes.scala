package nucleusrv.components.fpu

import chisel3._, chisel3.util._


trait RoundingModes {
  def RNE(significand: UInt, grs: UInt) = MuxLookup(grs, significand, Seq(
    4.U -> Mux(significand(0), significand + 1.U, significand)
  ) ++ (
    for (i <- 5 to 7)
      yield i.U -> (significand + 1.U)
  ))
}
