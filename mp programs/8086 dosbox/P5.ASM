assume cs:code,ds:data
data segment
        x db 10 dup(?)
        n db 0Ah
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        lea si,x
        mov al,00h
        mov [si],al
        inc si
        mov bl,01h
        mov [si],bl
        inc si
        mov cl,n
        dec cl
        dec cl

calculate:
        add al,bl
        mov [si],al
        inc si
        xchg al,bl
        loop calculate

        mov ah,4ch
        int 21h
        code ends
        end start

