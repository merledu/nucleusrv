package nucleusrv.components.vu

import chisel3._
import chisel3.util._
import chisel3.experimental.ChiselEnum
class controldec extends Module {
    val io = IO (new Bundle {
        val Instruction= Input(UInt(32.W))
        val RegWrite = Output(Bool())
        val opBsel = Output(Bool())
        val Ex_sel = Output(UInt(4.W))
        val aluop = Output(UInt(5.W))
        val vset = Output(Bool())
        val v_load = Output (UInt(4.W))
        val v_ins =Output(Bool())
        val RegRead = Output(Bool())
    })
    io.RegWrite := 0.B
    io.opBsel := 0.B
    io.Ex_sel := 0.U
    io.aluop := 0.U
    io.vset := 0.B
    io.v_load :=0.B
    io.v_ins := 0.B
    io.RegRead := 0.B

    val configtype = io.Instruction(31,30)
    val opcode = io.Instruction(6, 0)
    val func3 = io.Instruction(14,12)

    switch (opcode){
        is ("b1010111".U){ //vector operations
            
            io.v_ins := 1.B
            when (func3 ==="b111".U && (configtype ==="b00".U || configtype ==="b01".U )){ // vsetvli
                io.RegWrite:=1.B
                io.opBsel:=1.B
                io.Ex_sel:=3.U
                io.vset := 1.B
            }.elsewhen(func3 ==="b111".U && configtype ==="b10".U){ // vsetivli
                io.RegWrite:=1.B
                io.aluop:="b00001".U
                io.opBsel:=1.B
                io.Ex_sel:=3.U
                io.vset := 1.B
            }.elsewhen(func3 ==="b111".U && configtype ==="b11".U){ //vsetvl
                io.RegWrite:=1.B
                io.Ex_sel:=3.U
                io.vset := 1.B
            }.elsewhen (func3 === "b000".U) {//vector-vector
                io.RegWrite:=1.B
                io.aluop:=2.U
                io.Ex_sel:=4.U
                io.v_ins := 1.U
                io.RegRead := 1.B
            }.elsewhen (func3 === "b100".U) {//vector-scalar
                io.RegWrite:=1.B
                io.aluop:=3.U
                io.Ex_sel:=4.U
                io.RegRead := 1.B
            }.elsewhen (func3 === "b011".U) {//vector-immediate
                io.RegWrite:=1.B
                io.aluop:=1.U
                io.opBsel:=1.B
                io.Ex_sel:=4.U
                io.v_ins := 1.B
                io.RegRead := 1.B
            }
        }
    }
}
