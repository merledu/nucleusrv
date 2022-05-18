
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

  val wdata = Wire(Vec(4, UInt(8.W)))
  val offSet = io.aluResultIn(1,0)

  wdata(0) := io.writeData(7,0)
  wdata(1) := io.writeData(15,8)
  wdata(2) := io.writeData(23,16)
  wdata(3) := io.writeData(31,24)

  /* Store Half Word */
  when(io.writeEnable && io.func3 === "b000".U){
    when(offSet === 0.U){
      io.dccmReq.bits.activeByteLane := "b0001".U
    }.elsewhen(offSet === 1.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(7,0)
      wdata(2) := io.writeData(23,16)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0010".U
    }.elsewhen(offSet === 2.U){
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(31,24)
      io.dccmReq.bits.activeByteLane := "b0100".U
    }.otherwise{
      wdata(0) := io.writeData(15,8)
      wdata(1) := io.writeData(23,16)
      wdata(2) := io.writeData(31,24)
      wdata(3) := io.writeData(7,0)
      io.dccmReq.bits.activeByteLane := "b1000".U
    }
  }
    /* Store Half Word */
    .elsewhen(io.writeEnable && io.func3 === "b001".U){
    // offset will either be 0 or 2 since address will be 0x0000 or 0x0002
    when(offSet === 0.U){
      // data to be stored at lower 16 bits (15,0)
      io.dccmReq.bits.activeByteLane := "b0011".U
    }.otherwise{
      // data to be stored at upper 16 bits (31,16)
      io.dccmReq.bits.activeByteLane := "b1100".U
      wdata(2) := io.writeData(7,0)
      wdata(3) := io.writeData(15,8)
      wdata(0) := io.writeData(23,16)
      wdata(1) := io.writeData(31,24)
    }
  }
    /* Store Word */
    .otherwise{
    io.dccmReq.bits.activeByteLane := "b1111".U
  }

  io.dccmReq.bits.dataRequest := wdata.asUInt()
  io.dccmReq.bits.addrRequest := (io.aluResultIn & "h00001fff".U) >> 2
  io.dccmReq.bits.isWrite := io.writeEnable
  io.dccmReq.valid := Mux(io.writeEnable | io.readEnable, true.B, false.B)

  io.stall := (io.writeEnable || io.readEnable) && !io.dccmRsp.valid

  io.readData := Mux(io.dccmRsp.valid, io.dccmRsp.bits.dataResponse, DontCare) //dataMem.io.readData

  when(io.writeEnable && io.aluResultIn(31, 28) === "h8".asUInt()){
    printf("%x\n", io.writeData)
  }

}
