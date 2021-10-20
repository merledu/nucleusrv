package nucleusrv.components
import chisel3._
import chisel3.util._

class ALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(4.W))

    val zero: Bool = Output(Bool())
    val result: UInt = Output(UInt(32.W))
  })
  io.result := MuxCase(
    0.U,
    Array(
      (io.aluCtl === 0.U) -> (io.input1 & io.input2),
      (io.aluCtl === 1.U) -> (io.input1 | io.input2),
      (io.aluCtl === 2.U) -> (io.input1 + io.input2),
      (io.aluCtl === 3.U) -> (io.input1 - io.input2),
      (io.aluCtl === 4.U) -> (io.input1.asSInt < io.input2.asSInt).asUInt,
      (io.aluCtl === 5.U) -> (io.input1 < io.input2),
      (io.aluCtl === 6.U) -> (io.input1 << io.input2(4, 0)),
      (io.aluCtl === 7.U) -> (io.input1 >> io.input2(4, 0)),
      (io.aluCtl === 8.U) -> (io.input1.asSInt >> io.input2(4, 0)).asUInt,
      (io.aluCtl === 9.U) -> (io.input1 ^ io.input2)
    )
  )
  io.zero := DontCare
}
