#include <iostream>
void zad9cpp() {
	unsigned char a=5, b=4;
	unsigned int y=0;
	for (int i = 0; i < b; i++) {
		y += a;
	}
	printf("y = %d\n", y);
}
void zad9a() {
	unsigned char a = 5, b = 4;
	unsigned short y;
	_asm {
		MOV AX, 0
		MOV AL, a
		MOV BL, b
		MOV CX, 0
		AND BL, 128
		JZ SKIP_SHL7
		SHL AL, 7
		ADD CX, AX
		SKIP_SHL7:
		MOV BL, b
		AND BL, 64
		JZ SKIP_SHL6
		MOV AL, a
		SHL AL, 6
		ADD CX, AX
		SKIP_SHL6:
		MOV BL, b
		AND BL, 32
		JZ SKIP_SHL5
		MOV AL, a
		SHL AL, 5
		ADD CX, AX
		SKIP_SHL5:
		MOV BL, b
		AND BL, 16
		JZ SKIP_SHL4
		MOV AL, a
		SHL AL, 4
		ADD CX, AX
		SKIP_SHL4:
		MOV BL, b
		AND BL, 8
		JZ SKIP_SHL3
		MOV AL, a
		SHL AL, 3
		ADD CX, AX
		SKIP_SHL3:
		MOV BL, b
		AND BL, 4
		JZ SKIP_SHL2
		MOV AL, a
		SHL AL, 2
		ADD CX, AX
		SKIP_SHL2:
		MOV BL, b
		AND BL, 2
		JZ SKIP_SHL1
		MOV AL, a
		SHL AL, 2
		ADD CX, AX
		SKIP_SHL1:
		MOV BL, b
		AND BL, 1
		JZ SKIP_SHL0
		MOV AL, a
		SHL AL, 1
		ADD CX, AX
		SKIP_SHL0:
		MOV y, CX
	}
	printf("y = %d\n", y);
}
void zad9b() {
	unsigned char a = 5, b = 4;
	unsigned short y;
	_asm {
		MOV AX, 0
		MOV AL, a
		MOV BL, b
		MOV CX, 0
		TEST BL, 128
		JZ SKIP_SHL7
		SHL AL, 7
		ADD CX, AX
		SKIP_SHL7:
		TEST BL, 64
		JZ SKIP_SHL6
		MOV AL, a
		SHL AL, 6
		ADD CX, AX
		SKIP_SHL6:
		TEST BL, 32
		JZ SKIP_SHL5
		MOV AL, a
		SHL AL, 5
		ADD CX, AX
		SKIP_SHL5:
		TEST BL, 16
		JZ SKIP_SHL4
		MOV AL, a
		SHL AL, 4
		ADD CX, AX
		SKIP_SHL4:
		TEST BL, 8
		JZ SKIP_SHL3
		MOV AL, a
		SHL AL, 3
		ADD CX, AX
		SKIP_SHL3:
		TEST BL, 4
		JZ SKIP_SHL2
		MOV AL, a
		SHL AL, 2
		ADD CX, AX
		SKIP_SHL2:
		TEST BL, 2
		JZ SKIP_SHL1
		MOV AL, a
		SHL AL, 2
		ADD CX, AX
		SKIP_SHL1:
		TEST BL, 1
		JZ SKIP_SHL0
		MOV AL, a
		SHL AL, 1
		ADD CX, AX
		SKIP_SHL0:
		MOV y, CX
	}
	printf("y = %d\n", y);
}
void zad9c() {
	unsigned char a = 5, b = 4;
	unsigned short y;
	_asm {
		MOV AX, 0
		MOV AL, a
		MOV BL, b
		MOV CX, 0
		MOV DH, 1
		L1:
		TEST BL, DH
		JNZ SHIFTING
		SHL AL, 1
		SHL DH, 1
		JZ END
		JMP L1
		SHIFTING:
		ADD CX, AX
		SHL AL, 1
		SHL DH, 1
		JZ END
		JMP L1
		END:
		MOV y, CX
	}
	printf("y = %d\n", y);
}
void zad9d() {
	unsigned char a = 24, b = 9;
	unsigned short y;
	_asm {
		MOV AX, 0
		MOV AL, a
		MOV BL, b
		MOV CX, 0
		AND BL, 1
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 2
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 3
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 4
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 5
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 6
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		AND BL, 7
		SHL AL, 1
		ADD CX, AX
		MOV BL, b
		MOV y, CX
	}
	printf("y = %d", y);
}
int main()
{
	zad9cpp();
	zad9a();
	zad9b();
	zad9c();
	zad9d();
}