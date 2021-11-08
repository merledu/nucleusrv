// input  wire             i_clk,  
//   input  wire             i_rst,
//   input  wire [WIDTH-1:0] i_mdu_rs1,
//   input  wire [WIDTH-1:0] i_mdu_rs2,
//   input  wire [2:0]       i_mdu_op,
//   input  wire             i_mdu_valid,
//   output wire             o_mdu_ready,
//   output wire [WIDTH-1:0] o_mdu_rd


//module up_counter(input clk, reset, output[3:0] counter

//THIS IS MULTIPLICATION AND DIVISION UNIT USING BLACKBOX
//MULTIPLIER FILE OF CHISEL ASSOCIATED WITH CORE IS Multiplier.scala
package components

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOM extends Bundle{
    val i_clk = Input(Bool())
    val i_rst = Input(Bool())
    val i_mdu_rs1 = Input(UInt(32.W))
    val i_mdu_rs2 = Input(UInt(32.W))
    val i_mdu_op = Input(UInt(3.W))
    val i_mdu_valid= Input(Bool())
    val o_mdu_ready= Output(Bool())
    val o_mdu_rd= Output(UInt(32.W))

}

class mdu extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOM)
    addResource("/mdu.v")
    
}

class MDU extends Module{

    val io = IO(new Bundle{
    val i_mdu_rs1 = Input(UInt(32.W))
    val i_mdu_rs2 = Input(UInt(32.W))
    val i_mdu_op = Input(UInt(3.W))
    val i_mdu_valid= Input(Bool())
    val o_mdu_ready= Output(Bool())
    val o_mdu_rd= Output(UInt(32.W))
    })
    
    val a = Module(new mdu)
    val i_clk = WireInit(clock.asUInt()(0))
    val i_rst = WireInit(clock.asUInt()(0))


    a.io.i_clk := ~i_clk
    a.io.i_rst := i_rst
    a.io.i_mdu_rs1 := io.i_mdu_rs1
    a.io.i_mdu_rs2 := io.i_mdu_rs2
    a.io.i_mdu_op := io.i_mdu_op
    a.io.i_mdu_valid := io.i_mdu_valid
    io.o_mdu_ready := a.io.o_mdu_ready 
    io.o_mdu_rd := a.io.o_mdu_rd

}