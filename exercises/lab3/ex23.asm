; Ex_23: What is the final values of AL and BL registers in the following Assembly program?

ORG 100H
 MOV AL, 4H
 MOV BL, 8H
 ; AL = 4H, BL = 8H
 MOV CX, 3

 L1:
    ADD AL, 2H
    INC BL
 LOOP L1
RET
; AL = 10H
; BL = 11H