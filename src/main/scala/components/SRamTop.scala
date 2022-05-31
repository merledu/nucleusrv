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

    val validReg = RegInit(false.B)
    io.rsp.valid := validReg
    io.req.ready := true.B // assuming we are always ready to accept requests from device

    val rdata = Wire(UInt(32.W))

    // the memory
    val sram = Module(new sram(programFile))

    val clk = WireInit(clock.asUInt()(0))

    sram.io.clk0 := clk
    sram.io.csb0 := 1.B
    sram.io.web0 := DontCare
    sram.io.wmask0 := DontCare
    sram.io.addr0 := DontCare
    sram.io.din0 := DontCare
    // io.dout0 := a.io.dout0

    sram.io.clk1 := DontCare
    sram.io.csb1 := DontCare
    sram.io.addr1 := DontCare

    dontTouch(io.req.valid)

    when(io.req.valid && !io.req.bits.isWrite) {
        // READ
        // rdata := mem.read(io.req.bits.addrRequest/4.U)
        validReg := true.B
        sram.io.csb0 := false.B
        sram.io.web0 := true.B
        sram.io.addr0 := io.req.bits.addrRequest

        rdata := sram.io.dout0
    } .elsewhen(io.req.valid && io.req.bits.isWrite) {
        // WRITE
        // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
        // validReg := true.B
        // rdata map (_ := DontCare)
        sram.io.csb0 := false.B
        sram.io.web0 := false.B
        sram.io.wmask0 := io.req.bits.activeByteLane
        sram.io.addr0 := io.req.bits.addrRequest
        sram.io.din0 := io.req.bits.dataRequest
        validReg := true.B
        rdata := DontCare
    } .otherwise {
        validReg := false.B
        // rdata map (_ := DontCare)
        rdata := DontCare
    }

    io.rsp.bits.dataResponse := rdata
}

class SRAMIO extends Bundle {
    val clk0 = Input(Bool())
    val csb0 = Input(Bool())
    val web0 = Input(Bool())
    val wmask0 = Input(UInt(4.W))
    val addr0 = Input(UInt(10.W))
    val din0 = Input(UInt(32.W))
    val dout0 = Output(UInt(32.W))

    val clk1 = Input(Bool())
    val csb1 = Input(Bool())
    val addr1 = Input(UInt(10.W))
    val dout1 = Output(UInt(32.W))

}

class sram(programFile:Option[String] ) extends BlackBox(
    Map("IFILE" -> {if (programFile.isDefined) programFile.get else ""})
) with HasBlackBoxResource {
    val io = IO(new SRAMIO)
    addResource("/sram.v")
}