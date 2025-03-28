; task1
org 100h

    mov al, var[0]
    add al, var[1]
    add al, var[2]
    add al, var[3]

    mov sum, al

ret
var db 1, 2, 3, 4
sum db ?