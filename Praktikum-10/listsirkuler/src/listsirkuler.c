#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listsirkuler.h"

boolean IsEmpty (List L){
    return First(L) == Nil;
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address P){
    free(P);
}

address Search (List L, infotype X){
    address P = First(L);
    if (P == Nil) return Nil;

    while(Next(P) != First(L) && Info(P) != X){
        P = Next(P);
    }

    if (Info(P) == X) return P;

    return Nil;
}

void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil){
        if (IsEmpty(*L)){
            First(*L) = P;
            Next(P) = P;
            
        } else {

            address Q = First(*L);
            Next(P) = First(*L);

            while(Next(Q) != First(*L)){
                Q = Next(Q);
            }

            Next(Q) = P;
            First(*L) = P;
        }
    }
}

void InsVLast (List *L, infotype X){
    InsVFirst(L, X);
    First(*L) = Next(First(*L));
}


void DelVFirst (List *L, infotype * X){
    First(*L) = Next(First(*L));
    DelVLast(L, X);
}

void DelVLast (List *L, infotype * X){
    address P;
    address Q = First(*L);

    while (Next(Next(Q)) != First(*L)){
        Q = Next(Q);
    }

    P = Next(Q);
    *X = Info(P);

    if (Next(Q) == First(*L)){
        CreateEmpty(L);
    } else {
        Next(Q) = First(*L);
    }

    Dealokasi(P);
}

void InsertFirst (List *L, address P){
    if (IsEmpty(*L)){
        
        First(*L) = P;
        Next(P) = P;
    } else {
        address Q = First(*L);
        Next(P) = First(*L);
        while (Next(Q) != First(*L)){
            Q = Next(Q);
        }

        Next(Q) = P;
        First(*L) = P;
    }
}

void InsertLast (List *L, address P){
    InsertFirst(L, P);
    First(*L) = Next(P);
}

void InsertAfter (List *L, address P, address Prec){
    address Q = First(*L);
    First(*L) = Next(Prec);

    InsertFirst(L, P);
    First(*L) = Q;
}

void DelFirst (List *L, address *P){
    First(*L) = Next(First(*L));
    DelLast(L, P);
}

void DelLast (List *L, address *P){
    address R = First(*L);
    address Q = R;

    while (Next(Next(Q)) != R){
        Q = Next(Q);
    }

    *P = Next(Q);

    if (Next(Q) == R){
        CreateEmpty(L);
    } else {
        Next(Q) = R;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    address P = First(*L);
    First(*L) = Next(Next(Prec));

    DelLast(L, Pdel);
    First(*L) = P;
}

void DelP (List *L, infotype X){
    if(!IsEmpty(*L)){
        address Prec = First(*L);
        address dummy;

        if(Info(Prec) == X){
            DelFirst(L, &dummy);

        } else {
            while (Next(Prec) != First(*L) && Info(Next(Prec)) != X){
                Prec = Next(Prec);
            }

            if (Next(Prec) != First(*L)){
                DelAfter(L, &dummy, Prec);
            }
        }
    }
}

void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address P = First(L);
        printf("%d", Info(P));

        while (Next(P) != First(L)){
            P = Next(P);
            printf(",%d", Info(P));
        }
    }
    printf("]");
}
