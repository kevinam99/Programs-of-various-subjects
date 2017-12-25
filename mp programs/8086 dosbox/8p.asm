assume cs:code, ds:data
data segment
     fname2 db "hari.txt",0
     msg1 db "File created successfully$"
     fname1 db "emp.dat"
     msg2 db "File deleted successfully$"
code segment
start:    
     mov ax,data
     mov ds,ax

     mov ah,3ch
     mov cx,00
     lea dx,fname2
     int 21h
     jc next
     
     lea dx,msg1
     mov ah,09h
     int 21h
     
     
next:
     mov ah,41h
     lea dx,fname1
int 21h
     jc finish
     lea dx,msg2
     mov ah,09h
     int 21h
finish:
     mov ah,4ch
     int 21h
code ends
end start
