/*
 * This module interfaces with the memory.
 */

package nucleusrv.components
import chisel3._
import chisel3.util._ 


class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val stall: Bool = Input(Bool())
    val coreInstrReq = Decoupled(new MemRequestIO)
  })

  val rst: Bool = Wire(Bool())
  rst := reset.asBool()

  io.coreInstrReq.bits.activeByteLane := "b1111".U
  io.coreInstrReq.bits.isWrite := false.B
  io.coreInstrReq.bits.dataRequest := DontCare

  io.coreInstrReq.bits.addrRequest := io.address >> 2
  io.coreInstrReq.valid := Mux(rst || io.stall, false.B, true.B)
}
