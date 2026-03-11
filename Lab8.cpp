#include <iostream>
void zad8() {
    unsigned char a = 0x12;
    unsigned char r = 0;
    for (int i = 0; i < 8; i++) {
        if (i < 4) r += (a & (1<<i)) << (7 - (2 * i));
        else r += (a & (1<<i)) >> ((2 * i) - 7);
    }
    printf("r = %d\n", r);
}
void zad82() {
    unsigned char a = 0x12;
    unsigned char r = 0;
    for (int i = 0; i < 8; i++) {
        r += a & 1;
        if (i == 7) break;
        r = r << 1;
        a = a >> 1;
    }
    printf("r = %d\n", r);

}
void zad8a() {
    unsigned char a = 0x12;
    unsigned char r;
    _asm {
        MOV AL, a
        XOR BL, BL
        MOV CL, 1
        AND CL, AL
        SHL CL, 7
        OR BL, CL
        MOV CL, 2
        AND CL, AL
        SHL CL, 5
        OR BL, CL
        MOV CL, 4
        AND CL, AL
        SHL CL, 3
        OR BL, CL
        MOV CL, 8
        AND CL, AL
        SHL CL, 1
        OR BL, CL
        MOV CL, 16
        AND CL, AL
        SHR CL, 1
        OR BL, CL
        MOV CL, 32
        AND CL, AL
        SHR CL, 3
        OR BL, CL
        MOV CL, 64
        AND CL, AL
        SHR CL, 5
        OR BL, CL
        MOV CL, 128
        AND CL, AL
        SHR CL, 7
        OR BL, CL
        MOV r, BL
    }
    printf("r = %d\n", r);
}
void zad8b() {
    unsigned char a = 0x12;
    unsigned char r;
    _asm {
        MOV AL, a
        MOV BL, 0
        
        MOV r, BL
    }
    printf("r = %d\n", r);
}
void zad8c() {
    unsigned char a = 0x12;
    unsigned char r;
    _asm {
        MOV AL, a
        MOV CL, 0x80
        L1:
        SHL r, 1
        TEST AND, 1
        JZ L2
        OR r, 1
        L2:
        SHR AL, 1
        SHR CL, 1
        JZ END
        JMP L1
        END:
        MOV r, BL
    }
    printf("r = %d\n", r);
}
int main()
{
    zad8();
    zad82();
    zad8a();
    zad8b();
    zad8c();
}
