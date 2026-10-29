#!/usr/bin/env bash
# Builds ctest.bin (linked at 0x10000000, same startup/linker as DOOM). $1 = -march (default rv32imc)
set -e
cd "$(dirname "$0")"
T=$(dirname "$(ls /tools/riscv/*/bin/riscv32-unknown-elf-gcc)")
ARCH=${1:-rv32imc}
$T/riscv32-unknown-elf-gcc -march=$ARCH -mabi=ilp32 -O2 -ffreestanding -nostartfiles -static \
  -Wl,--no-warn-mismatch -T ../../../doom/link_ddr3.ld ../../../doom/start_ddr3.S main.c -o ctest.elf -lc -lgcc
$T/riscv32-unknown-elf-objcopy -O binary ctest.elf ctest.bin
