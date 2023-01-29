package nucleusrv.csr

import chisel3._
import chisel3.util._

object AddressMap {
    // Machine trap setup
    val MISA             = "h301".U
    val MHARTID          = "hf14".U
}