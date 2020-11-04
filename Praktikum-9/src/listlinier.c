#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L){
    return First(L) == Nil;
}

void CreateEmpty (List *L){
    List LR;
    First(LR) = Nil;
    *L = LR;
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
    if (Info(now) == X){
        return now;
    }

    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) == X){
            return now;
        }
    }
    return Nil;
}

void InsVFirst (List *L, infotype X){
    address first = First(*L);
    address newfirst = Alokasi(X);
    if (newfirst != Nil){
        Next(newfirst) = first;
        First(*L) = newfirst;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmpty(*L)){
        First(*L) = newlast;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
    }
    Next(newlast) = Nil;
}

void DelVFirst (List *L, infotype *X){
    if (IsEmpty(*L)) return;

    address deleted = First(*L);
    *X = Info(deleted);
    First(*L) = Next(deleted);

    Dealokasi(&deleted);
}

void DelVLast (List *L, infotype *X){
    if (IsEmpty(*L)) return;

    address now = First(*L);
    address last = Nil;
    // Misal ada A -> B -> C -> D
    // Maka D adalah now
    // dan C adalah last
    
    while (Next(now) != Nil){
        last = now; // Kedua terakhir sesuai simulasi diatas
        now = Next(now); // Paling terakhir
    }

    *X = Info(now);
    if (last == Nil){ // Kalau last nil, berarti List hanya berisi 1 elemen
        First(*L) = Nil;
    } else { // List berisi setidaknya 2 elemen
        Next(last) = Nil; // Menghapus elemen terakhir dengan mengganti pointer kedua terakhir menjadi Nil
    }

    Dealokasi(&now);

}

void InsertFirst (List *L, address P){
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    if (IsEmpty(*L)) return;
    if (Next(Prec) == Nil) return;

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
    if (IsEmpty(*L)) return;

    address deleted = Search(*L, X);
    if (deleted != Nil){
        address now = First(*L);
        address before = Nil;
        while (now != deleted){
            before = now;
            now = Next(now);
        }

        if (before == Nil){
            First(*L) = Next(now);
        } else {
            Next(before) = Next(now);
        }
        
        Dealokasi(&now);
    }
}

void DelLast (List *L, address *P){
    if (IsEmpty(*L)) return;

    address now = First(*L);
    address before = Nil;
    while (Next(now) != Nil){
        before = now;
        now = Next(now);
    }

    *P = now;
    if (before == Nil){
        First(*L) = Nil;
    } else {
        Next(before) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
    if (IsEmpty(*L)) return;

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
    if (!IsEmpty(*L3)){
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    } else {
        First(*L3) = First(*L2);
    }
    First(*L2) = Nil;
}