org 100h
   mov AX, NUM1
   mov bx, NUM2
   MUL bx
   xchg al, ah
   DIV bx
   mov quotient, ah
   mov reminder, al
ret
NUM1 dw 12H
NUM2 dw 13H
quotient dw ? 
reminder dw ? 