#include <iostream>
int main(){
   // unsigned char a;
  //  char z;
    char y;
    short z;
    y = -2;
    _asm {
        xor AX, AX // AX=0
        mov AL, y
        CBW
        mov z, AX
    }
    printf("z: %d", z);
    //zadanie domowe: liczba w szesnastkowym, operatory && i || i ^^ 
}