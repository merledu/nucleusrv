package nucleusrv.components.vu
import chisel3._
import chisel3.util._

class v_csr extends Module {
    val io = IO (new Bundle{
        val vtypei = Input (SInt (11.W ))             
        val vl = Input(SInt(32.W))
        val vset = Input(Bool())
        val ins = Input(UInt(32.W))
        val vl_out = Output(SInt(32.W))
        val vtype_out = Output(SInt(32.W))
        val vstart_out =Output(SInt(32.W))

})
// val vtype = RegInit("b00000000000000000000000000010000".U(32.W))
//     val vl =    RegInit("b00000000000000000000000000000100".U(32.W))
//     val vlenb = RegInit("b00000000000000000000000000010000".U(32.W))
//     val llll = vtype(2,0)
//     dontTouch(llll)
//     //update vtype csr through vsetvli instruction
//     when (opcode==="b1010111".U && io.instr(31)===0.B && io.instr(14,12)==="b111".U){
//         vtype := Cat(io.instr(8),"b00000000000000000000000".U,io.instr(27,20))  
//         vl := io.vl_in
//     }
//     //update vtype csr through vsetivli instruction
//     .elsewhen (opcode==="b1010111".U && io.instr(31,30)==="b11".U && io.instr(14,12)==="b111".U){
//         vtype := Cat(io.instr(8),"b00000000000000000000000".U,io.instr(27,20))  
//         vl := io.vl_in
//     }

//     // io.vlmul := vtype(2,0)
//     io.vsew := vtype(5,3)
//     io.mask := vtype(7)
//     io.tail := vtype(6)
//     io.vl_out := vl

    
                             

val vtypeReg = RegInit(0.S(32.W))
val vlReg = RegInit(0.S(32.W))
val vstart = RegInit(0.S(32.W))

when (io.vset === 1.B) {         
    vtypeReg := Cat(Fill(20, 0.U), io.vtypei).asSInt   //update 'vtype csr' with  vtype encoding, only when there is configuration setting instruction.
    vlReg := io.vl           //update 'vlReg' with 'io.vl_writeback', only when there is vsetvli instruction.
}

io.vl_out := vlReg
io.vtype_out := vtypeReg
io.vstart_out := vstart
}