NucleusRV: RV32IMAFC Processor Core for FPGA & ASIC
===================================================

NucleusRV is an open-source 32-bit RISC-V processor core implementing the RV32IMAFC extensions. It is written in Chisel, enabling high-parameterization and easy generation of Verilog.

Key Features
------------

- **Configurable Extensions**: Enable or disable M, A, F, C, and Zicsr extensions via configuration.
- **Classic 5-Stage Pipeline**: Fetch, Decode, Execute, Memory, and Write-Back stages.
- **Verilator Simulation**: Includes a C++ testbench for fast simulation and verification.
- **FPGA Friendly**: Designed to be synthesized on various FPGA families.

Supported ISA Extensions
------------------------

- **I**: Base Integer instruction set.
- **M**: Integer Multiply and Divide.
- **A**: Atomic Memory Operations.
- **F**: Single-Precision Floating-Point.
- **C**: Compressed 16-bit instructions.
- **Zicsr**: Control and Status Register instructions.

Where to Go Next
----------------

- :doc:`quickstart` to run your first simulation.
- :doc:`installation` to set up your environment.
- :doc:`concepts/isa-support` for technical details on ISA extensions.

What you can do with NucleusRV
----------------------------

* **Install dependencies**: Set up Verilator, RISC-V GNU toolchain, sbt, and Scala.
* **Generate Verilog**: Use ``NRVDriver`` to emit synthesis-ready Verilog.
* **Simulate with Verilator**: Run programs and verify execution with the included testbench.
* **Integrate into your design**: Connect separate instruction and data memory ports to your system.
