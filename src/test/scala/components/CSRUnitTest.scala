package nucleusrv.components
import chisel3._
import chisel3.util._
import chisel3.testers._
import chisel3.iotesters.PeekPokeTester

class CSRUnitTester(dut: CSRUnit) extends PeekPokeTester(dut) {
  
  println("=== CSR Unit Test ===")
  
  // Test 1: Read MHARTID (should return 0)
  println("Test 1: Reading MHARTID")
  poke(dut.io.csr_addr, 0xF14) // MHARTID
  poke(dut.io.csr_read, true)
  poke(dut.io.csr_write, false)
  poke(dut.io.csr_op, 1) // CSRRW
  step(1)
  val mhartid = peek(dut.io.csr_data)
  println(s"MHARTID = 0x${mhartid.toString(16)}")
  expect(dut.io.csr_data, 0) // Should be 0
  
  // Test 2: Write to MSCRATCH and read back
  println("Test 2: Write/Read MSCRATCH")
  poke(dut.io.csr_addr, 0x340) // MSCRATCH
  poke(dut.io.csr_write, true)
  poke(dut.io.rs1_data, 0xDEADBEEFL)
  poke(dut.io.csr_op, 1) // CSRRW
  step(1)
  
  // Read back MSCRATCH
  poke(dut.io.csr_write, false)
  poke(dut.io.csr_read, true)
  step(1)
  val mscratch = peek(dut.io.csr_data)
  println(s"MSCRATCH = 0x${mscratch.toString(16)}")
  expect(dut.io.csr_data, 0xDEADBEEFL)
  
  // Test 3: ECALL exception
  println("Test 3: ECALL exception")
  poke(dut.io.is_ecall, true)
  poke(dut.io.pc, 0x1000)
  step(1)
  expect(dut.io.exception, true)
  expect(dut.io.take_trap, true)
  poke(dut.io.is_ecall, false)
  step(1)
  
  // Test 4: EBREAK exception  
  println("Test 4: EBREAK exception")
  poke(dut.io.is_ebreak, true)
  poke(dut.io.pc, 0x2000)
  step(1)
  expect(dut.io.exception, true)
  expect(dut.io.take_trap, true)
  poke(dut.io.is_ebreak, false)
  step(1)
  
  // Test 5: MRET
  println("Test 5: MRET")
  poke(dut.io.is_mret, true)
  step(1)
  expect(dut.io.take_mret, true)
  
  println("=== All CSR tests passed! ===")
}

object CSRUnitTest {
  def main(args: Array[String]): Unit = {
    chisel3.iotesters.Driver(() => new CSRUnit) { c =>
      new CSRUnitTester(c)
    }
  }
}
