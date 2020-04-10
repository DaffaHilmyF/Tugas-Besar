#include "parent.h"

void createListParent(List_parent &L) {
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
    P = new elmlist_parent;
    info(P).id = customerID;
    info(P).nama = customerName;
    info(P).saldo = saldo;
    next(P) = NULL;
    prev(P) = NULL;
    
}

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
    } else if (first(L)) == last(L)) {
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

void deleteFirstParent(List_parent &L, address_parent &P) {
   if (istParentEmpty(L) == true) {
        cout << "data Kosong";
        cout << endl;
        P = NULL;
    } else if (next(L.first)==NULL) {
        P = first(L);
        first(L) = NULL;
        last(L) = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteByParent(List_parent &L, address_parent &P, string namaCostumer){
    address_parent Q;
    P = findElmParent(L, namaCostumer);

    if(P == NULL){
        cout << "Data tidak ditemukan." << endl << "Data gagal dihapus." << endl;
        P = NULL;
    }else if (next(P) == NULL && prev(P) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        if(P == last(L)){
            deleteLastParent(L, P);
        }else if(P == first(L)){
            deleteFirstParent(L, P);
        }else{
            Q = prev(P);
            next(Q) = next(P);
            prev(next(P)) = Q;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void printInfo(List_parent L) {
    cout << "==================== Menampilkan Data Customer ==================" << endl
    address_parent P = first(L);
    if(listParentEmpty(L)){
        cout << "Maaf tidak ada data";
    }else{
        P = first(L);
        while (P != NULL ) {
            cout <<"ID Customer     : " << info(P).id << endl;
            cout <<"Nama Customer   : " << info(P).nama << endl;
            cout <<"Saldo           : " << info(P).saldo << endl;
            
            P = next(P);
        }
    cout << "=================================================================" endl;
    }
}

address_parent findElmParent(List_parent L, string X) {
    address_parent P = first(L);
    while(P != NULL){
        if(info(P).nama == X) {
            return P;
        }else{
            P = next(P);
        }
    }
    return NULL;
}

void inputParent(List_parent &L){
    string ID, namaCostumer;
    int saldo;

    address_parent P;

    cout << "===================== Menambah Data Customer ====================" << endl << endl;
    cout << "ID Customer    : "; cin >> ID; cin.ignore();
    cout << "Nama Customer  : "; getline(cin, namaCostumer);
    cout << "Saldo          : "; cin >> saldo;
    createParentElmt(P, ID, namaCostumer, saldo);
    insertFirstParent(L, P);
    cout << "=================================================================" << endl;

}
