
package components
import chisel3._

class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val PCPlusOffset: UInt = Input(UInt(32.W))
    val PcSrc: Bool = Input(Bool())
    val instruction: UInt = Output(UInt(32.W))
    val PC: UInt = Output(UInt(32.W))
    val PcWrite: Bool = Input(Bool())
  })

  val IMEM: InstructionMemory = Module(new InstructionMemory)
  val PC: UInt = RegInit(0.U(32.W))

  IMEM.io.address := io.PC >> 2
  io.instruction := IMEM.io.instruction

  // Program Counter implementation
  val PCPlusFour: UInt = PC + 4.U

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
