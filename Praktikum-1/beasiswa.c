#include <stdio.h>
#include <stdbool.h>

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 27 Agustus 2020
Topik praktikum     : Pengenalan C
Deskripsi           : Program Beasiswa
*/

/* V a r i a b e l   G l o b a l: tidak perlu ada */

int main(){
    /* Nama yang dipakai */
    float ip, pot;
    
    /* Baca */
    scanf("%f\n%f", &ip, &pot);

    /* Aplikasi */
    if (ip >= 3.5F){
        printf("%d", 4);
    } else if (ip < 3.5F && pot < 1.0F){
        printf("%d", 1);
    } else if (pot >= 1.0F && pot < 5.0F && ip < 3.5){
        if (ip < 2.0F){
            printf("%d", 2);
        } else {
            printf("%d", 3);
        }
    } else {
        printf("%d", 0);
    }

}