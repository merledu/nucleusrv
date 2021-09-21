base_dir   = $(abspath .)
src_dir    = $(base_dir)/src/main
gen_dir    = $(base_dir)/generated-src
out_dir    = $(base_dir)/outputs

SBT       = sbt
SBT_FLAGS =

CXXFLAGS += -std=c++11 -Wall -Wno-unused-variable

# compile verilator
VERILATOR = verilator --cc --exe
VERILATOR_FLAGS = --assert -Wno-STMTDLY -O3 --trace --trace-fst \
	--top-module CPU -Mdir $(gen_dir)/VCPU.csrc \
	-CFLAGS "$(CXXFLAGS) -include $(gen_dir)/VCPU.csrc/VCPU.h"

default: clean verilator

$(gen_dir)/CPU.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) $(SBT_FLAGS) "run -td $(gen_dir)"

$(gen_dir)/VCPU: $(gen_dir)/CPU.v $(src_dir)/cc/emulator.cc
	$(VERILATOR) $(VERILATOR_FLAGS) -o $@ $< $(word 2, $^) $(word 3, $^)
	$(MAKE) -C $(gen_dir)/VCPU.csrc -f VCPU.mk

verilator: $(gen_dir)/VCPU
	$< 2> $(gen_dir)/core.log

# verilator:
# $(SBT) "test:runMain components.Launcher cpu --backend-name=verilator"


clean:
	rm -rf $(gen_dir) $(out_dir) test_run_dir