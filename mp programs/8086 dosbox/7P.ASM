assume cs:code
code segment 
start:    
    mov ah,2ch
    int 21h
    mov al,cl
    call disp
    
    mov dl,':'
    mov ah,02
    int 21h
    
    mov al,cl
    call disp
    mov ah,4ch
    int 21h
    
    disp proc
        
        aam
        add ax,3030h
        mov bx,ax
        mov dl,ah
        mov ah,02
        int 21h
        mov bx,ax
        mov dl,bl
        mov ah,02
        int 21h
         ret
         disp endp
    
    code ends
end start
           
        
    
