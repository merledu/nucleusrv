OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(_start)

SECTIONS
{
  . = 0x0000;
  .text.init : { *(.text.init) }
  .text : { *(.text) *(.text.*) }
  .rodata : { *(.rodata) *(.rodata.*) }
  .data : { *(.data) *(.data.*) }
  .sdata : { *(.sdata) *(.sdata.*) }
  .bss : { *(.bss) *(.bss.*) *(COMMON) }
  . = ALIGN(4);
  _end = .;
  __stack_top = 0x3FF0;
}
