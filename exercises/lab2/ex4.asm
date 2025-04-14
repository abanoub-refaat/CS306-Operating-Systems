org 100H  
   mov AX, LENGTH
   mov BX, WIDTH
   MUL BX
   mov AREA, AX
ret
LENGTH dw 12H
WIDTH dw 34H
AREA dw ?