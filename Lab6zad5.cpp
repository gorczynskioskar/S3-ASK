#include <iostream>
int main() {
	int y = 3;
	//A
	_asm {
		MOV EAX, y;
		L1:
		SUB EAX, 5
		JZ END1
		ADD EAX, 6
		JMP L1
		END1 :
		ADD EAX, 5
		MOV y, EAX
	}
	printf("y = %d\n", y);
	//B
	y = 3;
	_asm {
		MOV EAX, y;
		L2:
		CMP EAX, 5
		JZ END2
		ADD EAX, 1			
		JMP L2
		END2 :
		MOV y, EAX
	}
	printf("y = %d\n", y);
	//C
	y = 3;
	_asm {
		MOV EAX, y
		L3:
		ADD EAX, 1
		CMP EAX, 5
		JZ END3
		JMP L3
		END3:
		MOV y, EAX
	}
	printf("y = %d\n", y);
	//D
	y = 3;
	_asm {
		MOV EAX, y
		L4 :
		ADD EAX, 1
		ADD EAX, -5
		JZ END4
		ADD EAX, 5
		JMP L4
		END4 :
		ADD EAX, 5
		MOV y, EAX
	}
	printf("y = %d\n", y);
}