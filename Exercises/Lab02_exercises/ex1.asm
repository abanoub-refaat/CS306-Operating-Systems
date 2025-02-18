org 100h  
   mov AL, var1
   mov bl, var2
   MUL bl
   mov answer, al
ret
var1 db 00000001b
var2 db 00000010b   
answer db ?