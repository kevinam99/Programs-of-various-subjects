.MODEL SMALL
.DATA
        MPLY DW 025AH
        RES DW 8 DUP(0)
.CODE
        MOV AX,@DATA
        MOV DS,AX
        LEA SI,MPLY
        LEA DI,RES
        MOV AX,MPLY
        MOV BX,AX
        SHL AX,01
        SHL AX,01
        SHL AX,01
        ADC BX,AX
        SHL AX,01
        ADC BX,AX
        MOV AX,BX
        MOV [DI],AX
        MOV AH,4CH
        INT 21H
        END


