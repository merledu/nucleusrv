package nucleusrv.components

import chisel3._
import chisel3.util._

object FP_OP {
  val flw = "0000111"
  val fsw = "0100111"
  val fmadd_s = "1000011"
  val fmsub_s = "1000111"
  val fnmsub_s = "1001011"
  val fnmadd_s = "1001111"
  val r_type = "1010011"
}

object FBitPats {
  val flw = BitPat("b" + ("?" * 25) + "0000111")
  val fsw = BitPat("b" + ("?" * 25) + "0100111")
  val fmadd_s = BitPat("b" + ("?" * 25) + "1000011")
  val fmsub_s = BitPat("b" + ("?" * 25) + "1000111")
  val fnmsub_s = BitPat("b" + ("?" * 25) + "1001011")
  val fnmadd_s = BitPat("b" + ("?" * 25) + "1001111")
  val fadd_s = BitPat("b" + ("0" * 7) + ("?" * 18) + "1010011")
  val fsub_s = BitPat("b" + "0000100" + ("?" * 18) + "1010011")
  val fmul_s = BitPat("b" + "0001000" + ("?" * 18) + "1010011")
  val fdiv_s = BitPat("b" + "0001100" + ("?" * 18) + "1010011")
  val fsqrt_s = BitPat("b" + "0101100" + ("?" * 18) + "1010011")
  val fsgnj_s = BitPat("b" + "0010000" + ("?" * 10) + "000" + ("?" * 5) + "1010011")
  val fsgnjn_s = BitPat("b" + "0010000" + ("?" * 10) + "001" + ("?" * 5) + "1010011")
  val fsgnjx_s = BitPat("b" + "0010000" + ("?" * 10) + "010" + ("?" * 5) + "1010011")
  val fmin_s = BitPat("b" + "0010100" + ("?" * 10) + "000" + ("?" * 5) + "1010011")
  val fmax_s = BitPat("b" + "0010100" + ("?" * 10) + "001" + ("?" * 5) + "1010011")
  val fcvt_w_s = BitPat("b" + "1100000" + ("0" * 5) + ("?" * 13) + "1010011")
  val fcvt_wu_s = BitPat("b" + "1100000" + "00001" + ("?" * 13) + "1010011")
  val fmv_x_w = BitPat("b" + "1110000" + ("?" * 10) + "000" + ("?" * 5) + "1010011")
  val feq_s = BitPat("b" + "1010000" + ("?" * 10) + "010" + ("?" * 5) + "1010011")
  val flt_s = BitPat("b" + "1010000" + ("?" * 10) + "001" + ("?" * 5) + "1010011")
  val fle_s = BitPat("b" + "1010000" + ("?" * 10) + "000" + ("?" * 5) + "1010011")
  val fclass_s = BitPat("b" + "1110000" + ("?" * 10) + "001" + ("?" * 5) + "1010011")
  val fcvt_s_w = BitPat("b" + "1101000" + ("0" * 5) + ("?" * 13) + "1010011")
  val fcvt_s_wu = BitPat("b" + "1101000" + "00001" + ("?" * 13) + "1010011")
  val fmv_w_x = BitPat("b" + "1111000" + ("?" * 10) + "000" + ("?" * 5) + "1010011")
}

object FCONSTS {
  val canon_nan = "h7FC00000".U
  val neg_zero = "h80000000".U
  val pos_zero = "h00000000".U
  val pos_inf = "h7F800000".U
  val neg_inf = "hFF800000".U
}
