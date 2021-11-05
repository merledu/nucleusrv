OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv",
	      "elf32-littleriscv")
OUTPUT_ARCH(riscv)

MEMORY 
{
DCCM  : ORIGIN = 0x00000000, LENGTH = 4K
}

PROVIDE( __stack_top = ORIGIN(DCCM) + LENGTH(DCCM));