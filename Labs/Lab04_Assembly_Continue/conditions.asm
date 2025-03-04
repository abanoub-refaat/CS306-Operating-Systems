org 100h
    mov al, 5
    mov bl, 6

    cmp al, bl ;compare al by bl
    ; if equal
    je l ;jump equal and jump to l.
    
    ; if not
    mov dl, 2
    jmp stop ; if not equal go to stop.

    l:
    mov dl, 1
    stop:
ret
; la, lne, la, lb, lae, jbe unsigned
; la, lne, jg, jl, jga, jle signed