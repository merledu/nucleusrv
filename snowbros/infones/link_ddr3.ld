/* Linker script for NucleusRV DOOM running from DDR3 SDRAM (0x10000000) */
OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
  DDR3_EXEC (rwx) : ORIGIN = 0x10000000, LENGTH = 8M
}

SECTIONS
{
  . = 0x10000000;

  .text.init : ALIGN(4) {
    KEEP(*(.text.init))
  } > DDR3_EXEC

  .text : ALIGN(4) {
    *(.text)
    *(.text.*)
  } > DDR3_EXEC

  .rodata : ALIGN(4) {
    *(.rodata)
    *(.rodata.*)
  } > DDR3_EXEC

  .data : ALIGN(4) {
    *(.data)
    *(.data.*)
    *(.sdata)
    *(.sdata.*)
  } > DDR3_EXEC

  .bss : ALIGN(4) {
    __bss_start = .;
    *(.sbss)
    *(.sbss.*)
    *(.bss)
    *(.bss.*)
    *(COMMON)
    __bss_end = .;
  } > DDR3_EXEC

  . = ALIGN(16);
  _end = .;

  /* Stack at the top of 8MB executable area */
  __stack_top = 0x107FFFF0;
}
