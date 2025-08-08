OUTPUT_ARCH( "riscv" )
ENTRY(rvtest_entry_point)

MEMORY
{
	ICCM  : ORIGIN = 0x00000000, LENGTH = 1073741824
	DCCM  : ORIGIN = 0x40000000, LENGTH = 1073741824
}

SECTIONS
{
  . = 0x00000000;
  .text.init : { *(.text.init) } > ICCM
  .text : { *(.text) } > ICCM
  .data : { *(.data) } > DCCM
  .data.string : { *(.data.string)} > DCCM
  .bss : { *(.bss) } > DCCM
  _end = .;
}

