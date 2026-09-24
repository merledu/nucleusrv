RISCV=riscv32-unknown-elf-
CC=$(RISCV)gcc
OBJDUMP=$(RISCV)objdump
OBJCOPY=$(RISCV)objcopy
CFLAGS=-c -O2 -march=rv32gcv -mabi=ilp32 -ffreestanding -fomit-frame-pointer
OFLAGS=--disassemble-all
LFLAGS = -march=rv32gcv -mabi=ilp32 -static -nostdlib -nostartfiles -T link.ld

PROGRAM ?= fibonacci
TEST_DIR = tests/$(PROGRAM)
BUILD_DIR = out/$(TEST_DIR)

SRCS=$(wildcard $(TEST_DIR)/*.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

.PHONY: setup build clean

all: setup build

setup: clean
	@mkdir -p out

# Flat mem image: VMA layout with gaps zero-filled (not raw ELF bytes).
HEX_WORDS = 8192

build: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o out/program.elf -lgcc
	$(OBJDUMP) $(OFLAGS) out/program.elf > out/program.dump
	$(OBJCOPY) -O binary --gap-fill=0x00 out/program.elf out/program.bin
	python3 makehex.py out/program.bin $(HEX_WORDS) > out/program.hex

clean: 
	rm -rf out