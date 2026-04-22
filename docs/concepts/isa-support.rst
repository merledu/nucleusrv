RISC-V ISA Extensions Supported by NucleusRV
==========================================

NucleusRV implements the RV32IMAFC instruction set.

Supported Extensions
--------------------

- **I (Base Integer)**: Always enabled. Includes ALU, Load/Store, and Branch instructions.
- **M (Integer Multiply/Divide)**: Configurable. Implements multiplication and division.
- **A (Atomic Memory Operations)**: Configurable. Implements Load-Reserved/Store-Conditional and Atomic Memory Operations.
- **F (Single-Precision Floating-Point)**: Configurable. Implements IEEE 754 floating-point instructions.
- **C (Compressed Instructions)**: Configurable. Implements 16-bit compressed instructions to reduce code size.
- **Zicsr (CSR Instructions)**: Configurable. Enables access to Control and Status Registers.

Extension Details
-----------------

M Extension
~~~~~~~~~~~
- Multiplier: Single-cycle multiplication.
- Divider: Multi-cycle (up to 34 cycles) division/remainder unit.

A Extension
~~~~~~~~~~~
- LR.W / SC.W: Implemented using a reservation file.
- AMOs: Two-cycle read-modify-write sequence.

C Extension
~~~~~~~~~~~
- Realigner: Handles misaligned instruction boundaries.
- CompressedDecoder: Expands 16-bit instructions to 32-bit equivalents.

MISA Register
-------------

The ``misa`` register reports the supported extensions based on the core configuration.
The extensions bits are:
- Bit 8 (I): Base Integer.
- Bit 12 (M): Multiplication.
- Bit 0 (A): Atomics.
- Bit 5 (F): Floating-Point.
- Bit 2 (C): Compressed.
