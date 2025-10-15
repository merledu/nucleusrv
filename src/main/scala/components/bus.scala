package nucleusrv.components

import chisel3._
import chisel3.util._

class BusPortIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr  = Output(UInt(addrWidth.W))
  val wdata = Output(UInt(dataWidth.W))
  val rdata = Input(UInt(dataWidth.W))
  val wen   = Output(Bool())
  val ren   = Output(Bool())
}

class BusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val cpu  = Flipped(new BusPortIO(addrWidth, dataWidth)) // from CPU
  val imem = new BusPortIO(addrWidth, dataWidth)          // to IMEM
  val dmem = new BusPortIO(addrWidth, dataWidth)          // to DMEM
}

class Bus(addrWidth: Int = 32, dataWidth: Int = 32) extends Module {
  val io = IO(new BusIO(addrWidth, dataWidth))

  // Default signals
  io.imem.addr  := 0.U
  io.imem.wdata := 0.U
  io.imem.wen   := false.B
  io.imem.ren   := false.B

  io.dmem.addr  := 0.U
  io.dmem.wdata := 0.U
  io.dmem.wen   := false.B
  io.dmem.ren   := false.B

  io.cpu.rdata  := 0.U

  // Address decode: < 0x10000000 → imem, else → dmem
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
