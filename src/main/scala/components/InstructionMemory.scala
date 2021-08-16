
package components
import chisel3._
import chisel3.util.experimental.loadMemoryFromFile

class InstructionMemory extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))
  })

  val size: Int = 4096
  val imem: Mem[UInt] = Mem(size, UInt(32.W))
//  loadMemoryFromFile(imem, "/home/usman/Documents/test.txt")
  loadMemoryFromFile(imem, "/home/usman/Documents/riscv-pipelined/tools/main.hex")
  io.instruction := imem(io.address)
}
