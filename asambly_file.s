.text
.global main
main:
    addi    x1 ,x0 ,5 
    vsetvli x5, x1, e32,m1
    addi    x10, t0, 2 
    addi    x11, t0, 2 
    addi    x12, t0, 2 
    addi    x13, t0,100
    vle32.v v1, (a2)
    add     a2, a2, t1
    sub     a3, a3, t0
    addi    a1, x0 , 27
    vadd.vx v2, v1, a1
    vadd.vx v3, v1, a1
    vadd.vx v4, v1, a1
    vadd.vx v5, v1, a1
    addi    a0  ,x0 ,200
    vse32.v v2, (a0)
    add     a1, a0, t1
    vle32.v   v10, (a0)
