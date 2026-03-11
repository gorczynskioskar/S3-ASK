#include <iostream>
int main() {
	unsigned char a, y;
	unsigned char p=128;
	y = 0;
	a = 0x13;
	for (int i = 0; i < 8; i++) {
		if (a < p) {
			y++;
			p=p / 2;
		}
		else {
			a=a - p;
			p=p / 2;
		}
	}
	printf("y = %d\n", y);
	a = 0x13;
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
		MOV CL, 8

		SUB CL, BL
		MOV y, CL
	}
	printf("y = %d\n", y);
	a = 0x13;
	y = 0;
	//B
	_asm {
		MOV AL, a
		MOV BL, 0
		MOV CL, a
		L1:
		JZ end1
		ADD BL, 1
		SUB CL, 1
		AND AL, CL
		MOV CL, AL
		JMP L1
		end1:
		MOV CL, 8
		SUB CL, BL
		MOV y, CL
	}
	printf("y = %d\n", y);

}