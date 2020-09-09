#include <stdio.h>
#include "arraypos.h"
#include "boolean.h"

void MakeEmpty (TabInt * T){
    IdxType i;
    for(i=IdxMin; i <= IdxMax; i++){
        T->TI[i] = ValUndef;
    }
    return;
}

int NbElmt (TabInt T){
    IdxType i, count=0;
    for(i=IdxMin; i < IdxMax+1; i++){
        if (T.TI[i] != ValUndef){
            count++;
        } else {
            break;
        }
    }
    return count - IdxMin;
}

int MaxNbEl (TabInt T){
    return (IdxMax-IdxMin+1);
}

IdxType GetFirstIdx (TabInt T){
    return IdxMin;
}

IdxType GetLastIdx (TabInt T){
    return IdxMin+NbElmt(T)-1;
}

boolean IsIdxValid (TabInt T, IdxType i){
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i){
    return (i >= GetFirstIdx(T) && i <= GetLastIdx(T));
}

boolean IsEmpty (TabInt T){
    return (NbElmt(T) == 0);
}

boolean IsFull (TabInt T){
    return (NbElmt(T) == MaxNbEl(T));
}

void BacaIsi (TabInt * T){

    MakeEmpty(T);
    
    int N;
    while (true){
        scanf("%d\n", &N);
        if (N >= 0 && N <= MaxNbEl(*T)){
            break;
        }
        //Karena IsIdxValid(T) merupakan subset dari MaxNbEl(T)
    }

    if (N > 0){
        int i=IdxMin;
        for(i=IdxMin;i < N; i++){
            scanf("%d\n", &(T->TI[i]));
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
            
            if (i != GetLastIdx(T)){
                printf(",");
            }
        }
    }
    printf("]");
    return;
}

TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
    TabInt result;
    MakeEmpty(&result);
    int i;
    for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        if (plus){
            Elmt(result, i) = Elmt(T1, i)+(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
        } else {
            Elmt(result, i) = Elmt(T1, i)-(Elmt(T2, i) != ValUndef ? Elmt(T2, i) : 0);
        }
    }
    return result;
}

boolean IsEQ (TabInt T1, TabInt T2){
    if (NbElmt(T1) != NbElmt(T2)){
        return false;
    }

    boolean result = (NbElmt(T1) == NbElmt(T2));
    int i;
    for(i=GetFirstIdx(T1); i <= GetLastIdx(T1); i++){
        result = result && (Elmt(T1, i) == Elmt(T2, i));
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
    if (IsEmpty(T)){
        return false;
    }
    boolean found = false;
    int i;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if (Elmt(T, i) == X){
            found = true;
            break;
        } 
    }
    return found;
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
    if (IsEmpty(T)){
        return 0;
    }

    int i,sum = 0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        sum += Elmt(T,i);
    }
    return sum;
}

int CountX (TabInt T, ElType X){
    if (IsEmpty(T)){
        return 0;
    }
    int i,count=0;
    for(i=GetFirstIdx(T); i <= GetLastIdx(T); i++){
        if(Elmt(T,i) == X){
            count += 1; 
        }
    };
    return count;
}

boolean IsAllGenap (TabInt T){
    boolean genap = true;
    int i;
    while(genap && i <= GetLastIdx(T)){
        genap = (genap & (Elmt(T,i)%2 == 0));
        i++;
    }
    return genap;
    }

void Sort (TabInt * T, boolean asc){
    int i, j;
    IdxType key;

    for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
        key = Elmt(*T, i);
        j = i-1;
        while (j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < key) || (asc && Elmt(*T,j) > key))){
            Elmt(*T,j+1) = Elmt(*T, j);
            j--;
        }
        Elmt(*T,j+1) = key;
    }
    return;
}

void AddAsLastEl (TabInt * T, ElType X){
    if (!IsFull(*T)) {
        T->TI[(GetLastIdx(*T)+1)] = X;
    }
    return;
}

void DelLastEl (TabInt * T, ElType * X){
    if (IsEmpty(*T)) return;

    *X = T->TI[GetLastIdx(*T)];
    T->TI[GetLastIdx(*T)] = ValUndef;
    return;
}