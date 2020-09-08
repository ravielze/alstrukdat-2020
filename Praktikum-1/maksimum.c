#include <stdio.h>

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 27 Agustus 2020
Topik praktikum     : Pengenalan C
Deskripsi           : Nilai maksimal 3 bilangan
*/

/* P r o t o t y p e */
int maks(int a, int b);

/* V a r i a b e l   G l o b a l: tidak perlu ada */
int main(){
    /* Nama yang dipakai */
    int bil1, bil2, bil3, bilmaks;
    
    /* Baca */
    scanf("%d\n%d\n%d", &bil1, &bil2, &bil3);

    /* Maksimum */
    bilmaks = maks(maks(bil1, bil2), bil3);

    /* Output */
    printf("%d", bilmaks);

}

int maks(int a, int b){
    return ((a > b) ? a : b);
}