
package nucleusrv.components
import chisel3._
import chisel3.util._

class Control extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(32.W))
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
    /*   aluSrc  ToReg regWrite memRead  memWrite branch  jump  aluOp aluSrc1*/
    List(false.B, 0.U, false.B, false.B, false.B, false.B, 0.U, 0.U, 0.U),
    Array(
      // R-Type
      BitPat("b?????????????????????????0110011") -> List(
        true.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        2.U, // aluOp
        0.U // aluSrc1
      ),
      // I-Type
      BitPat("b?????????????????????????0010011") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        2.U, // aluOp
        0.U
      ),
      // Load
      BitPat("b?????????????????????????0000011") -> List(
        false.B, // aluSrc
        1.U, // memToReg
        true.B, // regWrite
        true.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // Store
      BitPat("b?????????????????????????0100011") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        false.B, // regWrite
        false.B, // memRead
        true.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // SB-Type
      BitPat("b?????????????????????????1100011") -> List(
        true.B, // aluSrc
        0.U, // memToReg
        false.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        true.B, // branch
        0.U, // jump
        0.U, // aluOp
        0.U
      ),
      // lui
      BitPat("b?????????????????????????0110111") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        2.U  // aluSrc1
      ),
      // auipc
      BitPat("b?????????????????????????0010111") -> List(
        false.B, // aluSrc
        0.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        0.U, // jump
        0.U, // aluOp
        1.U  // aluSrc1
      ),
      // jal
      BitPat("b?????????????????????????1101111") -> List(
        false.B, // aluSrc
        2.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        1.U, // jump
        0.U, // aluOp
        0.U
      ),
      // jalr
      BitPat("b?????????????????????????1100111") -> List(
        false.B, // aluSrc
        2.U, // memToReg
        true.B, // regWrite
        false.B, // memRead
        false.B, // memWrite
        false.B, // branch
        2.U, // jump
        0.U, // aluOp
        0.U
      )
    )
  )
  io.aluSrc := signals(0)
  io.memToReg := signals(1)
  io.regWrite := signals(2)
  io.memRead := signals(3)
  io.memWrite := signals(4)
  io.branch := signals(5)
  io.jump := signals(6)
  io.aluOp := signals(7)
  io.aluSrc1 := signals(8)
}
