org 100h
    mov al, var1
    mov bl, var2

    cmp al, bl
    ja l

    ; al <= bl
    mov max, bl
    mov min, al
    jmp skip

    ; al > bl
    l:
        mov max, al
        mov min, bl
    
    skip:
ret
var1 db 5
var2 db 6
max db ?
min db ?