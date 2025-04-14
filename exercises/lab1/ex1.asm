org 100H
    MOV AX, 1520H
    MOV SI, 0300H
    MOV [SI], 3040H
    ADD AX, [SI]
ret