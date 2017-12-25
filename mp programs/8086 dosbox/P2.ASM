assume cs:code,ds:data
data segment
        str db 'sis'
        n db n-str
        str2 db 3 dup('?')
        msg1 db "failed$"
        msg2 db "success$"
data ends
code segment
start:
        mov ax,data
        mov ds,ax
        mov es,ax

        lea si,n
        dec si
        lea di,str2
        ;mov ch,00
        mov cl,n

copy_string:
        mov al,[si]
        mov [di],al
        dec si
        inc di
        loop copy_string

        lea si,str
        lea di,str2
       ; cld
        mov ch,00
        mov cl,n

        rep cmpsb
        jnz fail
        lea dx,msg2
        jmp disp

fail:
        lea dx,msg1
        jmp disp
disp:
        mov ah,09h
        int 21h

        mov ah,4ch
        int 21h
        code ends
        end start


