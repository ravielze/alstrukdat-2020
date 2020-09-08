#include <stdio.h>
#include <stdbool.h>

/*
NIM                 : 13519002
Nama                : Steven Nataniel
Tanggal             : 27 Agustus 2020
Topik praktikum     : Pengenalan C
Deskripsi           : Program IP mahasiswa
*/


/* P r o t o t y p e */
bool IsWithinRange(float x, float min, float max);

/* V a r i a b e l   G l o b a l: tidak perlu ada */

int main(){
    /* Nama yang dipakai */
    int mhsw = 0, lulus = 0;
    float iptotal = 0.0F, ip;
    
    /* Baca */
    while (true){
        scanf("%f", &ip);
        if (ip == -999.0F){
            break;
        } else if (IsWithinRange(ip, 0.0F, 4.0F)) {
            iptotal += ip;
            mhsw += 1;
            if (IsWithinRange(ip, 2.75F, 4.0F)){
                lulus += 1;
            }
        }
    }
    if (mhsw != 0){
        printf("%d\n%d\n%d\n%.2f", mhsw, lulus, mhsw-lulus, (iptotal/mhsw));
    } else {
        printf("Tidak ada data");
    }

}

bool IsWithinRange(float x, float min, float max){
    return ((x >= min) && (x <= max));
}