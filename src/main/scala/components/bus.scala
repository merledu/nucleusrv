package nucleusrv.components

import chisel3._
import chisel3.util._

// CPU, IMEM, DMEM ports
class BusPortIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val addr  = Output(UInt(addrWidth.W))
  val wdata = Output(UInt(dataWidth.W))
  val rdata = Input(UInt(dataWidth.W))
  val wen   = Output(Bool())
  val ren   = Output(Bool())
  val valid = Output(Bool()) // request valid
  val ready = Input(Bool())  // bus ready, response valid
}

// newtoplevel bus interface 2CPU ports
class SharedBusIO(addrWidth: Int, dataWidth: Int) extends Bundle {
  val cpu  = Vec(2, Flipped(new BusPortIO(addrWidth, dataWidth))) // 2 cores
  val imem = new BusPortIO(addrWidth, dataWidth)
  val dmem = new BusPortIO(addrWidth, dataWidth)
}

// RoundRobinArbiter2: Simple 2input roundrobin arbiter
class RoundRobinArbiter2 extends Module {
  val io = IO(new Bundle {
    val req   = Input(Vec(2, Bool()))
    val grant = Output(Vec(2, Bool()))
  })

  val lastGrant = RegInit(0.U(1.W))
  io.grant := VecInit(Seq(false.B, false.B))

  when(io.req(0) && !io.req(1)) {
    io.grant(0) := true.B
  }.elsewhen(io.req(1) && !io.req(0)) {
    io.grant(1) := true.B
  }.elsewhen(io.req(0) && io.req(1)) {
    when(lastGrant === 0.U) {
      io.grant(1) := true.B
      lastGrant := 1.U
    }.otherwise {
      io.grant(0) := true.B
      lastGrant := 0.U
    }
  }
}

// SharedBus 2core shared bus with IMEM + DMEM
class SharedBus(addrWidth: Int = 32, dataWidth: Int = 32) extends Module {
  val io = IO(new SharedBusIO(addrWidth, dataWidth))
  for (i <- 0 until 2) {
    io.cpu(i).rdata := 0.U
    io.cpu(i).ready := false.B
  }

  io.imem.addr  := 0.U
  io.imem.wdata := 0.U
  io.imem.wen   := false.B
  io.imem.ren   := false.B

  io.dmem.addr  := 0.U
  io.dmem.wdata := 0.U
  io.dmem.wen   := false.B
  io.dmem.ren   := false.B

  // arbiter
  val arbiter = Module(new RoundRobinArbiter2)
  arbiter.io.req(0) := io.cpu(0).valid
  arbiter.io.req(1) := io.cpu(1).valid

  val grant = arbiter.io.grant

  // Select which core drives bus
  val active = Mux(grant(0), 0.U, Mux(grant(1), 1.U, 0.U))
  val sel = io.cpu(active)

  // Address Decode 
  val isIMem = sel.addr < "h10000000".U

  when(isIMem) {
    io.imem.addr  := sel.addr
    io.imem.wdata := sel.wdata
    io.imem.wen   := sel.wen
    io.imem.ren   := sel.ren
  }.otherwise {
    io.dmem.addr  := sel.addr
    io.dmem.wdata := sel.wdata
    io.dmem.wen   := sel.wen
    io.dmem.ren   := sel.ren
  }

  // response
  val rdata = Mux(isIMem, io.imem.rdata, io.dmem.rdata)
  when(grant(0)) {
    io.cpu(0).rdata := rdata
    io.cpu(0).ready := true.B
  }.elsewhen(grant(1)) {
    io.cpu(1).rdata := rdata
    io.cpu(1).ready := true.B
  }
}
