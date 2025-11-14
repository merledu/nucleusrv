#
# Makefile
#
# This Makefile compiles the RISC-V assembly file 'asm_test.S'
# into an ELF file and then splits it into two separate .hex files
# (one for imem, one for dmem) suitable for loading with Verilog's
# $readmemh.
#

# --- Toolchain ---
# Assumes 'riscv32-unknown-elf-' is in your PATH
TOOLCHAIN_PREFIX := /tools/riscv-toolchain-rv32/bin/riscv32-unknown-elf-
CC               := $(TOOLCHAIN_PREFIX)gcc
OBJCOPY          := $(TOOLCHAIN_PREFIX)objcopy
OBJDUMP          := $(TOOLCHAIN_PREFIX)objdump

# --- Files ---
ASM_SRC   := asm_test.S
LINKER_LD := linker.ld
TARGET    := asm_test
ELF_FILE  := $(TARGET).elf

# --- Flags ---
# -march=rv32ia: Base 'i'nteger + 'a'tomic extensions.
# -mabi=ilp32:   Specifies the 32-bit ABI.
ASFLAGS := -march=rv32ia -mabi=ilp32
LDFLAGS := -T $(LINKER_LD) -nostdlib -nostartfiles

# --- Targets ---

# Default target: build both hex files
all: imem.hex dmem.hex

# Target for instruction memory (imem)
# --only-section=.text: Extracts only the .text section
imem.hex: $(ELF_FILE)
	@echo "Generating Instruction Memory (imem) hex..."
	$(OBJCOPY) -O binary --only-section=.text $< imem.bin
	od -An -t x4 -w4 -v imem.bin | tr -d ' ' > imem.hex

# Target for data memory (dmem)
# --only-section=.data: Extracts only the .data section
dmem.hex: $(ELF_FILE)
	@echo "Generating Data Memory (dmem) hex..."
	$(OBJCOPY) -O binary --only-section=.data $< dmem.bin
	od -An -t x4 -w4 -v dmem.bin | tr -d ' ' > dmem.hex

# Link the object file into a final ELF file
$(ELF_FILE): $(ASM_SRC:.S=.o)
	@echo "Linking..."
	$(CC) $(LDFLAGS) -o $@ $^

# Compile the assembly source file into an object file
%.o: %.S
	@echo "Assembling..."
	$(CC) $(ASFLAGS) -c -o $@ $<

# Optional: Target to dump disassembly for debugging
dump: $(ELF_FILE)
	$(OBJDUMP) -d $<

# Clean up generated files
clean:
	@echo "Cleaning up..."
	rm -f *.o *.elf *.bin *.hex

.PHONY: all clean dump
