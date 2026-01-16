# NucleusRV

[![Join the chat at https://gitter.im/merledu/nucleusrv](https://badges.gitter.im/merledu/nucleusrv.svg)](https://gitter.im/merledu/nucleusrv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A chisel based riscv 5-stage pipelined cpu design, implementing 32-bit version of the ISA (incomplete).


## Dependencies

* [`verilator >= v5.002`](https://verilator.org/guide/latest/install.html): Simulation
* [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain): To build the C program


## Getting Started

### Clone

```sh
git clone --recurse-submodules https://github.com/merledu/nucleusrv.git
```

### Running RISC-V assembly

```sh
sbt "nucleusrv.components.NRVDriver --imem /path/to/imem/hex/file --dmem /path/to/dmem/hex/file --target-dir /path/to/output/dir"
export NRV_ROOT=$PWD
cd /path/to/output/dir
verilator --cc --exe --build --trace --no-timing $NRV_ROOT/tb_Top.cpp Top.v
./obj_dir/VTop
```

Waveform will can be found at `/path/to/output/dir/logs`.

### Running RISC-V Architectural Tests
* Make sure to have the RISC-V GNU Toolchain and Verilator in your `PATH`.
* Create a python virtual environment and setup `riscv-arch-test`.
```sh
python3 -m venv .venv
source .venv/bin/activate
pip3 install -e riscof/riscv-arch-test/riscv-ctg riscof/riscv-arch-test/riscv-isac
pip3 install git+https://github.com/riscv/riscof.git
```
* Run `run_riscv_arch_tests.py` in root directory.
```sh
python3 run_riscv_arch_tests.py
```

### Building C Programs
* In `tools/tests` directory, create a folder and write c program in the `main.c` file
* Run `make PROGRAM=<your_newly_created_test_folder_name`> inside tools directory
* Build the program with `sbt` command listed above. Make sure you are in root directory

* Optionally, you can skip writing/building c program and directly write hex instructions to `program.hex` file in `tools/out` directory.
