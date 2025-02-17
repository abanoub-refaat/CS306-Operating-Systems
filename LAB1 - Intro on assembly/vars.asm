; to define variables we write the variables after the ret keyword
mov ah, var1
mov dl, var2
xchg ah, dl
mov bh, a[0]
mov bl, a[1]
mov dh, a[4]  
mov cl, b[8]
; We can define vars befor the `ret` keyword using the `EQU` keyword
c EQU 6
mov ah, c
ret
; defining the vars we want.
var1 DB 12H
var2 DB 59H
a DB 12H,34H,11H,48H,98H ;An array of length 5. 
b DB 10 DUP (95H) ;An array of length 10 all element are 95H.