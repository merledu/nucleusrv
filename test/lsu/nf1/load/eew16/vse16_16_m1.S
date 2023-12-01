.text
.global main
main:
    addi x1 , x0,40
    addi x2 , x0 , 80
    addi x3 , x0 , 120
    addi x4 , x0, 135
    vsetvli x1,x2, e16, m1,tu,mu
    vadd.vx v10, v1, x3
    vadd.vx v11, v1 , x4
    addi x12 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse16.v v10 ,(x2)
    vse16.v v11 ,(x3)
    addi x5 , x0 , 10
    vle16.v v1, (x12)
