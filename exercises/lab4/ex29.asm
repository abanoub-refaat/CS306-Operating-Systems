;Write a program in Assembly language that copies array of string named SOURCE, which has the following 41-characters 'Assembly language is a low level language', into another array named TARGET.

ORG 100
    MOV CX, 41
    MOV SI, 0

    l:
        MOV AL, source[SI]
        MOV target[SI], AL
        INC SI
    LOOP l
RET

source db 'Assembly language is a low level language'
target db 41 dup(?)