package nucleusrv.components.vu

import chisel3._
import chisel3.util._
 
class Alu_Control ( ) extends Module {
    val io = IO (new Bundle {
        val func3 = Input ( UInt (3.W ) )
        val aluOp = Input ( UInt (3.W ) )
        val func6 = Input ( UInt (6.W) )                
        val aluc = Output ( UInt ( 9.W ) )
})

    when (io.aluOp === 0.U) {
        io.aluc := Cat("b000000".U, io.func3)
    //opivi
    }.elsewhen (io.aluOp === 1.U) {
        io.aluc := Cat(io.func6, io.func3)
    }.elsewhen (io.aluOp === 2.U) {
        io.aluc := Cat(io.func6, io.func3)
    }.elsewhen (io.aluOp === 3.U) {
        io.aluc := Cat(io.func6, io.func3)
    }.otherwise {
        io.aluc := 0.U
    }
}