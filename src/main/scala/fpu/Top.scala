package fpu

import chisel3._
import chisel3.util._
import jdk.internal.module.IllegalAccessLogger.Mode
import nucleusrv.fpu.RegFile

class Top extends Module{
  val io = IO(new Bundle{
    val instr = Input(UInt(32.W))
    val ld = Output(Bool())
    val str = Output(Bool())


  })

  val decoder = Module(new Decoder)
  val imm_gen = Module(new ImmediateGen)
  val reg_file = Module(new RegFile)
  val alu_ctrl = Module(new AluCtrl)
  val alu = Module(new Alu)

  decoder.io.instr := io.instr

  imm_gen.io.instr := io.instr

  alu_ctrl.io.opcode := decoder.io.opcode

}
