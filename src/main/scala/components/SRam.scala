// input  clk0; // clock
//   input   csb0; // active low chip select
//   input  web0; // active low write control
//   input [ADDR_WIDTH-1:0]  addr0;
//   input [DATA_WIDTH-1:0]  din0;
//   output [DATA_WIDTH-1:0] dout0;

package components

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOR extends Bundle{
    val clk0 = Input(Bool())
    val csb0 = Input(Bool())
    val web0 = Input(Bool())
    val addr0 = Input(UInt(7.W))
    val din0 = Input(UInt(32.W))
    val dout0 = Output(UInt(32.W))
    // clock    input(bool)
    // reset    == = = = = 
}

class sram extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOR)
    addResource("/sram.v")
    
}

class SRam extends Module{

    val io = IO(new Bundle{
        val clk0 = Input(Bool())
        val csb0 = Input(Bool())
        val web0 = Input(Bool())
        val addr0 = Input(UInt(7.W))
        val din0 = Input(UInt(32.W))
        val dout0 = Output(UInt(32.W))

    })
    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    val a = Module(new sram)
    val clk0 = WireInit(clock.asUInt()(0))
    a.io.clk0 := ~clk0
    a.io.csb0 := io.csb0
    a.io.web0 := io.web0
    a.io.addr0 := io.addr0
    a.io.din0 := io.din0
    // val rst = WireInit(reset.asUInt()(0))
    // a.io.reset := rst
    io.dout0 := a.io.dout0
    //a.io <> io

//     val a = Module(new sram_32_128_freepdk45)

//   val clk = WireInit(clock.asUInt()(0))

//   a.io.clk0 := ~clk
//   a.io.csb0 := io.csb0
//   a.io.web0 := io.web0
//   a.io.addr0 := io.addr0
//   a.io.din0 := io.din0
//   io.dout0 := a.io.dout0

}