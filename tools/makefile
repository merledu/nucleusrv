RISCV=riscv32-unknown-elf-
CC=$(RISCV)gcc
OBJDUMP=$(RISCV)objdump
OBJCOPY=$(RISCV)objcopy
CFLAGS=-c -march=rv32im -mabi=ilp32 -ffreestanding -fomit-frame-pointer -O2
OFLAGS=--disassemble-all --section=.text
LFLAGS = -march=rv32im -mabi=ilp32 -static -nostdlib -nostartfiles -T link.ld

PROGRAM ?= soc_smoke_test
TEST_DIR = tests/$(PROGRAM)
BUILD_DIR = out/$(TEST_DIR)

SRCS=$(wildcard $(TEST_DIR)/*.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

.PHONY: setup build clean

all: setup build

setup: clean
	@mkdir -p out

start.o: start.S
	$(CC) $(CFLAGS) start.S -o start.o

build: $(OBJS) start.o
	$(CC) $(LFLAGS) start.o $(OBJS) -o out/program.elf -lgcc
	$(OBJDUMP) $(OFLAGS) out/program.elf > out/program.dump
	$(OBJCOPY) -O binary out/program.elf out/program.bin
	python3 makehex.py out/program.bin 4096 > out/program.hex

clean: 
	rm -rf out