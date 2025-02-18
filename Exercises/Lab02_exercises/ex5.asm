org 100H 
   mov AX, N 
   mov bx, 4 
   MUL bx
   mov cx, 3 
   MUL cx
   mov dx, 2
   MUL dx
   mov FACT, AX
ret
N dw 5
FACT dw ? 