base_dir   = $(abspath .)
src_dir    = $(base_dir)/src/main
gen_dir    = $(base_dir)/generated-src
out_dir    = $(base_dir)/outputs

SBT       = sbt
SBT_FLAGS = -DprogramFile=tools/out/program.hex -DwriteVcd=1

CXXFLAGS += -std=c++11 -Wall -Wno-unused-variable

# compile verilator
VERILATOR = verilator --cc --exe
VERILATOR_FLAGS = --assert -Wno-STMTDLY -O3 --trace --trace-fst \
	--top-module Top -Mdir $(gen_dir)/VTop.csrc \
	-CFLAGS "$(CXXFLAGS) -include $(gen_dir)/VTop.csrc/VTop.h"

default: clean compile

compile:
	$(SBT) "testOnly nucleusrv.components.TopTest -- $(SBT_FLAGS)"

$(gen_dir)/Top.v: $(wildcard $(src_dir)/scala/*.scala)
	$(SBT) "run -td $(gen_dir)"

$(gen_dir)/VTop: $(gen_dir)/Top.v $(src_dir)/cc/emulator.cc
	$(VERILATOR) $(VERILATOR_FLAGS) -o $@ $< $(word 2, $^) $(word 3, $^)
	$(MAKE) -C $(gen_dir)/VTop.csrc -f VTop.mk

verilator: $(gen_dir)/VTop
	$< 2> $(gen_dir)/core.log

clean:
	rm -rf $(gen_dir) $(out_dir) test_run_dir
	rm -rf obj_dir
	rm *.v
	rm *.fir
	rm *.anno.json
	rm *.f
	
compliance:
	./run_compliance.sh $(ISA) $(TEST) $(DEVICE) 

IMEM=asm.txt

rtl:
	sbt "runMain nucleusrv.components.NRVDriver $(IMEM)"
	(echo '/* verilator lint_off ASSIGNDLY */' && echo '/* verilator lint_off UNUSED */' && echo '/* verilator lint_off BLKSEQ */' && echo '/* verilator lint_off DECLFILENAME */' && echo '/* verilator lint_off WIDTH */' && echo '/* verilator lint_off EOFNEWLINE */' && cat Top.v) > temp && mv temp Top.v

VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc Top.v --exe tb_Top.cpp

ver: 
	@( $(VERILATOR) $(VERILATOR_FLAGS); \
	   make -C obj_dir -f VTop.mk VTop) > ver_output.log 2>&1
	   obj_dir/VTop > trace.log 2>&1

sim: rtl ver

PYTHON := $(shell command -v python3 || command -v python)
ASM=test.s
asmtohex:
	$(PYTHON) ./tools/trace/scripts/assemblyParser.py --asm $(ASM) --hex assembly.hex


dv:
	$(MAKE) asmtohex
	$(MAKE) IMEM=assembly.hex sim
