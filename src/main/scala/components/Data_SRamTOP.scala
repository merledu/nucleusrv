package nucleusrv.components

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class Data_SRamTop(val programFile:Option[String] ) extends Module {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new MemRequestIO))
        val rsp = Decoupled(new MemResponseIO)
    })

    val validReg = RegInit(false.B)
    io.rsp.valid := validReg
    io.req.ready := true.B // assuming we are always ready to accept requests from device

    val rdata = Wire(UInt(32.W))

    // the memory
    val data_sram = Module(new datacache_sramTop(programFile))

    val clk = WireInit(clock.asUInt()(0))
    val rst = Wire(Bool())
    rst := reset.asBool()

    data_sram.io.clk_i := clk
    data_sram.io.rst_i := rst
    data_sram.io.csb_i := 1.B
    data_sram.io.we_i := DontCare
    data_sram.io.wmask_i := DontCare
    data_sram.io.addr_i := DontCare
    data_sram.io.wdata_i := DontCare

        dontTouch(io.req.valid)

        when(io.req.valid && !io.req.bits.isWrite) {
            // READ
            // rdata := mem.read(io.req.bits.addrRequest/4.U)
            validReg := true.B
            data_sram.io.csb_i := false.B
            data_sram.io.we_i := true.B
            data_sram.io.addr_i := io.req.bits.addrRequest

            rdata := data_sram.io.rdata_o
        } .elsewhen(io.req.valid && io.req.bits.isWrite) {
            // WRITE
            // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
            // validReg := true.B
            // rdata map (_ := DontCare)
            data_sram.io.csb_i := false.B
            data_sram.io.we_i := false.B
            data_sram.io.wmask_i := io.req.bits.activeByteLane
            data_sram.io.addr_i := io.req.bits.addrRequest
            data_sram.io.wdata_i := io.req.bits.dataRequest
            validReg := true.B
            rdata := DontCare
        } .otherwise {
            validReg := false.B
            // rdata map (_ := DontCare)
            rdata := DontCare
        }

    io.rsp.bits.dataResponse := data_sram.io.rdata_o
}

class Data_SRAMIO extends Bundle {
    val clk_i = Input(Bool())
    val rst_i = Input(Bool())
    val csb_i = Input(Bool())
    val we_i = Input(Bool())
    val wmask_i = Input(UInt(4.W))
    val addr_i = Input(UInt(13.W))
    val wdata_i = Input(UInt(32.W))
    val rdata_o = Output(UInt(32.W))
}

class datacache_sramTop(programFile:Option[String] ) extends BlackBox(
    Map("IFILE_IN" -> {if (programFile.isDefined) programFile.get else ""})
) with HasBlackBoxResource {
    val io = IO(new Data_SRAMIO)
    addResource("/datacache_sramTop.v")
    addResource("/datacache_sram.v")
}
