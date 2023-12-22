package nucleusrv.components
import chisel3._

class PC(implicit val config:Configs) extends Module{
  val io = IO(new Bundle {
    val in = Input(SInt(config.XLEN.W))
    val halt = Input(Bool())
    val out = Output(SInt(config.XLEN.W))
    val pc4 = Output(SInt(config.XLEN.W))
    val pc2 = Output(SInt(config.XLEN.W))
  })

  val pc_reg = RegInit((0x0-0x4).asSInt(config.XLEN.W))
  pc_reg := io.in
  io.out := pc_reg
  io.pc4 := Mux(io.halt, pc_reg, pc_reg + 4.S)
  io.pc2 := Mux(io.halt, pc_reg, pc_reg + 2.S)
}
