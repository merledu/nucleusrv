package fpu

import chisel3._
import chisel3.util._

class ImmediateGen extends Module with OpCodes {

  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val immediate = Output(UInt(12.W))
    val immSel = Output(Bool())
  })


  io.immediate := 0.U
  io.immSel := false.B

  switch(io.instr(6,0)){
    is(LOAD){
        io.immediate := io.instr(31,20)
        io.immSel := true.B
    }
    is(STORE){
      io.immediate := Cat(io.instr(31,25), io.instr(11,7))
      io.immSel := true.B
    }
  }



}
