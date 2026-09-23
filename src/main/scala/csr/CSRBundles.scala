// Created by @Talha-Ahmed-1

package nucleusrv.csr

import chisel3._
import chisel3.util._

class MISA(XLEN: Int) extends Bundle{
    val i_value = Input(UInt(XLEN.W))
}

class MARCHID(XLEN: Int) extends Bundle{
    val i_value = Input(UInt(XLEN.W))
}

class MHARTID(XLEN: Int) extends Bundle{
    val i_value = Input(UInt(XLEN.W))
}

class MINSTRET extends Bundle{
    val i_instr_retired = Input(Bool())
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

class CSR_IO(XLEN: Int) extends Bundle{
    val i_opr  = Input(UInt(2.W))
    val o_data = Output(UInt(XLEN.W))
    val i_data = Input(UInt(XLEN.W))
    val i_addr = Input(UInt(XLEN.W))
    val i_w_en = Input(Bool())
}

class CSRRegFileIO(XLEN: Int) extends Bundle{
    val MISA    = new MISA(XLEN)
    val MHARTID = new MHARTID(XLEN)
    val MARCHID = new MARCHID(XLEN)
    val CSR     = new CSR_IO(XLEN)
    val FCSR    = new FCSR()
    val MINSTRET = new MINSTRET()

    val mtvec_val = Output(UInt(XLEN.W))
    val mepc_val  = Output(UInt(XLEN.W))
    val medeleg_val = Output(UInt(XLEN.W))
    val mideleg_val = Output(UInt(XLEN.W))
    val misa_val    = Output(UInt(XLEN.W))
}
