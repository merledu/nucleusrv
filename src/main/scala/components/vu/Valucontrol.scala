package nucleusrv.components.vu

import chisel3._
import chisel3.util._
 
class Alu_Control ( ) extends Module {
    val io = IO (new Bundle {
        val func3 = Input ( UInt (3.W ) )
        // val func7 = Input ( Bool () )
        val aluOp = Input ( UInt (3.W ) )
        // val V_inst = Input ( Bool() )
        val func6 = Input ( UInt (6.W) )                
        val aluc = Output ( UInt ( 9.W ) )
        // val out_V = Output ( Bool() )                    
})
// when (io.V_inst === 0.B) {
//     // R type
//     when (io.aluOp === 0.U) {
//         io.aluc := Cat("b00000".U, io.func7, io.func3)
//         io.out_V := 0.U

//     // I type
//     }.elsewhen (io.aluOp === 1.U) {
//         io.aluc := Cat("b000000".U, io.func3)
//         io.out_V := 0.U

//     // SB type
//     }.elsewhen (io.aluOp === 2.U) {
//         io.aluc := Cat("b0000".U ,1.U, 0.U, io.func3)
//         io.out_V := 0.U

//     // UJ type
//     }.elsewhen (io.aluOp === 3.U) {
//         io.aluc := "b000011111".U
//         io.out_V := 0.U

//     // Loads
//     }.elsewhen (io.aluOp === 4.U) {
//         io.aluc := "b000000000".U
//         io.out_V := 0.U

//     // S type
//     }.elsewhen (io.aluOp === 5.U) {
//         io.aluc := "b000000000".U
//         io.out_V := 0.U

//     // U type(lui)
//     }.elsewhen (io.aluOp === 6.U) {
//         io.aluc := "b000000000".U
//         io.out_V := 0.U

//     // U type(auipc)
//     }.elsewhen (io.aluOp === 7.U) {
//         io.aluc := "b000000000".U
//         io.out_V := 0.U

//     }.otherwise{
//         io.aluc := 0.U
//         io.out_V := 0.U
//     }
// }.else

    // when (io.V_inst === 1.B) {
    // vsetvli
    when (io.aluOp === 0.U) {
        io.aluc := Cat("b000000".U, io.func3)
        // io.out_V := 1.B 
    //opivi
    }.elsewhen (io.aluOp === 1.U) {
        io.aluc := Cat(io.func6, io.func3)
        // io.out_V := 1.B 
    }.elsewhen (io.aluOp === 2.U) {
        io.aluc := Cat(io.func6, io.func3)
        // io.out_V := 1.B 
    }.elsewhen (io.aluOp === 3.U) {
        io.aluc := Cat(io.func6, io.func3)
        // io.out_V := 1.B 
    }.otherwise {
        io.aluc := 0.U
        // io.out_V := 0.U
    }
}