package nucleusrv.components.vu

import chisel3._ 
import chisel3.util._ 


object ALUOP1 {
   
    val V_ADDI = "b000000011".U
    val V_ADD = "b000000000".U
    val Vaddvx = "b000000100".U
    val VMVx = "b010111100".U
    val VMVvv = "b010111000".U
    val VMVvi = 187.U
    val Vsubvv  = 184.U 
    val Vsubvx = "b000010100".U 
    val Vrsubvx = "b000011100".U
    val Vrsubvi = "b000011011".U
    val Vminuvv = "b000100000".U
    val Vminuvx = "b000100100".U
    val Vminvv = "b000101000".U
    val Vminvx =  "b000101100".U
    val Vmaxuvv = "b000110000".U
    val Vmaxuvx = "b000110100".U
    val Vmaxvv  = "b000111000".U
    val Vmaxvx = "b000111100".U
    val Vandvv = "b001001000".U
    val Vandvx = "b001001100".U
    val Vandvi = "b001001011".U
    val Vorvv = "b001010000".U
    val Vorvx = "b001010100".U
    val Vorvi = "b00101011".U
    val Vxorvv = "b001011000".U
    val Vxorvx = "b001011100".U
    val Vxorvi = "b001011011".U

  
	}

trait Config{
    val WLEN = 32
    val ALUOP_SIG_LEN = 9
}

import ALUOP1._

class ALUIO extends Bundle with Config {
    val in_A = Input(SInt(WLEN.W))
    val in_B = Input(SInt(WLEN.W))
    val vs1 = Input(SInt(128.W))
    val vs2 = Input(SInt(128.W))
    val vs0 = Input(SInt(128.W))
    val vd = Input (SInt(128.W))
    val vl = Input(UInt(32.W))
    val vstart = Input(UInt(32.W))
    val vma =Input(UInt(1.W)) //vtype
    val vta = Input(UInt(1.W))
    val vm =Input(UInt(1.W)) //umasked=1  , masked = 0
    val vd_addr = Input(UInt(5.W))
    val aluc = Input(UInt(ALUOP_SIG_LEN.W))
    val sew = Input(UInt(3.W))
	val v_ins = Input(Bool())
	val v_output = Output(SInt(128.W))
    val vs0_o = Output(SInt(128.W))
    val vs3 = Output(SInt(128.W))
}

class VALU extends Module with Config {
    val io = IO(new ALUIO)

val sew_8_a = VecInit((0 until 16).map(i => io.vs1(8*i+7, 8*i).asSInt))
val sew_8_b = VecInit((0 until 16).map(i => io.vs2(8*i+7, 8*i).asSInt))
val sew_16_a = VecInit((0 until 8).map(i => io.vs1(16*i+15, 16*i).asSInt))
val sew_16_b = VecInit((0 until 8).map(i => io.vs2(16*i+15, 16*i).asSInt))
val sew_32_a = VecInit((0 until 4).map(i => io.vs1(32*i+31, 32*i).asSInt))
val sew_32_b = VecInit((0 until 4).map(i => io.vs2(32*i+31, 32*i).asSInt))
val sew_64_a = VecInit((0 until 2).map(i => io.vs1(64*i+63, 64*i).asSInt))
val sew_64_b = VecInit((0 until 2).map(i => io.vs2(64*i+63, 64*i).asSInt))

val out8 = VecInit(Seq.fill(16)(0.S(8.W)))
val out16 = VecInit(Seq.fill(8)(0.S(16.W)))
val out32 = VecInit(Seq.fill(4)(0.S(32.W)))
val out64 = VecInit(Seq.fill(2)(0.S(64.W)))

val sew_8_vd = VecInit((0 until 16).map(i => io.vd(8*i+7, 8*i).asSInt))
val sew_16_vd = VecInit((0 until 8).map(i => io.vd(16*i+15, 16*i).asSInt))
val sew_32_vd = VecInit((0 until 4).map(i => io.vd(32*i+31, 32*i).asSInt))
val sew_64_vd = VecInit((0 until 2).map(i => io.vd(64*i+63, 64*i).asSInt))
  

def VectorOp_vv( in_A: Vec[SInt], in_B: Vec[SInt], vlmax:UInt, vd:Vec[SInt]) :SInt = {
  
    val out = vd.zipWithIndex.map{ case(elem,i) => 
       Mux(i.U < io.vstart,elem,
       Mux(i.U >= io.vstart && i.U < io.vl,
                            Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 0.U, elem,
                                Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 1.U, (-1).S,MuxLookup(
            io.aluc,
            0.S, // Default case (no operation)
            Seq(
                V_ADD -> (in_A(i) + in_B(i)).asSInt,
                Vsubvv  -> (in_A(i) - in_B(i)).asSInt,
                Vandvv -> (in_A(i) & in_B(i)).asSInt,
                Vorvv -> (in_A(i) | in_B(i)).asSInt,
                Vxorvv -> (in_A(i) ^ in_B(i)).asSInt,
                Vminuvv -> Mux(in_B(i).asUInt <= in_A(i).asUInt, in_B(i).asSInt, in_A(i).asSInt),
                Vminvv -> Mux(in_B(i) <= in_A(i), in_B(i).asSInt, in_A(i).asSInt)
            )
        ))
                            ), 
        Mux(io.vta === 0.U && i.U >= io.vl && i.U < vlmax, elem, (-1).S)
        ))
        }
      Cat(out.reverse).asSInt
}

def VectorOp_vi( in_A: Vec[SInt], imm: SInt, vlmax:UInt, vd:Vec[SInt]) :SInt = {
  
    val out = vd.zipWithIndex.map{ case(elem,i) => 
       Mux(i.U < io.vstart,elem,
       Mux(i.U >= io.vstart && i.U < io.vl,
                            Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 0.U, elem,
                                Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 1.U, (-1).S,MuxLookup(
            io.aluc,
            0.S, // Default case (no operation)
            Seq(
                V_ADDI  -> (in_A(i) + imm).asSInt,
                Vrsubvi -> ( imm-in_A(i)).asSInt,
                Vandvi -> (in_A(i) & imm).asSInt,
                Vorvi -> (in_A(i) | imm).asSInt,
                Vxorvi -> (in_A(i) ^ imm).asSInt
                
            )
        ))
                            ), 
        Mux(io.vta === 0.U && i.U >= io.vl && i.U < vlmax, elem, (-1).S)
        ))
        }
      Cat(out.reverse).asSInt
}
def VectorOp_vx( in_A: Vec[SInt], imm: SInt, vlmax:UInt, vd:Vec[SInt]) :SInt = {
  
    val out = vd.zipWithIndex.map{ case(elem,i) => 
       Mux(i.U < io.vstart,elem,
       Mux(i.U >= io.vstart && i.U < io.vl,
                            Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 0.U, elem,
                                Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 1.U, (-1).S,MuxLookup(
            io.aluc,
            0.S, // Default case (no operation)
            Seq(
                Vaddvx  -> (in_A(i) + imm).asSInt,
                Vsubvx -> ( in_A(i) - imm).asSInt,
                Vrsubvx -> ( imm-in_A(i)).asSInt,
                Vandvx -> (in_A(i) & imm).asSInt,
                Vorvx -> (in_A(i) | imm).asSInt,
                Vxorvx -> (in_A(i) ^ imm).asSInt,
                Vminuvx -> Mux(imm.asUInt <= in_A(i).asUInt, imm.asSInt, in_A(i).asSInt),
                Vminvx -> Mux(imm <= in_A(i), imm.asSInt, in_A(i).asSInt),
                Vmaxuvx -> Mux(imm.asUInt >= in_A(i).asUInt, imm.asSInt, in_A(i).asSInt),
                Vmaxvx -> Mux(imm >= in_A(i), imm.asSInt, in_A(i).asSInt)
            )
        ))
                            ), 
        Mux(io.vta === 0.U && i.U > io.vl && i.U < vlmax, elem, (-1).S)
        ))
        }
      Cat(out.reverse).asSInt
}

def Vectormove_vxvi( imm: SInt, vlmax:UInt, vd:Vec[SInt]) :SInt = {
  val out = vd.zipWithIndex.map{ case(elem,i) => 
       Mux(i.U < io.vstart,elem.asUInt,
       Mux(i.U >= io.vstart && i.U < io.vl,
                            Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 0.U, elem.asUInt,
                                Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 1.U, "b1111111111111111111111111111111111111111111111111111111111111111".U,(imm).asUInt)
                            ), 
        Mux(io.vta === 0.U && i.U > io.vl && i.U < vlmax, elem.asUInt, "b1111111111111111111111111111111111111111111111111111111111111111".U)
        ))
        }
      Cat(out.reverse).asSInt
}
def Vectormove_vv( in_A: Vec[SInt], vlmax:UInt, vd:Vec[SInt]) :SInt = {
  val out = vd.zipWithIndex.map{ case(elem,i) => 
       Mux(i.U < io.vstart,elem.asUInt,
       Mux(i.U >= io.vstart && i.U < io.vl,
                            Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 0.U, elem.asUInt,
                                Mux(io.vm === 0.U && io.vs0(i) === 0.U && io.vma === 1.U, "b1111111111111111111111111111111111111111111111111111111111111111".U,(in_A(i)).asUInt)
                            ), 
        Mux(io.vta === 0.U && i.U > io.vl && i.U < vlmax, elem.asUInt, "b1111111111111111111111111111111111111111111111111111111111111111".U)
        ))
        }
      Cat(out.reverse).asSInt
}



io.v_output := 0.S

//Opivv
    	when (io.sew === "b011".U  && io.aluc(2,0) === "b000".U){  //sew = 64
            io.v_output := VectorOp_vv(sew_64_a,sew_64_b,2.U,sew_64_vd)	        
        }.elsewhen (io.sew === "b010".U  && io.aluc(2,0) === "b000".U){ // sew = 32
            io.v_output := VectorOp_vv(sew_32_a,sew_32_b,4.U,sew_32_vd)
        }.elsewhen(io.sew === "b001".U  && io.aluc(2,0) === "b000".U){ //sew = 16
            io.v_output := VectorOp_vv(sew_16_a,sew_16_b,8.U,sew_16_vd)
	    }.elsewhen(io.sew === "b000".U  && io.aluc(2,0) === "b000".U){ //sew = 8
            io.v_output := VectorOp_vv(sew_8_a,sew_8_b,16.U,sew_8_vd)

   //Opivi
        }.elsewhen(io.sew === "b011".U && io.aluc(2,0) === "b011".U){
            val imm = Cat(0.S(32.W), io.in_B).asSInt
        io.v_output := VectorOp_vi(sew_64_b,imm,2.U,sew_64_vd)
        }.elsewhen(io.sew === "b010".U && io.aluc(2,0) === "b011".U){
            val imm = io.in_B(31,0).asSInt        
            io.v_output := VectorOp_vi(sew_32_b,imm,4.U,sew_32_vd)  
        }.elsewhen(io.sew === "b000".U && io.aluc(2,0) === "b011".U){
            val imm = io.in_B(7,0).asSInt
            io.v_output := VectorOp_vi(sew_8_b,imm,16.U,sew_8_vd)
        }.elsewhen (io.sew === "b001".U && io.aluc(2,0) === "b011".U){
            val imm = io.in_B(15,0).asSInt
            io.v_output := VectorOp_vi(sew_16_b,imm,8.U,sew_16_vd)
    	}  
        //opivx
        .elsewhen(io.sew === "b011".U && io.aluc(2,0) === "b100".U){
		    val imm = Cat(0.S(32.W), io.in_A).asSInt
            io.v_output := VectorOp_vx(sew_64_b,imm,2.U,sew_64_vd)
        }.elsewhen(io.sew === "b010".U && io.aluc(2,0) === "b100".U){
           val imm = io.in_A(31,0).asSInt
            io.v_output := VectorOp_vx(sew_32_b,imm,4.U,sew_32_vd)
        }.elsewhen(io.sew === "b000".U && io.aluc(2,0) === "b100".U){
	    	val imm = io.in_A(7,0).asSInt
            io.v_output := VectorOp_vx(sew_8_b,imm,16.U,sew_8_vd)
        }.elsewhen (io.sew === "b001".U && io.aluc(2,0) === "b100".U){
		    val imm = io.in_A(15,0).asSInt
            io.v_output := VectorOp_vx(sew_16_b,imm,8.U,sew_16_vd)
	    }  
    //vector move vx instruction
        .elsewhen (io.aluc === VMVx){
            when(io.vd_addr === 0.U){
                io.v_output := Cat((0.S(96.W)),io.in_A).asSInt
  	        }.otherwise{
                when (io.sew === "b011".U){
                    val imm = Cat(0.S(32.W), io.in_A).asSInt
                    io.v_output := Vectormove_vxvi(imm,2.U,sew_64_vd)
                }.elsewhen(io.sew === "b010".U ){
                    val imm = io.in_A(31,0).asSInt
                    io.v_output := Vectormove_vxvi(imm,4.U,sew_32_vd)
                }.elsewhen (io.sew === "b001".U){
		            val imm = io.in_A(15,0).asSInt
    	            io.v_output := Vectormove_vxvi(imm,8.U,sew_16_vd)
                }.elsewhen(io.sew === "b000".U ){
                    val imm = io.in_A(7,0).asSInt
                    io.v_output := Vectormove_vxvi(imm,16.U,sew_8_vd)
                } 
            }
        }//vmv vx end
    
    //vector move vi instruction
        .elsewhen (io.aluc === VMVvi){
            when(io.vd_addr === 0.U){
                io.v_output := Cat((0.S(96.W)),io.in_B).asSInt
  	        }.otherwise{
                when (io.sew === "b011".U){
                    val imm = Cat(0.S(32.W), io.in_B).asSInt
                    io.v_output := Vectormove_vxvi(imm,2.U,sew_64_vd)
    
                }.elsewhen(io.sew === "b010".U ){
                    val imm = io.in_B(31,0).asSInt
                    io.v_output := Vectormove_vxvi(imm,4.U,sew_32_vd)
                }.elsewhen(io.sew === "b000".U ){
		            val imm = io.in_B(7,0).asSInt
    	            io.v_output := Vectormove_vxvi(imm,16.U,sew_8_vd)
	            }.elsewhen (io.sew === "b001".U){
		            val imm = io.in_B(15,0).asSInt
                    io.v_output := Vectormove_vxvi(imm,8.U,sew_16_vd)      
                }
            }
        }
    //vmv vi end
           
    //vector move vv instruction
        .elsewhen (io.aluc === VMVvv){
            when(io.vd_addr === 0.U){
                io.v_output := io.vs1
  	        }.otherwise{
            when (io.sew === "b011".U){
        io.v_output := Vectormove_vv(sew_64_a,2.U,sew_64_vd)
    
        }.elsewhen(io.sew === "b010".U ){
         io.v_output := Vectormove_vv(sew_32_a,4.U,sew_32_vd)
	  
        }.elsewhen(io.sew === "b000".U ){
			    io.v_output := Vectormove_vv(sew_8_a,16.U,sew_8_vd)
	      }.elsewhen (io.sew === "b001".U){
          io.v_output := Vectormove_vv(sew_16_a,8.U,sew_16_vd)
        }
        }
    }//vmv vv end

    io.vs3 := io.vd
    io.vs0_o := io.vs0
}