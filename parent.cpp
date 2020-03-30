#include "parent.h"

void createList(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

bool listParentEmpty(List_parent L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    } else {
        return false;
    }
}

void createParentElmt(address_parent &P, int customerID, string customerName, int saldo) {
    P = new elmList_parent;
    
    cout<<"masukkan nama pelanggan"<<endl;
    cin>> nama;
    info(p).nama = customerName;
    cout<< endl;
    
    cout<<"masukkan ID pelanggan"<<endl;
    cin>> id;
    info(p).id = customerID;
    cout<< endl;
    
    cout<<"masukkan saldo pelanggan"<<endl;
    cin>> saldo;
    info(p).saldo = saldo;
    cout<< endl;
    
    next(p) = NULL;
    prev(p) = NULL;
};

void insertFirstParent(List_parent &L, address_parent P) {
    address_parent Q;
    if(listParentEmpty(L)==true) {
        first(L)= P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteLastParent(List_parent &L, address_parent &P){
    if (listParentEmpty(L) == true) {
        cout << "data Kosong";
        cout << endl;
        P = NULL;
    } else if (next(first(L)) == NULL && next(last(L)) == NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = last(L);
        last(L) = prev(P);
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}

void tambahdatasetelah(list &l,address p,address prec){
    if (prec != NULL){
        next(p) = next(prec);
        prev(p) = prec;
        next(prec) = p;

        if (prec =last(l)){
            last(l) = p;
        } else {
            prev(next(p)) = p;
        }
    }
}

void printInfo(List_parent L) {
    address_parent P = first(L);
    P = first(L);
    while (P != NULL ) {
        cout << info(P).id << info(P).nama << info(P).saldo << endl;
        P = next(P);
    }
    cout << endl;
}

address_parent findElmParent(List_parent L, string X) {
    address_parent P = first(L);
    while(P != first(L)){
        if(info(P).nama == X) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
