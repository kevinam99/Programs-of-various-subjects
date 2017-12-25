assume cs:code,ds:data
data segment
    password db "twilight"
    new db 100 dup(?)
    msg db "not authenticated$"
data ends

code segment
start:
    mov ax,data
    mov ds,ax
    mov es,ax
    mov bh,3

wait1:
    lea si,new
rpt:
    mov ah,7
    int 21h

    cmp al,0dh
    je compare
    mov [si],al
    inc si
    jmp rpt

compare:
    lea si,password
    lea di, new
    mov cl,8

    rep cmpsb
    jz next

    lea dx,msg
    mov ah,9

    int 21h
    dec bh
    jnz wait1

wait2:    jmp wait2

next:
    mov ah,4ch
    int 21h
    code ends

    end start
