.text
.global main
main:
    addi x1 , x0, 4
    addi x2 , x0 , 80
    addi x3 , x0 , 13
    addi x4 , x0, 50
    vsetvli x1,x3, e32, m2,tu,mu
    vadd.vx v2, v1, x3
    vadd.vx v5, v1 , x4
    addi x21 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse32.v v8 ,(x2)
    vle32.v v12, (x22)
