#!/bin/bash

cd ../../../../../..
riscv32-unknown-elf-objcopy -O binary -j .text.init $1/my.elf $1/DUT-nucleusrv.text.bin
riscv32-unknown-elf-objcopy -O binary -j .data $1/my.elf $1/DUT-nucleusrv.data.bin
hexdump -v -e '"%08x\n"' $1/DUT-nucleusrv.text.bin > $1/DUT-nucleusrv.program.hex
hexdump -v -e '"%08x\n"' $1/DUT-nucleusrv.text.bin > $1/DUT-nucleusrv.data.hex
cd ../../../../..
sbt "testOnly nucleusrv.components.TopTest -- -DprogramFile=$1/DUT-nucleusrv.program.hex -DwriteVcd=1 -DdataFile=$1/DUT-nucleusrv.data.hex" 2> $1/DUT-nucleusrv.stdout
grep '^[a-f0-9]\+$' $1/DUT-nucleusrv.stdout > $1/DUT-nucleusrv.signature.output