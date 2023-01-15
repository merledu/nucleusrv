Instruction Fetch
=================

.. figure:: images/if_module.svg
   :name: if_stage
   :align: center

   Instruction Fetch (IF) stage

The Instruction Fetch (IF) stage fetches one instruction from the memory, increments the PC and supplys the instruction to Instruction Decode (ID) stage. It serves one instruction per cycle.

The core supports misaligned instruction address by allowing the program counter to increment by 2. This happens when a compressed instruction is encountered. The :code:`is_comp` signal denotes that whehter we have received compressed instruction.

We cannot pass misaligned address that we may have ended up with after incrementing the program counter by 2 and thats where the Realigner module comes in. This module takes as input the instruction address (PC) and corresponding instruction and make sures that instruction address (PC) is word aligned. The module operates as follows: If the address is aligned, it is passed to instruction memory to fetch the instruction as is. If it is misaligned, the state machine performs the following actions:

1. Store the upper half-word of current instruction, halt the PC for one cycle, and send the address to the next instruction. Meanwhile, NOP will be fed to the core.

2. After one cycle, when the instruction arrives, the lower half-word of this instruction is concatenated with the previously stored upper-half word. And this new instruction will be fed to the core.

The instruction is then passed to Compressed Decoder which decodes the 16 bit instruction instruction into its equivalent 32 bit instruction and also sets the :code:`is_comp` flag. The next pc address is calculated on the basis of this flag, that is, it increments by 2 if it is true and by 4 if false. 

The calculations for jump and branch addresses are done in Instruction Decode stage and then passed to Instruction fetch when the branch is taken.
