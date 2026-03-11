#include <iostream>

int main()
{
    unsigned char a, b;
    unsigned int y;
    short z;
    a = 255;
    b = 200;
    _asm {
        XOR AX, AX
        MOV AL, b
        IMUL SI, AL, 3 // SI = 3 * AL
        MOV z, SI
    }
    printf("z = %d", z);
}