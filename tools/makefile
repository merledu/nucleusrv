RISCV=riscv32-unknown-elf-
CC=$(RISCV)gcc
OBJDUMP=$(RISCV)objdump
HEX=$(RISCV)elf2hex
CFLAGS=-c -march=rv32i -mabi=ilp32 -ffreestanding -fomit-frame-pointer
OFLAGS=--disassemble-all --section=.text
# LFLAGS = -march=rv32im -mabi=ilp32 -static -nostdlib -nostartfiles -T link.ld

# $(CC) $(LFLAGS) -o main.a start.S main.o
main: main.c
	@mkdir -p out
	$(CC) $(CFLAGS) -o out/main.o main.c
	$(OBJDUMP) $(OFLAGS) out/main.o > out/main.dump
	$(HEX) --bit-width 32 --input out/main.o --output main.hex
