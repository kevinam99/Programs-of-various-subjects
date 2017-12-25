assume cs:code,ds:data
data segment
        a db 55h
        b db ?
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        mov al,a
        mov bl,00
        mov cl,08
check:
        ror al,1
        jnc dn_inc
        inc bl
dn_inc:
        dec cl
        jnz check
        mov b,bl
        mov ah,4ch
        int 21h
        code ends
        end start




