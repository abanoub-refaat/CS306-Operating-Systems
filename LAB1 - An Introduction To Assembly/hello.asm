.model tiny  ; com program, code data 
.code        ; code segment

org 100h     ; code starts at offset 100h


main proc near

mov ah, 09h
mov dx, offset message ; offset of Message string terminating with $
int 21h

mov ah,4ch
mov al, 00
int 21h

endp
message db "Hello World $"
end main
