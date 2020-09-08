#include "arraypos.h"
#include <stdio.h>

int main(){
    TabInt T;
    MakeEmpty(&T);
    T.TI[0] = 5;
    T.TI[1] = 4;
    T.TI[2] = 3;
    T.TI[3] = 1;
    T.TI[4] = 2;
    TulisIsiTab(T); printf("\n");
    Sort(&T, true);
    TulisIsiTab(T); printf("\n");
    Sort(&T, false);
    TulisIsiTab(T); printf("\n");
    return 0;
}