package nucleusrv.components

import chisel3._
import chisel3.util._

/**
 * A simple behavioral model for single-ported Read-Write Memory
 * default 32-bit addrWidth and 32-bit dataWidth
 * Responds to one word-request at a time after 1 cycle
 */
class MemReadWrite(byteSize: Int) extends Module {
  val io = IO(new Bundle {
    val memReq = Flipped(Decoupled(new MemRequestIO))
    val memRsp = Decoupled(new MemResponseIO)
  })

  // Each mem addr responds with 4 bytes, so total Mem Rows = byteSizes/4
  val mem = SyncReadMem(byteSize / 4, UInt(32.W))

  val memAddr = io.memReq.bits.addrRequest >> 4
  val memEnable = io.memReq.valid && io.memReq.ready

  io.memReq.ready := true.B // always ready to receive new request
  io.memRsp.bits.dataResponse := DontCare
  when (memEnable) {
    val rwPort = mem(memAddr)
    when (io.memReq.bits.isWrite) {
      rwPort := io.memReq.bits.dataRequest
    } .otherwise {
      io.memRsp.bits.dataResponse := rwPort
    }
  }
}