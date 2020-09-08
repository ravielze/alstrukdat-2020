#include <stdio.h>

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 27 Agustus 2020
Topik praktikum     : Pengenalan C
Deskripsi           : Mengonversi Suhu
*/

/* V a r i a b e l   G l o b a l: tidak perlu ada */

int main(){
    /* Nama yang dipakai */
    float c;
    char suhu;
    
    /* Baca */
    scanf("%f\n %c", &c, &suhu);

    /* Aplikasi Rumus dan Output */
    if (suhu == 'R'){
        printf("%.2f", 0.8F*c);
    } else if (suhu == 'F') {
        printf("%.2f", 1.8F*c+32);
    } else if (suhu == 'K') {
        printf("%.2f", c+273.15F);
    }

}