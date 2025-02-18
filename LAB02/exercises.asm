; Q1:
;org 100h  
;    mov AL, var1
;    mov bl, var2
;    MUL bl
;    mov answer, al
;ret
;var1 db 00000001b
;var2 db 00000010b   
;answer db ?

; Q2:
;org 100h 
;    mov ax, var1
;    mov bl, var2
;    DIV bl
;    mov answer, ax
;    
;ret
;var1 dw 0000000000000100b
;var2 db 0000010b
;answer dw ?
    
;Q3:
;org 100H
;    mov bx, 12H
;    mov cx, 32H
;    XCHG bx, cx
;ret    

;Q4:
;org 100H  
;    mov AX, LENGTH
;    mov BX, WIDTH
;    MUL BX
;    mov AREA, AX
;ret
;LENGTH dw 12H
;WIDTH dw 34H
;AREA dw ?   

;Q5:
;org 100H 
;    mov AX, N 
;    mov bx, 4 
;    MUL bx
;    mov cx, 3 
;    MUL cx
;    mov dx, 2
;    MUL dx
;    mov FACT, AX
;ret
;N dw 5
;FACT dw ? 
;org 100h
;    mov AX, NUM1
;    mov bx, NUM2
;    MUL bx
;    xchg al, ah
;    DIV bx
;    mov quotient, ah
;    mov reminder, al
;ret
;NUM1 dw 12H
;NUM2 dw 13H
;quotient dw ? 
;reminder dw ? 