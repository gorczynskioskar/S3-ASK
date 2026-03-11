#include <iostream>

int main()
{
	unsigned char a, b;
	unsigned int y;
	short z;
	a = 255;
	b = 200;
	__asm {
		XOR EAX, EAX
		XOR EBX, EBX
		XOR ECX, ECX

		MOV AL, a
		MOV BL, b
		MOV CL, AL //kopia zmiennej a

		MUL BL //wynik w AX: AX = AL * BL
		SHL EAX, 1 //wynik w EAX: 2ab
		MOV ESI, EAX //kopia 2ab

		MOV EAX, ECX
		MUL AL //wynik w AX: a^2
		ADD ESI, EAX

		MOV EAX, EBX
		MUL AL //wynik w AX: b^2

		ADD ESI, EAX
		
		MOV y, ESI 
	}
	printf("y = %d", y);
}

