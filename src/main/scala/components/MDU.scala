// Created by @Talha-Ahmed-1

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

    val MULW    = 8.U
    val DIVW    = 12.U
    val DIVUW   = 13.U
    val REMW    = 14.U
    val REMUW   = 15.U
}

class MDU(XLEN:Int) extends Module{
    val io = IO(new Bundle{
        val src_a         = Input(UInt(XLEN.W))
        val src_b         = Input(UInt(XLEN.W))
        val op            = Input(UInt(4.W))
        val valid         = Input(Bool())
        val ready         = Output(Bool())
        
        val output        = Valid(Output(UInt(XLEN.W)))
    })

    // Multiplier

    val result = Wire(UInt((XLEN*2).W))
    result := MuxCase(0.U, Array(
        (io.op === MUL || io.op === MULHU)  ->  io.src_a * io.src_b,
        (io.op === MULHSU)                  ->  (io.src_a.asSInt * io.src_b).asUInt,
        (io.op === MULH)                    ->  (io.src_a.asSInt * io.src_b.asSInt).asUInt,
        (io.op === MULW)                    ->  (io.src_a(31,0) * io.src_b(31,0))(31,0)
    ))


    // Divider
    val r_ready    = RegInit(1.U(1.W))
    val r_counter  = RegInit(XLEN.U((log2Ceil(XLEN) + 1).W))
    val r_dividend = RegInit(0.U(XLEN.W))
    val r_quotient = RegInit(0.U(XLEN.W))

    io.output.valid := 0.U

    val is_div_rem_u = WireInit(io.op === DIVU || io.op === REMU) 
    val is_div_rem_s = WireInit(io.op === DIV || io.op === REM) 
    val is_div_rem_u_w = WireInit(io.op === DIVUW || io.op === REMUW)
    val is_div_rem_s_w = WireInit(io.op === DIVW || io.op === REMW)
    val max_count = Mux(io.op(3), (XLEN/2).U, XLEN.U)
    when(is_div_rem_s || is_div_rem_u || is_div_rem_s_w || is_div_rem_u_w){
        val dividend  = Mux(is_div_rem_s_w || is_div_rem_u_w,
                            Mux(is_div_rem_s_w && io.src_a(max_count-1.U), -io.src_a(31,0), io.src_a(31,0)),
                            Mux(is_div_rem_s && io.src_a(max_count-1.U), -io.src_a, io.src_a))

        val divisor   = Mux(is_div_rem_s_w || is_div_rem_u_w,
                            Mux(is_div_rem_s_w && io.src_b(max_count-1.U), -io.src_b(31,0), io.src_b(31,0)),
                            Mux(is_div_rem_s && io.src_b(max_count-1.U), -io.src_b, io.src_b))
        
        when(io.valid === 1.U) {
            r_ready    := 0.U
            r_counter  := max_count
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

    val quotient = WireInit(r_quotient)
    val inv_quotient = WireInit(-r_quotient)
    val dividend = WireInit(r_dividend)
    val inv_dividend = WireInit(-r_dividend)

    io.ready     := r_ready
    when(io.op === MUL){
        io.output.bits := result(XLEN-1,0)
        io.output.valid := 1.U
    }.elsewhen(io.op === MULH || io.op === MULHU || io.op === MULHSU){
        io.output.bits := result((2*XLEN)-1,XLEN)
        io.output.valid := 1.U
    }.elsewhen(io.op === DIV){
        io.output.bits := Mux(io.src_a(XLEN-1) =/= io.src_b(XLEN-1) & io.src_b.orR,-r_quotient, r_quotient)
    }.elsewhen(io.op === DIVU){
        io.output.bits := r_quotient
    }.elsewhen(io.op === REM){
        io.output.bits := Mux(io.src_a(XLEN-1),-r_dividend, r_dividend)
    }.elsewhen(io.op === REMU){
        io.output.bits := r_dividend
    }.elsewhen(io.op === MULW){
        io.output.bits := Cat(Fill(32, result(31)), result(31,0))
        io.output.valid := 1.U
    }.elsewhen(io.op === DIVW){
        io.output.bits := Mux(io.src_a(max_count-1.U) =/= io.src_b(max_count-1.U) & io.src_b(31,0).orR,
                             Cat(Fill(32, inv_quotient(31)), inv_quotient(31,0)), 
                             Cat(Fill(32, quotient(31)), quotient(31,0)))
    }.elsewhen(io.op === DIVUW){
        io.output.bits := Cat(Fill(32, quotient(31)), quotient(31,0))
    }.elsewhen(io.op === REMW){
        io.output.bits := Mux(io.src_a(max_count-1.U),
                             Cat(Fill(32, inv_dividend(31)), inv_dividend(31,0)), 
                             Cat(Fill(32, dividend(31)), dividend(31,0)))
    }.elsewhen(io.op === REMUW){
        io.output.bits := Cat(Fill(32, dividend(31)), dividend(31,0))
    }.otherwise{
        io.output.bits := 0.U
    }
}
