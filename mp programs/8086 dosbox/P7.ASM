assume cs:code
code segment
start:
        mov ah,2ch
        int 21h
        mov al,ch
        call calculate
        mov dl,':'
        mov ah,02h
        int 21h
        mov al,cl        
        call calculate
       ; mov dl,':'
       ; mov ah,02h
       ; int 21h
       ; mov ah,dh        
       ; call calculate
        mov ah,4ch
        int 21h
calculate proc
        aam
        add ax,3030h
        mov bx,ax
        mov dl,ah
        mov ah,02h
        int 21h
       ; mov bx,ax
        mov dl,bl
        mov ah,02h
        int 21h
        ret
        calculate endp
        code ends
        end start
        

