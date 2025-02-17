mov cx, 1234H
mov al, ch 
mov [bx], cx
mov dl, [bx]
mov ah, [bx + 1]
mov ax, 34CDH
mov ss, ax
mov [0A300H], ss 
mov es, [0A300H]
xchg al,cl
ret