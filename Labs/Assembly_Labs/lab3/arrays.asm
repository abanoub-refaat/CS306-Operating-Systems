; arrays 
org 100h
    mov al, var1[0]
    mov bx, var2[2] ; moves two memory locations
ret
var1 db 12h, 23h, 34h, 56h ; defining an array
var2 dw 12h, 23h, 34h, 56h ; at first var2 has the first value (so we should move it with the index to get the rest).


; indirect memory indexing location
org 100h
mov si, offset arr ;
inc si ;si = 2
mov al, [si  + 2]
ret
arr db 1, 2, 3, 4