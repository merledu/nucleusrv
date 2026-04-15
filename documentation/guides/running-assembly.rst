Simulate RISC-V Assembly Programs with NucleusRV
===============================================

Learn how to write, assemble, and simulate RISC-V assembly programs on NucleusRV.

Write Your Assembly File
------------------------

Create an assembly file (e.g., ``program.S``) in the ``tools/`` directory:

.. code-block:: assembler

   .section .text, "ax"
   .global _start
   _start:
     li x1, 10
     li x2, 20
     add x3, x1, x2
     nop

Assemble and Convert to Hex
---------------------------

Use the RISC-V GCC toolchain to assemble and link your program:

.. code-block:: bash

   riscv32-unknown-elf-gcc -march=rv32gcv -mabi=ilp32 -static -nostdlib -nostartfiles -T tools/link.ld program.S -o program.elf
   python3 tools/makehex.py program.elf 2048 > imem.hex

Generate Verilog and Simulate
-----------------------------

Follow the :doc:`../quickstart` guide to generate Verilog using your ``imem.hex`` and run the simulation with Verilator.

Verify Output
-------------

The simulation output will show retiring instructions and register updates. You can also inspect the generated waveform file.
