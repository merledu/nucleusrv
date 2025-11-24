package nucleusrv.components
import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._


class Top(
    numCores: Int,
    cacheSize: Int,
    cacheLineSize: Int,
    imemBaseAddr: UInt,
    dmemBaseAddr: UInt,
    programFile:Option[String], 
    dataFile:Option[String]
) extends Module{

    val io = IO(new Bundle() {
        val pin = Output(Vec(numCores, UInt(32.W)))
        val rvfi = Vec(numCores, new TracerO)
    })

    implicit val config:Configs = Configs(
        XLEN = 32,
        M = true,
        F = true,
        C = false,
        Zicsr = true,
        TRACE = true
    )

    // --- Instantiate Cores ---
    // VecInit creates a vector of modules and wires their IO into a Vec
    val coreTilesIO = VecInit(Seq.fill(numCores)(Module(new CoreTile(cacheSize, cacheLineSize)).io))

    // --- Instantiate Memories ---
    val imem = Module(new SRamTop(programFile))
    val dmem = Module(new SRamTop(dataFile))

    // --- Instantiate Buses ---
    val iBus = Module(new Bus(numCores, imemBaseAddr))
    val dBus = Module(new Bus(numCores, dmemBaseAddr))

    // Connect I-Caches from all coreTilesIO to the I-Bus
    for (i <- 0 until numCores) {
        iBus.io.coreReqs(i) <> coreTilesIO(i).iCacheBusReq
        iBus.io.coreRsps(i) <> coreTilesIO(i).iCacheBusRsp
    }

    // Connect the I-Bus to the I-Memory
    imem.io.req <> iBus.io.memReq
    imem.io.rsp <> iBus.io.memRsp

    // Connect D-Caches from all coreTilesIO to the D-Bus
    for (i <- 0 until numCores) {
        dBus.io.coreReqs(i) <> coreTilesIO(i).dCacheBusReq
        dBus.io.coreRsps(i) <> coreTilesIO(i).dCacheBusRsp
    }

    // Connect the D-Bus to the D-Memory
    dmem.io.req <> dBus.io.memReq
    dmem.io.rsp <> dBus.io.memRsp

    // Connect IO pins and traces
    for (i <- 0 until numCores) {
        io.pin(i) <> coreTilesIO(i).pin
        io.rvfi(i) <> coreTilesIO(i).rvfi
    }    

}

object NRVDriver {
  // generate verilog
  def main(args: Array[String]): Unit = {
        val numCores = 2
        val cacheSize = 1024
        val cacheLineSize = 16
        // --- Define Memory Map region for each IMEM and DMEM ---
        val I_MEM_BASE = "h00000000".U(32.W)
        val D_MEM_BASE = "h00010000".U(32.W)
        val IMem = if (args.contains("--imem")) Some(args(args.indexOf("--imem") + 1)) else None
        val DMem = if (args.contains("--dmem")) Some(args(args.indexOf("--dmem") + 1)) else None
        new ChiselStage().emitVerilog(
            new Top(numCores, cacheSize, cacheLineSize, I_MEM_BASE, D_MEM_BASE, IMem, DMem),
            if (args.contains("--target-dir")) args.slice(
            args.indexOf("--target-dir"),
            args.indexOf("--target-dir") + 2
            ) else Array()
        )
  }
}
