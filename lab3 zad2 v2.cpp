#include <iostream>

int main()
{
	unsigned char a, b;
	unsigned int y;
	short z;
	a = 255;
	b = 200;
	__asm {
		XOR AX, AX
		XOR BX, BX

		MOV AL, a
		MOV BL, b
		ADD AX, BX

		MUL AX //wynik w DX:AX
		SHL EDX, 16
		MOV DX, AX
		MOV y, EDX
	}
	printf("y = %d", y);
}


