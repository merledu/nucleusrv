// TODO: Need to properly implement this
//package nucleusrv.components
//
//import chisel3._
//import chisel3.util._
//import nucleusrv.tracer._
//
//import cachematic.cache._
//
///**
// * Bundles an I-Cache and a D-Cache together for a single core.
// * Exposes separate I-Cache and D-Cache bus ports.
// */
//class CoreTile(
//    cacheSize: Int,
//    blockSize: Int
//) extends Module {
//  val io = IO(new Bundle {
//    // --- Separate bus ports for I-Cache and D-Cache ---
//    val iCacheBusReq = Decoupled(new MemRequestIO)
//    val iCacheBusRsp = Flipped(Decoupled(new MemResponseIO))
//    val dCacheBusReq = Decoupled(new MemRequestIO)
//    val dCacheBusRsp = Flipped(Decoupled(new MemResponseIO))
//
//    val pin = Output(UInt(32.W))
//    val rvfi = new TracerO
//
//  })
//    implicit val config:Configs = Configs(
//        XLEN = 32,
//        M = true,
//        F = true,
//        C = false,
//        Zicsr = true,
//        TRACE = true
//    )
//    // --- Instantiate CPU Core ---
//    val core    = Module(new Core())
//    core.io.stall := false.B
//
//    // --- Instantiate Caches ---
//    val iCache = Module(new DirectMapped(CacheType.Instruction, cacheSize, blockSize))
//    val dCache = Module(new DirectMapped(CacheType.Data, cacheSize, blockSize))
//
//    // --- Connect CPU Ports ---
//    iCache.io.cpuReq <> core.io.imemReq
//    dCache.io.cpuReq <> core.io.dmemReq
//
//    core.io.imemRsp     <> iCache.io.cpuRsp
//    core.io.dmemRsp     <> dCache.io.cpuRsp
//
//    // --- Connect Cache Memory Ports directly to outputs ---
//    iCache.io.memReq <> io.iCacheBusReq
//    iCache.io.memRsp <> io.iCacheBusRsp
//    dCache.io.memReq <> io.dCacheBusReq
//    dCache.io.memRsp <> io.dCacheBusRsp
//
//    io.pin := core.io.pin
//
//    if (config.TRACE) {
//        val tracer = Module(new Tracer)
//        tracer.rvfi_i <> core.io.rvfi.get
//        io.rvfi <> tracer.rvfi_o
//    }
//}

