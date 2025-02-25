; add sub
; mul div
; xchg
; db dw
; and or xor
; inc ;dec
; not neg


org 100h

    mov al, 10101111b
    mov bl, al
    ; one's complement
    not al 

    ; two's complement = one's complement + 1
    inc al 
    neg bl

ret
