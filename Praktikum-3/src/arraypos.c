#include "arraypos.h"
#include <stdio.h>

void MakeEmpty (TabInt * T){
    int i;
    for(i=IdxMin; i <= IdxMax; i++)
        T->TI[i] = ValUndef;
}

int MaxNbEl (TabInt T){
    int i, count=0;
    for(i=IdxMin; i < IdxMax+1; i++){
        if (T.TI[i] == ValUndef) count++;
    }
    return count;
}

int NbElmt (TabInt T){
    return IdxMax+1-MaxNbEl(T);
}

IdxType GetFirstIdx (TabInt T){
    int index=IdxUndef,i;
    for(i=IdxMin; i < IdxMax+1; i++){
        if (T.TI[i] != ValUndef){
            index = i;
            break;
        }
    }
    return index;
}

IdxType GetLastIdx (TabInt T){
    int index=IdxUndef,i;
    for(i=IdxMax; i >= IdxMin; i--){
        if (T.TI[i] != ValUndef){
            index = i;
            break;
        }
    }
    return index;
}

boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty (TabInt T){
    return (GetFirstIdx(T) == IdxUndef && GetLastIdx(T) == IdxUndef);
}

boolean IsFull (TabInt T){
    return (GetFirstIdx(T) == IdxMin && GetLastIdx(T) == IdxMax);
}

void BacaIsi (TabInt * T){

    MakeEmpty(T);
    
    int N=0;
    while (true){
        scanf("%d", &N);
        if (IsIdxValid(*T,N)) break;
        //Karena IsIdxValid(T) merupakan subset dari MaxNbEl(T)
    }

    if (N > 0){
        int i=IdxMin;
        for(i=IdxMin;i < N; i++){
            scanf("%d", &(T->TI[i]));
        }
    }

}

void TulisIsiTab (TabInt T){
    printf("[");
    if (!IsEmpty(T)){
        int i;
        for (i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d", T.TI[i]);
            
            if (i != GetLastIdx(T)) printf(",");
        }
    }
    printf("]");
}

TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    TabInt result;
    MakeEmpty(&result);
    int i;
    for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if (plus){
            Elmt(result, i) = Elmt(T1, i) + Elmt(T2, i);
        } else {
            Elmt(result, i) = Elmt(T1, i) - Elmt(T2, i);
        }
    }
    return result;
}

boolean IsEQ (TabInt T1, TabInt T2){
    boolean result = true;
    int i;
    for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if (Elmt(T1, i) != Elmt(T2, i)){
            result = false;
            break;
        }
    }
    return result;
}

IdxType Search1 (TabInt T, ElType X){
    if (IsEmpty(T)) return IdxUndef;

    int i,result=IdxUndef;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            result = i;
            break;
        } 
    }
    return result;
}

boolean SearchB (TabInt T, ElType X){
    return Search1(T,X) != IdxUndef;
}

void MaxMin (TabInt T, ElType * Max, ElType * Min){
    int nmax, nmin, i;
    nmin = Elmt(T, GetFirstIdx(T));
    nmax = Elmt(T, GetFirstIdx(T));
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T,i) > nmax){
            nmax = Elmt(T,i);
        } else if (Elmt(T,i) < nmin) {
            nmin = Elmt(T,i);
        }
    }
    *Max = nmax;
    *Min = nmin;
}

ElType SumTab (TabInt T);
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX (TabInt T, ElType X);
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap (TabInt T);
/* Menghailkan true jika semua elemen T genap */

/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc);
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X);
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */