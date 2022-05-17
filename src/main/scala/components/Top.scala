package nucleusrv.components
import chisel3._
import caravan.bus.common.{AbstrRequest, AbstrResponse, BusConfig, BusDevice, BusHost}
import caravan.bus.wishbone.{WBRequest, WBResponse, WishboneConfig}
import caravan.bus.tilelink.{TLRequest, TLResponse, TilelinkConfig}
import components.RVFIPORT
import jigsaw.rams.fpga.BlockRam
import jigsaw.rams.sram._

class Top(programFile:Option[String], dataFile:Option[String]) extends Module{

  val io = IO(new Bundle() {
    val pin = Output(UInt(32.W))
    val rvfi = new RVFIPORT
  })

  implicit val config = WishboneConfig(32, 32) //WishboneConfig(32,32)

  val core: Core = Module(new Core(/*req, rsp*/ new WBRequest /*WBRequest*/,new WBResponse /*WBResponse*/))
  core.io.stall := false.B
  val imemAdapter = Module(new WishboneAdapter() /*TilelinkAdapter()*/) //instrAdapter
  val dmemAdapter = Module(new WishboneAdapter() /*WishboneAdapter()*/) //dmemAdapter

  // TODO: Make RAMs generic
  // val imemCtrl = Module(BlockRam.createNonMaskableRAM(programFile, config, 8192))
//  val dmemCtrl = Module(BlockRam.createNonMaskableRAM(programFile, config, 8192))
  // val dmemCtrl = Module(BlockRam.createMaskableRAM(config, 8192))
  val dmemCtrl = Module(new SRAM1kb(new WBRequest, new WBResponse)(dataFile))
  val imemCtrl = Module(new SRAM1kb(new WBRequest, new WBResponse)(programFile))

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

  io.rvfi <> core.io.rvfi
  io.pin := core.io.pin

}
//class Top(programFile:Option[String]) extends Module{
//  val io = IO(new Bundle() {
//    val pin = Output(UInt(32.W))
//    val rvfi = new RVFIPORT
//  })
//
//  implicit val config = TilelinkConfig(32) //WishboneConfig(32,32)
//
//  val core: Core = Module(new Core(/*req, rsp*/ new TLRequest /*WBRequest*/,new TLResponse /*WBResponse*/))
//  val imemAdapter = Module(new TilelinkAdapter() /*TilelinkAdapter()*/) //instrAdapter
//  val dmemAdapter = Module(new TilelinkAdapter() /*WishboneAdapter()*/) //dmemAdapter
//
//  // TODO: Make RAMs generic
//  val imemCtrl = Module(BlockRam.createNonMaskableRAM(programFile, config, 8192))
//  val dmemCtrl = Module(BlockRam.createMaskableRAM(config, 1024))
//
//  /*  Imem Interceonnections  */
//  imemAdapter.io.reqIn <> core.io.imemReq
//  core.io.imemRsp <> imemAdapter.io.rspOut
//  imemCtrl.io.req <> imemAdapter.io.reqOut
//  imemAdapter.io.rspIn <> imemCtrl.io.rsp
//
//  /*  Dmem Interconnections  */
//  dmemAdapter.io.reqIn <> core.io.dmemReq
//  core.io.dmemRsp <> dmemAdapter.io.rspOut
//  dmemCtrl.io.req <> dmemAdapter.io.reqOut
//  dmemAdapter.io.rspIn <> dmemCtrl.io.rsp
//
//  io.rvfi <> core.io.rvfi
//  io.pin := core.io.pin
//
//}