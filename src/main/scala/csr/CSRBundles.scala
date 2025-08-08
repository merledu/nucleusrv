package nucleusrv.csr

import chisel3._
import chisel3.util._

class MISA extends Bundle{
    val i_value = Input(UInt(32.W))
}

class MHARTID extends Bundle{
    val i_value = Input(UInt(32.W))
}

class FCSR extends Bundle{
    val except = Input(Vec(5, Bool()))

    val nx  = Output(Bool())
    val uf  = Output(Bool())
    val of  = Output(Bool())
    val dz  = Output(Bool())
    val nv  = Output(Bool())
    val frm = Output(UInt(3.W))
}



class CSR_IO extends Bundle{
    val i_opr  = Input(UInt(2.W))
    val o_data = Output(UInt(32.W))
    val i_data = Input(UInt(32.W))
    val i_addr = Input(UInt(12.W))
    val i_w_en = Input(Bool())
}

class CSRRegFileIO extends Bundle{
    val MISA    = new MISA()
    val MHARTID = new MHARTID()
    val CSR     = new CSR_IO()
    val FCSR    = new FCSR()
}
