; Ex_22: Find the final values of AX and BX registers in the following Assembly program?

ORG 100H 
 MOV AX, 5
 MOV BX, 2
 ; AX = 5, BX = 2

 JMP S1
 BACK: INC AX ; AX = 4

 JMP S2

 S1: SUB AX, BX ; AX = 3
 JMP BACK

 S2: DEC BX ; BX = 1

RET

; The values of AX and BX after excuing the previous code is 4, 1 respectivly.