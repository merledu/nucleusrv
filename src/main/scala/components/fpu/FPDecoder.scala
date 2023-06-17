package nucleusrv.components.fpu

import chisel3._


class FPDecoderIO(XLEN:Int) extends Bundle with Parameters {
  val inst: UInt = Input(UInt(XLEN.W))

  val opcode: UInt = Output(UInt(fOpcodeWidth.W))
  val rm    : UInt = Output(UInt(rmWidth.W))
  val fmt   : UInt = Output(UInt(fFmtWidth.W))
  val funct5: UInt = Output(UInt(f5Width.W))
}


class FPDecoder(XLEN:Int) extends RawModule {
  val io: FPDecoderIO = IO(new FPDecoderIO(XLEN))

  Seq(
    io.opcode -> (6, 0),
    io.rm     -> (14, 12),
    io.fmt    -> (26, 25),
    io.funct5 -> (31, 27)
  ).foreach(
    f => f._1 := io.inst(f._2._1, f._2._2)
  )
}
