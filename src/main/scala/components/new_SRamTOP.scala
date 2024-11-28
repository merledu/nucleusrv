package nucleusrv.components

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class new_SRamTop(val programFile:Option[String] ) extends Module {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new MemRequestIO))
        val rsp = Decoupled(new MemResponseIO)
    })

    val validReg = RegInit(false.B)
    io.rsp.valid := validReg
    io.req.ready := true.B // assuming we are always ready to accept requests from device

    val rdata = Wire(UInt(32.W))

    // the memory
    val new_sram = Module(new new_sramTop(programFile))

    val clk = WireInit(clock.asUInt()(0))
    val rst = Wire(Bool())
    rst := reset.asBool()

    new_sram.io.clk_i := clk
    new_sram.io.rst_i := rst
    new_sram.io.csb_i := 1.B
    new_sram.io.we_i := DontCare
    new_sram.io.wmask_i := DontCare
    new_sram.io.addr_i := DontCare
    new_sram.io.wdata_i := DontCare

        dontTouch(io.req.valid)

        when(io.req.valid && !io.req.bits.isWrite) {
            // READ
            // rdata := mem.read(io.req.bits.addrRequest/4.U)
            validReg := true.B
            new_sram.io.csb_i := false.B
            new_sram.io.we_i := true.B
            new_sram.io.addr_i := io.req.bits.addrRequest

            rdata := new_sram.io.rdata_o
        } .elsewhen(io.req.valid && io.req.bits.isWrite) {
            // WRITE
            // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
            // validReg := true.B
            // rdata map (_ := DontCare)
            new_sram.io.csb_i := false.B
            new_sram.io.we_i := false.B
            new_sram.io.wmask_i := io.req.bits.activeByteLane
            new_sram.io.addr_i := io.req.bits.addrRequest
            new_sram.io.wdata_i := io.req.bits.dataRequest
            validReg := true.B
            rdata := DontCare
        } .otherwise {
            validReg := false.B
            // rdata map (_ := DontCare)
            rdata := DontCare
        }

    io.rsp.bits.dataResponse := new_sram.io.rdata_o
}

class new_SRAMIO extends Bundle {
    val clk_i = Input(Bool())
    val rst_i = Input(Bool())
    val csb_i = Input(Bool())
    val we_i = Input(Bool())
    val wmask_i = Input(UInt(4.W))
    val addr_i = Input(UInt(13.W))
    val wdata_i = Input(UInt(32.W))
    val rdata_o = Output(UInt(32.W))
}

class new_sramTop(programFile:Option[String] ) extends BlackBox(
    Map("IFILE_IN" -> {if (programFile.isDefined) programFile.get else ""})
) with HasBlackBoxResource {
    val io = IO(new new_SRAMIO)
    addResource("/new_sramTop.v")
    addResource("/new_sram.v")
}
