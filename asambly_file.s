.text
.global main
main:
    addi    x1 ,x0 ,5 
    vsetvli x5, x1, e32,m1
    addi    x10, t0, 2 
    addi    x11, t0, 2 
    addi    x12, t0, 2 
    addi    x13, t0,100
    vmv.v.i	v29,-16
    vse32.v v29, (a0)
    add     a1, a0, t1
    vle32.v   v30, (a0)
