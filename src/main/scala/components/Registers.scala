package nucleusrv.components

import chisel3._
import chisel3.util.MuxCase

class Registers(F: Boolean) extends Module {
  val io = IO(new Bundle {
    val readAddress = Input(Vec(if (F) 3 else 2, UInt(5.W)))
    val writeEnable = Input(Vec(if (F) 2 else 1, Bool()))
    val writeAddress = Input(UInt(5.W))
    val writeData = Input(UInt(32.W))

    val f_read = if (F) Some(Input(Vec(3, Bool()))) else None

    val readData = Output(Vec(if (F) 3 else 2, UInt(32.W)))
  })
  val i_reg = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))
  val f_reg = if (F) Some(Reg(Vec(32, UInt(32.W)))) else None

  when (io.writeEnable(0) && (io.writeAddress =/= 0.U)) {
    i_reg(io.writeAddress) := io.writeData
  }

  if (F) {
    when (io.writeEnable(1)) {
      f_reg.get(io.writeAddress) := io.writeData
    }
  }

  for (i <- 0 until 2) {
    io.readData(i) := MuxCase(0.U, (
      if (F) Vector(io.f_read.get(i) -> f_reg.get(io.readAddress(i)))
      else Vector()
    ) ++ Vector(
      (io.readAddress(i) =/= 0.U) -> i_reg(io.readAddress(i))
    ))
  }
  if (F) {
    io.readData(2) := Mux(io.f_read.get(2), f_reg.get(io.readAddress(2)), 0.U)
  }
}
