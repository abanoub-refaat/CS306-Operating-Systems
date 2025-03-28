include 'emu8086.inc'
org 100h  
    ; initialization  
    mov bl, data[si] 
    mov al, data[si]
    
    mov max, al
    mov min, bl
    
    ; initialize cx to 8
    mov cx, 8
            
    inc si
    ; start the loop
    l1:        
        mov dl, data[si]
        cmp dl, max   ; compare dl with max
        ja a
        jmp skip
        ; if al > max
        a:
            mov max, dl
        
        skip:
        cmp dl, min
        jb b
        jmp fskip
        
        ; if dl < min
        b:
            mov min, dl
        
        fskip:
        ; increament si to the next element in data
        inc si
    loop l1
ret
data db 2, 1, 3, 4, 5, 6, 10, 11
min db ?
max db ?