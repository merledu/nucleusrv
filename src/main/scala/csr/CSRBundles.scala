package nucleusrv.csr

import chisel3._
import chisel3.util._

class MISA extends Bundle{
    val i_value = Input(UInt(32.W))
}

class CSR_IO extends Bundle{
    val i_opr  = Input(UInt(2.W))
    val o_data = Output(UInt(32.W))
    val i_data = Input(UInt(32.W))
    val i_addr = Input(UInt(12.W))
    val i_w_en = Input(Bool())
}

class CSRRegFileIO extends Bundle{
    val MISA = new MISA()
    val CSR  = new CSR_IO()
}