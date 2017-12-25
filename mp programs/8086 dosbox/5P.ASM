assume cs:code,ds:data
data segment
    x db 10 dup(?)
data ends
code segment
start:
    mov ax,data
    mov ds,ax  
    
    lea si,x
    mov al,00
    mov [si],al
    inc si
    mov bl,01
    mov [si],bl
    
    mov cx,08
    inc si
next:
    add al,bl
    mov [si],al
    inc si
    xchg al,bl
    loop next
    
    mov ah,4ch
    int 21h
code ends
end start
        
    
