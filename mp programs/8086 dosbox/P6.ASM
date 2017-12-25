assume cs:code,ds:data
data segment
        n db 04h
        res db ?
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        mov ah,00
        mov al,n
        call fact
        mov ah,4ch
        int 21h



fact proc
        cmp al,00
        je final
        push ax
        dec al
        call fact
        pop ax
        mul res
        mov res,al
        ret
final:
        mov res,01h
        ret

        fact endp
        code ends
        end start





