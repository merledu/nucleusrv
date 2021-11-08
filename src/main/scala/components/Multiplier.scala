package components

import chisel3._
import chisel3.util._

class Multiplier extends Module{
    val io = IO(new Bundle{
        val src_a         = Input(SInt(32.W))
        val src_b         = Input(SInt(32.W))
        val op            = Input(UInt(5.W))
        val output        = Output(SInt(32.W))
    })
;
    val cases = Array((io.op === 0.U || io.op === 1.U )     ->      io.src_a * io.src_b,
                    (io.op === 2.U)                         ->      io.src_a * (io.src_b.asUInt).asSInt,
                    (io.op === 3.U)                         ->      (io.src_a.asUInt * io.src_b.asUInt).asSInt)

    val out_wire = Wire(SInt(64.W))
    out_wire := MuxCase(0.S, cases)
    io.output := Mux(io.op === 0.U, out_wire(31,0).asSInt, out_wire(63,32).asSInt)
}