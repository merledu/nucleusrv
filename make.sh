riscv32-unknown-elf-gcc -c -march=rv32gv -o asambly_file.o asambly_file.s
riscv32-unknown-elf-objdump -d asambly_file.o | awk '{print $2}' | grep -E '^[0-9a-f]+$' > asm.txt
