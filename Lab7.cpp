#include <iostream>
void zad7a() {
    unsigned char a, y;
    a = 0x12;
    y = 0;
    _asm {
		MOV AL, a //a
		MOV BL, 0 //y

		MOV CL, 128
		AND CL, AL
		SHR CL, 7
		ADD BL, CL

		MOV CL, 64
		AND CL, AL
		SHR CL, 6
		ADD BL, CL

		MOV CL, 32
		AND CL, AL
		SHR CL, 5
		ADD BL, CL

		MOV CL, 16
		AND CL, AL
		SHR CL, 4
		ADD BL, CL

		MOV CL, 8
		AND CL, AL
		SHR CL, 3
		ADD BL, CL

		MOV CL, 4
		AND CL, AL
		SHR CL, 2
		ADD BL, CL

		MOV CL, 2
		AND CL, AL
		SHR CL, 1
		ADD BL, CL

		MOV CL, 1
		AND CL, AL
		ADD BL, CL
		MOV CL, 1
		AND BL, CL
		XOR CL, BL
		MOV y, CL
    }
	printf("y = %d\n", y);
}
void zad7b() {
	unsigned char a, y;
	a = 0x12;
	y = 0;
	_asm {
		MOV AL, a
		MOV DH, 0
		MOV CL, 8
		L1:
		MOV DL, AL
		AND DL, 1
		ADD DH, DL
		SHR AL, 1
		SUB CL, 1
		JNZ L1
		END1:
		AND DH, 1
		XOR DH, 1
		MOV y, DH
	}
	printf("y = %d\n", y);
}
int main()
{
	zad7b();
}
