package nucleusrv.components.vu
import chisel3._
import chisel3.util._

class v_csr extends Module {
    val io = IO (new Bundle{
        val vtypei = Input (SInt (11.W ))             
        val vl = Input(SInt(32.W))
        val vset = Input(Bool())
        val vl_out = Output(SInt(32.W))
        val vtype_out = Output(SInt(32.W))
        val vstart_out =Output(SInt(32.W))

})
                                 

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