package nucleusrv.components
import chisel3._
import chisel3.util._
import nucleusrv.components.MDUOps._
import chisel3.experimental._


object  MDUOps {
    val MUL     = 0.U
    val MULH    = 1.U
    val MULHSU  = 2.U
    val MULHU   = 3.U
    val DIV     = 4.U
    val DIVU    = 5.U
    val REM     = 6.U
    val REMU    = 7.U
}

class MDU extends Module{
    val io = IO(new Bundle{
        val src_a         = Input(UInt(32.W))
        val src_b         = Input(UInt(32.W))
        val op            = Input(UInt(5.W))
        val valid         = Input(Bool())
        val ready         = Output(Bool())
        
        val output        = Valid(Output(UInt(32.W)))
    })

    // Multiplier

    val result = Wire(UInt(64.W))
    result := MuxCase(0.U, Array(
        (io.op === MUL || io.op === MULHU)  ->  io.src_a * io.src_b,
        (io.op === MULHSU)                  ->  (io.src_a.asSInt * io.src_b).asUInt,
        (io.op === MULH)                    ->  (io.src_a.asSInt * io.src_b.asSInt).asUInt
    ))


    // Divider
    val r_ready    = RegInit(1.U(1.W))
    val r_counter  = RegInit(32.U(6.W))
    val r_dividend = RegInit(0.U(32.W))
    val r_quotient = RegInit(0.U(32.W))

    io.output.valid := 0.U

    val is_div_rem_u = WireInit(io.op === DIVU || io.op === REMU) 
    val is_div_rem_s = WireInit(io.op === DIV || io.op === REM) 
    when(is_div_rem_s || is_div_rem_u){
        val dividend  = Mux(is_div_rem_s && io.src_a(31), -io.src_a, io.src_a)  //WireInit(io.src_a)
        val divisor   = Mux(is_div_rem_s && io.src_b(31), -io.src_b, io.src_b)  //WireInit(io.src_b)
        when(io.valid === 1.U) {
            r_ready    := 0.U
            r_counter  := 32.U
            r_dividend := dividend
            r_quotient := 0.U
        }.elsewhen(r_counter =/= 0.U){
            when(r_dividend >= (divisor<<(r_counter-1.U))){
                r_dividend    := r_dividend - (divisor<<(r_counter-1.U))
                r_quotient    := r_quotient + (1.U<<(r_counter-1.U))
            }.otherwise {
                r_ready := 1.U
            }
            r_counter  := r_counter - 1.U
            r_ready    := (r_counter === 1.U)
        }.otherwise{
            io.output.valid := 1.U
        }
    }

    io.ready     := r_ready
    when(io.op === MUL){
        io.output.bits := result(31,0)
        io.output.valid := 1.U
    }.elsewhen(io.op === MULH || io.op === MULHU || io.op === MULHSU){
        io.output.bits := result(63,32)
        io.output.valid := 1.U
    }.elsewhen(io.op === DIV){
        io.output.bits := Mux(io.src_a(31) =/= io.src_b(31) & io.src_b.orR,-r_quotient, r_quotient)
    }.elsewhen(io.op === DIVU){
        io.output.bits := r_quotient
    }.elsewhen(io.op === REM){
        io.output.bits := Mux(io.src_a(31),-r_dividend, r_dividend)
    }.elsewhen(io.op === REMU){
        io.output.bits := r_dividend
    }.otherwise{
        io.output.bits := 0.U
    }
}