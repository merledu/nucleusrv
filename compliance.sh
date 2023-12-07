# Disassemble the ELF file
riscv32-unknown-elf-objdump -D /home/hassan/nucleusrv/imperas-riscv-tests/work/rv32i_m/I/$1.elf > /home/hassan/nucleusrv/imperas_test/$1.disass

# Parse the assembly and generate hex file
python3 /home/hassan/nucleusrv/tools/trace/scripts/assemblyParser.py --asm /home/hassan/nucleusrv/imperas_test/$1.disass --hex /home/hassan/nucleusrv/imperas_test/$1.hex

# Clean the hex file
python3 /home/hassan/nucleusrv/tools/trace/scripts/hex_cleaner.py --hex /home/hassan/nucleusrv/imperas_test/$1.hex

# Move to the nucleusrv directory
cd /home/hassan/nucleusrv

# Run tests 
make sim IMEM=/home/hassan/nucleusrv/imperas_test/$1.hex

#cd /home/hassan/Burq-Suite/simulate_rtl/

#./simulate.sh /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/Top.v /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/sram_top.v /home/hassan/Documents/nucleusrv/test_run_dir/Top_Test/sram.v


# Convert sbt dump to log
python3 /home/hassan/nucleusrv/tools/trace/scripts/sbtToLog.py --asm /home/hassan/nucleusrv/imperas_test/$1.disass --sbt_dump /home/hassan/nucleusrv/trace.log --log /home/hassan/nucleusrv/imperas_test/$1.log

python3 /home/hassan/nucleusrv/tools/trace/scripts/imperas_log_to_sig.py --log /home/hassan/nucleusrv/imperas-riscv-tests/work/rv32i_m/I/$1.log --sig /home/hassan/nucleusrv/imperas-riscv-tests/work/rv32i_m/I/$1.signature


	# Convert log to signature
python3 /home/hassan/nucleusrv/tools/trace/scripts/logToSignature.py --log /home/hassan/nucleusrv/imperas_test/$1.log --disass /home/hassan/nucleusrv/imperas_test/$1.disass --signature /home/hassan/nucleusrv/imperas_test/$1.signature

# Clean the ref signature file
#python3 /home/hassan/nucleusrv/tools/trace/scripts/hex_cleaner.py --hex /home/hassan/imperas-riscv-tests/work/rv32i_m/I/$1.signature.output

# Signature Compare
python3 /home/hassan/nucleusrv/tools/trace/scripts/compare.py --ref_sig /home/hassan/nucleusrv/imperas-riscv-tests/work/rv32i_m/I/$1.signature --dut_sig /home/hassan/nucleusrv/imperas_test/$1.signature
