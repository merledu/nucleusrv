
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

  io.dccmRsp.ready := true.B

  val offSet = io.aluResultIn(1,0)
  val mask = Wire(UInt(8.W))
  
  when(io.writeEnable && io.func3 === "b010".U){ 
    when(offSet === 0.U){
      mask := "b1111".U
    }.elsewhen(offSet === 1.U){
      mask := "b1110".U
    }.elsewhen(offSet === 2.U){
      mask := "b1100".U
    }.otherwise{
      mask := "b1000".U
    }
  }
  .elsewhen(io.writeEnable && io.func3 === "b000".U){ 
    when(offSet === 0.U){
      mask := "b0001".U
    }.elsewhen(offSet === 1.U){
      mask := "b0010".U
    }.elsewhen(offSet === 2.U){
      mask := "b0100".U
    }.otherwise{
      mask := "b1000".U
    }
  }.elsewhen(io.writeEnable && io.func3 === "b001".U){
    when(offSet === 0.U){
      mask := "b0011".U
    }.elsewhen(offSet === 1.U){
      mask := "b0110".U
    }.elsewhen(offSet === 2.U){
      mask := "b1100".U
    }.otherwise{
      mask := "b1000".U
    }
  }.otherwise{
    mask := "b1111".U
  }

  // data alignment according to the mask
  val dataAlign = Wire(Vec(4, UInt(8.W)))
  when(offSet === 1.U){
    dataAlign(1) := io.writeData(7,0)
    dataAlign(2) := io.writeData(15,8)
    dataAlign(3) := io.writeData(23,16)
    dataAlign(0) := io.writeData(31,24)
  }.elsewhen(offSet === 2.U){
    dataAlign(2) := io.writeData(7,0)
    dataAlign(3) := io.writeData(15,8)
    dataAlign(1) := io.writeData(23,16)
    dataAlign(0) := io.writeData(31,24)
  }.elsewhen(offSet === 3.U){
    dataAlign(3) := io.writeData(7,0)
    dataAlign(2) := io.writeData(15,8)
    dataAlign(1) := io.writeData(23,16)
    dataAlign(0) := io.writeData(31,24)
  }.otherwise{
    dataAlign(0) := io.writeData(7,0)
    dataAlign(1) := io.writeData(15,8)
    dataAlign(2) := io.writeData(23,16)
    dataAlign(3) := io.writeData(31,24)
  }

  io.dccmReq.bits.activeByteLane := mask
  io.dccmReq.bits.dataRequest := dataAlign.asUInt
  io.dccmReq.bits.addrRequest := (io.aluResultIn & "h00001fff".U) >> 2
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid


  io.readData := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare) //dataMem.io.readData
  // io.readData := Mux(io.dccmRsp.valid, readWire, DontCare)

  when(io.writeEnable && io.aluResultIn(31, 28) === "h8".asUInt()){
    printf("%x\n", io.writeData)
  }

}
  // io.dccmReq <> dataMem.io.coreDccmReq
  // dataMem.io.coreDccmRsp <> io.dccmRsp

  // val readWire     = Wire(UInt(32.W))
  // val dataRspWire  = Wire(UInt(32.W))
  // dataRspWire     := io.dccmRsp.bits.dataResponse

  // when(~io.writeEnable && io.func3 === "b000".U){ 
  //   readWire := Cat(Fill(24,dataRspWire(7)),dataRspWire(7,0))
  // }.elsewhen(~io.writeEnable && io.func3 === "b001".U){
  //   readWire := Cat(Fill(16,dataRspWire(15)),dataRspWire(15,0))
  // }.elsewhen(~io.writeEnable && io.func3 === "b100".U){
  //   readWire := Cat(Fill(24,0.B),dataRspWire(7,0))
  // }.elsewhen(~io.writeEnable && io.func3 === "b101".U){
  //   readWire := Cat(Fill(16,0.B),dataRspWire(15,0))
  // }.otherwise{
  //   readWire := dataRspWire
  // }
