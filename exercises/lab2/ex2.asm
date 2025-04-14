org 100h 
   mov ax, var1
   mov bl, var2
   DIV bl
   mov answer, ax
ret
var1 dw 0000000000000100b
var2 db 0000010b
answer dw ?