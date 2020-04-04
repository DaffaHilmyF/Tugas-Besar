#include "relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

void createElemenRelasi(address_parent P, address_child C){
    address_relasi Q = new elmlist_relasi;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
}


void insertLastRelasi(List_relasi &L, address_relasi P){
    if(isEmptyRelasi(L) == true){
        first(L) = P;
    }else{
        address_relasi Q = first(L);
        while(Q != NULL){
            Q = next(Q);
        }

        next(Q) = P;
        next(P) = NULL;

    }
}


bool isEmptyRelasi(List_relasi L){
    if(first(L) == NULL){
        return true;
    }else{
        return false;
    }

}

void deleteFirstRelasi(List_relasi &L, address_relasi &P){
    if(isEmptyRelasi(L) == true){
        cout << "Relasi tidak ada" << endl;
        P = NULL;
    }else if (next(P) == NULL){
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    }else{
        P = first(L);
        first(L) = P;
        next(P) = NULL;
    }

}

void deleteLastRelasi(List_relasi &L, address_relasi &P){
    if(isEmptyRelasi(L) == true){
        cout << "Relasi tidak ada" << endl;
        P = NULL;
    }else if (next(P) == NULL){
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    }else{
        address_relasi Q;
        P = first(L);
        while (next(P) != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        next(P) = NULL;
    }

}


void deleteByRelasi(List_relasi &L, address_parent &orgTua, address_child &anak, address_relasi &P){
    address_relasi Q;
    P = findElmRelasi(L, orgTua, anak);

    if(P == NULL){ // jika address P tidak ditemukan
        cout << "Data tidak ditemukan." << endl << "Data gagal dihapus." << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){ // jika data hanya ada pada akhir list
        first(L) = NULL;
    }else{
        if(next(P) == NULL){ //Jika Data yang dihapus ada pada akhir list
            while(next(Q) != P){
                Q = next(Q);
            }
            next(Q) == NULL;

        }else{ // Jika data ada pada tengah list
            while(next(Q) != P){
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;

        }
    }

}



address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C){
    address_relasi Q = first(L);
    while(Q != NULL) {
        if(parent(Q)==P && child(Q)== C) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;



}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
   while(P !=NULL) {
        cout << info(parent(P)).id <<endl;
        P = next(P);
    }
}
