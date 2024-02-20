package nucleusrv.components

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class SRamTop(val programFile: Option[String]) extends Module {
  val io = IO(new Bundle {
    val req = Flipped(Decoupled(new MemRequestIO))
    val rsp = Decoupled(new MemResponseIO)
  })

  // SRAM instances
  val sram1 = Module(new sram_top(programFile))
  val sram2 = Module(new sram_top(programFile))

  // Connect SRAM1
  sram1.io.clk_i := clock.asUInt()(0)
  sram1.io.rst_i := reset.asBool()
  sram1.io.csb_i := true.B // Default
  sram1.io.we_i := DontCare
  sram1.io.wmask_i := DontCare
  sram1.io.addr_i := DontCare
  sram1.io.wdata_i := DontCare

  // Connect SRAM2
  sram2.io.clk_i := clock.asUInt()(0)
  sram2.io.rst_i := reset.asBool()
  sram2.io.csb_i := true.B // Default
  sram2.io.we_i := DontCare
  sram2.io.wmask_i := DontCare
  sram2.io.addr_i := DontCare
  sram2.io.wdata_i := DontCare

  // Handle SRAM operations based on request
  val rdata = WireInit(0.U(64.W))
  val validReg = RegInit(false.B)
  io.rsp.valid := validReg
  io.req.ready := true.B // assuming we are always ready to accept requests from device

  when(io.req.valid) {
    validReg := true.B
    when(!io.req.bits.isWrite) {
      // READ
      val addr = io.req.bits.addrRequest
      when(addr(0) === false.B) {
        // Even address, read from SRAM1
        sram1.io.csb_i := false.B
        sram1.io.we_i := true.B
        sram1.io.addr_i := addr >> 1
        rdata := Cat(sram1.io.rdata_o, sram2.io.rdata_o)
      } .otherwise {
        // Odd address, read from SRAM2
        sram2.io.csb_i := false.B
        sram2.io.we_i := true.B
        sram2.io.addr_i := addr >> 1
        rdata := Cat(sram1.io.rdata_o, sram2.io.rdata_o)
      }
    } .otherwise {
      // WRITE
      val addr = io.req.bits.addrRequest
      val wdata = io.req.bits.dataRequest
      when(addr(0) === false.B) {
        // Even address, write to SRAM1
        sram1.io.csb_i := false.B
        sram1.io.we_i := false.B
        sram1.io.wmask_i := "b0011".U // Lower 32 bits
        sram1.io.addr_i := addr >> 1
        sram1.io.wdata_i := Cat(wdata(0), wdata(1))
        // Also write to SRAM2, but with default values
        sram2.io.csb_i := false.B
        sram2.io.we_i := false.B
        sram2.io.addr_i := DontCare
        sram2.io.wdata_i := DontCare
      } .otherwise {
        // Odd address, write to SRAM2
        sram2.io.csb_i := false.B
        sram2.io.we_i := false.B
        sram2.io.wmask_i := "b1100".U // Upper 32 bits
        sram2.io.addr_i := addr >> 1
        sram2.io.wdata_i := Cat(wdata(2), wdata(3))
        // Also write to SRAM1, but with default values
        sram1.io.csb_i := false.B
        sram1.io.we_i := false.B
        sram1.io.addr_i := DontCare
        sram1.io.wdata_i := DontCare
      }
    }
  } .otherwise {
    validReg := false.B
    rdata := DontCare
  }

  io.rsp.bits.dataResponse := rdata
}

class SRAMIO extends Bundle {
  val clk_i = Input(Bool())
  val rst_i = Input(Bool())
  val csb_i = Input(Bool())
  val we_i = Input(Bool())
  val wmask_i = Input(UInt(4.W))
  val addr_i = Input(UInt(13.W))
  val wdata_i = Input(UInt(32.W))
  val rdata_o = Output(UInt(32.W))
}

class sram_top(programFile: Option[String]) extends BlackBox(
  Map("IFILE_IN" -> {if (programFile.isDefined) programFile.get else ""})
) with HasBlackBoxResource {
  val io = IO(new SRAMIO)
  addResource("/sram_top.v")
  addResource("/sram.v")
}
