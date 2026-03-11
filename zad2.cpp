#include <iostream>

int main()
{
	 char a=0x32, y;
	 // A
	_asm {
		MOV AL, a
		MOV BL, 1 //y

		SUB AL, 0x32
		JNZ KONIEC
		MOV BL, 0
		KONIEC:
		MOV y, BL
	}

//	printf("y = %d", y);
	// B
	_asm {
		MOV AL, a
		MOV BL, 0
		
		CMP AL, 0x32
		JZ END
		MOV BL, 1
		END:
		MOV y, BL
	}
//	printf("y = %d", y);
	// C
	_asm {
		MOV AL, a
		MOV BL, 1

		ADD AL, -0x32
		JNZ END2
		MOV BL, 0
		END2:
		MOV y, BL
	}
	printf("y = %d", y);
}
