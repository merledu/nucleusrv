
package components
import chisel3._

class DataMemory extends Module {
  val io = IO(new Bundle {
    val address = Input(UInt(32.W))
    val writeData = Input(UInt(32.W))
    val writeEnable = Input(Bool())
    val readEnable = Input(Bool())

    val readData = Output(UInt(32.W))
  })

  val size: Int = 4096
  val mem: SyncReadMem[UInt] = SyncReadMem(size, UInt(32.W))

  io.readData := DontCare
  when(io.writeEnable) {
    mem(io.address) := io.writeData
  }
  when(io.readEnable) {
    io.readData := mem(io.address)
  }
}
