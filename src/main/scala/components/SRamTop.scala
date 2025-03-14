package nucleusrv.components

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class SRamTop(val programFile:Option[String] ) extends Module {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new MemRequestIO))
        val rsp = Decoupled(new MemResponseIO)
    })

    val ready_reg = RegInit(0.B)
    val valid = RegInit(0.B)

    ready_reg := !reset.asBool && !ready_reg
    io.req.ready := ready_reg

    val rdata = Wire(UInt(32.W))

    // the memory
    val sram = Module(new sram_top(programFile))

    val clk = WireInit(clock.asUInt()(0))
    val rst = Wire(Bool())
    rst := reset.asBool()

    sram.io.clk_i := clk
    sram.io.rst_i := rst
    sram.io.csb_i := !(ready_reg && io.req.valid)
    sram.io.we_i := !io.req.bits.isWrite
    sram.io.wmask_i := io.req.bits.activeByteLane
    sram.io.addr_i := io.req.bits.addrRequest
    sram.io.wdata_i := io.req.bits.dataRequest

    rdata := sram.io.rdata_o

    valid := ready_reg
    io.rsp.valid := valid
    io.rsp.bits.dataResponse := Mux(io.rsp.ready && valid, sram.io.rdata_o, DontCare)
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

class sram_top(programFile:Option[String] ) extends BlackBox(
    Map("IFILE_IN" -> {if (programFile.isDefined) programFile.get else ""})
) with HasBlackBoxResource {
    val io = IO(new SRAMIO)
    addResource("/sram_top.v")
    addResource("/sram.v")
}
