ORG 100h
    MOV CX, 15
    MOV BX, 1
    MOV AL, data[bx]
    MOV DL, 15
    l:
        ADD AL, data[BX+1]
        INC BX
    Loop l
    MOV sum, DL
    DIV DL
    MOV avg, AL
RET
data DB  00h, 01h, 02h, 03h, 04h, 05h, 06h, 07h, 08h, 09h, 0Ah, 0Bh, 0Ch, 0Dh, 0Eh, 0Fh
avg DB ?
sum DB ? 