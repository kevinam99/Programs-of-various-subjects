mov r0,#9
mov r10,#0
mov r11,#0
outerloop:
ldr r2,=arr
add r3,r2,#4
mov r11,#0
innerloop:
ldr r8,[r2]
ldr r9,[r3]
cmp r8,r9
movgt r4,r8
movgt r8,r9
movgt r9,r4
str r8,[r2],#4
str r9,[r3],#4
add r11,r11,#1
cmp r11,r0
blt innerloop
add r10,r10,#1
cmp r10,r0
blt outerloop















.data 
arr: .word 9,8,7,6,5,4,3,2,1