
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
  val offSet = io.aluResultIn(1,0)
  
  when(io.writeEnable && io.func3 === "b010".U){ 
    when(offSet === 0.U){
      maskedData := ("b1111".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1111".U
    }.elsewhen(offSet === 1.U){
      maskedData := ("b1110".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1110".U
    }.elsewhen(offSet === 2.U){
      maskedData := ("b1100".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1100".U
    }.otherwise{
      maskedData := ("b1000".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1000".U
    }
  }
  .elsewhen(io.writeEnable && io.func3 === "b000".U){ 
    when(offSet === 0.U){
      maskedData := ("b0001".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b0001".U
    }.elsewhen(offSet === 1.U){
      maskedData := ("b0010".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b0010".U
    }.elsewhen(offSet === 2.U){
      maskedData := ("b0100".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b0100".U
    }.otherwise{
      maskedData := ("b1000".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1000".U
    }
  }.elsewhen(io.writeEnable && io.func3 === "b001".U){
    when(offSet === 0.U){
      maskedData := ("b0011".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b0011".U
    }.elsewhen(offSet === 1.U){
      maskedData := ("b0110".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b0110".U
    }.elsewhen(offSet === 2.U){
      maskedData := ("b1100".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1100".U
    }.otherwise{
      maskedData := ("b1000".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
      io.dccmReq.bits.activeByteLane := "b1000".U
    }
  }.otherwise{
    maskedData := ("b1111".U).asTypeOf(Vec(4, Bool())) map (Fill(8,_))
    io.dccmReq.bits.activeByteLane := "b1111".U
  }

  // io.dccmReq.bits.activeByteLane := "b1111".U
  io.dccmReq.bits.dataRequest := io.writeData //& maskedData.asUInt
  io.dccmReq.bits.addrRequest := (io.aluResultIn & "h00001fff".U) >> 2
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

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

  io.readData := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare) //dataMem.io.readData
  // io.readData := Mux(io.dccmRsp.valid, readWire, DontCare)

  when(io.writeEnable && io.aluResultIn(31, 28) === "h8".asUInt()){
    printf("%x\n", io.writeData)
  }

}
