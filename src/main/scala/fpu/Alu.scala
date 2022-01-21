package fpu

import chisel3._
import chisel3.util._

class Alu extends Module{
  val io = IO(new Bundle{
    val operandA = Input(SInt(32.W))
    val operandB = Input(SInt(32.W))
    val aluCtrl = Input(UInt(2.W))
    val aluOut = Output(SInt(32.W))
  })

  switch(io.aluCtrl){
    is("b00".U){
      io.aluOut := io.operandA + io.operandB
    }
  }

}
