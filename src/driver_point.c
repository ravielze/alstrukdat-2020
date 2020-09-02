/* File: driver_point.c */
/* Tanggal: 28 Agustus 2016 */
/* Driver ABSTRACT DATA TYPE POINT */

#include <stdio.h>
#include "point.h"

int main(){
    POINT P1, P2;
    P1 = MakePOINT(6, 9);
    printf("Diberikan point pertama: ");
    TulisPOINT(P1);printf("\n");
    printf("Masukkan Point anda: ");
    BacaPOINT(&P2);

    if(EQ(P1, P2)){
        printf("Point pertama dan kedua sama\n");
    }
    if(NEQ(P1, P2)){
        printf("Point pertama dan kedua beda\n");
    }
    printf("Point anda berada pada kuadran %d\n", Kuadran(P2));

    printf("Apabila digeser satu ke kanan, koordinatnya: ");
    TulisPOINT(NextX(P2));printf("\n");
    printf("Apabila digeser satu ke atas, koordinatnya: ");
    TulisPOINT(NextY(P2));printf("\n");
    printf("Apabila digeser satu ke kiri dan bawah, koordinatnya: ");
    TulisPOINT(PlusDelta(P2, -1, -1));printf("\n");
    printf("Apabila dicerminkan sumbu X, koordinatnya: ");
    TulisPOINT(MirrorOf(P2, true));printf("\n");
    printf("Apabila dicerminkan sumbu Y, koordinatnya: ");
    TulisPOINT(MirrorOf(P2, false));printf("\n");

    printf("Point anda akan ditranslasi sebesar P1\n");
    Geser(&P2, 6, 9);
    printf("Point anda dicerminkan sumbu X, kemudian sumbu Y, lalu diputar 180 derajat searah jarum jam sehingga kembali lagi\n");
    Mirror(&P2, true);
    Mirror(&P2, false);
    Putar(&P2, 180);

    printf("Jarak P1 dengan origin ialah %f, sedangkan dengan P2 ialah %f", Jarak0(P1), Panjang(P1, P2));

    if(IsOnSbX(P2)){
        printf("Point anda sudah di sumbu x\n");
    }else{
        printf("Point anda akan digeser ke sumbu x\n");
        GeserKeSbX(&P2);
    }
    if(IsOnSbY(P2)){
        printf("Point anda sudah di sumbu y\n");
    }else{
        printf("Point anda akan digeser ke sumbu y\n");
        GeserKeSbY(&P2);
    }
    if(IsOrigin(P2)){
        printf("Seharusnya sekarang point anda ada di origin");
    }

}