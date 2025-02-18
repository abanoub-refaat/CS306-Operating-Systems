org 100h

MOV AL, 000000B
OR AL, 100000B   
XOR AL, 00011B  ; flip
ret      

; MUL , DIV, VARS 
; Storing hello! in reverse
ORG 100H
MOV [1200H], 'he'
MOV [1202H], 'll'
MOV [1204H], 'o!'
RET

ORG 100H
MOV BX, 3
MUL AX, 1234H ;Will not work

; but this will work
mov AX, 3
mov Bx, 3
MUL Bx ; AX = AX * BX
; Multiplication always happen in AX.
ret
       
       ; mul BL :: Ax = al * bl
       ; mul BX :: ax * bx                              
                                     
ORG 100h
mov AX, 4
mov Bx, 3 ; we are using words so the overflow will go to the DX
; if we were using AL, the reminder will go to the AH and viseversa.

DIV BX
ret                                     
var1 db 12h
var2 db 13h
var3 db ? ; we are not going to initialize it.