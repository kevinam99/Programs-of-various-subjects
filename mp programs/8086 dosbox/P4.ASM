assume cs:code,ds:data
 data segment
        a db 05h,04h,03h,02h,01h
        n dw n-a
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        mov bx,n
        dec bx
outer_loop:
        mov cx,bx
        mov ah,00
 ;       lea si,a
inner_loop:
        mov al,[si]
        cmp al,[si+1]
        jle nothing_to_do
        xchg al,[si+1]
        mov [si],al
        mov ah,01h
nothing_to_do:
        inc si
        loop inner_loop
        cmp ah,00h
        je finish
        dec bx
        jnz outer_loop

finish:
        mov ah,4ch
        int 21h
        code ends
        end start



