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
	--top-module Top -Mdir $(gen_dir)/VTop.csrc \
	-CFLAGS "$(CXXFLAGS) -include $(gen_dir)/VTop.csrc/VTop.h"

default: clean verilator

$(gen_dir)/Top.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) $(SBT_FLAGS) "run -td $(gen_dir)"

$(gen_dir)/VTop: $(gen_dir)/Top.v $(src_dir)/cc/emulator.cc
	$(VERILATOR) $(VERILATOR_FLAGS) -o $@ $< $(word 2, $^) $(word 3, $^)
	$(MAKE) -C $(gen_dir)/VTop.csrc -f VTop.mk

verilator: $(gen_dir)/VTop
	$< 2> $(gen_dir)/core.log

# verilator:
# $(SBT) "test:runMain components.Launcher cpu --backend-name=verilator"


clean:
	rm -rf $(gen_dir) $(out_dir) test_run_dir