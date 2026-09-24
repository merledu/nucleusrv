OUTPUT_FORMAT("elf32-littleriscv", "elf32-littleriscv", "elf32-littleriscv")
OUTPUT_ARCH(riscv)

SECTIONS
{
  /* Reset PC is 0 — code must live at 0 for FPGA $readmemh (flat) images. */
  . = 0x0;
  .text : { *(.text.init) *(.text) *(.text.*) }
  . = ALIGN(0x2000);
  .data : { *(.data) }
  .data.string : { *(.data.string)}
  .bss : { *(.bss) }
  _end = .;
}
