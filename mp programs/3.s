wait: swi 0x202
        cmp r0, #0
        beq wait

        ldr r5, =zero
        ldr r3, =F
        mov r1, #0
        cmp r0, #1
        bgt loop2
     
 loop1: ldrb r0, [r5]
           add r1, r1, #1
           cmp r1, #17
           beq end
           swi 0x200
           add r5, r5, #1
           bl count 
           b loop1

loop2: ldrb r0, [r3]
          add r1, r1, #1
          cmp r1, #17
          beq end
          swi 0x200
          sub r3, r3, #1
          bl count
          b loop2

end: b wait
       
count: mov r4, #64000
 
count1: cmp r4, #0
            subgt r4, r4, #1
            bgt count1
            swi 0x206
            mov pc, lr

.data
zero: 	.byte 0xFD
one:	.byte 0x70
two:	.byte 0xDE
three:	.byte 0xFA
four:	.byte 0x73
five:	.byte 0xBB
six:	.byte 0xBF
seven:	.byte 0xF0
eight:	.byte 0xFF
nine:	.byte 0xFB

A: .byte 0xE7
B: .byte 0xEF
C: .byte 0x8D
D: .byte 0xED
E: .byte 0x8F
F: .byte 0x87
