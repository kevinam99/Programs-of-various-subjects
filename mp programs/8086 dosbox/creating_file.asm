DATA SEGMENT
FILENAME DB'HELLO.NEW'
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START: MOV AX,DATA
MOV DS,AX
MOV AH,3CH
MOV CX,0
;initialise data segment
;dos function call to create
;new file
;CX = file attribute
CODE
ENDS
END START
MOV DX,OFFSET FILENAME ; dx has offset address of
;filename
INT 21H 