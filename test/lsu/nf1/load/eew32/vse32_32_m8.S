.text
.global main
main:
    addi x1 , x0,40
    addi x2 , x0 , 80
    addi x3 , x0 , 120
    addi x4 , x0, 135
    vsetvli x1,x2, e32, m8,tu,mu
    vadd.vx v2, v1, x3
    vadd.vx v10, v1 , x4
    addi x21 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse32.v v2 ,(x2)
    vle32.v v19, (x22)
