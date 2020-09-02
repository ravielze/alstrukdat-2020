#include "jam.h"
#include <stdio.h>

boolean IsJAMValid (int H, int M, int S){
    return ((H >= 0) && (H <= 23) && (M >= 0) && (M <= 59) && (S >= 0) && (S <= 59));
}

JAM MakeJAM (int HH, int MM, int SS){
    JAM j;
    j.HH = HH;
    j.MM = MM;
    j.SS = SS;
    return j;
}

void BacaJAM (JAM * J){
    int H, M, S;
    do
    {
        scanf("%d %d %d", &H, &M, &S);
    } while (!IsJAMValid(H, M, S));
    *J = MakeJAM(H, M, S);
}

void TulisJAM (JAM J){
    printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J){
    return (3600L*J.HH + 60L*J.MM + 1L*J.SS);
}

JAM DetikToJAM (long N){
    return MakeJAM(((N % 86400) / 3600), (((N % 86400) % 3600) / 60), (((N % 86400) % 3600) % 60));
}

boolean JEQ (JAM J1, JAM J2){
    return ((J1.HH == J2.HH) && (J1.MM == J2.MM) && (J1.SS == J2.SS));
}

boolean JNEQ (JAM J1, JAM J2){
    return JEQ(J1, J2) == false;
}

boolean JLT (JAM J1, JAM J2){
    if (J1.HH < J2.HH) return true;
    if (J1.MM < J2.MM) return true;
    if (J1.SS < J2.SS) return true;

    return false;
}

boolean JGT (JAM J1, JAM J2){
    return (JLT(J1, J2) == false);
}

JAM NextNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) + (1L*N));
}

JAM NextDetik (JAM J){
    return NextNDetik(J, 1);
}

JAM PrevNDetik (JAM J, int N){
    return DetikToJAM(JAMToDetik(J) - (1L*N));
}

JAM PrevDetik (JAM J){
    return PrevNDetik(J, 1);
}

long Durasi (JAM JAw, JAM JAkh){
    long awal = JAMToDetik(JAw);
    long akhir = JAMToDetik(JAkh);
    if (awal > akhir) awal += 86400L;
    return (akhir-awal);
}