package nucleusrv.components

import chisel3._
import chisel3.util._

import nucleusrv.components.ALUOps._

class ALU extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(32.W))
    val input2: UInt = Input(UInt(32.W))
    val aluCtl: UInt = Input(UInt(4.W))

    val result: UInt = Output(UInt(32.W))
  })
  io.result := MuxCase(
    0.U,
    Array(
      (io.aluCtl === AND) -> (io.input1 & io.input2),
      (io.aluCtl === OR) -> (io.input1 | io.input2),
      (io.aluCtl === ADD) -> (io.input1 + io.input2),
      (io.aluCtl === SUB) -> (io.input1 - io.input2),
      (io.aluCtl === SLT) -> (io.input1.asSInt < io.input2.asSInt).asUInt,
      (io.aluCtl === SLTU) -> (io.input1 < io.input2),
      (io.aluCtl === SLL) -> (io.input1 << io.input2(4, 0)),
      (io.aluCtl === SRL) -> (io.input1 >> io.input2(4, 0)),
      (io.aluCtl === SRA) -> (io.input1.asSInt >> io.input2(4, 0)).asUInt,
      (io.aluCtl === XOR) -> (io.input1 ^ io.input2)
    )
  )
}
