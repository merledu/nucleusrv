
package nucleusrv.components
import chisel3._

object ALUOps {
  val ALU_ADD = 2.asUInt(4.W)
  val ALU_SUB = 6.asUInt(4.W)
  val ALU_AND = 0.asUInt(4.W)
  val ALU_OR = 1.asUInt(4.W)
  val ALU_XOR = 9.asUInt(4.W)
  // val ALU_SLL = 3.asUInt(4.W)
  // val ALU_SRL = 4.asUInt(4.W)
  // val ALU_SRA = 5.asUInt(4.W)
  // val ALU_SLT = 9.asUInt(4.W)
  // val ALU_SLTU = 10.asUInt(4.W)
  // val ALU_COPY1 = 11.asUInt(4.W)
  // val ALU_X = 0.asUInt(4.W)
}
