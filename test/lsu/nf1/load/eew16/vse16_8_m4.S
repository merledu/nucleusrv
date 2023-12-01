.text
.global main
main:
    addi x1 , x0, 8
    addi x2 , x0 , 8
    addi x3 , x0 , 12
    addi x4 , x0, 15
    vsetvli x1,x2, e8, m4,tu,mu
    vadd.vx v10, v1, x3
    vse16.v v15 ,(x2)
    vadd.vx v20, v1 , x4
    vle16.v v25, (x1)
    addi x21 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse16.v v1 ,(x21)
    vle16.v v6, (x23)
