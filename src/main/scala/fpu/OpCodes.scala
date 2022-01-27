package fpu
import chisel3._


/*
   * 0000111 - LOAD FP
   * 0100111 - STORE FP
   * 1010011 - OP FP
 */


trait OpCodes {
  val LOAD = "b0000111".U
  val STORE = "b0100111".U
}
