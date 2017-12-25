assume cs:code,ds:data
data segment
    x db 5,4,3,2,1
    n dw n-x
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        
        mov bx,n
        dec bx
    outerloop:
        mov cx,bx
        mov ah,00
        lea si,x
    innerloop:
        mov al,[si]
        cmp al,[si+1]
        jle next
        xchg al,[si+1]
        mov [si],al
        mov ah,01
    next:
        inc si
        loop innerloop
        cmp ah,00
        je finish
        dec bx
        jnz outerloop
        
     finish:
        mov ah,4ch
        int 21h
        code ends
end start

                
            
        
        