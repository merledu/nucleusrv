# Define directories
OUT_DIR = "./Vector_Complaince_ChipAllaince/riscv-vector-tests/out/v128x32machine/bin/stage1"
WORK_DIR = "./Vector_Complaince_ChipAllaince/riscv-vector-tests/work"
NUCLEUSRV_DIR = /home/mlatif/nucleusrv
BIN_FILE = $(OUT_DIR)/vadd_vv-0

# Target binary and hex files
TEXT_BIN = $(WORK_DIR)/vadd_vv.text.bin
DATA_BIN = $(WORK_DIR)/vadd_vv.data.bin
PROGRAM_HEX = $(WORK_DIR)/vadd_vv.program.hex
DATA_HEX = $(WORK_DIR)/vadd_vv.data.hex
SPIKE_SIGNATURE = $(WORK_DIR)/vadd_vv-spike.signature

# Default rule
all: prepare_folder copy_text copy_data create_hexes run_test run_spike

# Prepare work folder:
prepare_folder:
	@if [ -d "$(WORK_DIR)" ]; then \
		echo "Removing existing work folder..."; \
		rm -rf $(WORK_DIR); \
	fi
	mkdir -p $(WORK_DIR)

# Copy text section to binary
copy_text:
	riscv32-unknown-elf-objcopy -O binary -j .text.init $(BIN_FILE) $(TEXT_BIN)

# Copy data section to binary
copy_data:
	riscv32-unknown-elf-objcopy -O binary -j .data $(BIN_FILE) $(DATA_BIN)

# Create hex files from the binary files
create_hexes:
	hexdump -v -e '"%08x\n"' $(TEXT_BIN) > $(PROGRAM_HEX)
	hexdump -v -e '"%08x\n"' $(DATA_BIN) > $(DATA_HEX)

# Run testOnly command in /home/mlatif/nucleusrv directory
run_test:
	cd $(NUCLEUSRV_DIR) && sbt "testOnly nucleusrv.components.TopTest -- -DwriteVcd=1 -DprogramFile=$(PROGRAM_HEX) -DdataFile=$(DATA_HEX) -J-Xmx4G" 2> trace.log

# Run Spike simulator with signature output
run_spike:
	spike --isa=rv32gcv +signature=$(SPIKE_SIGNATURE) +signature-granularity=4 $(BIN_FILE)

# Clean the work folder
clean:
	rm -rf $(WORK_DIR)

