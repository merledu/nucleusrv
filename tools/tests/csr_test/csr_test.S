# CSR Test Program
# This program tests basic CSR functionality including:
# - Reading machine information registers
# - Writing/reading scratch registers  
# - Exception handling with ECALL
# - Performance counter access

.section .text
.globl _start

_start:
    # Test 1: Read MHARTID (Hardware Thread ID)
    csrr x1, mhartid       # x1 = MHARTID (should be 0)
    
    # Test 2: Read MISA (ISA and extensions) 
    csrr x2, misa          # x2 = MISA register
    
    # Test 3: Write to MSCRATCH and read back
    li x3, 0xDEADBEEF     # Load test value
    csrw mscratch, x3      # Write to MSCRATCH
    csrr x4, mscratch      # Read back MSCRATCH (should equal x3)
    
    # Test 4: Set bits in MIE register
    li x5, 0x888          # Machine interrupt enable bits
    csrs mie, x5          # Set bits in MIE
    csrr x6, mie          # Read MIE register
    
    # Test 5: Clear bits in MIE register  
    li x7, 0x800          # Clear timer interrupt enable
    csrc mie, x7          # Clear bits in MIE
    csrr x8, mie          # Read MIE register
    
    # Test 6: CSR immediate operations
    csrwi mscratch, 15    # Write immediate to MSCRATCH
    csrr x9, mscratch     # Read back (should be 15)
    
    # Test 7: Read cycle counter (low)
    csrr x10, mcycle      # Read cycle counter low 32 bits
    
    # Test 8: Read instruction counter (low)
    csrr x11, minstret    # Read instruction retire counter
    
    # Test 9: Setup trap vector (for ECALL test)
    la x12, trap_handler  # Load trap handler address
    csrw mtvec, x12       # Set trap vector
    
    # Test 10: ECALL (system call) - this should trap to mtvec
    ecall                 # Trigger exception
    
    # If we get here, trap handling worked
    li x13, 0xC0FFEE     # Success marker
    
    # Test 11: EBREAK (breakpoint)
    ebreak                # Trigger breakpoint exception
    
    # End of program
    li x14, 0x600D        # End marker
    j end

trap_handler:
    # Simple trap handler
    csrr x15, mcause      # Read exception cause
    csrr x16, mepc        # Read exception PC
    
    # For ECALL, increment MEPC by 4 to skip the ecall instruction
    addi x16, x16, 4      # Skip past ecall
    csrw mepc, x16        # Write back incremented PC
    
    # Set success flag
    li x17, 0x7EAF        # Trap success marker
    
    # Return from trap
    mret                  # Return from machine mode

end:
    # Infinite loop to end program
    j end

.section .data
# Test data section
test_data:
    .word 0x12345678
    .word 0x9ABCDEF0
