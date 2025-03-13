; Lab 5 Content:
; cmp
; jump in unsigned: ja, jb, je, jne, jc, jnc
; jump in signed: jg, jl, je, jne
; --------------------------

; Example 1: For the unsigned
ORG 100h
    lea si, arr
    mov al, [si]
    inc si
    mov bl, [si]
    cmp al, bl
    ja l   ; is al > bl? if yes go to l

    mov max, bl
    mov min, al
    jmp break ; when we get here go to break to skip l

    l:
        mov max, al
        mov min, bl
    
    break:
RET
arr db 5,  10
max db ?
min db ?

; ----------------------------
; cbw and cwd : convert byte to word , convert word to byte
; Exampl 2: 
ORG 100h
    mov al, 011111111b
    mov al, 0ffh
    cbw ;the last move will be change from byte to word
RET

; ---------------------------
; flags: of, cf, 0f

; the cf and 0f will be 1 (they are used  by the unsigned)
ORG 100h
    mov al, 225
    add al, 1
RET
; sf = 1 and of = 1 (by the signed)
ORG 100h
    mov al, 127
    add al, 1
RET

; jc, jnc, adc
ORG 100h
    lea si, arr
    mov al, [si]
    mov cx, 2

    l:  
    inc si 
    add al, [si]
    jc l1; if a carry happend go to l1
    jmp break
        l1:
            adc ah, 0 ; ah = ah + 0 + cf
        break:
    loop l
    mov sum, ax
RET
arr db 255, 1, 1
sum dw ?

; ----------------------
; printing hello world using external libraries.
include 'emu8086.inc'
ORG 100h
    println 'hello world'
RET

