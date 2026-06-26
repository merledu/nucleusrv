NucleusRV Pipeline Stages and Signal Reference
==============================================

Detailed reference for each of NucleusRV's five pipeline stages.

Stage 1: IF — Instruction Fetch
-------------------------------

Key Responsibilities:
- Instruction fetch via ``imemReq``.
- Handle misaligned instructions (if ``C = true``).
- Update PC.

Key Signals:
- ``if_reg_pc``: PC of the current fetch.
- ``if_reg_ins``: Fetched instruction.
- ``ral_halt_o``: Halt signal from Realigner.

Stage 2: ID — Instruction Decode
--------------------------------

Key Responsibilities:
- Decode opcode and generate control signals.
- Read register file (rs1, rs2, rs3).
- Immediate generation.
- Branch resolution.

Key Signals:
- ``id_reg_pc``: PC transmitted from IF.
- ``id_reg_rd1``, ``id_reg_rd2``: Operands from register file.
- ``ctl_aluOp``, ``ctl_memRead``, etc.: Control signals.

Stage 3: EX — Execute
---------------------

Key Responsibilities:
- ALU operations.
- Data forwarding.
- Multi-cycle M and F operations.

Key Signals:
- ``ex_reg_result``: ALU result.
- ``stall``: Stall signal for multi-cycle ops.

Stage 4: MEM — Memory Access
----------------------------

Key Responsibilities:
- Data memory access via ``dmemReq``.
- AMO sequencing.

Key Signals:
- ``dmemRsp.valid``: Response validity.
- ``mem_reg_result``: Data read or ALU result.

Stage 5: WB — Write Back
------------------------

Key Responsibilities:
- Register file write.
- Debug output (``io.pin``).

Key Signals:
- ``wb_data``: Final data to be written back.
- ``ID.writeData``: Write data to register file.
- ``ID.writeReg``: Target register for write-back.

Top-level IO Port Reference
---------------------------

* **clock / reset**: System clock and active-high synchronous reset.
* **io_stall**: External stall input (active-high).
* **io_pin**: 32-bit debug output (retired instruction data).

Memory Interface Ports
~~~~~~~~~~~~~~~~~~~~~~

* **io_imemReq**: Instruction memory request bundle.
    * ``bits.addrRequest``: Byte address.
    * ``valid``: Request valid.
    * ``ready``: Memory ready to accept.
* **io_imemRsp**: Instruction memory response bundle.
    * ``bits.dataResponse``: 32-bit instruction data.
    * ``valid``: Instruction data valid.
* **io_dmemReq**: Data memory request bundle.
    * ``bits.isWrite``: Write enable.
    * ``bits.activeByteLane``: 4-bit byte-mask.
* **io_dmemRsp**: Data memory response bundle.
    * ``bits.dataResponse``: Read data.

RVFI Interface
~~~~~~~~~~~~~~
Enabled when ``TRACE = true``. Provides a complete trace of every retired instruction for formal verification and logging.
