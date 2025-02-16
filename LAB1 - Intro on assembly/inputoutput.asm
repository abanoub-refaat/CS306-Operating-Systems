.model small
.code 

    mov ah, 1h ;code for read characters
    int 21h
    mov dl, al ;copy characters to dl

    mov ah, 2h ;code for write characters
    int 21h    ;displays character in dl

end