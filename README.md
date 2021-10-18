# NucleusRV
A chisel based riscv 5-stage pipelined cpu design, implementing 32-bit version of the ISA (incomplete).


## Dependencies

* [`elf2hex`](https://github.com/sifive/elf2hex) Converts elf to hex instructions (for building C programs)
* [`verilator`](https://verilator.org/guide/latest/install.html) v4.016 recommended by Chisel. Tested on v4.210.
* [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain) To build the C program


## Build Instructions

#### Building with SBT
Run this command is SBT Shell
```bash
testOnly components.TopTest -- -DwriteVcd=1 -DmemFile=/path/to/instructions/hex
```

#### Building C Programs
* In `tools` directory, write c program in the `main.c` file
* Edit the `make` file to set compiler prefix to either riscv32-unknown-elf or riscv64-unknown-elf
* Build the program with `sbt` command listed above.

* Optionally, you can skip the building a c program and directly write hex instructions to `main.hex` file in `tools/out` directory.