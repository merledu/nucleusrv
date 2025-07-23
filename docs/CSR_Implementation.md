# CSR (Control and Status Register) Implementation for NucleusRV

## Overview

This implementation adds comprehensive CSR support to the NucleusRV RISC-V processor, including:

- **CSR Instructions**: CSRRW, CSRRS, CSRRC, CSRRWI, CSRRSI, CSRRCI
- **System Instructions**: ECALL, EBREAK, MRET  
- **Exception Handling**: Basic trap and interrupt support
- **Performance Counters**: Cycle and instruction retire counters
- **Machine Mode**: Full machine-level privilege mode support

## Files Added/Modified

### New Files
- `src/main/scala/components/CSR.scala` - CSR register file implementation
- `src/main/scala/components/CSRUnit.scala` - CSR execution unit
- `tools/tests/csr_test/csr_test.S` - Assembly test program
- `tools/tests/csr_test/main.c` - C test program

### Modified Files
- `src/main/scala/components/Constants.scala` - Added CSR and instruction constants
- `src/main/scala/components/Control.scala` - Added CSR control signals
- `src/main/scala/components/InstructionDecode.scala` - Added CSR decode logic
- `src/main/scala/components/Core.scala` - Integrated CSR pipeline

## CSR Registers Implemented

### Machine Information Registers (Read-Only)
- **MVENDORID** (0xF11) - Vendor ID (0x0)
- **MARCHID** (0xF12) - Architecture ID (0x0)  
- **MIMPID** (0xF13) - Implementation ID (0x1)
- **MHARTID** (0xF14) - Hardware Thread ID (0x0)

### Machine Trap Setup
- **MSTATUS** (0x300) - Machine status register
- **MISA** (0x301) - ISA and extensions (RV32IM)
- **MIE** (0x304) - Machine interrupt enable
- **MTVEC** (0x305) - Machine trap vector base address

### Machine Trap Handling  
- **MSCRATCH** (0x340) - Machine scratch register
- **MEPC** (0x341) - Machine exception program counter
- **MCAUSE** (0x342) - Machine exception cause
- **MTVAL** (0x343) - Machine trap value
- **MIP** (0x344) - Machine interrupt pending

### Machine Performance Counters
- **MCYCLE** (0xB00) - Machine cycle counter (low 32 bits)
- **MINSTRET** (0xB02) - Machine instructions retired (low 32 bits)
- **MCYCLEH** (0xB80) - Machine cycle counter (high 32 bits)
- **MINSTRETH** (0xB82) - Machine instructions retired (high 32 bits)

## Instruction Support

### CSR Instructions
- **CSRRW** rd, csr, rs1 - Atomic Read/Write CSR
- **CSRRS** rd, csr, rs1 - Atomic Read and Set Bits in CSR
- **CSRRC** rd, csr, rs1 - Atomic Read and Clear Bits in CSR
- **CSRRWI** rd, csr, zimm - CSRRW with immediate
- **CSRRSI** rd, csr, zimm - CSRRS with immediate  
- **CSRRCI** rd, csr, zimm - CSRRC with immediate

### System Instructions
- **ECALL** - Environment Call (generates exception)
- **EBREAK** - Breakpoint (generates exception)
- **MRET** - Machine Return (returns from trap)

## Exception Handling

### Exception Causes Supported
- **0**: Instruction address misaligned
- **1**: Instruction access fault
- **2**: Illegal instruction
- **3**: Breakpoint (EBREAK)
- **8**: Environment call from U-mode
- **9**: Environment call from S-mode  
- **11**: Environment call from M-mode

### Exception Flow
1. **Exception occurs** → PC saved to MEPC, cause to MCAUSE
2. **Privilege escalation** → Switch to Machine mode
3. **Jump to handler** → PC set to MTVEC value
4. **Handler executes** → Process exception
5. **MRET** → Restore PC from MEPC, return to previous mode

## Pipeline Integration

### Decode Stage
- Detects CSR and system instructions
- Generates appropriate control signals
- Extracts CSR address from instruction

### Execute Stage  
- CSRUnit performs CSR operations
- Handles exception detection
- Manages trap vector generation

### Memory Stage
- Forwards CSR data through pipeline
- Manages exception/trap state

### Write-Back Stage
- Writes CSR data to register file (memToReg = 3)
- Updates PC for traps and MRET

## Usage Examples

### Reading CSR
```assembly
csrr x1, mhartid    # Read hardware thread ID into x1
```

### Writing CSR
```assembly
li x2, 0x1800       # Load value
csrw mstatus, x2    # Write to machine status
```

### Setting/Clearing Bits
```assembly
csrs mie, x3        # Set interrupt enable bits
csrc mie, x4        # Clear interrupt enable bits
```

### Exception Handling
```assembly
# Setup trap handler
la x1, trap_handler
csrw mtvec, x1

# Trigger exception
ecall

trap_handler:
    csrr x2, mcause   # Read exception cause
    csrr x3, mepc     # Read exception PC
    # Handle exception...
    mret              # Return from trap
```

## Testing

### Assembly Tests
- `tools/tests/csr_test/csr_test.S` - Comprehensive assembly test
- Tests all CSR instructions and exception handling

### C Tests  
- `tools/tests/csr_test/main.c` - C language test with macros
- Demonstrates practical CSR usage

### Unit Tests
- `src/test/scala/components/CSRUnitTest.scala` - Chisel unit tests
- Verifies CSR functionality at module level

## Performance Impact

- **Minimal area overhead** - Only ~500 lines of new Chisel code
- **Single cycle CSR operations** - CSR instructions execute in normal pipeline
- **Fast exception handling** - Single cycle trap entry/exit
- **Performance counters** - Built-in cycle and instruction counting

## Compliance

This implementation provides the foundation for:
- **RISC-V Privileged ISA v1.11** compliance  
- **RV32I** system instruction support
- **Machine mode** privilege level
- **Basic exception handling** as per RISC-V spec

## Future Enhancements

- User and Supervisor privilege modes
- Virtual memory support (MMU)
- Interrupt controller integration
- Additional performance counters
- Debug mode support
