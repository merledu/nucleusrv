
package components
import chisel3._
import chisel3.util._ 

import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse}

class InstructionFetch(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
  val io = IO(new Bundle {
    val address: UInt = Input(UInt(32.W))
    val instruction: UInt = Output(UInt(32.W))

    val coreInstrReq = Decoupled(req)
    val coreInstrResp = Flipped(Decoupled(rsp))
  })

  io.coreInstrResp.ready := true.B

  io.coreInstrReq.bits.activeByteLane := "b1111".U
  io.coreInstrReq.bits.isWrite := false.B
  io.coreInstrReq.bits.dataRequest := DontCare

  io.coreInstrReq.bits.addrRequest := io.address
  io.coreInstrReq.valid := Mux(io.coreInstrReq.ready, true.B, false.B)

  io.instruction := Mux(io.coreInstrResp.valid, io.coreInstrResp.bits.dataResponse, DontCare)
}
