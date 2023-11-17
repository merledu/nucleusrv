package nucleusrv.components

import chisel3._
import chisel3.util._

class CSRController extends Module{
    val io = IO(new Bundle{
        val regWrExecute = Input(Bool())
        val rdSelExecute = Input(UInt(5.W))
        val csrWrExecute = Input(Bool())

        val regWrMemory = Input(Bool())
        val rdSelMemory = Input(UInt(5.W))
        val csrWrMemory = Input(Bool())

        val regWrWriteback = Input(Bool())
        val rdSelWriteback = Input(UInt(5.W))
        val csrWrWriteback = Input(Bool())

        val rs1SelDecode = Input(UInt(5.W))
        val csrInstDecode = Input(Bool())

        val csrInstIsImmd = Input(Bool())

        val forwardRS1 = Output(UInt(3.W))

        // val loadInstExecute = Input(Bool())
        // val loadInstMemory = Input(Bool())
        // val dccm_rvalid_i = Input(Bool())
        // val csr_op_en_o = Output(Bool())
    })

    val hazard_DecEx = Mux(io.regWrExecute &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelExecute.orR &&
                           ~io.csrWrExecute &&
                           io.rdSelExecute === io.rs1SelDecode,
                           true.B,
                           false.B)

    val hazard_DecMem = Mux(io.regWrMemory &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelMemory.orR &&
                           ~io.csrWrMemory &&
                           io.rdSelMemory === io.rs1SelDecode &&
                           ~hazard_DecEx,
                           true.B,
                           false.B)

    val hazard_DecWb = Mux(io.regWrWriteback &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelWriteback.orR &&
                           ~io.csrWrWriteback &&
                           io.rdSelWriteback === io.rs1SelDecode &&
                           ~hazard_DecEx &&
                           hazard_DecMem,
                           true.B,
                           false.B)

    val csrHazard_DecEx = Mux(io.regWrExecute &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelExecute.orR &&
                           io.csrWrExecute &&
                           io.rdSelExecute === io.rs1SelDecode,
                           true.B,
                           false.B)

    val csrHazard_DecMem = Mux(io.regWrMemory &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelMemory.orR &&
                           io.csrWrMemory &&
                           io.rdSelMemory === io.rs1SelDecode &&
                           ~csrHazard_DecEx,
                           true.B,
                           false.B)

    val csrHazard_DecWb = Mux(io.regWrWriteback &&
                           io.csrInstDecode &&
                           ~io.csrInstIsImmd &&
                           io.rdSelWriteback.orR &&
                           io.csrWrWriteback &&
                           io.rdSelWriteback === io.rs1SelDecode &&
                           ~csrHazard_DecEx &&
                           csrHazard_DecMem,
                           true.B,
                           false.B)

    val cases = Array(
        hazard_DecEx        -> 1.U,
        hazard_DecMem       -> 2.U,
        hazard_DecWb        -> 3.U,
        csrHazard_DecEx     -> 4.U,
        csrHazard_DecMem    -> 5.U,
        csrHazard_DecWb     -> 6.U
    )

    io.forwardRS1 := MuxLookup(true.B, DontCare, cases)
}
