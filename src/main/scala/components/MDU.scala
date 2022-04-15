package nucleusrv.components
import chisel3._
import chisel3.util._
import chisel3.experimental._

class MDU(n:Int = 32) extends Module{
    val io = IO(new Bundle{
        val src_a         = Input(UInt(32.W))
        val src_b         = Input(UInt(32.W))
        val op            = Input(UInt(5.W))
        val valid         = Input(Bool())
        val ready         = Output(Bool())
        
        val output        = Valid(Output(UInt(32.W)))
    })

    // Multiplier

    val out_wire = Wire(UInt(64.W))
    out_wire := io.src_a * io.src_b

    // Divider
    val r_ready    = RegInit(1.U(1.W))
    val r_counter  = RegInit(n.U(6.W))
    val r_dividend = RegInit(0.U(n.W))
    val r_quotient = RegInit(0.U(n.W))

    io.output.valid := 0.U

    // shift + substract
    when(io.op === 5.U || io.op === 7.U){
        val dividend  = WireInit(io.src_a.asUInt)
        val divisor   = WireInit(io.src_b.asUInt)
        when(io.valid === 1.U) {
            r_ready    := 0.U
            r_counter  := n.U
            r_dividend := dividend
            r_quotient := 0.U
        }.elsewhen(r_counter =/= 0.U){
            when(r_dividend >= (divisor<<(r_counter-1.U))){
            r_dividend    := r_dividend - (divisor<<(r_counter-1.U))
            r_quotient    := r_quotient + (1.U<<(r_counter-1.U))
            }.otherwise {r_ready := 1.U}
            r_counter  := r_counter - 1.U
            r_ready    := (r_counter === 1.U)
        }.otherwise{io.output.valid := 1.U}
    }

    io.ready     := r_ready
    when(io.op === 0.U){
        io.output.bits := out_wire(31,0)
        io.output.valid := 1.U
    }.elsewhen(io.op === 1.U || io.op === 2.U || io.op === 3.U){
        io.output.bits := out_wire(63,32)
        io.output.valid := 1.U
    }.elsewhen(io.op === 5.U){
        io.output.bits := r_quotient
    }.elsewhen(io.op === 7.U){
        io.output.bits := r_dividend
    }.otherwise{
        io.output.bits := 0.U
    }
}