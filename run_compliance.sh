#!/bin/bash

export NUCLEUSRV=$PWD
FILE=$NUCLEUSRV/test_run_dir/Top_Test/verilated/VTop

if [ -f $FILE ]; then
        echo "$FILE exists."
else 
        echo "$FILE does not exist."
        echo "Running sbt testOnly TopTest"
        sbt "testOnly nucleusrv.components.TopTest"
fi

ISA=$1
TEST=$2
DEVICE=$3

cd $NUCLEUSRV/imperas-riscv-tests 

make clean TARGETDIR=$NUCLEUSRV/riscv-target RISCV_PREFIX=riscv64-unknown-elf- RISCV_BASE=i RISCV_TARGET=nucleusrv RISCV_DEVICE=$DEVICE RISCV_ISA=$ISA RISCV_MODE=m RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/verilated/VTop
make TARGETDIR=$NUCLEUSRV/riscv-target RISCV_PREFIX=riscv64-unknown-elf- RISCV_BASE=i RISCV_TARGET=nucleusrv RISCV_DEVICE=$DEVICE RISCV_ISA=$ISA RISCV_MODE=m RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/verilated/VTop | tee Test_result.txt

cd ../
