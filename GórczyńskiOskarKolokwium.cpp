#include <iostream>
void zad1() {
	unsigned char a = 2, b = 8, y;
	_asm {
		MOV AL, a
		MOV BL, b
		CMP AL, 3
		JZ ety1
		CMP BL, 7
		JC ety1
		MOV y, 5
		CMP AL, AL
		JZ end
		ety1 :
		MOV y, 8
		end :
	}
	printf("y = %d\n", y);
}
void zad2() {
	unsigned char a=0x8C, y;
	_asm {
		MOV AL, a
		MOV BL, 0
		MOV DL, 255
		ety1:
		SHR DL, 1
		JNC ety2
		SHR AL, 1
		JNC skipshr
		INC BL
		skipshr :
		MOV CL, 1
		SHR CL, 1
		JC ety1
		ety2:
		SHR BL, 1
		JC falsz
		MOV y, 1
		MOV BL, 1
		SHR BL, 1
		JC end
		falsz:
		MOV y, 0
		end:
	}
	printf("a = %d, y = %d\n", a, y);
}
int main()
{
	zad1();
	zad2();
}
