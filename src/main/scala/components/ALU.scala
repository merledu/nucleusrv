package nucleusrv.components

import chisel3._
import chisel3.util._

import nucleusrv.components.ALUOps._

class ALU(XLEN: Int) extends Module {
  val io = IO(new Bundle {
    val input1: UInt = Input(UInt(XLEN.W))
    val input2: UInt = Input(UInt(XLEN.W))
    val aluCtl: UInt = Input(UInt(4.W))

    val result: UInt = Output(UInt(XLEN.W))
  })
  
    val addw = if (XLEN == 64) Some(WireInit((io.input1(31, 0) + io.input2(31, 0))(31, 0))) else None
    val subw = if (XLEN == 64) Some(WireInit((io.input1(31, 0) - io.input2(31, 0))(31, 0))) else None
    val sllw = if (XLEN == 64) Some(WireInit((io.input1(31, 0) << io.input2(4, 0))(31, 0))) else None
    val srlw = if (XLEN == 64) Some(WireInit((io.input1(31, 0) >> io.input2(4, 0))(31, 0))) else None
    val sraw = if (XLEN == 64) Some(WireInit((io.input1(31, 0).asSInt >> io.input2(4, 0))(31, 0).asUInt)) else None

  io.result := MuxCase(
    0.U,
    Array(
      (io.aluCtl === AND) -> (io.input1 & io.input2),
      (io.aluCtl === OR) -> (io.input1 | io.input2),
      (io.aluCtl === ADD) -> (io.input1 + io.input2),
      (io.aluCtl === SUB) -> (io.input1 - io.input2),
      (io.aluCtl === SLT) -> (io.input1.asSInt < io.input2.asSInt).asUInt,
      (io.aluCtl === SLTU) -> (io.input1 < io.input2),
      (io.aluCtl === SLL) -> (io.input1 << io.input2(log2Ceil(XLEN)-1, 0)),
      (io.aluCtl === SRL) -> (io.input1 >> io.input2(log2Ceil(XLEN)-1, 0)),
      (io.aluCtl === SRA) -> (io.input1.asSInt >> io.input2(log2Ceil(XLEN)-1, 0)).asUInt,
      (io.aluCtl === XOR) -> (io.input1 ^ io.input2)
    ) ++ (if (XLEN == 64) {
      Array(
        (io.aluCtl === ADDW) -> Cat(Fill(32, addw.get(31)), addw.get),
        (io.aluCtl === SUBW) -> Cat(Fill(32, subw.get(31)), subw.get),
        (io.aluCtl === SLLW) -> Cat(Fill(32, sllw.get(31)), sllw.get),
        (io.aluCtl === SRLW) -> Cat(Fill(32, srlw.get(31)), srlw.get),
        (io.aluCtl === SRAW) -> Cat(Fill(32, sraw.get(31)), sraw.get),
      )
    } else {
      Array()
    })
  )
}
