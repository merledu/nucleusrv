<picture>
  <source media="(prefers-color-scheme: dark)" srcset="nrv_B.png">
  <source media="(prefers-color-scheme: light)" srcset="NucleusRV_w.png">
  <img alt="NucleusRV Logo" src="NucleusRV_w.png" width="600">
</picture>

[![Join the chat at https://gitter.im/merledu/nucleusrv](https://badges.gitter.im/merledu/nucleusrv.svg)](https://gitter.im/merledu/nucleusrv?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

A chisel based riscv 5-stage pipelined cpu design, implementing 32-bit version of the ISA (incomplete).

## Supported Extensions

| Extension | Description |
|-----------|-------------|
| I         | Base Integer Instructions |
| M         | Integer Multiplication & Division |
| F         | Single-Precision Floating Point |
| C         | Compressed Instructions |
| A         | Atomic Instructions |



## Dependencies

* [`verilator >= v5.002`](https://verilator.org/guide/latest/install.html): Simulation
* [`riscv-gnu-toolchain`](https://github.com/riscv/riscv-gnu-toolchain): To build the C program


## Getting Started

### Clone

```sh
git clone --recurse-submodules https://github.com/merledu/nucleusrv.git
```

### Generating SystemVerilog

```sh
python3 gen_verilog.py <imem> <dmem>
```

### Running RISC-V assembly

```sh
python3 simulate.py --sbt_args "--imem <PATH_TO_YOUR_IMEM_FILE>" nucleusrv.components.NRVDriver Top

```

### Running RISC-V Architectural Tests
* Make sure to have the RISC-V GNU Toolchain and Verilator in your `PATH`.
* Create a python virtual environment.
```sh
python3 -m venv .venv
source .venv/bin/activate
```
* Install Python Dependencies for RISCoF
```sh
pip install --upgrade pip
pip install git+https://github.com/riscv/riscof.git
```
* Run `run_riscv_arch_tests.py` in root directory.
```sh
python3 run_riscv_arch_tests.py
```
* RISCoF Architecture Tests:
```sh
cd riscof/riscv-arch-test/riscv-ctg
pip install -e .
```
```sh
cd ../riscv-isac
pip install -e .
cd ../../..
```
* Verify Installation
```sh
riscof --help
spike --help
```
You should see RISCoF and Spike help options displayed.


### Building C Programs
* In `tools/tests` directory, create a folder and write c program in the `main.c` file
* Run `make PROGRAM=<your_newly_created_test_folder_name`> inside tools directory
* Build the program with `sbt` command listed above. Make sure you are in root directory

* Optionally, you can skip writing/building c program and directly write hex instructions to `program.hex` file in `tools/out` directory.
