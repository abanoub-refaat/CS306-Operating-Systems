; given the array -5, 4, -2, 0, 4, 7, 1 store the min and max with only one loop

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
        jg a
        jmp skip
        ; if al > max
        a:
            mov max, dl
        
        skip:
        cmp dl, min
        jl b
        jmp fskip
        
        ; if dl < min
        b:
            mov min, dl
        
        fskip:
        ; increament si to the next element in data
        inc si
    loop l1
ret
data db -5, 4, -2, 0, 4, 7, 1
min db ?
max db ?