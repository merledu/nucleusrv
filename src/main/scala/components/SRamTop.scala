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

    val state_reg = dontTouch(RegInit(0.U))
    state_reg := MuxCase(state_reg, Vector(
      (state_reg === 0.U) || ((state_reg === 2.U) && io.rsp.ready),  // ready
      (state_reg === 1.U) && io.req.valid  // valid
    ).zipWithIndex.map(
      s => s._1 -> (s._2 + 1).U
    ))
    io.rsp.valid := state_reg === 2.U
    io.req.ready := state_reg === 1.U

    val rdata = Wire(UInt(32.W))

    // the memory
    val sram = Module(new sram_top(programFile))

    val clk = WireInit(clock.asUInt)
    val rst = Wire(Bool())
    rst := reset.asBool

    sram.io.clk_i := clk
    sram.io.rst_i := rst
    sram.io.csb_i := !io.req.valid
    sram.io.we_i := DontCare
    sram.io.wmask_i := DontCare
    sram.io.addr_i := DontCare
    sram.io.wdata_i := DontCare

    rdata := sram.io.rdata_o



        dontTouch(io.req.valid)

        when(io.req.valid && !io.req.bits.isWrite) {
            // READ
            // rdata := mem.read(io.req.bits.addrRequest/4.U)
            sram.io.we_i := true.B
            sram.io.addr_i := io.req.bits.addrRequest

            rdata := sram.io.rdata_o
        } .elsewhen(io.req.valid && io.req.bits.isWrite) {
            // WRITE
            // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
            // validReg := true.B
            // rdata map (_ := DontCare)
            sram.io.we_i := false.B
            sram.io.wmask_i := io.req.bits.activeByteLane
            sram.io.addr_i := io.req.bits.addrRequest
            sram.io.wdata_i := io.req.bits.dataRequest
            rdata := DontCare
        } .otherwise {
            // rdata map (_ := DontCare)
            rdata := DontCare
        }

    io.rsp.bits.dataResponse := sram.io.rdata_o
}

class SRAMIO extends Bundle {
    val clk_i = Input(Bool())
    val rst_i = Input(Bool())
    val csb_i = Input(Bool())
    val we_i = Input(Bool())
    val wmask_i = Input(UInt(4.W))
    val addr_i = Input(UInt(28.W))
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
