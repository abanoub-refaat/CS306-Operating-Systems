; to define variables we write the variables after the ret keyword
mov ah, var1
mov dl, var2
xchg ah, dl
ret
; defining the vars we want.
var1 DB 12H
var2 DB 59H