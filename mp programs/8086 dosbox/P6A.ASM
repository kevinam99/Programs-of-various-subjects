assume cs:code
code segment
start:
        mov ah,00h
        mov al,03h
        ;mov ah,1h
        int 10h

        mov ah,02
        mov dh,12d
        mov dl,40d
        int 10h

 next:
        mov dl,0
        mov al,dl
        mov bl,8ch
        mov cl,1
        mov ah,09h
        int 10h
        cmp dl,9
        je success
        inc dl
        jmp next


       ;mov ah,07h
       ;int 21h

 success:
        mov ah,4ch
        int 21h

        code ends
        end start


