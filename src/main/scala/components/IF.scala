package components
import chisel3._

class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val PCPlusOffset = Input(UInt(64.W))
    val PcSrc = Input(Bool())
    val instruction = Output(UInt(32.W))
    val PC = Output(UInt(64.W))
    val PcWrite = Input(Bool())
  })

  val IMEM = Module(new InstructionMemory)
  val PC = RegInit(0.U(64.W))

  IMEM.io.address := io.PC >> 2
  io.instruction := IMEM.io.instruction

  // Program Counter implementation
  val PCPlusFour = PC + 4.U

  when(io.PcWrite) {
    when(io.PcSrc) {
      PC := io.PCPlusOffset
    }.otherwise {
      PC := PCPlusFour
    }
  }.otherwise {
    PC := io.PC
  }
  io.PC:= PC
}
