#!/bin/bash

export NUCLEUSRV=$PWD
FILE=$NUCLEUSRV/test_run_dir/Top_Test/VTop

if [ -f $FILE ]; then
        echo "$FILE exists."
else 
        echo "$FILE does not exist."
        echo "Running sbt testOnly TopTest"
        sbt "testOnly nucleusrv.components.TopTest"
fi

ISA=$1
TEST=$2

cd $NUCLEUSRV/riscv-arch-test

make clean TARGETDIR=$NUCLEUSRV/riscv-target RISCV_PREFIX=riscv64-unknown-elf-  RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop
make TARGETDIR=$NUCLEUSRV/riscv-target RISCV_PREFIX=riscv64-unknown-elf- RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop | tee Test_result.txt

cd ../