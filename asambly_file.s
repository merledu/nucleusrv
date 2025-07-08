.section .text
.global _start
_start:
    # Step 1: Set up base addresses using x2 (Assuming x2 contains a valid memory base)
    addi x3, x2, 0x00   # Base address for array1
    addi x4, x2, 0x10   # Base address for array2
    addi x5, x2, 0x20   # Base address for result

    # Step 2: Store values into memory using `sw`
    addi x6, x0, 1     # x6 = 1
    addi x7, x0, 2     # x7 = 2
    addi x8, x0, 3     # x8 = 3
    addi x9, x0, 4     # x9 = 4

    sw x6, 0(x3)       # Store 1 at array1[0]
    sw x7, 4(x3)       # Store 2 at array1[1]
    sw x8, 8(x3)       # Store 3 at array1[2]
    sw x9, 12(x3)      # Store 4 at array1[3]

    addi x10, x0, 5    # x10 = 5
    addi x11, x0, 6    # x11 = 6
    addi x12, x0, 7    # x12 = 7
    addi x13, x0, 8    # x13 = 8

    sw x10, 0(x4)      # Store 5 at array2[0]
    sw x11, 4(x4)      # Store 6 at array2[1]
    sw x12, 8(x4)      # Store 7 at array2[2]
    sw x13, 12(x4)     # Store 8 at array2[3]

    # Step 3: Load data into vector registers
    li t0, 4           # Load vector length (4 elements)
    vsetvli t0, t0, e32 # Set vector length for 32-bit elements

    vle32.v v0, (x3)   # Load array1 into v0
    vle32.v v1, (x4)   # Load array2 into v1

    # Step 4: Perform vector addition
    vadd.vv v2, v0, v1 # v2 = v0 + v1 (element-wise addition)

    # Step 5: Store the result
    vse32.v v2, (x5)   # Store v2 into memory (result array)

    # Exit program (optional)
    li a7, 10          # syscall for exit