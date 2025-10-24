package nucleusrv.components

import chisel3._
import chisel3.stage.ChiselStage
import nucleusrv.tracer._
import cachematic._

class Top(programFile: Option[String], dataFile: Option[String]) extends Module {
  val io = IO(new Bundle {
    val pin  = Output(UInt(32.W))
    val rvfi = new TracerO
  })

  implicit val config: Configs = Configs(
    XLEN = 32,
    M = true,
    F = true,
    C = false,
    Zicsr = true,
    TRACE = true
  )

  //  Two NucleusRV cores
  val core0 = Module(new Core())
  val core1 = Module(new Core())
  core0.io.stall := false.B
  core1.io.stall := false.B

  //  caches per core (16KB)
  val icache0 = Module(new Cache(16384, 64, CacheAccessType.ReadOnly))
  val dcache0 = Module(new Cache(16384, 64, CacheAccessType.ReadWrite))
  
  val icache1 = Module(new Cache(16384, 64, CacheAccessType.ReadOnly))
  val dcache1 = Module(new Cache(16384, 64, CacheAccessType.ReadWrite))

  // Shared Bus + Memories
  val bus = Module(new SharedBus())   //hared roundrobin bus
  val imem = Module(new SRamTop(programFile))
  val dmem = Module(new SRamTop(dataFile))

  // Core 0 cache connections
  icache0.io.addr  := core0.io.imemReq.bits.addrRequest
  core0.io.imemRsp.bits.dataResponse := icache0.io.rdata

  dcache0.io.addr  := core0.io.dmemReq.bits.addrRequest
  dcache0.io.wdata := core0.io.dmemReq.bits.dataRequest
  dcache0.io.wen   := core0.io.dmemReq.bits.isWrite
  core0.io.dmemRsp.bits.dataResponse := dcache0.io.rdata

  // Core 1 cache connections
  icache1.io.addr  := core1.io.imemReq.bits.addrRequest
  core1.io.imemRsp.bits.dataResponse := icache1.io.rdata

  dcache1.io.addr  := core1.io.dmemReq.bits.addrRequest
  dcache1.io.wdata := core1.io.dmemReq.bits.dataRequest
  dcache1.io.wen   := core1.io.dmemReq.bits.isWrite
  core1.io.dmemRsp.bits.dataResponse := dcache1.io.rdata

  // Connect caches to Shared Bus (2 CPU ports)
  //  Core 0 side
  bus.io.cpu(0).addr  := Mux(icache0.io.valid, icache0.io.addr, dcache0.io.addr) // note: match the actual dcache field name
  bus.io.cpu(0).wdata := dcache0.io.wdata
  bus.io.cpu(0).wen   := dcache0.io.wen
  bus.io.cpu(0).ren   := !dcache0.io.wen
  bus.io.cpu(0).valid := icache0.io.valid || dcache0.io.valid

  // The bus drives mem responses into cache memory-side inputs (mem_rdata/mem_valid).
  icache0.io.mem_rdata := bus.io.cpu(0).rdata
  icache0.io.mem_valid := bus.io.cpu(0).valid // or another signal that indicates response (simple mapping)

  dcache0.io.mem_rdata := bus.io.cpu(0).rdata
  dcache0.io.mem_valid := bus.io.cpu(0).valid

  // Core still reads from cache output as before:
  core0.io.imemRsp.bits.dataResponse := icache0.io.rdata
  core0.io.dmemRsp.bits.dataResponse := dcache0.io.rdata

  //  Core 1 side
  bus.io.cpu(1).addr  := Mux(icache1.io.valid, icache1.io.addr, dcache1.io.addr)
  bus.io.cpu(1).wdata := dcache1.io.wdata
  bus.io.cpu(1).wen   := dcache1.io.wen
  bus.io.cpu(1).ren   := !dcache1.io.wen
  bus.io.cpu(1).valid := icache1.io.valid || dcache1.io.valid

  icache1.io.mem_rdata := bus.io.cpu(1).rdata
  icache1.io.mem_valid := bus.io.cpu(1).valid

  dcache1.io.mem_rdata := bus.io.cpu(1).rdata
  dcache1.io.mem_valid := bus.io.cpu(1).valid

  // Core reads cache outputs
  core1.io.imemRsp.bits.dataResponse := icache1.io.rdata
  core1.io.dmemRsp.bits.dataResponse := dcache1.io.rdata


  // Connect bus to memories
  bus.io.imem <> imem.io
  bus.io.dmem <> dmem.io

  io.pin := core0.io.pin | core1.io.pin

  if (config.TRACE) {
    val tracer = Module(new Tracer)
    tracer.rvfi_i <> core0.io.rvfi.get
    io.rvfi <> tracer.rvfi_o
  }
}

// Verilog Generation Driver
object NRVDriver {
  def main(args: Array[String]): Unit = {
    val IMem = if (args.contains("--imem")) Some(args(args.indexOf("--imem") + 1)) else None
    val DMem = if (args.contains("--dmem")) Some(args(args.indexOf("--dmem") + 1)) else None

    new ChiselStage().emitVerilog(
      new Top(IMem, DMem),
      if (args.contains("--target-dir"))
        args.slice(args.indexOf("--target-dir"), args.indexOf("--target-dir") + 2)
      else Array()
    )
  }
}
