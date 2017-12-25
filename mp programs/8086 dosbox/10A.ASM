data segment
    filename db 'vvj.txt',0
    fhandle dw ? 
    buff db "8086 ALP $"
    data ends
code segment
    start :
    mov ax,data
    mov ds,ax
    
    mov ah,3ch;set function number to crate filename 
    xor cx,cx ;make contents of cx all zero
    mov dx,seg filename;mov segment address of filename in which 
    mov ds,dx; it is appearing, to register dx  and then to ds
    mov dx,offset filename; points to filename
    int 21h;call software interrupt of type 21 h
    
    mov ah,3dh;set function number to open file  
    mov al,1 ; set file access mode as 1 i.e. write access
    mov dx,seg filename;mov segment address of filename in which
    mov ds,dx; it is appearing, to register dx  and then to ds
    mov dx,offset filename;points to filename
    int 21h; call sofrware interrupt of type 21h 
    mov fhandle,ax; mov flie handler of file vvj.txt to fhandle 
     
    mov ah,40h;mov function number to ah to write into file
    mov dx,seg buff;mov segment address of buff in which
    mov ds,dx;it is appearing, to register dx  and then to ds
    mov dx,offset buff; points to buff
    mov bx,fhandle;mov flie handler of file vvj.txt to fhandle  
    mov cx,8; specify number of butes to write into file
    int 21h;call software interrupt of type 21h to write into file 
    
    mov ah,3eh;set function number to close file
    mov bx,fhandle; move fhandle to bx 
    int 21h; call software interruopt of the type 21h to close file
    code ends
end start