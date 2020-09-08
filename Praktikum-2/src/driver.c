#include "garis.h"
#include "point.h"
#include <stdio.h>

int main(){
    GARIS garis, garis2;
    BacaGARIS(&garis);
    TulisGARIS(garis);printf("\n");
    BacaGARIS(&garis2);
    TulisGARIS(garis2);printf("\n");
    if (IsTegakLurus(garis, garis2)) printf("yes");printf("\n");
    return 0;
}