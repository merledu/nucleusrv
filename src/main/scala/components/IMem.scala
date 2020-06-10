package components
import chisel3._
import chisel3.util.experimental.loadMemoryFromFile

class InstructionMemory extends Module {
  val io = IO(new Bundle {
    val address = Input(UInt(32.W))
    val instruction = Output(UInt(32.W))
  })

  val imem = Mem(4096, UInt(32.W))
  loadMemoryFromFile(imem, "/home/usman/Documents/chisel-projects/test.txt")
  io.instruction := imem(io.address)
}
