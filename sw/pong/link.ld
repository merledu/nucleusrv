OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)

MEMORY
{
  sram (rwx) : ORIGIN = 0x00000000, LENGTH = 32K
}

SECTIONS
{
  . = 0x00000000;
  . = ALIGN(8);

  .text : {
    . = ALIGN(8);
    *(.text.init)
    *(.text)
    *(.text.*)
  } > sram

  . = ALIGN(8);
  .rodata : {
    . = ALIGN(8);
    *(.rodata)
    *(.rodata.*)
  } > sram

  . = ALIGN(8);
  .data : {
    . = ALIGN(8);
    *(.data)
    *(.data.*)
    *(.sdata)
    *(.sdata.*)
  } > sram

  . = ALIGN(8);
  .bss : {
    . = ALIGN(8);
    *(.bss)
    *(.bss.*)
    *(.sbss)
    *(.sbss.*)
  } > sram

  . = ALIGN(8);
  _end = .;
}
