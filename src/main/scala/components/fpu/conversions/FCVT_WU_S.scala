//package fpu.conversions
//
//import chisel3._, chisel3.util._
//import fpu._
//
//
//class FCVT_WU_S_IO extends Bundle with Parameters {
//  val in: UInt = Input(UInt(flen.W))
//
//  val out       : UInt = Output(UInt(flen.W))
//  val exceptions: UInt = Output(UInt(2.W))
//}
//
//
//class FCVT_WU_S extends Module with Parameters {
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
//  val rShiftedMag: UInt = WireInit(0.U(magnitude.getWidth.W))  // Zero extending for bigger within range exponent
//  val lShiftedMag: UInt = WireInit(0.U(magnitude.getWidth.W))  // Truncating for smaller within range exponent
//
//  unbias      := exponent - bias.S
//  magnitude   := Cat("b1".U, significand)
//  rShiftedMag := magnitude >> (23.S - unbias).asUInt
//  lShiftedMag := magnitude << (unbias - 23.S).asUInt
//
//  io.out := MuxCase(0.U, Seq(
//    //((outType("inf") || (unbias >= 31.S)) && sign.asBool)               -> "h00000000".U,          // in case of -ve infinity or out of range
//    (((outType("inf") || (unbias >= 31.S)) && !sign) || outType("NaN")) -> "hFFFFFFFF".U(flen.W),  // in case of +ve infinity, NaN or out of range
//    (unbias >= 23.S)                                                    -> Cat(sign, Mux(sign.asBool, -lShiftedMag, lShiftedMag)),
//    ((unbias < 23.S) && (unbias >= 0.S))                                -> Cat(sign, Mux(sign.asBool, -rShiftedMag, rShiftedMag))
//  ))
//}
