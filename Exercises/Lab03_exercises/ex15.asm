org 100h
mov si offset marks
mov al, [si]
add al, [si + 1]
add al, [si +2]

mov sum, al
mov bl, 3
div bl ; calculate the average

mov avg_q, al ; store the average
mov avg_r, ah ; store the average

ret
marks db 60, 80, 90
sum db ?
avg_q db ?
avg_r db ?