#include <stdio.h>
#include "boolean.h"
#include "arraypos.h"

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 10 September 2020
Topik praktikum     : ADT Array Pada C
Deskripsi           : Program yang menerima array sebesar N dan mencari X serta mendeskripsikan X adalah nilai min/maks/median.
*/

int main(){

    TabInt T, Tdesc, Tasc;
    BacaIsi(&T);
    Tdesc = T;
    Tasc = T;

    Sort(&Tdesc, false);
    Sort(&Tasc, true);

    if (IsEQ(T, Tdesc) && IsEQ(T, Tasc)){
        printf("Array monotonik statik\n");
    } else {
        if (IsEQ(T, Tasc)){
            printf("Array monotonik tidak mengecil\n");
        } else if (IsEQ(T, Tdesc)){
            printf("Array monotonik tidak membesar\n");
        } else {
            printf("Array tidak monotonik\n");
        }
    }
}