; task2
org 100h
    mov al, var[0]
    mov copy[0], al

    mov al, var[1]
    mov copy[1], al

    mov al, var[2]
    mov copy[2], al

    mov al, var[3]
    mov copy[3], al
ret
var db 9, 8, 7, 6
copy db 4 dup(?) ; copy will be 4 element and all of them are ? (dont have a value)