mov r0,#0
	bl getdig
	mov r6,r2 ; first operand
	mov r0,#3 ; x cordinate
	mov r1,#2 ; y cordinate
	swi 0x205 ; Display an integer on the LCD screen
	
	mov r0,#0
	bl getop
	mov r0,#6 ; x cordinate
	mov r1,#2 ; y cordinate
	cmp r7,#2 ;'-' operation
	ldrlt r2,=op1	;r2:operator '+'
	ldreq r2,=op2  ;r2:operator '-'
	cmp r7,#3 ; '*' operation
	ldreq r2,=op3 ;'*' operation
	ldrgt r2,=op5 ;'/' operation
	swi 0x204 ;Display a string on the LCD screen
	
	mov r0,#0
	bl getdig
	mov r8,r2	;r8:second operand
	mov r0,#9 ; x cordinate
	mov r1,#2 ; y cordinate
	swi 0x205 ; Display an integer on the LCD screen

	mov r0,#0
wait:
	swi 0x203  ;Check if one of the Blue Buttons has been pressed  r0 = the Blue Button Pattern
	cmp r0,#0  
	beq wait
	cmp r7,#2  ;'-' operation
	addlt r9,r6,r8 ; less than mean '+' operation
	beq sub
	cmp r7,#3  ;'*' operation
	muleq r9,r6,r8	;r9:result
	bgt division  ;'/' operation


back:	mov r0,#12 ; x cordinate
	mov r1,#2  ; y cordinate
	ldr r2,=op4 ;'=' printed
	swi 0x204  ;Display a string on the LCD screen
	cmp r5,#1
	beq printdiff
	mov r0,#16
	mov r2,r9
	swi 0x205	
	
	swi 0x11
getdig:
	swi 0x203;Check if one of the Blue Buttons has been pressed  r0 = the Blue Button Pattern
	cmp r0,#0
	beq getdig
	clz r0,r0 ; count the leading zeros if no 0's in rm then rd=32 else 31
	rsb r0,r0,#31
	mov r2,r0
	mov pc,lr
	
getop:
	swi 0x203
	cmp r0,#0 
	beq getop
	cmp r0,#2 ; number 1 (0.1) pressed i.e '-'
	moveq r7,#2 ; '-' operation
	movlt r7,#1 ;if r0<2 i.e r0=1  then r7=1 i.e '+'
	cmp r0,#3   ; the number 3(0.2) pressed i.e '*'
	moveq r7,#3
	movgt r7,#4 ;if r0>3 i.e r0=4 or 5  then r7=4 i.e '/'
	mov pc,lr

sub:    cmp r8,r6
	bgt rsub
	sub r9,r6,r8
	b back
	
rsub:	mov r5,#1
	sub r9,r8,r6
	b back

printdiff:  mov r0,#15; x coordinate
	    ldr r2,=op2
	    swi 0x204 ;Display a string on the LCD screen
	    mov r2,r9
	    mov r0,#16; x coordinate
	   swi 0x205 ; result printed
	    swi 0x11 ; stop execution

division:  mov r10,#0
	mov r11,r6
cmpo:	cmp r11,r8
	blt back
	sub r11,r11,r8
	add r10,r10,#1
	mov r9,r10
	b cmpo
	

.data:
	op1: .asciz "+"
	op2: .asciz "-"
	op3: .asciz "*"
	op5: .asciz "/"
	op4: .asciz "="
.end	
