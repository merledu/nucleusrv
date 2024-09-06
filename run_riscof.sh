#!/bin/bash

cd ../../../../../..
riscv64-unknown-elf-objcopy -O binary -j .text.init $1/my.elf $1/DUT-nucleusrv.text.bin
riscv64-unknown-elf-objcopy -O binary -j .data $1/my.elf $1/DUT-nucleusrv.data.bin
hexdump -v -e '"%08x\n"' $1/DUT-nucleusrv.text.bin > $1/DUT-nucleusrv.program.hex
hexdump -v -e '"%08x\n"' $1/DUT-nucleusrv.text.bin > $1/DUT-nucleusrv.data.hex
make sim-compliance IMEM=$1/DUT-nucleusrv.program.hex DMEM=$1/DUT-nucleusrv.data.hex PTH=$1 
grep '^[a-f0-9]\+$' $1/trace.log > $1/DUT-nucleusrv.signature
