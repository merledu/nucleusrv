package nucleusrv.components

import chisel3._
import chisel3.experimental.BundleLiterals._
import chiseltest._
import chiseltest.simulator.WriteVcdAnnotation
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

/**
 * Unit Tester for the Bus.scala module
 *
 * This test simulates the behavior of cores and memory
 * at the bus boundaries.
 */
class BusTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {

  behavior of "Bus"

  // Helper function to initialize all bus ports
  def initPorts(dut: Bus, numCores: Int) = {
    dut.io.memReq.ready.poke(false.B)
    dut.io.memRsp.valid.poke(false.B)
    dut.io.memRsp.bits.dataResponse.poke(0.U)

    for (i <- 0 until numCores) {
      dut.io.coreReqs(i).valid.poke(false.B)
      dut.io.coreReqs(i).bits.addrRequest.poke(0.U)
      dut.io.coreRsps(i).ready.poke(false.B)
    }
  }

  it should "pass a request from Core 0 and route response back" in {
    val numCores = 2
    test(new Bus(numCores))
        .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
      // 1. Initialize
      initPorts(dut, numCores)
      dut.io.coreRsps(0).ready.poke(true.B) // Core 0 is ready for response

      // 2. Core 0 sends request
      dut.io.coreReqs(0).valid.poke(true.B)
      dut.io.coreReqs(0).bits.addrRequest.poke(0x1234.U)

      // 3. Bus should arbitrate and send request to memory
      dut.io.memReq.valid.expect(true.B)
      dut.io.memReq.bits.addrRequest.expect(0x1234.U)

      // 4. Simulate memory accepting the request
      dut.io.memReq.ready.poke(true.B)
      dut.clock.step(1)
      // `busRequester` register should now be 0

      // 5. Stop sending request, simulate memory processing
      initPorts(dut, numCores)

      // 6. Simulate Memory sending response
      dut.io.memRsp.valid.poke(true.B)
      dut.io.memRsp.bits.dataResponse.poke(0xAAAA.U)
      dut.io.coreRsps(0).ready.poke(true.B) // Make sure core is ready

      // 7. Check if response is steered to Core 0
      dut.io.coreRsps(0).valid.expect(true.B)
      dut.io.coreRsps(0).bits.dataResponse.expect(0xAAAA.U)

      // 8. Check that response is NOT steered to Core 1
      dut.io.coreRsps(1).valid.expect(false.B)

      // 9. Handshake completes
      dut.io.memRsp.ready.expect(true.B)
      dut.clock.step(1)
    }
  }

  it should "route responses correctly under overlapped requests" in {
    val numCores = 2
    test(new Bus(numCores))
         .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>

      // 1. Initialize
      initPorts(dut, numCores)
      // Simulate a memory that is ALWAYS ready
      dut.io.memReq.ready.poke(true.B)
      // Both cores are ready to receive responses
      dut.io.coreRsps(0).ready.poke(true.B)
      dut.io.coreRsps(1).ready.poke(true.B)

      // --- Cycle 0: Core 0 sends request ---
      dut.io.coreReqs(0).valid.poke(true.B)
      dut.io.coreReqs(0).bits.addrRequest.poke(0x1234.U)
      dut.io.memReq.valid.expect(true.B, "Bus should be in sIdle and accept req")
      dut.io.memReq.bits.addrRequest.expect(0x1234.U)
      dut.clock.step(1)
      // At end of C0: Bus state moves to sBusy, busRequester = 0

      // --- Cycle 1: Core 1 sends req, Mem responds to Core 0 ---
      // Core 0 stops sending
      dut.io.coreReqs(0).valid.poke(false.B)
      // Core 1 starts sending
      dut.io.coreReqs(1).valid.poke(true.B)
      dut.io.coreReqs(1).bits.addrRequest.poke(0x5678.U)

      // ** CHECK STALL **: Bus is in sBusy, so it should NOT send Core 1's req
      dut.io.memReq.valid.expect(false.B, "Bus should be in sBusy and stall new reqs")

      // At the same time, memory responds to Core 0's request
      dut.io.memRsp.valid.poke(true.B)
      dut.io.memRsp.bits.dataResponse.poke(0xAAAA.U)

      // ** CHECK RESPONSE ROUTING **
      // Response for Core 0 should go to Core 0
      dut.io.coreRsps(0).valid.expect(true.B, "Response for Core 0")
      dut.io.coreRsps(0).bits.dataResponse.expect(0xAAAA.U)
      dut.io.coreRsps(1).valid.expect(false.B, "Core 1 should not get response")

      dut.clock.step(1)
      // At end of C1: memRsp.fire = true, bus moves to sIdle

      // --- Cycle 2: Bus is sIdle, should now accept Core 1's request ---
      // Memory response is done
      dut.io.memRsp.valid.poke(false.B)
      // ** CHECK NEW REQUEST **
      dut.io.memReq.valid.expect(true.B, "Bus is now sIdle and should accept req from Core 1")
      dut.io.memReq.bits.addrRequest.expect(0x5678.U)

      dut.clock.step(1)
      // At end of C2: memReq.fire = true, bus moves to sBusy, busRequester = 1

      // --- Cycle 3: Stop Core 1's req, wait for its response ---
      dut.io.coreReqs(1).valid.poke(false.B)
      dut.clock.step(1)

      // --- Cycle 4: Memory responds to Core 1's request ---
      dut.io.memRsp.valid.poke(true.B)
      dut.io.memRsp.bits.dataResponse.poke(0xBBBB.U)

      // ** CHECK RESPONSE ROUTING **
      dut.io.coreRsps(0).valid.expect(false.B, "Core 0 should not get response")
      dut.io.coreRsps(1).valid.expect(true.B, "Response for Core 1")
      dut.io.coreRsps(1).bits.dataResponse.expect(0xBBBB.U)
      dut.clock.step(1)

    }
  }  
}