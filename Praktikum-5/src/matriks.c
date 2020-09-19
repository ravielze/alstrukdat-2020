#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    M->NBrsEff = NB;
    M->NKolEff = NK;
    
    int i,j;
    for (i = 0; i < NB; i++){
        for (j = 0; j < NK; j++){
            M->Mem[i][j] = 0;
        }
    }
}

boolean IsIdxValid (int i, int j){
    return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M){
    return M.NKolEff-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return M.Mem[i][i];
}

void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    MakeMATRIKS(MIn.NBrsEff, MIn.NKolEff, MHsl);

    int i,j;
    for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++){
        for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++){
            MHsl->Mem[i][j] = MIn.Mem[i][j];
        }
    }
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB, NK, M);

    int i,j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            scanf("%d", &(M->Mem[i][j]));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    int i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf((
                (j != GetLastIdxKol(M)) ? "%d " : 
                ((i != GetLastIdxBrs(M)) ? "%d\n" : "%d")
                ), M.Mem[i][j]);
        }
    }
}
                              
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS MR;
    MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &MR);

    int i,j;
    for (i = GetFirstIdxBrs(MR); i <= GetLastIdxBrs(MR); i++){
        for (j = GetFirstIdxKol(MR); j <= GetLastIdxKol(MR); j++){
            MR.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
        }
    }
    return MR;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS MR;
    MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &MR);

    int i,j;
    for (i = GetFirstIdxBrs(MR); i <= GetLastIdxBrs(MR); i++){
        for (j = GetFirstIdxKol(MR); j <= GetLastIdxKol(MR); j++){
            MR.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
        }
    }
    return MR;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2);
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */

MATRIKS KaliKons (MATRIKS M, ElType X){
    MATRIKS MR;
    MakeMATRIKS(M.NBrsEff, M.NKolEff, &MR);

    int i,j;
    for (i = GetFirstIdxBrs(MR); i <= GetLastIdxBrs(MR); i++){
        for (j = GetFirstIdxKol(MR); j <= GetLastIdxKol(MR); j++){
            MR.Mem[i][j] = X*M.Mem[i][j];
        }
    }
    return MR;
}

void PKaliKons (MATRIKS * M, ElType K){
    *M = KaliKons(*M, K);
}

boolean EQ (MATRIKS M1, MATRIKS M2){
    boolean result = NBElmt(M1) == NBElmt(M2);
    int i,j;
    int baris1 = GetFirstIdxBrs(M1) >= GetFirstIdxBrs(M2) ? GetFirstIdxBrs(M1) : GetFirstIdxBrs(M2);
    int baris2 = GetLastIdxBrs(M1) <= GetLastIdxBrs(M2) ? GetLastIdxBrs(M1) : GetLastIdxBrs(M2);
    int kol1 = GetFirstIdxKol(M1) >= GetFirstIdxKol(M2) ? GetFirstIdxKol(M1) : GetFirstIdxKol(M2);
    int kol2 = GetLastIdxKol(M1) <= GetLastIdxKol(M2) ? GetLastIdxKol(M1) : GetLastIdxKol(M2);
    for (i = baris1; i <= baris2; i++){
        for (j = kol1; j <= kol2; j++){
            result = result && (M1.Mem[i][j] == M2.Mem[i][j]);
        }
    }
    return result;
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
    return (!EQ(M1, M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2){
    return (M1.NBrsEff == M2.NBrsEff && M1.NKolEff == M2.NKolEff);
}

int NBElmt (MATRIKS M){
    return (M.NBrsEff*M.NKolEff);
}

boolean IsBujurSangkar (MATRIKS M){
    return (M.NBrsEff == M.NKolEff);
}

boolean IsSimetri (MATRIKS M){
    boolean result = IsBujurSangkar(M);
    int i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            result = result && (M.Mem[i][j] == M.Mem[j][i]);
        }
    }
    return result;
}

boolean IsSatuan (MATRIKS M){
    boolean result = IsBujurSangkar(M);
    if (result){
        int i,j;
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
                result = result && ((i != j) ? (M.Mem[i][j] == 0) : (M.Mem[i][j] == 1));
            }
        }
    }
    return result;
}

boolean IsSparse (MATRIKS M){
    int zero = 0,i,j;

    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            zero += (M.Mem[i][j] == 0 ? 1 : 0);
        }
    }

    return (((zero*100/(M.NBrsEff*M.NKolEff))/100) <= 5);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M);
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M);
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M);
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
    MATRIKS MNew;
    MakeMATRIKS(M->NBrsEff, M->NKolEff, &MNew);

    int i,j;
    for (i = GetFirstIdxBrs(MNew); i <= GetLastIdxBrs(MNew); i++){
        for (j = GetFirstIdxKol(MNew); j <= GetLastIdxKol(MNew); j++){
            MNew.Mem[i][j] = M->Mem[j][i];
        }
    }

    *M = MNew;
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */