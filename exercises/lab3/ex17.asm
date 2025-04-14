ORG 100H 
 LEA SI, MARKS
 LEA DI, COPY

 MOV CX, 3
 copy_loop:
    MOV AL, [SI]
    MOV [DI], AL
    INC SI
    INC DI
 LOOP copy_loop

RET 
MARKS DB 10, 20, 30
COPY DB 3 DUP(?)