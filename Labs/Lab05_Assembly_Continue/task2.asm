; given array of 1 3 and array of 2 4, merge 2 sorted array into one.

ORG 100h
    lea si, arr1
    lea di, arr2
    lea bp, ans

    mov al, [si]
    mov bl, [di]
    cmp al, bl
    jb l1

    mov [bp], bl
    mov [bp + 1], al

    jmp break_above

    l1:
        mov [bp], al
        mov [bp + 1], bl
        jmp break_below

    break_above:
        mov al, [si + 1]
        mov bl, [di + 1]
        mov [bp + 2], bl
        mov [bp + 3], al
        jmp break

    break_below:
        mov al, [si + 1]
        mov bl, [di + 1]
        mov [bp + 2], al
        mov [bp + 3], bl
        jmp break

    break:
RET
arr1 db 1, 3
arr2 db 2, 4
ans db 4 dup(?)