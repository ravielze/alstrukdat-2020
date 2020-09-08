#include "arraypos.h"
#include <stdio.h>

int main(){
    TabInt T;
    MakeEmpty(&T);
    T.TI[4] = 2;
    T.TI[3] = 1;
    printf("%d\n", GetFirstIdx(T));
    BacaIsi(&T);
    TulisIsiTab(T);
    return 0;
}