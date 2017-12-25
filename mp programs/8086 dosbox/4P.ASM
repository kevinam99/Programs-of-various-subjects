assume cs:code,ds:data
data segment
    n db 4 
    res db ?
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        
        mov al,n
        call fact
        mov ah,4ch
        int 21h
        
        fact proc
            
            cmp al,00
            je result
            push ax
            dec al
            call fact
            pop ax
            mul res
            mov res,al
            ret
        result:
            mov res,01
            ret
        fact endp
        
        code ends
end start

                        
        
