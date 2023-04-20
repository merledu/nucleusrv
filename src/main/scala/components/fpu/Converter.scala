package nucleusrv.components.fpu

import chisel3._, chisel3.util._
import nucleusrv.components.fpu.conversions._


class ConverterIO extends Bundle with Parameters {
  val uIn      : UInt = Input(UInt(flen.W))
  val sIn      : SInt = Input(SInt(flen.W))
  val roundMode: UInt = Input(UInt(roundModeWidth.W))
  val aluCtl   : UInt = Input(UInt(4.W))

  val uOut: UInt = Output(UInt(flen.W))
  val sOut: SInt = Output(SInt(flen.W))
}


class Converter extends Module {
  val io: ConverterIO = IO(new ConverterIO)

  // Modules
  val sIntToFloat: FCVT_S_W = Module(new FCVT_S_W)
  val uIntToFloat: FCVT_S_WU = Module(new FCVT_S_WU)

  // Connections
  Seq(
    (sIntToFloat.io.in, io.sIn),
    (uIntToFloat.io.in, io.uIn)
  ).map(
    f => f._1 := f._2
  )

  Seq(
    sIntToFloat.io.roundMode,
    uIntToFloat.io.roundMode
  ).map(
    f => f := io.roundMode
  )

  io.sOut := Mux(io.aluCtl === 1.U, io.sIn, 0.S)
  io.uOut := MuxLookup(io.aluCtl, 0.U, Seq(
    10.U -> sIntToFloat.io.out,
    11.U -> uIntToFloat.io.out
  ))
}
