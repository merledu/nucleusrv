/*
 * linker.ld
 *
 * This linker script maps the .text and .data sections to two different
 * memory regions, corresponding to the separate imem and dmem in the
 * Chisel Top.scala design.
 */

OUTPUT_ARCH(riscv)
ENTRY(_start) /* Specify the entry point of our code */

MEMORY
{
  /*
   * imem: Instruction memory (Read-Only, Executable)
   * The CPU will start fetching instructions from here.
   */
  imem (rx) : ORIGIN = 0x00000000, LENGTH = 4K

  /*
   * dmem: Data memory (Read-Write)
   */
  dmem (rw) : ORIGIN = 0x00010000, LENGTH = 4K
}

SECTIONS
{
  /*
   * Place the .text section (all executable code) into the 'imem' region.
   */
  .text : {
    *(.text)
  } > imem

  /*
   * Place the .data section (initialized variables) into the 'dmem' region.
   */
  .data : {
    *(.data)
  } > dmem
}
