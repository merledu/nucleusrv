// Created by @Talha-Ahmed-1

package nucleusrv.csr

import chisel3._
import chisel3.util._

object AddressMap {
    // Machine Mode CSRs
    val MARCHID          = "hF12".U
    val MHARTID          = "hf14".U
    val MSTATUS          = "h300".U
    val MISA             = "h301".U
    val MIE              = "h304".U
    val MTVEC            = "h305".U
    val MSCRATCH         = "h340".U
    val MEPC             = "h341".U
    val MCAUSE           = "h342".U
    val MTVAL            = "h343".U
    val MIP              = "h344".U

    // Floating Point CSRs
    val FFLAGS           = "h001".U
    val FRM              = "h002".U
    val FCSR             = "h003".U

    // Counters
    val MCYCLE           = "hB00".U
    val MCYCLEH          = "hB80".U
    val MINSTRET         = "hB02".U
    val MINSTRETH        = "hB82".U
    val MCOUNTINHIBIT    = "h320".U
    
    // Time CSRs
    val TIME             = "hC01".U
    val TIMEH            = "hC81".U
}
