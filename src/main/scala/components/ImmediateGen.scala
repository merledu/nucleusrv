
package nucleusrv.components
import chisel3._
import chisel3.util._

class ImmediateGen extends Module {
  val io = IO(new Bundle {
    val instruction = Input(UInt(32.W))
    val out = Output(UInt(32.W))
  })
  val opcode = io.instruction(6, 0)

  //I-type
  when(
    opcode === 3.U || opcode === 15.U || opcode === 19.U || opcode === 27.U || opcode === 103.U || opcode === 115.U
  ) {
    val imm_i = io.instruction(31, 20)
    val ext_i = Cat(Fill(20, imm_i(11)), imm_i)
    io.out := ext_i

  }
  //U-type
    .elsewhen(opcode === 23.U || opcode === 55.U) {
      val imm_u = io.instruction(31, 12)
      val ext_u = Cat(imm_u, Fill(12, 0.U))
      io.out := ext_u
    }
    //S-type
    .elsewhen(opcode === 35.U) {
      val imm_s = Cat(io.instruction(31, 25), io.instruction(11, 7))
      val ext_s = Cat(Fill(20, imm_s(11)), imm_s)
      io.out := ext_s
    }
    //SB-type
    .elsewhen(opcode === 99.U) {
      val imm_sb = Cat(
        io.instruction(31),
        io.instruction(7),
        io.instruction(30, 25),
        io.instruction(11, 8)
      )
      val ext_sb = Cat(Fill(19, imm_sb(11)), imm_sb, 0.U)
      io.out := ext_sb
    }
    //UJ-type
    .otherwise //(opcode === 111.U)
  {
    val imm_uj = Cat(
      io.instruction(31),
      io.instruction(19, 12),
      io.instruction(20),
      io.instruction(30, 21)
    )
    val ext_uj = Cat(Fill(11, imm_uj(19)), imm_uj, 0.U)
    io.out := ext_uj
  }
}
