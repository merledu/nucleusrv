package nucleusrv.components

import chisel3._
import chisel3.tester._
import org.scalatest.FreeSpec

class FSMTest extends FreeSpec with ChiselScalatestTester {
  "FSM Module Test" in {
    test(new FSM) { dut =>
      // Default 0
      dut.io.cpuRequest.poke(false.B)
      dut.io.cacheHit.poke(false.B)
      dut.io.dirtyBit.poke(false.B)
      dut.io.memoryReady.poke(false.B)
      
      dut.io.setTag.expect(false.B)
      dut.io.setValid.expect(false.B)
      dut.io.setDirty.expect(false.B)
      dut.io.writeBack.expect(false.B)
      dut.io.memoryRead.expect(false.B)
      dut.io.cacheReady.expect(false.B)
      dut.io.miss.expect(false.B)

      // Idle to CompareTag
      dut.io.cpuRequest.poke(true.B)
      dut.clock.step(10)
      dut.io.cacheReady.expect(false.B)
      
      // Cache hit
      dut.io.cacheHit.poke(true.B)
      dut.clock.step(10)
      dut.io.cacheReady.expect(true.B)
      dut.io.setValid.expect(true.B)
      dut.io.setTag.expect(true.B)
      dut.io.miss.expect(false.B)

      // Cache miss (dirty bit set)
      dut.io.cacheHit.poke(false.B)
      dut.io.dirtyBit.poke(true.B)
      dut.clock.step(10)
      dut.io.miss.expect(true.B)
      dut.io.writeBack.expect(true.B)

      // Memory ready for write-back
      dut.io.memoryReady.poke(true.B)
      dut.clock.step(10)
      dut.io.memoryRead.expect(true.B)

      // CompareTag
      dut.clock.step(10)
      dut.io.setTag.expect(false.B)
      dut.io.setValid.expect(false.B)
      dut.io.cacheReady.expect(false.B)
    }
  }
}
