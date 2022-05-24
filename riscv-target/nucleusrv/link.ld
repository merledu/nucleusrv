OUTPUT_ARCH( "riscv" )
ENTRY(_start)

MEMORY
{
	ICCM  : ORIGIN = 0x20000000, LENGTH = 16K
	DCCM  : ORIGIN = 0x10000000, LENGTH = 4K
}

SECTIONS
{
  . = 0x00000000;
  .text : { *(.text) }
  .text.init : { *(.text.init) }
  . = ALIGN(0x1000);
  .tohost : { *(.tohost) }
  . = ALIGN(0x2000);
  .data : { *(.data) }
  .data.string : { *(.data.string)}
  .bss : { *(.bss) }
  _end = .;
}