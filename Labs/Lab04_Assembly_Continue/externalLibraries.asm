include 'emu8086.inc'

org 100h
mov al, 1000000b
cbw ; copy byte word

mov ax, 0ffffh
cwd ; copy double word will copy to dx 
; they are used to transform a byte to a word and vice verca.

printn 'hello, world' ; print the string hello, world
ret