ORG 100h
 ; Direct-offset Addressing
 MOV AL, VAR[0]
 MOV AH, VAR[1]
 MOV BL, VAR[2]
 MOV BH, VAR[3]
RET
VAR DB 10h, 11h, 12h, 13h