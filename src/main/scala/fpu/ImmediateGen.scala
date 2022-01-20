package fpu

import chisel3._
import chisel3.util._

class ImmediateGen extends Module{

  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val immediate = Output(UInt(12.W))
  })

/*
   * 0000111 - LOAD FP
   * 0100111 - STORE FP
   * 1010011 - OP FP
 */

  io.immediate := 0.U

  switch(io.instr(6,0)){
    is("b0000111".U){ // LOAD
        io.immediate := io.instr(31,20)
    }
    is("b0100111".U){
      io.immediate := Cat(io.instr(31,25), io.instr(11,7))
    }
  }



}
