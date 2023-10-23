package nucleusrv.components.vu
import chisel3._
import chisel3.util._
import chisel3.experimental._

class configure extends Module {
  val io = IO (new Bundle {
    val zimm = Input(UInt(32.W))
    val rs1= Input(UInt(5.W))
    val rd= Input(UInt(5.W))
    val rs1_readdata =Input(SInt(32.W))
    val current_vl =Input(SInt(32.W))
    val lmul = Output(UInt(32.W))
    val vl = Output(SInt(32.W))
    val rd_out = Output(UInt(5.W))
    val avl_o = Output(SInt(32.W))
    val valmax_o = Output(SInt(32.W))
    // val zimm_out = Output(UInt(11.W))
    })

    val vlmul = io.zimm(2,0)
    val vsew =io.zimm(5,3)
    val valmax = WireInit(0.S)
    val avl = WireInit(0.S)
    io.lmul := 1.U
    // io.zimm_out := io.zimm(10, 0)



    when (vlmul === "b101".U){  //lmul=1/8   

        when (vsew === "b000".U){ //sew=8
            valmax :=2.S
        }.elsewhen(vsew === "b001".U){
            valmax :=1.S
        }.elsewhen(vsew === "b010".U){
            valmax :=(1.S >> 2)
        // }.elsewhen(vsew ==="b011".U){
        //     valmax :=1/4.U
        }


    }.elsewhen(vlmul === "b110".U){ //lmul=1/4

        when (vsew === "b000".U){ //sew=8
            valmax :=4.S
        }.elsewhen(vsew === "b001".U){ //sew=16
            valmax :=2.S
        }.elsewhen(vsew === "b010".U){ //sew=32
            valmax :=1.S
        // }.elsewhen(vsew ==="b011".U){ //sew=64
        //     valmax :=1/2.U
        }

    }.elsewhen(vlmul === "b111".U){ //lmul=1/2

        when (vsew === "b000".U){ //sew=8
            valmax :=8.S
        }.elsewhen(vsew === "b001".U){ //sew=16
            valmax :=4.S
        }.elsewhen(vsew === "b010".U){ //sew=32
            valmax :=2.S
        }.elsewhen(vsew ==="b011".U){ //sew=64
            valmax :=1.S
        }
    }.otherwise{ //lmul >= 1
        val y0 = !vlmul(1) && !vlmul(0) || vlmul(2)
        val y1 = !vlmul(2) && !vlmul(1) && vlmul(0)
        val y2 = !vlmul(2) && vlmul(1) && !vlmul(0)
        val y3 = !vlmul(2) && vlmul(1) && vlmul(0)
        io.lmul := Cat(y3, y2, y1, y0)
        
        when(vsew === "b000".U){  //sew=8
           valmax:= Cat(io.lmul, 0.U(4.W)).asSInt
        }.elsewhen(vsew === "b001".U){ //sew=16
            valmax:= Cat(io.lmul, 0.U(3.W)).asSInt
        }.elsewhen(vsew === "b010".U){ //sew=32
            valmax:= Cat(io.lmul, 0.U(2.W)).asSInt
        }.elsewhen(vsew ==="b011".U){ //sew=64
            valmax:= Cat(io.lmul, 0.U(1.W)).asSInt
        }
    }

avl:= Mux(io.rs1 =/= "b00000".U, io.rs1_readdata,
    Mux(io.rd =/= "b00000".U && io.rs1 === "b00000".U, valmax,
    Mux(io.rs1 === 0.U && io.rd === 0.U, io.current_vl, 0.S)))

    when (avl <= valmax){
        io.vl:=avl
    }.otherwise{
        io.vl:=valmax
    }
        
io.rd_out:= io.rd
io.valmax_o := valmax
io.avl_o := avl
// io.zimm_o := io.zimm
}