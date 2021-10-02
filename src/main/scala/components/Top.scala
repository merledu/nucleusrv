
package components
import chisel3._
import caravan.bus.common.{BusConfig, AbstrRequest, AbstrResponse, BusHost, BusDevice}
import jigsaw.rams.fpga.BlockRam

class Top(val req:AbstrRequest, val rsp:AbstrResponse,val adapter:Module , programFile:Option[String]) (implicit val config:BusConfig) extends Module{
  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
  })

//  val imem: InstructionMemory = Module(new InstructionMemory)
//  val dmem: DataMemory = Module(new DataMemory)
  val core: Core = Module(new Core(req, rsp))
  val imemAdapter = Module(new adapter())
  val dmemAdapter = Module(new adapter())
  
  // TODO: Make RAMs generic
  val imemCtrl = Module(new BlockRam.createNonMaskableRAM(programFile, config, 1024))
  val dmemCtrl = Module(new BlockRam.createMaskableRAM(config, 1024))

  /*  Imem Interceonnections  */
  imemAdapter.io.reqIn <> core.io.imemReq
  core.io.imemRsp <> imemAdapter.io.rspOut
  imemCtrl.io.req <> imemAdapter.io.reqOut
  imemAdapter.io.rspIn <> imemCtrl.io.rsp

  /*  Dmem Interconnections  */
  dmemAdapter.io.reqIn <> core.io.dmemReq
  core.io.dmemRsp <> dmemAdapter.io.rspOut
  dmemCtrl.io.req <> dmemAdapter.io.reqOut
  dmemAdapter.io.rspIn <> dmemCtrl.io.rsp


//  core.io.imem <> imem.io
//  core.io.dmem <> dmem.io
  io.pin := core.io.pin

}
