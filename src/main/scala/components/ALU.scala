package nucleusrv.components
import chisel3._
import chisel3.util._
import nucleusrv.components.fpu._

class ALU(F :Boolean) extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(5.W))

    val input3 = if (F) Some(Input(UInt(32.W))) else None
    val rm = if (F) Some(Input(UInt(3.W))) else None
    val fstall = if (F) Some(Output(Bool())) else None

    val zero: Bool = Output(Bool())
    val result: UInt = Output(UInt(32.W))
  })

  /*****************
   *  F Extension  *
   *****************/
  val fConv = if (F) Some(Module(new Converter)) else None
  val fAlu  = if (F) Some(Module(new FALU)) else None
  if (F) {
    fConv.get.io.sIn := io.input1.asSInt
    fConv.get.io.uIn := io.input1
    fConv.get.io.roundMode := io.rm.get
    fConv.get.io.aluCtl := io.aluCtl
    fAlu.get.io.aluCtl := io.aluCtl
    fAlu.get.io.roundMode := 0.U
    fAlu.get.io.input(0) := io.input1
    fAlu.get.io.input(1) := io.input2
    fAlu.get.io.input(2) := io.input3.get
    fAlu.get.io.stallValidIn := ((io.aluCtl === 15.U) || (io.aluCtl === 24.U))
    io.fstall.get := fAlu.get.io.stallValidOut(0)
  }

  io.result := MuxCase((io.input1 & io.input2), Seq(
    (io.aluCtl === 1.U)  -> (io.input1 | io.input2),
    (io.aluCtl === 2.U)  -> (io.input1 + io.input2),
    (io.aluCtl === 3.U)  -> (io.input1 - io.input2),
    (io.aluCtl === 4.U)  -> (io.input1.asSInt < io.input2.asSInt).asUInt,
    (io.aluCtl === 5.U)  -> (io.input1 < io.input2),
    (io.aluCtl === 6.U)  -> (io.input1 << io.input2(4, 0)),
    (io.aluCtl === 7.U)  -> (io.input1 >> io.input2(4, 0)),
    (io.aluCtl === 8.U)  -> (io.input1.asSInt >> io.input2(4, 0)).asUInt,
    (io.aluCtl === 9.U)  -> (io.input1 ^ io.input2)) ++ (
      if (F) Seq(
        ((io.aluCtl >= 10.U) && (io.aluCtl <= 12.U)) -> fConv.get.io.uOut,
        (io.aluCtl === 13.U) -> fConv.get.io.sOut.asUInt,
        ((io.aluCtl >= 14.U) && (io.aluCtl <= 31.U)) -> fAlu.get.io.out
      ) else Seq()
    )
  )
  io.zero := DontCare
}
