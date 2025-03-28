; put the first 50 even numbers in e_nums array and the first 50 odd numbers in o_nums array using only one loop and indirect offset
org 100h     
  lea si, e_nums
  lea di, o_nums
  
  mov cl, 50
  lp:
     mov [si], bl 
     inc bl
     mov [di], bl  
     inc bl
     inc si 
     inc di
  loop lp 
ret
e_nums db 50 dup(?)
o_nums db 50 dup(?)