# Simple CSR Test for NucleusRV
# Tests basic CSR functionality without compliance framework complexity

.section .text.init
.globl _start
_start:

# Test 1: Basic CSR Write/Read (mstatus)
    li t0, 0x1800        # Set MIE and MPIE bits
    csrw mstatus, t0     # Write to mstatus
    csrr t1, mstatus     # Read back mstatus
    
    # Verify the write worked (at least some bits should match)
    li t3, 0x1800
    and t2, t1, t3       # Check if MIE/MPIE bits are set
    beqz t2, test_fail   # If zero, test failed

# Test 2: CSR Set Bits (mstatus)
    li t0, 0x08          # MPIE bit
    csrs mstatus, t0     # Set MPIE bit
    csrr t1, mstatus     # Read mstatus
    andi t2, t1, 0x08    # Check MPIE bit
    beqz t2, test_fail   # Should be set

# Test 3: CSR Clear Bits (mstatus) 
    li t0, 0x08          # MPIE bit
    csrc mstatus, t0     # Clear MPIE bit
    csrr t1, mstatus     # Read mstatus
    andi t2, t1, 0x08    # Check MPIE bit
    bnez t2, test_fail   # Should be cleared

# Test 4: CSR Write/Read with immediate (mtvec)
    csrwi mtvec, 0x10    # Write immediate to mtvec
    csrr t1, mtvec       # Read mtvec
    andi t2, t1, 0xFF    # Check lower bits
    li t3, 0x10
    bne t2, t3, test_fail

# Test 5: CSR Set with immediate (mie)
    csrsi mie, 0x08      # Set timer interrupt enable
    csrr t1, mie         # Read mie
    andi t2, t1, 0x08    # Check timer bit
    beqz t2, test_fail

# Test 6: CSR Clear with immediate (mie)
    csrci mie, 0x08      # Clear timer interrupt enable  
    csrr t1, mie         # Read mie
    andi t2, t1, 0x08    # Check timer bit
    bnez t2, test_fail   # Should be cleared

# Test 7: Multiple CSR access
    li t0, 0x12345678
    csrw mscratch, t0    # Write to mscratch
    csrr t1, mscratch    # Read back
    bne t0, t1, test_fail # Should match exactly

# Test 8: CSR swap operation
    li t0, 0x11111111
    li t1, 0x22222222
    csrw mscratch, t0    # Initial value
    csrrw t2, mscratch, t1  # Swap: t2 gets old value, mscratch gets t1
    bne t2, t0, test_fail   # t2 should have old value
    csrr t3, mscratch       # Read current value
    bne t3, t1, test_fail   # Should have new value

test_pass:
    # Signal test passed - write 0x1 to address 0x10000
    li t0, 0x10000
    li t1, 0x1
    sw t1, 0(t0)
    
    # Print success pattern to console (if any)
    li a0, 0xDEADBEEF    # Success pattern
    li a1, 0xCAFEBABE    # Another success pattern
    
    # Infinite loop to stop simulation
    j test_pass

test_fail:
    # Signal test failed - write 0x0 to address 0x10000  
    li t0, 0x10000
    li t1, 0x0
    sw t1, 0(t0)
    
    # Print failure pattern
    li a0, 0xDEADDEAD    # Failure pattern
    li a1, 0x12345678    # Another failure pattern
    
    # Infinite loop to stop simulation
    j test_fail
