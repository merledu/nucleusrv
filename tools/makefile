RISCV=riscv32-unknown-elf-
CC=$(RISCV)gcc
OBJDUMP=$(RISCV)objdump
OBJCOPY=$(RISCV)objcopy
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
	$(CC) $(LFLAGS) $(OBJS) -o out/program.elf -lgcc
	$(OBJDUMP) $(OFLAGS) out/program.elf > out/program.dump
	python3 makehex.py out/program.elf 2048 > out/program.hex

clean: 
	rm -rf out