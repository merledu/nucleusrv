
package components
import chisel3._
import chisel3.util._ 
import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse}


class DataMemory(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
  val io = IO(new Bundle {
    // val address = Input(UInt(32.W))
    // val writeData = Input(UInt(32.W))
    // val writeEnable = Input(Bool())
    // val readEnable = Input(Bool())

    // val readData = Output(UInt(32.W))

    val coreDccmReq = Flipped(Decoupled(req))
    val coreDccmRsp = Decoupled(rsp)
  })

  val size: Int = 4096
  val mem: SyncReadMem[UInt] = SyncReadMem(size, UInt(32.W))

  io.coreDccmReq.ready := true.B

  // io.coreDccmReq.bits.activeByteLane := "b1111".U
  // io.coreDccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)
  // io.coreDccmReq.bits.dataRequest := Mux(io.writeEnable, io.writeData, DontCare)
  // io.coreDccmReq.bits.addrRequest := io.address
  // io.coreDccmReq.bits.isWrite := io.readEnable //Mux(io.writeEnable, true.B, Mux(io.readEnable, false.B, DontCare )) 

  // io.readData := io.coreDccmRsp.bits.dataResponse.asUInt

  io.coreDccmRsp.bits.dataResponse := Mux(io.coreDccmReq.bits.isWrite, DontCare, mem(io.coreDccmReq.bits.addrRequest))
  io.coreDccmRsp.bits.error := Mux(io.coreDccmReq.bits.isWrite, true.B, false.B)
  io.coreDccmRsp.valid := io.coreDccmReq.valid

  // io.readData := DontCare
  when(io.coreDccmReq.bits.isWrite) {
    mem(io.coreDccmReq.bits.addrRequest) := io.coreDccmReq.bits.dataRequest
  }
  
  // when(io.readEnable) {
  //   io.readData := mem(io.address)
  // }
}
