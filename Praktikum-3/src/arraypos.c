#include "arraypos.h"
#include "boolean.h"
#include <stdio.h>

void MakeEmpty (TabInt * T){
    int i;
    for(i=IdxMin; i <= IdxMax; i++)
        T->TI[i] = ValUndef;
    return;
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

    return;
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
    printf("]\n");
    return;
}

TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    TabInt result;
    MakeEmpty(&result);
    int i;
    for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if (plus){
            Elmt(result, i) = (Elmt(T1, i) != ValUndef ? Elmt(T1, i) : 0)+(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
        } else {
            Elmt(result, i) = (Elmt(T1, i) != ValUndef ? Elmt(T1, i) : 0)-(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
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
    return;
}

ElType SumTab (TabInt T){
    if (IsEmpty(T)) return 0;

    int i,sum;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++) sum += Elmt(T,i);
    return sum;
}

int CountX (TabInt T, ElType X){
    if (IsEmpty(T)) return 0;

    int i,count=0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X) count += 1; 
    };
    return count;
}

boolean IsAllGenap (TabInt T){
    boolean genap = true;
    int i;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) % 2 != 0){
            genap = false;
            break;
        } 
    }
    return genap;
    }

void Sort (TabInt * T, boolean asc){
    int i, j, n = NbElmt(*T);

    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (((T->TI[j] > T->TI[j+1]) && asc == true) ||
               ((T->TI[j] < T->TI[j+1]) && asc == false)) {
                int temp = T->TI[j];
                T->TI[j] = T->TI[j+1];
                T->TI[j+1] = temp;
            }
        }
    }
    return;
}

void AddAsLastEl (TabInt * T, ElType X){
    if (IsFull(*T)) return;

    T->TI[GetLastIdx(*T)+1] = X;
    return;
}

void DelLastEl (TabInt * T, ElType * X){
    if (IsEmpty(*T)) return;

    (*X) = T->TI[GetLastIdx(*T)];
    T->TI[GetLastIdx(*T)] = ValUndef;
    return;
}