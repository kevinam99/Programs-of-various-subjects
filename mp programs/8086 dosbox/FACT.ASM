
assume cs:code,ds:data
data segment
        n db 4h
        res dw ?
data ends
code segment
start:
        mov ax,data
        mov ds,ax
        ;mov ah,00
        mov al,n
        push ax
        call fact
        mov ah,4ch
        int 21h
fact proc
        cmp al,00
        je result
      ; dec al
        push ax
        dec al
        call fact
        pop ax
        mul res
        mov res,ax
        ret
result:
        mov res,01
        ret
        fact endp
        code ends
        end start




