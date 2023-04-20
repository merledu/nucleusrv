//package nucleusrv.components.fpu
//
//import chisel3._, chisel3.util._
//
//
//class FALU_IO extends Bundle {
//  // Inputs
//  val input    : Vec[UInt] = Input(Vec(3, UInt(32.W)))
//  val aluCtl   : UInt      = Input(UInt(4.W))
//  val roundMode: UInt      = Input(UInt(3.W))
//
//  // Outputs
//  val out: UInt = Output(UInt(32.W))
//}
//
//
//class FALU extends Module {
//  val io: FALU_IO = IO(new FALU_IO)
//
//  // Constants
//  val expWidth: Int = 8
//  val sigWidth: Int = 24
//
//  // Modules
//
//  // Debug Counter
//  val counter: UInt = dontTouch(RegInit(0.U(32.W)))
//  counter := counter + 1.U
//
//  // Connections
//  Seq(
//  ).map(
//    f =>
//      f._1 := f._2
//  )
//
//  // Operation Selection
//  io.out := MuxLookup(io.aluCtl, 0.U, Seq(
//  ))
//
//
//
//  // DEBUG
//}
