/* Created By Hamna Mohiuddin @hamnamohi as a Google Summer of Code 2024 Project.*/

package BabyKyber

import chisel3._
import chisel3.util._
import chisel3.experimental._
import chisel3.util.experimental._

class RequestIO extends Bundle {
    val addrRequest = Input(UInt(32.W))
    val dataRequest = Input(UInt(32.W))
    val activeByteLane= Input(UInt(4.W))
    val isWrite = Input(Bool())
}

class ResponseIO extends Bundle {
    val dataResponse: UInt = Input(UInt(32.W))
}