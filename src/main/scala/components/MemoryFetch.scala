
package nucleusrv.components
import chisel3._
import chisel3.util._ 

import caravan.bus.common.{AbstrRequest, AbstrResponse, BusConfig}

class MemoryFetch(val req:AbstrRequest, val rsp:AbstrResponse)(implicit val config:BusConfig) extends Module {
  val io = IO(new Bundle {
    val aluResultIn: UInt = Input(UInt(32.W))
    val writeData: UInt = Input(UInt(32.W))
    val writeEnable: Bool = Input(Bool())
    val readEnable: Bool = Input(Bool())
    val readData: UInt = Output(UInt(32.W))
    val stall: Bool = Output(Bool())
    val func3 = Input(UInt(3.W))

    val dccmReq = Decoupled(req)
    val dccmRsp = Flipped(Decoupled(rsp))
  })

  // val dataMem: DataMemory = Module(new DataMemory(req, rsp))
  // dataMem.io.address := io.aluResultIn
  // dataMem.io.writeData := io.writeData
  // dataMem.io.writeEnable := io.writeEnable
  // dataMem.io.readEnable := io.readEnable

  io.dccmRsp.ready := true.B

  val maskedData = Wire(Vec(4, UInt(8.W)))
  
  when(io.writeEnable && io.func3 === "b000".U){
    maskedData := ("b0001".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
  }.elsewhen(io.writeEnable && io.func3 === "b001".U){
    maskedData := ("b0011".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
  }.otherwise{
    maskedData := ("b1111".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
  }

  io.dccmReq.bits.activeByteLane := "b1111".U
  io.dccmReq.bits.dataRequest := io.writeData & maskedData.asUInt
  io.dccmReq.bits.addrRequest := io.aluResultIn
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

  // io.dccmReq <> dataMem.io.coreDccmReq
  // dataMem.io.coreDccmRsp <> io.dccmRsp

  io.readData := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare) //dataMem.io.readData

  when(io.writeEnable && io.aluResultIn(31, 28) === "h8".asUInt()){
    printf("%x\n", io.writeData)
  }

}
