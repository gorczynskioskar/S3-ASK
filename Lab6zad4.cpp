#include <iostream>

int main()
{
    int i, y;
    y = 0;
    _asm {
        MOV EAX, y
        MOV EBX, 5
        L1:
        CMP EBX, 0
        JZ END
        ADD EBX, -1
        MOV ECX, EBX
        XOR ECX, 0XFFFFFFFF
        ADD EAX, ECX
        JMP L1
        END:
        MOV y, EAX
    }
    printf("y = %d", y);
}
