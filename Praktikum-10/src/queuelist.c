#include "queuelist.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void Alokasi (address *P, infotype X){
    *P = (address) malloc (sizeof(ElmtQueue));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P){
    free(P);
}

boolean IsEmpty (Queue Q){
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q){
    int n = 0;
    if (!IsEmpty(Q)){
        address now = Head(Q);
        while (now != Nil){
            n++;
            now = Next(now);
        }
    }
    return n;
}

void CreateEmpty(Queue * Q){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void Enqueue (Queue * Q, infotype X){
    address A;
    Alokasi(&A, X);
    if (A == Nil) return;

    if (IsEmpty(*Q)){
        Head(*Q) = A;
        Tail(*Q) = A;
    } else {
        Next(A) = Nil;
        Next(Tail(*Q)) = A;
        Tail(*Q) = A;
    }
}

void Dequeue(Queue * Q, infotype * X){
    *X = InfoHead(*Q);
    Head(*Q) = Next(Head(*Q));
    if (Head(*Q) == Nil){
        Tail(*Q) = Nil;
    }
}
