import chisel3._ 
import chisel3.util._ 
import components.CPU
import caravan.bus.tilelink.{TilelinkConfig, TilelinkDevice, TilelinkHost, TLRequest, TLResponse, TilelinkSlave}
import caravan.bus.common.BusConfig
import jigsaw.rams.fpga.BlockRam


class TilelinkHarness(programFile:Option[String])(implicit val config:TilelinkConfig) extends Module {
    val io = IO(new Bundle{
        val out = Decoupled(new TilelinkSlave())
    })

    val tl_imem_host = Module(new TilelinkHost())
    val tl_imem_slave = Module(new TilelinkDevice())
    val tl_dmem_host = Module(new TilelinkHost())
    val tl_dmem_slave = Module(new TilelinkDevice())
    val imem_ctrl = Module(BlockRam.createNonMaskableRAM(programFile, bus=config, rows=1024))
    val dmem_ctrl = Module(BlockRam.createMaskableRAM(bus=config, rows=1024))
    val core = Module(new CPU(new TLRequest, new TLResponse))

    tl_imem_host.io.tlMasterTransmitter <> tl_imem_slave.io.tlMasterReceiver
    tl_imem_slave.io.tlSlaveTransmitter <> tl_imem_host.io.tlSlaveReceiver

    tl_dmem_host.io.tlMasterTransmitter <> tl_dmem_slave.io.tlMasterReceiver
    tl_dmem_slave.io.tlSlaveTransmitter <> tl_dmem_host.io.tlSlaveReceiver

    tl_imem_host.io.reqIn <> core.io.imemReq
    core.io.imemRsp <> tl_imem_host.io.rspOut
    tl_imem_slave.io.reqOut <> imem_ctrl.io.req
    tl_imem_slave.io.rspIn <> imem_ctrl.io.rsp

    tl_dmem_host.io.reqIn <> core.io.dmemReq
    core.io.dmemRsp <> tl_dmem_host.io.rspOut
    tl_dmem_slave.io.reqOut <> dmem_ctrl.io.req
    tl_dmem_slave.io.rspIn <> dmem_ctrl.io.rsp

    io.out <> tl_dmem_slave.io.tlSlaveTransmitter


}