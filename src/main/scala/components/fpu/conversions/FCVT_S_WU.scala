package nucleusrv.components.fpu.conversions

import chisel3._, chisel3.util._
import nucleusrv.components.fpu._


class FCVT_S_WU_IO extends Bundle with Parameters {
  val in       : UInt = Input(UInt(flen.W))
  val roundMode: UInt = Input(UInt(roundModeWidth.W))

  val out: UInt = Output(UInt(flen.W))
}


class FCVT_S_WU extends Module with Parameters with RoundingModes {
  val io: FCVT_S_WU_IO = IO(new FCVT_S_WU_IO)

  val exponent    : SInt = Wire(SInt(expWidth.W))
  val significand : UInt = Wire(UInt(sigWidth.W))
  val rSignificand: UInt = Wire(UInt(sigWidth.W))
  val sign        : UInt = Wire(UInt(signWidth.W))
  val unbias      : UInt = Wire(UInt(expWidth.W))

  val shiftedMag: UInt = dontTouch(Wire(UInt(flen.W)))

  // The prioirity encoder is used to find the position of the leading one.
  // In CHISEL, the priority encoder has the highest priority starting from LSB.
  // Therefore the magnitude is reversed to find the leading one and then
  // the resulting position is subtracted from 30 (the no. of bits in magnitude)
  // to get the un-reversed (aka the original) position of the leading one (aka unbiased exponent)
  val rev = Reverse(io.in)
  val priorityEn = PriorityEncoder(rev)
  unbias := (flen - 1).U - priorityEn

  val magnLSB: Int = flen - sigWidth
  shiftedMag := io.in << (priorityEn + 1.U)
  significand := shiftedMag(flen - 1, magnLSB)
  val grs: UInt = dontTouch(Map(
    "G" -> shiftedMag(magnLSB - 1).asUInt,
    "R" -> shiftedMag(magnLSB - 2).asUInt,
    "S" -> shiftedMag(magnLSB - 3, 0).orR.asUInt
  ).values.reduce((x, y) => Cat(x, y)))

  rSignificand := MuxLookup(io.roundMode, RNE(significand, grs), Seq(
  ))

  sign        := 0.U
  exponent    := unbias.asSInt + bias.S

  io.out := Cat(sign, exponent, rSignificand)


  // Debug Section
  val debug_magnLSB = dontTouch(WireInit(magnLSB.U))
  val debug_G = dontTouch(grs(2))
  val debug_R = dontTouch(grs(1))
  val debug_S = dontTouch(grs(0))
}
