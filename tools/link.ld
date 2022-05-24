OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv",
	      "elf32-littleriscv")
OUTPUT_ARCH(riscv)

SECTIONS
{
  . = 0x00000000;
  .text : { *(.text) }
  .text.init : { *(.text.init) }
  . = ALIGN(0x2000);
  .data : { *(.data) }
  .data.string : { *(.data.string)}
  .bss : { *(.bss) }
  _end = .;
}