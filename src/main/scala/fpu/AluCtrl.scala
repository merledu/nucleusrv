package fpu

import chisel3._
import chisel3.util._

class AluCtrl extends Module with OpCodes {
  val io = IO(new Bundle{
    val opcode = Input(UInt(7.W))
    val aluctrl = Output(UInt(2.W))
  })

  switch(io.opcode){
    is(LOAD | STORE){
      io.aluctrl := 0.U // ADD
    }
  }

}
