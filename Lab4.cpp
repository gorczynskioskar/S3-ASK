#include <iostream>
// Ile wynosi suma nieparzystych liczb naturalnych mniejszych od 100?
int main()
{
	short suma1 = 0;
	_asm{
		XOR AX, AX // na sumê
		MOV BX, 1 // i = 1
		
		L1:
		ADD AX, BX
		ADD BX, 2
		CMP BX, 100
		JB L1
		MOV suma1, AX
	}
	//printf("Suma: %d", suma1);

	short suma2 = 0;

	_asm {
		XOR AX, AX
		MOV CX, 1
		POWROT:
		CMP CX, 100
		JB ETYKIETA
		JMP KONIEC
		ETYKIETA:
		ADD AX, CX
		ADD CX, 2
		JMP POWROT
		KONIEC:
		MOV suma2, AX
	}
	//printf("Suma: %d", suma2);

	short suma3 = 0;
	_asm {
		XOR AX, AX
		MOV CX, 99
		POWROT2:
		ADD AX, CX
		SUB CX, 2
		JNS POWROT2
		MOV suma3, AX
	}
//	printf("Suma: %d", suma3);

	unsigned short y = 0;
	unsigned char a = 25;
	_asm {
		MOV AX, 0
		MOV BX, 0
		MOV AL, a
		MOV BL, a
		SHL AX, 4
		SHL BX, 2
		ADD AX, BX
		MOV y, AX
	}
	//printf("y = %d", y);

	y = 0;
	a = 25;
	_asm {
		MOV AX,0
		SHL AX, 2
		MOV y, AX
		SHL AX, 2
		SUB y, AX
		MOV AX, 0
		SUB AX, y
		MOV y, AX
	}
	printf("y = %d", y);
}