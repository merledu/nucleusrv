package nucleusrv.components
import chisel3._

class PC extends Module{
  val io = IO(new Bundle {
    val in = Input(SInt(32.W))
    val halt = Input(Bool())
    val out = Output(SInt(32.W))
    val pc4 = Output(SInt(32.W))
  })

  val pc_reg = RegInit((0x0-0x4).asSInt(32.W))
  pc_reg := io.in
  io.out := pc_reg
  io.pc4 := Mux(io.halt, pc_reg, pc_reg + 4.S)
}
