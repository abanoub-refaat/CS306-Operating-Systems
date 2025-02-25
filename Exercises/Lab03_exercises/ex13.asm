org 100h

mov bx, 6000
mov ax, 20
mov cx, 100

mul bx
div cx

sub bx, ax
mov res, bx

ret
res dw ?