// package nucleusrv.components

// import chisel3._
// import chisel3.util._
// import chisel3.experimental._
// import chisel3.util.experimental._

// class SRamTop(val programFile1: Option[String], val programFile2: Option[String]) extends Module {
//   val io = IO(new Bundle {
//     val req = Flipped(Decoupled(new MemRequestIO))
//     val rsp = Decoupled(new MemResponseIO)
//   })

//   val validReg = RegInit(false.B)
//   io.rsp.valid := validReg
//   io.req.ready := true.B // assuming we are always ready to accept requests from device

//   // Initialize rdata1 and rdata2 to zero to ensure they are always assigned a value
//   val rdata1 = WireInit(0.U(32.W))
//   val rdata2 = WireInit(0.U(32.W))
//   val rdata64 = Wire(UInt(64.W))

//   // the 32-bit memories
//   val sram1 = Module(new sram_top(programFile1))
//   val sram2 = Module(new sram_top(programFile2))

//   val clk = WireInit(clock.asUInt()(0))
//   val rst = Wire(Bool())
//   rst := reset.asBool()

//   sram1.io.clk_i := clk
//   sram1.io.rst_i := rst
//   sram1.io.csb_i := 1.B
//   sram1.io.we_i := DontCare
//   sram1.io.wmask_i := DontCare
//   sram1.io.addr_i := DontCare
//   sram1.io.wdata_i := DontCare

//   sram2.io.clk_i := clk
//   sram2.io.rst_i := rst
//   sram2.io.csb_i := 1.B
//   sram2.io.we_i := DontCare
//   sram2.io.wmask_i := DontCare
//   sram2.io.addr_i := DontCare
//   sram2.io.wdata_i := DontCare

//   dontTouch(io.req.valid)

//   when(io.req.valid && !io.req.bits.isWrite) {
//     // READ
//     validReg := true.B
//     sram1.io.csb_i := false.B
//     sram1.io.we_i := true.B
//     sram1.io.addr_i := io.req.bits.addrRequest

//     sram2.io.csb_i := false.B
//     sram2.io.we_i := true.B
//     sram2.io.addr_i := io.req.bits.addrRequest + 1.U

//     rdata1 := sram1.io.rdata_o
//     rdata2 := sram2.io.rdata_o

//     rdata64 := Cat(rdata2, rdata1)
//   }.elsewhen(io.req.valid && io.req.bits.isWrite) {
//     // WRITE
//     sram1.io.csb_i := false.B
//     sram1.io.we_i := false.B
//     sram1.io.wmask_i := io.req.bits.activeByteLane(3, 0)
//     sram1.io.addr_i := io.req.bits.addrRequest
//     sram1.io.wdata_i := io.req.bits.dataRequest(31, 0)

//     sram2.io.csb_i := false.B
//     sram2.io.we_i := false.B
//     sram2.io.wmask_i := io.req.bits.activeByteLane(3, 0)
//     sram2.io.addr_i := io.req.bits.addrRequest + 1.U
//     sram2.io.wdata_i := io.req.bits.dataRequest(31, 0)

//     validReg := true.B
//     rdata64 := DontCare
//   } .otherwise {
//     validReg := false.B
//     rdata64 := DontCare
//   }

//   io.rsp.bits.dataResponse := rdata64
// }

// class SRAMIO extends Bundle {
//   val clk_i = Input(Bool())
//   val rst_i = Input(Bool())
//   val csb_i = Input(Bool())
//   val we_i = Input(Bool())
//   val wmask_i = Input(UInt(8.W))  // for 64 bit make 4 to 8
//   val addr_i = Input(UInt(13.W))
//   val wdata_i = Input(UInt(32.W))
//   val rdata_o = Output(UInt(32.W))
// }

// class sram_top(programFile: Option[String]) extends BlackBox(
//   Map("IFILE_IN" -> { if (programFile.isDefined) programFile.get else "" })
// ) with HasBlackBoxResource {
//   val io = IO(new SRAMIO)
//   addResource("/sram_top.v")
//   addResource("/sram.v")
// }