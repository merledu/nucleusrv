# NucleusRV

[![Join the chat at https://gitter.im/merledu/nucleusrv](https://badges.gitter.im/merledu/nucleusrv.svg)](https://gitter.im/merledu/nucleusrv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A chisel based riscv 5-stage pipelined cpu design, implementing 32-bit version of the ISA (incomplete).


## Dependencies

* [`verilator`](https://verilator.org/guide/latest/install.html) v4.016 recommended by Chisel. Tested on v4.210.
* [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain) To build the C program


## Build Instructions

#### Building with SBT
Run this command is SBT shell
```bash
testOnly nucleusrv.components.TopTest -- -DwriteVcd=1 -DprogramFile=/path/to/instructions/hex
```
#### Running Compliance Tests
* Clone `riscv-arch-test`, `sail-riscv`,`spike`, `riscv-gnu-toolchain` repo and setup riscof as mentioned in  [`RISCOF`](https://riscof.readthedocs.io/en/stable/)
* Verify paths in `config.ini`
* Add the following lines at the end of the .bashrc file:
   `export SBT_LOG=/PATH/TO/nucleusrv/tools/trace/logs`
   `export NRV_SCRIPT=/PATH/TO/nucleusrv/tools/trace/scripts`
* Run `riscof run --config=/PATH/TO/nucleusrv/config.ini --suite=/PATH/TO/riscv-arch-test/riscv-tes
t-suite/ --env=/PATH/TO/riscv-arch-test/riscv-test-suite/env` in nrv root directory

#### Building C Programs
* In `tools/tests` directory, create a folder and write c program in the `main.c` file
* Run `make PROGRAM=<your_newly_created_test_folder_name`> inside tools directory
* Build the program with `sbt` command listed above. Make sure you are in root directory

* Optionally, you can skip writing/building c program and directly write hex instructions to `program.hex` file in `tools/out` directory.
