assume cs:code,ds:data
data segment
   pa equ 20A0h
   pb equ 20A1h
   pc equ 20A2h
   cr equ 20A3h

   msg db 71h,0ffh,0ffh,0ffh,71h,0ffh,0ffh,0ffh,71h,0ffh,0ffh,0ffh
data ends

code segment
start: mov ax,data
       mov ds,ax

       mov al,90h
       mov dx,cr
       out dx,al
rpt: mov cx,12
     lea si,msg

nextchar: mov al,[si]
          call disp
          call delay
          inc si
          loop nextchar

          mov ah,06h
          mov dl,00h
          int 21h
          jz rpt

          mov ah,4ch
          int 21h

     disp proc
          push cx
          mov cx,08h

     nextbit: mov dx,pb
              out dx,al
              push ax
              mov al,00
              mov dx,pc
              out dx,al
              mov al,0ffh
              out dx,al
              pop ax
              ror al,1
              loop nextbit
              pop cx
              ret
       disp endp
       delay proc
              mov bx,02fffh
              l2:mov di,0ffffh
              l1: dec di
                  jnz l1
                  dec bx
                  jnz l2
                  ret
               delay endp
               code ends
               end start

