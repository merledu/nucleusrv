package nucleusrv.components

import chisel3._

/**
 * This abstract class provides a template for other protocols to implement the transaction wires.
 * This is used as a template for e.g when the core wants to communicate with the memory or with the peripheral registers.
 * It will set these signals up in order to talk to the Host adapter of the relevant bus protocol
 */
class MemRequestIO extends Bundle {
  val addrRequest: UInt = Input(UInt(32.W))
  val dataRequest: UInt = Input(UInt(32.W))
  val activeByteLane: UInt = Input(UInt(4.W))
  val isWrite: Bool = Input(Bool())
}

class MemResponseIO extends Bundle {
  val dataResponse: UInt = Input(UInt(32.W))
}
