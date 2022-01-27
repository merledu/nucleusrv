package fpu

import chisel3._
import chisel3.util._

class Decoder extends Module{
  val io = IO(new Bundle{
    val instr = Input(UInt(32.W))
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val instr_width = Output(UInt(3.W))
    val opcode = Output(UInt(7.W))

  })

  io.opcode := io.instr(6,0)
  io.rd := io.instr(11,7)
  io.instr_width := io.instr(14,12)
  io.rs1 := io.instr(19,15)
  io.rs2 := io.instr(24,20)
}
