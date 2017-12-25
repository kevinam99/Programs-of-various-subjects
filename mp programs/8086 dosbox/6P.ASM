assume cs:code
code segment
start:
    ;mov ax,data
    ;mov ds,ax  
    
    mov ah,00
    mov al,02
    int 10h
    
    mov ah,02
    mov dh,12d
    mov dl,40d
    int 10h
    
    
    mov al,'X'
    mov bl,8ch
    mov cl,01
    mov ah,09
    int 10h
    
    mov ah,4ch
    int 21h
    
    code ends
end start
    
    
    
    
        
        
    
