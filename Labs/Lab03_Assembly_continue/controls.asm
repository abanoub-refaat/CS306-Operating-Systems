; lea (load effective address)
; loops
org 100h
lea si, marks

mov cx, 3 ;set the counter register to 3

lp:
    add al, [si]
    inc si
loop lp

; store the sum
mov sum, al

ret
marks db  60, 80, 90
sum db ?