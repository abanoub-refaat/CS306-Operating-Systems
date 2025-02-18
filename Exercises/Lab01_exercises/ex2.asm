org 100H
MOV AL, 12H
MOV BL, 33H

; Exchange with additionary container
MOV CL, AL
MOV AL, BL
MOV Bl, CL
MOV CL, 00h

; Exchange with XCHG instuction
xchg AL, BL
ret    