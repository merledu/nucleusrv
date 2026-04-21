NucleusRV 5-Stage Pipeline Architecture
=======================================

NucleusRV uses a classic 5-stage pipeline to achieve balanced throughput and frequency.

Pipeline Stages
---------------

1. **Instruction Fetch (IF)**: Fetches instructions from instruction memory. Includes the PC unit, Realigner, and Compressed Decoder.
2. **Instruction Decode (ID)**: Decodes the instruction, reads the register file, and generates control signals. Includes the Immediate Generator and Hazard Unit.
3. **Execute (EX)**: Performs ALU operations, multiplication, division, and floating-point operations. Handles data forwarding.
4. **Memory (MEM)**: Accesses data memory for load and store instructions. Manages atomic memory operations.
5. **Write-Back (WB)**: Writes results back to the register file.

Hazard Handling
---------------

- **Data Hazards**: Handled via forwarding from EX and MEM stages to the ID stage.
- **Load-Use Hazards**: Handled by stalling the pipeline for one cycle.
- **Control Hazards**: Branches and jumps are resolved in the ID stage, resulting in a 1-cycle penalty for taken branches.
- **Atomic Hazards**: Special handling for read-modify-write sequences in the MEM stage.

Pipeline Registers
------------------

Inter-stage registers are named following the ``<stage>_reg_<signal>`` pattern (e.g., ``if_reg_pc``, ``ex_reg_result``).
