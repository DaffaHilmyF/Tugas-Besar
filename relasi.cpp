#include "list_relasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
    last(L) = NULL;
}


void insertLastRelasi(List_relasi &L, address_relasi P){
    if(isEmptyRelasi(L) == true){
        first(L) = P;
        last(L) = P;
    }else{
        address Q = first(L);
        while(Q != NULL){
            Q = next(Q);
        }
        
        next(Q) = P;
        next(P) = NULL;
        
    }
}

void createElemenRelasi(address_parent P, address_child C){
    address_relasi Q = new elmlist_relasi;
    parent(Q) = Q;
    child(Q) = Q;
    next(Q) = NULL;
}

void isEmptyRelasi(List_relasi L){
    if(first(L) == NULL && last(L) == NULL){
        return true;
    }else{
        return false;
    }

}
