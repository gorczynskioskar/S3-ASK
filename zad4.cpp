#include <iostream>
int main() {
	int i=0, y=5;
	// A
	_asm {
		MOV EAX, i //i
		MOV EBX, y //y
		L1:
		MOV ECX, 5
		SUB ECX, EAX
		JZ KONIEC
		ADD EBX, EAX
		ADD EAX, 1
		JMP L1
		KONIEC:
		MOV y, EBX
	}
	printf("y = %d\n", y);
	// B
	i = 0;
	y = 0;
	_asm {
		MOV EAX, i
		MOV EBX, y
		L2:
		CMP EAX, 5
		JZ END
		ADD EBX, EAX
		ADD EAX, 1
		JMP L2
		END:
		MOV y, EBX
	}
	printf("y = %d\n", y);
}