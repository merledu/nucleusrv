#include <stdint.h>

// CSR access macros
#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })

#define swap_csr(reg, val) ({ unsigned long __tmp; \
  asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "rK"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "rK"(bit)); \
  __tmp; })

// Test CSR functionality
int main() {
    uint32_t val;
    
    // Read machine information registers
    val = read_csr(mhartid);   // Hardware thread ID
    val = read_csr(misa);      // ISA and extensions
    val = read_csr(mvendorid); // Vendor ID
    val = read_csr(marchid);   // Architecture ID
    val = read_csr(mimpid);    // Implementation ID
    
    // Test MSCRATCH register (read/write)
    write_csr(mscratch, 0xDEADBEEF);
    val = read_csr(mscratch);
    if (val != 0xDEADBEEF) {
        return 1; // Test failed
    }
    
    // Test CSR bit operations
    write_csr(mscratch, 0x0);
    set_csr(mscratch, 0xF0F0);    // Set some bits
    val = read_csr(mscratch);
    if (val != 0xF0F0) {
        return 2; // Test failed
    }
    
    clear_csr(mscratch, 0xF000);  // Clear some bits
    val = read_csr(mscratch);
    if (val != 0x00F0) {
        return 3; // Test failed
    }
    
    // Test swap operation
    val = swap_csr(mscratch, 0x1234);
    if (val != 0x00F0) {
        return 4; // Test failed
    }
    
    val = read_csr(mscratch);
    if (val != 0x1234) {
        return 5; // Test failed
    }
    
    // Read performance counters
    val = read_csr(mcycle);    // Cycle counter (low)
    val = read_csr(minstret);  // Instruction counter (low)
    
    return 0; // All tests passed
}
