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
        next(last(L)) = P;
        last(L) = P;
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
