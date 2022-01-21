package fpu

import chisel3._
import chisel3.util._

class RegFile extends Module{
  val io = IO(new Bundle{
    val readAddress = Input(UInt(5.W))
    val writeEnable = Input(Bool())
    val writeAddress = Input(UInt(5.W))
    val writeData = Input(UInt(32.W))

    val readData = Output(UInt(32.W))
  })

  val regs = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))
   io.readData := regs(io.readAddress)

   when(io.writeEnable) {
     regs(io.writeAddress) := io.writeData
   }

}