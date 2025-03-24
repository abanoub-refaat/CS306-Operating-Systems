; Ex_24: How many times will the loop executes in the following Assembly program?

ORG 100H
 MOV AX, 0
 MOV CX, 0

 L1:
    INC AX
 LOOP L1
RET
; Because the LOOP instruction sees CX = 0, decrements it to FFFFh, and never reaches 0 again logically.