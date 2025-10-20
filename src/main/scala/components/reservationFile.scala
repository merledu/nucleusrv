package nucleusrv.components

import chisel3._
import chisel3.util._

/**
 * ReservationFile — tracks a single reserved address for LR/SC in a core.
 */
class ReservationFileIO extends Bundle {
  val set       = Input(Bool())        // Set reservation (on LR)
  val clear     = Input(Bool())        // Clear reservation (on SC or invalidation)
  val addrIn    = Input(UInt(32.W))    // address for reservation or compare
  val matchAddr = Output(Bool())       // True if addrIn matches reserved
  val reserved  = Output(Bool())       // True if there is an active reservation
}

class ReservationFile extends Module {
  val io = IO(new ReservationFileIO)

  val reservedValid = RegInit(false.B)
  val reservedAddr  = Reg(UInt(32.W))

  io.matchAddr := false.B
  io.reserved  := reservedValid

  when(io.set) { // set reservation with new address
    reservedAddr  := io.addrIn
    reservedValid := true.B
  }

  when(io.clear) { // clear reservation (after SC or invalidation)
    reservedValid := false.B
  }

  // Match check
  when(reservedValid && (reservedAddr === io.addrIn)) {
    io.matchAddr := true.B
  }
}
