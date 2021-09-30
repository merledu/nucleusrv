package components
import chisel3._



class Top extends Module{
  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })

  val imem: InstructionMemory = Module(new InstructionMemory)
  val dmem: DataMemory = Module(new DataMemory)
  val core: Core = Module(new Core)

  core.io.imem <> imem.io
  core.io.dmem <> dmem.io
  io.pin := core.io.pin

}
