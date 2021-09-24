package components
import chisel3._

class CpuIO extends Bundle {
  val w_enable = Input(UInt(32.W))
}

class Top extends Module{
  val io = IO(new CpuIO())

}
