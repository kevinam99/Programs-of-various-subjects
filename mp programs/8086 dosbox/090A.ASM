assume cs:code
code segment
start:
        mov cx,100d
        mov bl,00
next_digit:  mov al,bl
        aam
        add ax,3030h
	call setpos
        call disp
        call delay
        inc bl
        
        loop next_digit
        mov ah,4ch
        int 21h

setpos proc
	push ax
	mov ah,00h
        mov al,2h
        int 10h

        mov dh,12d
        mov dl,40d
        mov ah,2h
        int 10h
	pop ax
	ret
setpos endp


disp proc
	mov dl,ah
        mov ah,2
        push ax
        int 21h
        pop ax
        mov dl,al
        mov ah,2
        int 21h
        ;mov dl,0dh
       ; mov ah,2
       ; int 21h
	ret
disp endp

delay proc
        mov si,000fh
    l2: mov di,0ffffh
    l1: dec di
        jnz l1
        dec si
        jnz l2
        ret
delay endp
code ends
end start
