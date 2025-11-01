package nucleusrv.components

import chisel3._
import chisel3.util._

/**
 * A shared bus module that arbitrates requests from N cores to a single memory port.
 * It uses a Round-Robin arbiter for fairness and handles steering
 * the single memory response back to the correct core.
 *
 * This version uses a state machine to STALL the bus, ensuring only one
 * request is "in-flight" at a time. This prevents the pipelining bug
 * where a new request could overwrite the ID of the core awaiting a response.
 *
 * @param numCores The number of cores sharing this bus
 */
class Bus(numCores: Int) extends Module {
  val io = IO(new Bundle {
    // --- Connections to the Cores ---
    // Receives requests from all cores
    val coreReqs = Flipped(Vec(numCores, Decoupled(new MemRequestIO)))
    // Sends responses back to the correct core
    val coreRsps = Vec(numCores, Decoupled(new MemResponseIO))

    // --- Connection to the Memory ---
    // Sends the arbitrated request to memory
    val memReq = Decoupled(new MemRequestIO)
    // Receives the single response from memory
    val memRsp = Flipped(Decoupled(new MemResponseIO))
  })

  //=================================================
  //== STATE MACHINE
  //=================================================

  // Define the states:
  // sIdle: Waiting for a new request from any core
  // sBusy: Waiting for a response from memory for a request already sent
  val sIdle :: sBusy :: Nil = Enum(2)
  val state = RegInit(sIdle)

  //=================================================
  //== ARBITRATION & REQUEST LOGIC
  //=================================================

  // 1. Arbiter: N Core Reqs -> 1 Mem Req
  val busArbiter = Module(new RRArbiter(new MemRequestIO, numCores))
  busArbiter.io.in <> io.coreReqs

  // 2. Track the Requester
  // We register the 'chosen' core ID only when we *successfully send* a request
  // (i.e., when io.memReq fires).
  val busRequester = RegEnable(busArbiter.io.chosen, io.memReq.fire)

  // 3. Bus -> Memory Request Path
  // The bus is valid to send a request *if* the arbiter has one AND we are in sIdle.
  io.memReq.valid := busArbiter.io.out.valid && (state === sIdle)
  io.memReq.bits  := busArbiter.io.out.bits

  // ** THIS IS THE STALL LOGIC **
  // When state === sBusy, this becomes false, stalling the arbiter.
  busArbiter.io.out.ready := io.memReq.ready && (state === sIdle)

  //=================================================
  //== RESPONSE LOGIC
  //=================================================
  val memRsp = io.memRsp // Create a simple alias for clarity

  // The bus is ready to accept a response from memory *if*
  // 1. We are in the sBusy state (expecting a response)
  // 2. The *correct* core (busRequester) is ready to accept it
  val coreRspReadys = VecInit(io.coreRsps.map(_.ready))
  memRsp.ready := coreRspReadys(busRequester) && (state === sBusy)

  // Connect the memory's response to all cores
  for (i <- 0 until numCores) {
    io.coreRsps(i).bits := memRsp.bits
    io.coreRsps(i).valid := memRsp.valid && (busRequester === i.U) && (state === sBusy)
  }

  //=================================================
  //== STATE TRANSITION LOGIC
  //=================================================
  switch (state) {
    is (sIdle) {
      // If a request is successfully sent to memory (memReq.fire), move to sBusy
      when (io.memReq.fire) { // This is (io.memReq.valid && io.memReq.ready)
        state := sBusy
      }
    }
    is (sBusy) {
      // If a response is successfully received from memory (memRsp.fire), move to sIdle
      when (io.memRsp.fire) { // This is (io.memRsp.valid && io.memRsp.ready)
        state := sIdle
      }
    }
  }
}

