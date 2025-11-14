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

    // --- Define FSM states clearly ---
    // We will re-use your `state_reg` but with clear state names
    val sIdle :: sReadWait :: sReadRespond :: Nil = Enum(3)
    
    // We keep your `state_reg` as requested
    val state_reg = RegInit(sIdle)

    // --- The Posedge-Triggered Response Guarantee ---
    // We add a register for the SRAM's output. This is the "slight change"
    // that forces the design to be fully posedge-synchronous.
    val rdata_reg = Reg(UInt(32.W))
    rdata_reg := 0.U // Default

    // --- The SRAM BlackBox ---
    val sram = Module(new sram_top(programFile))
    sram.io.clk_i := clock.asBool
    sram.io.rst_i := reset.asBool

    // --- Default Signal Values ---
    // All signals are turned OFF by default.
    io.req.ready := false.B
    io.rsp.valid := false.B
    io.rsp.bits.dataResponse := rdata_reg // Response always comes from the register

    sram.io.csb_i   := true.B  // Chip select OFF
    sram.io.we_i    := true.B  // Write enable OFF (i.e., read)
    sram.io.wmask_i := 0.U
    sram.io.addr_i  := 0.U
    sram.io.wdata_i := 0.U

    // --- FSM Logic (Corrected) ---
    // We use a switch, which is clearer but still uses your state_reg
    switch (state_reg) {
        is (sIdle) {
            // This is the "Ready" state (was your State 1)
            io.req.ready := true.B

            // **FIX 3**: SRAM signals are now driven *only* when FSM is ready
            when(io.req.valid) {
                sram.io.csb_i   := false.B // Chip select ON
                sram.io.we_i    := !io.req.bits.isWrite
                sram.io.addr_i  := io.req.bits.addrRequest >> 2
                sram.io.wmask_i := io.req.bits.activeByteLane
                sram.io.wdata_i := io.req.bits.dataRequest

                // **FIX 2**: Handle writes vs. reads
                when (io.req.bits.isWrite) {
                    // It's a write. It's done. Stay in sIdle.
                    state_reg := sIdle
                } .otherwise {
                    // It's a read. Go to sReadWait.
                    state_reg := sReadWait
                }
            }
        }

        is (sReadWait) {
            // **FIX 1**: This is the new "Wait" state.
            // The read data is coming from SRAM *this cycle*.
            // We capture it in our register at the end of this cycle.
            rdata_reg := sram.io.rdata_o
            
            // Go to the "Respond" state next cycle
            state_reg := sReadRespond
        }

        is (sReadRespond) {
            // This is the "Response Valid" state (was your State 2)
            // The data is now safely in rdata_reg
            io.rsp.valid := true.B

            // When the handshake is complete, return to idle
            when (io.rsp.ready) {
                state_reg := sIdle
            }
        }
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
