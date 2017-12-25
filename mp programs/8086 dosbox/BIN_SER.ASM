assume cs:code,ds:data
data segment
         arr db 10h,20h,30h,40h,50h
         n db n-arr
         key db 30h
         msg2 db "element not found$"
         msg1 db "element found at "         
         pos db ?,"$"
data ends
code segment
start:
        mov ax,data
        mov ds,ax

        mov al,0h
        mov dl,n
        dec dl
check:  cmp al,dl
        jae fail
        mov ah,00h
        mov cl,al
        add al,dl
        shr al,1
        mov si,ax
        mov bl,[si]
        cmp bl,key
        jae part1
        inc ax
        jmp check
part1:  je success
        dec al
        mov dl,al
        mov al,cl
        jmp check
         jmp disp
fail:   lea dx,msg2
        jmp disp

success: 
        inc al
        add al,30h
        mov pos,al
        lea dx,msg1

disp: mov ah,09h
        int 21h
        mov ah,4ch
        int 21h

        code ends
        end start




             
