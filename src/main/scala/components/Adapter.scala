package nucleusrv.components

import chisel3._ 
import chisel3.util._
import caravan.bus.wishbone._
import caravan.bus.tilelink._ 

class WishboneAdapter(implicit val config:WishboneConfig) extends Module {
    val io = IO(new Bundle{

        /*  MASTER SIDE  */
        val reqIn =  Flipped(Decoupled(new WBRequest))
        val rspOut = Decoupled(new WBResponse)

        /*  SLAVE SIDE */
        val reqOut = Decoupled(new WBRequest)
        val rspIn = Flipped(Decoupled(new WBResponse))
    })

    val wbHost = Module(new WishboneHost)
    val wbSlave = Module(new WishboneDevice)

    /*  Connecting Master Interconnects  */
    wbHost.io.wbMasterTransmitter <> wbSlave.io.wbMasterReceiver

    /*  Connecting Slave Interconnects  */
    wbSlave.io.wbSlaveTransmitter <> wbHost.io.wbSlaveReceiver

    /*  Sending Request in Master  */
    wbHost.io.reqIn <> io.reqIn

    /*  Sending Response out from Master  */
    io.rspOut <> wbHost.io.rspOut

    /*  Sending Request out from Slave  */
    io.reqOut <> wbSlave.io.reqOut

    /*  Sending Response in Slave  */
    wbSlave.io.rspIn <> io.rspIn
}

class TilelinkAdapter(implicit val config:TilelinkConfig) extends Module {
    val io = IO(new Bundle{

        /*  MASTER SIDE  */
        val reqIn =  Flipped(Decoupled(new TLRequest))
        val rspOut = Decoupled(new TLResponse)

        /*  SLAVE SIDE */
        val reqOut = Decoupled(new TLRequest)
        val rspIn = Flipped(Decoupled(new TLResponse))
    })

    val tlHost = Module(new TilelinkHost)
    val tlSlave = Module(new TilelinkDevice)

    /*  Connecting Master Interconnects  */
    tlHost.io.tlMasterTransmitter <> tlSlave.io.tlMasterReceiver

    /*  Connecting Slave Interconnects  */
    tlSlave.io.tlSlaveTransmitter <> tlHost.io.tlSlaveReceiver

    /*  Sending Request in Master  */
    tlHost.io.reqIn <> io.reqIn

    /*  Sending Response out from Master  */
    io.rspOut <> tlHost.io.rspOut

    /*  Sending Request out from Slave  */
    io.reqOut <> tlSlave.io.reqOut

    /*  Sending Response in Slave  */
    tlSlave.io.rspIn <> io.rspIn
}