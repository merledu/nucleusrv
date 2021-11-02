
package nucleusrv.components
import chisel3._
import chisel3.util._
import nucleusrv.components.Control._

object Control {
  val R_TYPE = BitPat("b0110011")
  val I_TYPE = BitPat("b0010011")
  val LOAD = BitPat("b0000011")
  val STORE = BitPat("b0100011")
  val SB_TYPE = BitPat("b1100011")
  val LUI = BitPat("b0110111")
  val AUIPC = BitPat("b0010111")
  val JAL = BitPat("b1101111")
  val JALR = BitPat("b1100111")
  val CSR = BitPat("b1110011")
}

class Control extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(7.W))
    val aluSrc = Output(Bool())
    val memToReg = Output(UInt(2.W))
    val regWrite = Output(Bool())
    val memRead = Output(Bool())
    val memWrite = Output(Bool())
    val branch = Output(Bool())
    val aluOp = Output(UInt(2.W))
    val jump = Output(UInt(2.W))
    val aluSrc1 = Output(UInt(2.W))
  })

  val signals = ListLookup(
    io.in,
    /*                aluSrc  ToReg regWrite memRead  memWrite branch  jump aluOp aluSrc1*/
    List(/*         */false.B, 0.U, false.B, false.B, false.B, false.B, 0.U, 0.U, 0.U),
    Array(
      R_TYPE  -> List(true.B,  0.U, true.B,  false.B, false.B, false.B, 0.U, 2.U, 0.U),
      I_TYPE  -> List(false.B, 0.U, true.B,  false.B, false.B, false.B, 0.U, 2.U, 0.U),
      LOAD    -> List(false.B, 1.U, true.B,  true.B,  false.B, false.B, 0.U, 0.U, 0.U),
      STORE   -> List(false.B, 0.U, false.B, false.B, true.B,  false.B, 0.U, 0.U, 0.U),
      SB_TYPE -> List(true.B,  0.U, false.B, false.B, false.B, true.B,  0.U, 0.U, 0.U),
      LUI     -> List(false.B, 0.U, true.B,  false.B, false.B, false.B, 0.U, 0.U, 0.U),
      AUIPC   -> List(true.B,  0.U, true.B,  false.B, false.B, false.B, 0.U, 0.U, 1.U),
      JAL     -> List(false.B, 2.U, true.B,  false.B, false.B, false.B, 1.U, 0.U, 0.U),
      JALR    -> List(false.B, 2.U, true.B,  false.B, false.B, false.B, 2.U, 0.U, 0.U),
      CSR     -> List(false.B, 0.U, false.B, false.B, false.B, false.B, 0.U, 0.U, 0.U)

    )
  )
  io.aluSrc := signals.head
  io.memToReg := signals(1)
  io.regWrite := signals(2)
  io.memRead := signals(3)
  io.memWrite := signals(4)
  io.branch := signals(5)
  io.jump := signals(6)
  io.aluOp := signals(7)
  io.aluSrc1 := signals(8)
}
