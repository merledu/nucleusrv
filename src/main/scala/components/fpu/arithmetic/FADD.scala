//package fpu.FloatALU.arithmetic
//
//import chisel3._, chisel3.util._
//import hardfloat._
//
//
//class FADDIO extends Bundle {
//  val input: Vec[UInt] = Input(Vec(2, UInt(32.W)))
//
//  val out: UInt = Output(UInt(32.W))
//}
//
//
//class FADD extends Module {
//  val io: FADDIO = IO(new FADDIO)
//
//  val hf: AddRecFN = Module(new AddRecFN(8, 23))
//
//  Seq(
//    (hf.io.subOp, 0.B),
//    (hf.io.a, io.input(0)),
//    (hf.io.b, io.input(1)),
//    (hf.io.roundingMode, 0.U),
//    (hf.io.detectTininess, 1.B),
//    (io.out, hf.io.out)
//  ).map(x => x._1 := x._2)
//}
