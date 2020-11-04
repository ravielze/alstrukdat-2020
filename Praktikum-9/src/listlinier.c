#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L){
    return First(L) == Nil;
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
    }
    return result;

}

void Dealokasi (address *P){
    free(*P);
}

address Search (List L, infotype X){
    if (IsEmpty(L)) return Nil;

    address now = First(L);
    while(now != Nil && Info(now)!=X){
        now = Next(now);
    }
    return now;
}

void InsVFirst (List *L, infotype X){
    address newfirst = Alokasi(X);
    if (newfirst != Nil){
        Next(newfirst) = First(*L);
        First(*L) = newfirst;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmpty(*L)){
        InsVFirst(L, X);
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
        Next(Next(now)) = Nil;
    }
}

void DelVFirst (List *L, infotype *X){
    address deleted = First(*L);
    *X = Info(deleted);
    First(*L) = Next(deleted);

    Dealokasi(&deleted);
}

void DelVLast (List *L, infotype *X){
    address now = First(*L);
    if(Next(now) != Nil){
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        *X = Info(Next(now));
        Dealokasi(&Next(now));
        Next(now) = Nil;
    }else{
        DelVFirst(L, X);
    }
}

void InsertFirst (List *L, address P){
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    if (P == Nil) return;

    if (IsEmpty(*L)){
        First(*L) = P;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(P) = Nil;
        Next(now) = P;
    }
}

void DelFirst (List *L, address *P){
    address deleted = First(*L);
    *P = deleted;
    First(*L) = Next(deleted);
}

void DelP (List *L, infotype X){
    if(!IsEmpty(*L)){
        address now = First(*L);
        address dummy;
        if(Info(now) == X){
            DelFirst(L, &dummy);
        }else{
            while(Next(now) != Nil && Info(Next(now)) != X){
                now = Next(now);
            }
            if(Next(now) != Nil){
                DelAfter(L, &dummy, now);
            }
        }
    }
}

void DelLast (List *L, address *P){
    address now = First(*L);
    if(Next(now) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        DelAfter(L, P, now);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){

    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Next(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}

int NbElmt (List L){
    int n = 0;
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil){
            n++;
            now = Next(now);
        }
    }
    return n;
}

infotype Min (List L){
    address now = First(L);
    infotype min = Info(now);
    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) < min){
            min = Info(now);
        }
    }
    return min;
}
infotype Max (List L){
    address now = First(L);
    infotype max = Info(now);
    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) > max){
            max = Info(now);
        }
    }
    return max;
}

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    }
    First(*L2) = Nil;
}