package nucleusrv.csr

import chisel3._
import chisel3.util._

object AddressMap {
    // Machine trap setup
    val MISA             = "h301".U
    val MHARTID          = "hf14".U
    val MSTATUS          = "h300".U
    val MTVEC            = "h305".U
    val MIE              = "h304".U
    val MCAUSE           = "h342".U
    val MEPC             = "h341".U
    val FFLAGS           = "h001".U
    val FRM              = "h002".U
    val FCSR             = "h003".U
}