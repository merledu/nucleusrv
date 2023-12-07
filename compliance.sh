#!/bin/bash
# Disassemble the ELF file
riscv32-unknown-elf-objdump -D $(pwd)/imperas-riscv-tests/work/rv32i_m/I/$1.elf > $(pwd)/imperas_test/$1.disass

# Parse the assembly and generate hex file
python3 $(pwd)/tools/trace/scripts/assemblyParser.py --asm $(pwd)/imperas_test/$1.disass --hex $(pwd)/imperas_test/$1.hex

# Clean the hex file
python3 $(pwd)/tools/trace/scripts/hex_cleaner.py --hex $(pwd)/imperas_test/$1.hex

# Move to the nucleusrv directory
cd $(pwd)

# Run tests 
make sim IMEM=$(pwd)/imperas_test/$1.hex

#cd /home/hassan/Burq-Suite/simulate_rtl/

#./simulate.sh /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/Top.v /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/sram_top.v /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/sram.v


# Convert sbt dump to log
python3 $(pwd)/tools/trace/scripts/sbtToLog.py --asm $(pwd)/imperas_test/$1.disass --sbt_dump $(pwd)/trace.log --log $(pwd)/imperas_test/$1.log

python3 $(pwd)/tools/trace/scripts/imperas_log_to_sig.py --log $(pwd)/imperas-riscv-tests/work/rv32i_m/I/$1.log --sig $(pwd)/imperas-riscv-tests/work/rv32i_m/I/$1.signature


	# Convert log to signature
python3 $(pwd)/tools/trace/scripts/logToSignature.py --log $(pwd)/imperas_test/$1.log --disass $(pwd)/imperas_test/$1.disass --signature $(pwd)/imperas_test/$1.signature

# Clean the ref signature file
#python3 $(pwd)/tools/trace/scripts/hex_cleaner.py --hex /home/hassan/imperas-riscv-tests/work/rv32i_m/I/$1.signature.output

# Signature Compare
python3 $(pwd)/tools/trace/scripts/compare.py --ref_sig $(pwd)/imperas-riscv-tests/work/rv32i_m/I/$1.signature --dut_sig $(pwd)/imperas_test/$1.signature
