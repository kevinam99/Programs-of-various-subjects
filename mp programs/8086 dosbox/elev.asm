assume cs:code,ds:data
data segment
     pa equ 20A0h
     pb equ 20A1h
     pc equ 20A2h
     cr equ 20A3h
data ends

code segment
start: mov ax,data
       mov ds,ax

       mov al,82h
       mov dx,cr
       out dx,al

       mov dx,pa
       mov al,00h
       out dx,al
       mov al,0f0h
       out dx,al

       mov dx,pb

  scanagain: in al,dx
             and al,0fh
             cmp al,0fh
             je scanagain
             mov cl,01

    rotagain: ror al,1
              jc next
              jmp startmov

    next: add cl,03h
          jmp rotagain

    startmov:  mov dx,pa
               mov al,0f0h

    nextled: out dx,al
             call delay
             inc al
             dec cl
             jnz nextled
             call delay

             dec al
             and al,0fh

    comedown: out dx,al
              call delay
              dec al
              cmp al,00h
              jge comedown
              mov ah,4ch
              int 21h

          delay proc
               mov bx,02fffh
            l2: mov di,0ffffh
            l1: dec di
                    
                jnz l1
                dec bx
                jnz l2
                ret
   delay endp
   code ends
   end start
