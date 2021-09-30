
package components
import chisel3._
import chisel3.util.experimental.loadMemoryFromFileInline

class IMemIO extends Bundle {
  val address: UInt = Input(UInt(32.W))
  val instruction: UInt = Output(UInt(32.W))
}

class InstructionMemory extends Module {
  val io = IO(new IMemIO)


  val size: Int = 4096
  val imem: SyncReadMem[UInt] = SyncReadMem(size, UInt(32.W))

  loadMemoryFromFileInline(imem, "/home/usman/Documents/riscv-pipelined/tools/out/program.hex")

  io.instruction := imem(io.address)
}
