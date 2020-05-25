package components
import chisel3._

class DataMemory extends Module {
  val io = IO(new Bundle {
    val address = Input(UInt(64.W))
    val writeData = Input(UInt(64.W))
    val writeEnable = Input(Bool())
    val readEnable = Input(Bool())

    val readData = Output(UInt(64.W))
  })

  val mem = Mem(4096, UInt(64.W))

  io.readData := DontCare
  when(io.writeEnable) {
    mem(io.address) := io.writeData
  }
  when(io.readEnable) {
    io.readData := mem(io.address)
  }
}
