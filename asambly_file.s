    .text
    .global     min_data_vec_32
# void min_data_vec_32(int32_t *dest_data, int32_t *src1, int32_t *src2, int data_num);
# a0=dest, a1=src1, a2=src2, a3=n
#
min_data_vec_32:
.loop_32:
    addi    a3,x0,3
    vsetvli t0, a3, e32,m1   # Vectors of 8b
    addi    t0,x0,3
    slli    t1, t0, 2       # shift 2-bit
    addi a1,x0,10
    vle32.v v0, (a1)        # Load bytes
    add     a1, a1, t1  	# Bump pointer
    vle32.v v1, (a2)        # Load bytes
    add     a2, a2, t1  	# Bump pointer
    sub     a3, a3, t0  	# Decrement count
    vmin.vv v2, v1, v0      # Vector Sub
    vse32.v v2, (a0)    	# Store bytes
    add     a0, a0, t1  	# Bump pointer
    bnez    a3, .loop_32   	# Any more?
    ret  
