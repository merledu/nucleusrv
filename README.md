# riscv-pipelined
A riscv 5-stage pipelined cpu design, implementing 32-bit version of the ISA (incomplete).


## Dependencies

* [`elf2hex`](https://github.com/sifive/elf2hex) Converts elf to hex instructions 
* [`verilator`](https://verilator.org/guide/latest/install.html) v4.016 recommended by Chisel. Tested on v4.210.
* [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain) To build the c program


## Build Instructions

* In `tools` directory, write c program in the `main.c` file
* Edit the `make` file to set riscv32-unknown-elf or riscv64-unknown-elf
* Build the program with `make` command
* Edit the `src/main/scala/components/InstructionMemory.scala` file and change path to hex file that was created in tools directory with the above command.
* Create a vcd dump with `sbt test:runMain components.Launcher cpu --backend-name=verilator`
* View the dump with `gtkwave` or any other waveform viewer.

* Optionally, you can skip the building a c program and directly write hex instructions to `main.hex` file in tools directory.