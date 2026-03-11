#include <iostream>
int main() {
	char a = 0x32;
	bool y = 0;
	_asm {
		MOV AL, a
		SUB AL, 0x32
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		SHR AL, 1
		OR y, AL
		AND y, 1
	}
	printf("y = %d", y);
}