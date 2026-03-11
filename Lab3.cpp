#include <iostream>

int main()
{
    unsigned char a, b;
    unsigned short y;
    a = 255;
    b = 200;
    __asm {
        XOR AH, AH
        MOV AL, a
        MOV BL, b
        ADD AL, BL
        ADC AH, 0
        LEA ESI, y
        MOV [ESI], AL
        MOV [ESI+1], AH
    }
    printf("y = %d", y);
}