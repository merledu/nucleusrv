CROSS_COMPILE ?= riscv32-unknown-elf-
CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

CFLAGS = -march=rv32imafc -mabi=ilp32f -O2 -ffreestanding -nostdlib
LDFLAGS = -T link.ld -nostdlib

SRCS = start.S pong.c
OBJS = start.o pong.o

all: pong.hex

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

pong.elf: $(OBJS) link.ld
	$(CC) $(LDFLAGS) $(OBJS) -o $@

pong.bin: pong.elf
	$(OBJCOPY) -O binary $< $@

pong.hex: pong.bin
	python3 ../../tools/makehex.py $< 8192 > $@

clean:
	rm -f *.o *.elf *.bin *.hex

.PHONY: all clean
