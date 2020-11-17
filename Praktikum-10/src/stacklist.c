#include "stacklist.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

void Alokasi (address *P, infotype X){
    *P = (address) malloc (sizeof(ElmtStack));
    if (*P != Nil){
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi (address  P){
    free(P);
}

boolean IsEmpty (Stack S){
    return Top(S) == Nil;
}

void CreateEmpty (Stack * S){
    Top(*S) = Nil;
}

void Push (Stack * S, infotype X){
    address A;
    Alokasi(&A, X);
    if (A == Nil) return;

    address first = Top(*S);
    Next(A) = first;
    Top(*S) = A;
}

void Pop (Stack * S, infotype * X){
    *X = InfoTop(*S);

    address deleted = Top(*S);
    Top(*S) = Next(deleted);
}