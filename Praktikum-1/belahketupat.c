#include <stdio.h>
#include <stdbool.h>

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 27 Agustus 2020
Topik praktikum     : Pengenalan C
Deskripsi           : Gambar Belah Ketupat
*/


/* P r o t o t y p e */
bool IsValid(int x);
void GambarBelahKetupat(int x);

/* V a r i a b e l   G l o b a l: tidak perlu ada */

int main(){
    /* Nama yang dipakai */
    int n;
    
    /* Baca */
    scanf("%d", &n);
    if (IsValid(n) != true) {
        printf("Masukan tidak valid");
        return 0;
    }
    GambarBelahKetupat(n);

}

bool IsValid(int x){
    return ((x % 2 == 1) && (x > 0));
}

void GambarBelahKetupat(int x){
    if (x == 1){
        printf("*");
        return;
    }
    int i,j;

    for(i = 1; i <= x; i++) {
        if (i % 2 == 0) continue;
        for(j = 1; j <= (x-i)/2; j++)
            printf(" ");

        for(j = 1; j <= i; j++)
            printf("*");

        printf("\n");
    }
    for(i = 1; i <= x; i++) {
        if (i % 2 == 1) continue;
        for(j = 1; j <= i/2; j++)
            printf(" ");

        for(j = 1; j <= x-i; j++)
            printf("*");


        printf("\n");
    }
}