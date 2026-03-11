#include <iostream>
void zad10c() {
    unsigned short a=1000, y=0;
    y += a;
    y += (a << 3);
    y = y>>3;
    printf("y = %d\n", y);
}
void zad10asm() {
    unsigned short a = 1000, y;
    _asm {
        MOV AX, a
        MOV BX, 0
        ADD BX, AX
        SHL AX, 3
        ADD BX, AX
        SHR BX, 3
        MOV y, BX
    }
    printf("y = %d\n", y);
}
void zad11a() {
    unsigned short a=4, y;
    _asm {
        MOV AX, a
        SUB AX, 5
        JC zero
        MOV y, 1
        JMP end
        zero:
        MOV y, 0
        end:
    }
    printf("y = %d\n", y);
}
void zad11b() {
    unsigned short a = 5, y;
    _asm {
        MOV AX, a
        SUB AX, 5
        JC zero
        MOV y, 1
        STC
        JC end
        zero :
        MOV y, 0
        end :
    }
    printf("y = %d\n", y);
}
void zad11c() {
    unsigned short a = 5, y;
    _asm {
        MOV AX, a
        MOV BX, 5
        CMP BX, AX
        JC one
        MOV y, 0
        STC
        JC end
        one :
        MOV y, 1
        end :
    }
    printf("y = %d\n", y);
}
void zad11d() {
    unsigned short a = 5, y;
    _asm {
        MOV y, 0
        MOV AX, a
        MOV BX, -6
        ADD BX, AX
        JC end
        MOV y, 1
        end :
    }
    printf("y = %d\n", y);
}
void cmpflags() {
    unsigned short y;
    _asm {
        MOV CX, 1
        MOV AX, 4
        CMP AX, 5
        PUSHF
        POP AX
        SHR AX, 7
        JC equal
        MOV CX, 0
        equal:
        MOV y, CX
    }
    printf("y = %d\n", y);
}
void zad12a() {
    unsigned int i, y;
    _asm {
        MOV EAX, 0
        MOV EBX, 0
        L1:
        SUB EBX, 5
        JNC end
        ADD EBX, 5
        ADD EAX, EBX
        ADD EBX, 1
        JMP L1
        end:
        MOV y, EAX
    }
    printf("y = %d\n", y);
}
void zad12b() {
    unsigned int i, y;
    _asm {
        MOV EAX, 0
        MOV EBX, 0
        L1:
        CMP EBX, 5
        JNC end
        ADD EAX, EBX
        ADD EBX, 1
        JMP L1
        end :
        MOV y, EAX
    }
    printf("y = %d\n", y);
}
void zad12c() {
    int i, y;
    _asm {
        MOV EAX, 0
        MOV EBX, 5
        L1:
        CMP EBX, 1
        JC end
        ADD EAX, EBX
        ADD EBX, -1
        JMP L1
        end :
        XOR EAX, -1
        ADD EAX, 1
        MOV y, EAX
    }
    printf("y = %d\n", y);
}
void zad13() {
    unsigned char a=2, b=7, c=1; //c=3;
    _asm {
        
        MOV CL, c
        AND CL, 7
        SUB CL, 1
        JZ equal
        SUB AL, AL
        JZ end
        equal:
        MOV BL, b
        AND BL, 3
        MOV a, BL
        ADD CL, 1
        end:
    }
    printf("a = %d\n", a);
}
void zad14() {
    unsigned char a=1, b=5, c=3;
    _asm {
        MOV CL, 0
        MOV AL, a
        AND AL, 1
        JZ skip
        MOV BL, b
        AND BL, 7
        MOV CL, BL
        skip:
        MOV c, CL
    }
    printf("c = %d\n", c);
}
void zad15a() {
    int i = 0;
    unsigned char tab[5];
    _asm {
        MOV EAX, i
        LEA EBX, tab
        petla:
        CMP EAX, 5
        JNZ mniejsze
        JMP koniec
        mniejsze:
        MOV BYTE PTR[EBX + EAX], AL
        ADD EAX, 1
        JMP petla
        koniec:
    }
    for (int i = 0; i < 5; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}
void zad15b() {
    int i = 0;
    unsigned char tab[5];
    _asm {
        MOV EAX, i
        LEA EBX, tab
        petla :
        CMP EAX, 5
            JC mniejsze
            JMP koniec
            mniejsze :
        MOV BYTE PTR[EBX + EAX], AL
            ADD EAX, 1
            JMP petla
            koniec :
    }
    for (int i = 0; i < 5; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}
int main(){
    zad15a();
    zad15b();
}