.text
.global main
main:
    addi x1 , x0, 12
    addi x2 , x0 , 8
    addi x3 , x0 , 12
    addi x4 , x0, 15
    addi x5 , x0, 10
    vsetvli x1,x5, e32, m4,tu,mu
    vadd.vx v15, v1, x4
    vse32.v v15 ,(x3)
    vadd.vx v20, v1 , x4
    vle32.v v25, (x1)
    addi x21 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse32.v v20 ,(x21)
    vle32.v v6, (x23)
