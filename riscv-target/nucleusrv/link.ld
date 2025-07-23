OUTPUT_ARCH( "riscv" )
ENTRY(rvtest_entry_point)

MEMORY
{
	ICCM  : ORIGIN = 0x00000000, LENGTH = 64K
	DCCM  : ORIGIN = 0x00010000, LENGTH = 64K
}

SECTIONS
{
  .text.init : { *(.text.init) } > ICCM
  .text : { *(.text) } > ICCM
  .data : { *(.data) } > DCCM
  .data.string : { *(.data.string)} > DCCM
  .bss : { *(.bss) } > DCCM
  .tohost : { *(.tohost) } > DCCM
}

PROVIDE(_start = rvtest_entry_point);