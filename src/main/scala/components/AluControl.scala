package components
import chisel3._
import chisel3.util._

class AluControl extends Module {
  val io = IO(new Bundle {
    val aluOp = Input(UInt(2.W))
    val f7 = Input(UInt(1.W))
    val f3 = Input(UInt(3.W))
    val aluSrc = Input(Bool())
    val out = Output(UInt(4.W))
  })

  io.out := 15.U

  when(io.aluOp === 0.U) {
    io.out := 2.U
  }.otherwise { //(io.aluOp === 2.U)
    switch(io.f3) {
      is(0.U) {
        when(!io.aluSrc || io.f7 === 0.U) {
          io.out := 2.U
        } //add
          .otherwise {
            io.out := 3.U
          } // sub
      }
      is(1.U) {
        io.out := 6.U
      } // sll
      is(2.U) {
        io.out := 4.U
      } // slt
      is(3.U) {
        io.out := 5.U
      } // sltu
      is(5.U) {
        when(io.f7 === 0.U) {
          io.out := 7.U // srl
        }.otherwise {
          io.out := 8.U // sra
        }
      }
      is(7.U) {
        io.out := 0.U
      } // and
      is(6.U) {
        io.out := 1.U
      } // or
      is(4.U) {
        io.out := 9.U
      } //xor
    }
  }
}
