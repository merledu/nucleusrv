package nucleusrv.components
import chisel3._

object ALUOps {
    val AND = 0.U(4.W)
    val OR  = 1.U(4.W)
    val ADD = 2.U(4.W)
    val SUB = 3.U(4.W)
    val SLT = 4.U(4.W)
    val SLTU= 5.U(4.W)
    val SLL = 6.U(4.W)
    val SRL = 7.U(4.W)
    val SRA = 8.U(4.W)
    val XOR = 9.U(4.W)
}
