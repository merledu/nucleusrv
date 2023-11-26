.text
.global main
main:
    addi x1 , x0,42
    addi x2 , x0 , 10
    addi x3 , x0 , 120
    addi x4 , x0, 135
    vsetvli x1,x2, e16, m8,ta,mu
    vadd.vx v10, v1, x3
    addi x21 , x0,120
    addi x22 , x0 , 80
    addi x23 , x0,120
    vse32.v v10 ,(x2)
