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

  // Core configuration
  implicit val config: Configs = Configs(
    XLEN = 32,
    M = true,
    F = true,
    C = false,
    Zicsr = true,
    TRACE = true
  )

  //  2 NucleusRV core
  val core0 = Module(new Core())
  val core1 = Module(new Core())
  core0.io.stall := false.B
  core1.io.stall := false.B

  //   caches (16KB each 64B line)
  val icache0 = Module(new Cache(16384, 64, CacheAccessType.ReadOnly))   // icache for Core0
  val dcache0 = Module(new Cache(16384, 64, CacheAccessType.ReadWrite))  // dcache for Core0

  val icache1 = Module(new Cache(16384, 64, CacheAccessType.ReadOnly))   // icache for Core1
  val dcache1 = Module(new Cache(16384, 64, CacheAccessType.ReadWrite))  // dcache for Core1

  //  Shared Bus + Memory system
  val bus0 = Module(new Bus()) // Core0 bus to imem,dmem
  val bus1 = Module(new Bus()) // Core1 bus to imem,dmem

  val imem = Module(new SRamTop(programFile))
  val dmem = Module(new SRamTop(dataFile))

  // Core 0 instruction
  core0.io.imemReq.bits.addrRequest  := icache0.io.addr
  core0.io.imemRsp.bits.dataResponse := icache0.io.rdata
  
  // Core 0 data
  core0.io.dmemReq.bits.addrRequest  := dcache0.io.addr
  core0.io.dmemReq.bits.dataRequest  := dcache0.io.wdata
  core0.io.dmemReq.bits.isWrite      := dcache0.io.wen
  core0.io.dmemRsp.bits.dataResponse := dcache0.io.rdata
  
  // Core 1 instruction
  core1.io.imemReq.bits.addrRequest  := icache1.io.addr
  core1.io.imemRsp.bits.dataResponse := icache1.io.rdata
  
  // Core 1 data
  core1.io.dmemReq.bits.addrRequest  := dcache1.io.addr
  core1.io.dmemReq.bits.dataRequest  := dcache1.io.wdata
  core1.io.dmemReq.bits.isWrite      := dcache1.io.wen
  core1.io.dmemRsp.bits.dataResponse := dcache1.io.rdata

  //  Connect caches to bus
  
  // Core0 cache to Bus0
  bus0.io.cpu.addr  := Mux(icache0.io.valid, icache0.io.addr, dcache0.io.addr)
  bus0.io.cpu.wdata := dcache0.io.wdata
  bus0.io.cpu.wen   := dcache0.io.wen
  bus0.io.cpu.ren   := !dcache0.io.wen
  dcache0.io.rdata  := bus0.io.cpu.rdata
  icache0.io.rdata  := bus0.io.cpu.rdata

  // Core1 caches to Bus1
  bus1.io.cpu.addr  := Mux(icache1.io.valid, icache1.io.addr, dcache1.io.addr)
  bus1.io.cpu.wdata := dcache1.io.wdata
  bus1.io.cpu.wen   := dcache1.io.wen
  bus1.io.cpu.ren   := !dcache1.io.wen
  dcache1.io.rdata  := bus1.io.cpu.rdata
  icache1.io.rdata  := bus1.io.cpu.rdata


  //  Shared Memory connection
  bus0.io.imem <> imem.io
  bus0.io.dmem <> dmem.io

  bus1.io.imem <> imem.io
  bus1.io.dmem <> dmem.io

  io.pin := core0.io.pin | core1.io.pin

  if (config.TRACE) {
    val tracer = Module(new Tracer)
    tracer.rvfi_i <> core0.io.rvfi.get
    io.rvfi <> tracer.rvfi_o
  }
}

object NRVDriver {
  def main(args: Array[String]): Unit = {
    val IMem = if (args.contains("--imem")) Some(args(args.indexOf("--imem") + 1)) else None
    val DMem = if (args.contains("--dmem")) Some(args(args.indexOf("--dmem") + 1)) else None
    new ChiselStage().emitVerilog(
      new Top(IMem, DMem),
      if (args.contains("--target-dir")) args.slice(
        args.indexOf("--target-dir"),
        args.indexOf("--target-dir") + 2
      ) else Array()
    )
  }
}