//package fpu.conversions
//
//import chisel3._, chisel3.util._, scala.math.pow
//import fpu._
//
//
//class FCVT_W_S_IO extends Bundle with Parameters {
//  val in: UInt = Input(UInt(flen.W))
//
//  val out       : SInt = Output(SInt(flen.W))
//  val exceptions: UInt = Output(UInt(2.W))
//}
//
//
//class FCVT_W_S extends Module with Parameters {
//  val io: FCVT_W_S_IO = IO(new FCVT_W_S_IO)
//
//  val sign       : UInt = io.in(flen - 1)
//  val exponent   : SInt = io.in(flen - 2, sigWidth).asSInt
//  val significand: UInt = io.in(sigWidth - 1, 0)
//
//  // Setting exceptions
//  val outType: Map[String, Bool] = Map(
//    "inf" -> (exponent.asUInt.andR && !significand.orR),
//    "NaN" -> (exponent.asUInt.andR && significand.orR)
//  )
//
//  io.exceptions := Mux(
//    outType.values.reduce(
//      (f, s) => f || s
//    ),
//    1.U, 0.U
//  )
//
//  // Output
//  val unbias     : SInt = WireInit(0.S(expWidth.W))
//  val magnitude  : UInt = WireInit(0.U((flen - 1).W))
//  val rShiftedMag: UInt = WireInit(0.U(magnitude.getWidth.W))
//  val lShiftedMag: UInt = WireInit(0.U(magnitude.getWidth.W))
//
//  unbias      := exponent - bias.S
//  magnitude   := Cat("b1".U, significand)
//  rShiftedMag := magnitude >> (23.S - unbias).asUInt
//  lShiftedMag := magnitude << (unbias - 23.S).asUInt
//
//  io.out := MuxCase(0.S, Seq(
//    ((outType("inf") || (unbias >= 31.S)) && sign.asBool)               -> "h80000000".U.asSInt,          // in case of -ve infinity or out of range
//    (((outType("inf") || (unbias >= 31.S)) && !sign) || outType("NaN")) -> "h7FFFFFFF".U(flen.W).asSInt,  // in case of +ve infinity, NaN or out of range
//    (unbias >= 23.S)                                                    -> Cat(sign, Mux(sign.asBool, -lShiftedMag, lShiftedMag)).asSInt,
//    ((unbias < 23.S) && (unbias >= 0.S))                                -> Cat(sign, Mux(sign.asBool, -rShiftedMag, rShiftedMag)).asSInt
//  ))
//
//
//
//  // DEBUG Section
//  val debug_unbias = dontTouch(WireInit(unbias))
//  val debug_magnitude = dontTouch(WireInit(magnitude))
//  val debug_shiftedMag = dontTouch(WireInit(rShiftedMag))
//  val debug_inf = dontTouch(WireInit(outType("inf")))
//  val debug_NaN = dontTouch(WireInit(outType("NaN")))
//  val debug_unbias_gt_31 = dontTouch(WireInit(unbias > 31.S))
//  val debug_out1 = dontTouch(WireInit((outType("inf") && sign.asBool) || (unbias > 31.S)))
//  val debug_sign_extend = dontTouch(WireInit("h7FFFFFFF".U.asSInt))
//}
