
package nucleusrv.components
import chisel3._
import chisel3.util._ 


class InstructionFetch extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))
    val stall: Bool = Input(Bool())
    val coreInstrReq = Decoupled(new MemRequestIO)
    val coreInstrResp = Flipped(Decoupled(new MemResponseIO))
  })

  val rst = Wire(Bool())
  rst := reset.asBool()
  io.coreInstrResp.ready := true.B

//  io.coreInstrReq.ready := Mux(rst, false.B, true.B)

  io.coreInstrReq.bits.activeByteLane := "b1111".U
  io.coreInstrReq.bits.isWrite := false.B
  io.coreInstrReq.bits.dataRequest := DontCare

  io.coreInstrReq.bits.addrRequest := io.address >> 2
  io.coreInstrReq.valid := Mux(rst || io.stall, false.B, true.B)

  io.instruction := Mux(io.coreInstrResp.valid, io.coreInstrResp.bits.dataResponse, DontCare)
}
