RISCV=riscv32-unknown-elf-
CC=$(RISCV)gcc
OBJDUMP=$(RISCV)objdump
HEX=$(RISCV)elf2hex
CFLAGS=-c -march=rv32i -mabi=ilp32 -ffreestanding -fomit-frame-pointer
OFLAGS=--disassemble-all --section=.text
LFLAGS = -march=rv32im -mabi=ilp32 -static -nostdlib -nostartfiles -T link.ld

PROGRAM ?= fibonacci
TEST_DIR = tests/$(PROGRAM)
BUILD_DIR = out/$(TEST_DIR)

SRCS=$(wildcard $(TEST_DIR)/*.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

.PHONY: setup build clean

all: setup build

setup: clean
	@mkdir -p out

build: $(OBJS)
	$(CC) $(LFLAGS) start.S $(OBJS) -o out/program.elf -lgcc
	$(OBJDUMP) $(OFLAGS) out/program.elf > out/program.dump
	srec_cat out/program.elf -binary -offset 0x0000 -byte-swap 4 -o out/program.hex -vmem
#$(HEX) --bit-width 32 --input out/program.elf --output out/program.hex

clean: 
	rm -rf out

# main: main.c
# 	$(CC) $(CFLAGS) -o out/main.o $(PROGRAM)/*.c
# 	$(OBJDUMP) $(OFLAGS) out/main.o > out/main.dump
# 	$(HEX) --bit-width 32 --input out/main.o --output main.hex

