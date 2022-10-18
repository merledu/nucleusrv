export NUCLEUSRV=$PWD
FILE=$NUCLEUSRV/test_run_dir/Top_Test/VTop

TEST=$1
ISA=$2

if [ -f $FILE ]; then
        echo "$FILE exists."
        export NUCLEUSRV=$PWD
        cd $NUCLEUSRV/riscv-arch-test
        make clean TARGETDIR=$NUCLEUSRV/riscv-target RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop
        make TARGETDIR=$NUCLEUSRV/riscv-target RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop | tee Test_result.txt
        cd ../
        # exec bash

else 
        echo "$FILE does not exist."
        echo "First run sbt testOnly TopTest"
        export NUCLEUSRV=$PWD
        cd $NUCLEUSRV
        sbt "testOnly nucleusrv.components.TopTest"
        # cd ../../
        cd $NUCLEUSRV/riscv-arch-test
        make clean TARGETDIR=$NUCLEUSRV/riscv-target RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop
        make TARGETDIR=$NUCLEUSRV/riscv-target RISCV_TARGET=nucleusrv RISCV_DEVICE=rv32i RISCV_ISA=$ISA RISCV_TEST=$TEST TARGET_SIM=$NUCLEUSRV/test_run_dir/Top_Test/VTop | tee Test_result.txt
        cd ..
fi



