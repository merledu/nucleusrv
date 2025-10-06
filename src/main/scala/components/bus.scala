package nucleusrv.components

import chisel3._
import chisel3.util._

class BusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr  = Input(UInt(addrWidth.W))
  val wdata = Input(UInt(dataWidth.W))
  val rdata = Output(UInt(dataWidth.W))
  val wen   = Input(Bool())
  val ren   = Input(Bool())
}

class Bus(addrWidth: Int = 32, dataWidth: Int = 32) extends Module {
  val io = IO(new Bundle {
    val cpu   = Flipped(new BusIO(addrWidth, dataWidth))
    val imem  = new BusIO(addrWidth, dataWidth)
    val dmem  = new BusIO(addrWidth, dataWidth)
  })

  // Default signals
  io.imem := 0.U.asTypeOf(io.imem)
  io.dmem := 0.U.asTypeOf(io.dmem)
  io.cpu.rdata := 0.U

  // Address decode: <0x1000_0000 -> imem, else -> dmem
  when(io.cpu.addr < "h10000000".U) {
    io.imem.addr  := io.cpu.addr
    io.imem.wdata := io.cpu.wdata
    io.imem.wen   := io.cpu.wen
    io.imem.ren   := io.cpu.ren
    io.cpu.rdata  := io.imem.rdata
  }.otherwise {
    io.dmem.addr  := io.cpu.addr
    io.dmem.wdata := io.cpu.wdata
    io.dmem.wen   := io.cpu.wen
    io.dmem.ren   := io.cpu.ren
    io.cpu.rdata  := io.dmem.rdata
  }
}