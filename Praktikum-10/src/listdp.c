#include "listdp.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty (List L){
    return (First(L) == Nil) && (Last(L) == Nil);
}

void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
        Prev(result) = Nil;
    }
    return result;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X){
    address now = First(L);
    while(now != Nil && Info(now)!=X){
        now = Next(now);
    }
    return now;
}

void InsVFirst (List *L, infotype X){
    address newfirst = Alokasi(X);
    if (newfirst != Nil){
        if (First(*L) == Nil){
            Last(*L) = newfirst;
        } else {
            Prev(First(*L)) = newfirst;
        }
        Next(newfirst) = First(*L);
        First(*L) = newfirst;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);
    if (newlast != Nil){
        if (Last(*L) == Nil){
            First(*L) = newlast;
        } else {
            Next(Last(*L)) = newlast;
        }
        Prev(newlast) = Last(*L);
        Last(*L) = newlast;
    }
}

void DelVFirst (List *L, infotype *X){
    address deleted = First(*L);
    *X = Info(deleted);
    if (First(*L) == Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
        return;
    }
    Prev(Next(deleted)) = Nil;
    First(*L) = Next(deleted);
    Dealokasi(deleted);
}

void DelVLast (List *L, infotype *X){
    address deleted = Last(*L);
    *X = Info(deleted);
    if (First(*L) == Last(*L)){
        First(*L) = Nil;
        Last(*L) = Nil;
        return;
    }
    Next(Prev(deleted)) = Nil;
    Last(*L) = Prev(deleted);
    Dealokasi(deleted);
}

void InsertFirst (List *L, address P){
    address newfirst = P;
    if (First(*L) == Nil){
        Last(*L) = newfirst;
    } else {
        Prev(First(*L)) = newfirst;
    }
    Next(newfirst) = First(*L);
    First(*L) = newfirst;
}

void InsertLast (List *L, address P){
    address newlast = P;
    if (Last(*L) == Nil){
        First(*L) = newlast;
    } else {
        Next(Last(*L)) = newlast;
    }
    Prev(newlast) = Last(*L);
    Last(*L) = newlast;
}

void InsertAfter (List *L, address P, address Prec){
    if (Prec == Last(*L)){
        InsertLast(L, P);
    } else {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
        Prev(P) = Prec;
        Next(Prec) = P;
    }
}

void InsertBefore (List *L, address P, address Succ){
    if (Succ == First(*L)){
        InsertFirst(L, P);
    } else {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Next(P) = Succ;
        Prev(Succ) = P;
    }
}

void DelFirst (List *L, address *P){
    *P = First(*L);
    First(*L) = Next(*P);
    if (First(*L)==Nil){
        Last(*L) = Nil;
    } else {
        Prev(First(*L)) = Nil;
    }
}

void DelLast (List *L, address *P){
    *P = Last(*L);
    Last(*L) = Prev(*P);
    if(Last(*L)==Nil){
        First(*L) = Nil;
    } else {
        Next(Last(*L)) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if ((*Pdel) == First(*L)){
        DelFirst(L, (*Pdel));
    } else if ((*Pdel) == Last(*L)){
        DelLast(L, Pdel);
    } else {
        Prev(Next(*Pdel)) = Prec;
        Next(Prec) = Next(*Pdel);
    }
}

void DelP (List *L, infotype X){
    address cari = Search(*L, X);
    if (cari != Nil){
        if (cari == First(*L)){
            DelFirst(L, cari);
        } else if (cari == Last(*L)){
            DelLast(L, &cari);
        } else {
            address dummy;
            DelAfter(L, &dummy, Prev(cari));
        }
    }
}

void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    if(*Pdel == First(*L)){
        DelFirst(L, Pdel);
    }else{
        DelAfter(L, Pdel, Prev(*Pdel));
    }
}


void PrintForward (List L){
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

void PrintBackward (List L){
    printf("[");
    if (!IsEmpty(L)){
        address now = Last(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Prev(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}