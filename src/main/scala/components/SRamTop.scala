package nucleusrv.components

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class SRamTop(val programFile:Option[String], val programFile1:Option[String], XLEN:Int) extends Module {
    val io = IO(new Bundle {
        val req = Flipped(Decoupled(new MemRequestIO(XLEN = XLEN)))
        val rsp = Decoupled(new MemResponseIO(XLEN = XLEN))
    })

    val rst = Wire(Bool())
    rst := reset.asBool

    val init :: valid :: ready :: Nil = Enum(3)
    val state_reg = dontTouch(RegInit(0.U))
    state_reg := MuxCase(state_reg, Vector(
      //(state_reg === 0.U) || ((state_reg === 2.U) && io.rsp.ready),  // ready
      //(state_reg === 1.U) && io.req.valid  // valid
      ((state_reg === init) && !rst) -> ready,
      ((state_reg === valid) && io.rsp.fire) -> ready,
      ((state_reg === ready) && io.req.fire) -> valid,
      rst -> init
    ))
    io.rsp.valid := state_reg === valid
    io.req.ready := state_reg === ready

    val rdata_0 = Wire(UInt(32.W))

    // the memory
    val sram_0 = Module(new sram_top(programFile = programFile))

    val clk = WireInit(clock.asUInt)

    sram_0.io.clk_i := clk
    sram_0.io.rst_i := rst
    sram_0.io.csb_i := !io.req.valid
    sram_0.io.we_i := DontCare
    sram_0.io.wmask_i := DontCare
    sram_0.io.addr_i := DontCare
    sram_0.io.wdata_i := DontCare

    rdata_0 := sram_0.io.rdata_o

    dontTouch(io.req.valid)

    when(io.req.valid && !io.req.bits.isWrite) {
        // READ
        // rdata := mem.read(io.req.bits.addrRequest/4.U)
        sram_0.io.we_i := true.B
        sram_0.io.addr_i := io.req.bits.addrRequest

        rdata_0 := sram_0.io.rdata_o

    } .elsewhen(io.req.valid && io.req.bits.isWrite) {
        // WRITE
        // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
        // validReg := true.B
        // rdata map (_ := DontCare)
        sram_0.io.we_i := false.B
        sram_0.io.wmask_i := io.req.bits.activeByteLane(3,0)
        sram_0.io.addr_i := io.req.bits.addrRequest
        sram_0.io.wdata_i := io.req.bits.dataRequest(31,0)
        rdata_0 := DontCare

    } .otherwise {
        // rdata map (_ := DontCare)
        rdata_0 := DontCare
    }


    if (XLEN == 64){
        val rdata_1 = Wire(UInt(32.W))

        // the memory
        val sram_1 = Module(new sram_top(programFile = programFile1))

        sram_1.io.clk_i := clk
        sram_1.io.rst_i := rst
        sram_1.io.csb_i := !io.req.valid
        sram_1.io.we_i := DontCare
        sram_1.io.wmask_i := DontCare
        sram_1.io.addr_i := DontCare
        sram_1.io.wdata_i := DontCare

        rdata_1 := sram_1.io.rdata_o

        when(io.req.valid && !io.req.bits.isWrite) {
            // READ
            // rdata := mem.read(io.req.bits.addrRequest/4.U)

            sram_1.io.we_i := true.B
            sram_1.io.addr_i := io.req.bits.addrRequest
            rdata_1 := sram_1.io.rdata_o

        } .elsewhen(io.req.valid && io.req.bits.isWrite) {
            // WRITE
            // mem.write(io.req.bits.addrRequest/4.U, wdata, mask)
            // validReg := true.B
            // rdata map (_ := DontCare)
            sram_1.io.we_i := false.B
            sram_1.io.wmask_i := io.req.bits.activeByteLane(7,4)
            sram_1.io.addr_i := io.req.bits.addrRequest
            sram_1.io.wdata_i := io.req.bits.dataRequest(63,32)
            rdata_1 := DontCare

        } .otherwise {
            // rdata map (_ := DontCare)
            rdata_1 := DontCare
        }

        io.rsp.bits.dataResponse := Cat(rdata_1, rdata_0)
    }else{
        io.rsp.bits.dataResponse := rdata_0
    }
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
