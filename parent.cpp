#include "parent.h"

/** LIST PARENT DOUBLE LIST && INSERT FIRST **/

//MEMBUAT LIST KOSONG
void createListParent(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

//MENGECEK LIST PARENT
bool listParentEmpty(List_parent L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    } else {
        return false;
    }
}

//MEMBUAT ELEMENLIST PARENT
void createParentElmt(address_parent &P, string customerID, string customerName, int saldo) {
    P = new elmlist_parent;
    info(P).nama = customerName;
    info(P).id = customerID;
    info(P).saldo = saldo;
    next(P) = NULL;
    prev(P) = NULL;
};


//INSERT FIRST DOUBLE LIST
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

//DELETE LAST DOUBLE LIST
void deleteLastParent(List_parent &L, address_parent &P){
    if (listParentEmpty(L) == true) {
        P = NULL;
    } else if (first(L) == last(L)) {
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


//DELETE FIRST DOUBLE LIST
void deleteFirstParent(List_parent &L, address_parent &P){
    if (listParentEmpty(L) == true) {
        P = NULL;
    } else if (first(L) == last(L)) {
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

//DELETE ELEMEN BERDASARKAN NAMA COSTUMER
//IMPLEMENTASI DELETE AFTER YANG DI MODIFIKASI
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

//MENAMPILKAN DATA PARENT
void printInfoParent(List_parent L){
    cout << "==================== Menampilkan Data Costumer ==================" << endl << endl;
    address_parent P = first(L);
    if(listParentEmpty(L)){
        cout << "Maaf tidak ada data";
    }else{
        while(P != NULL){
            cout <<"ID Costumer     : " << info(P).id << endl;
            cout <<"Nama Costumer   : " << info(P).nama << endl;
            cout <<"Saldo           : " << info(P).saldo << endl;

            P = next(P);
        }
    cout << "=================================================================" << endl;
    }
}

//MENCARI ADDRESS SEBUAH ELEMEN MENGUNAKAN INPUT NAMA COSTUMER
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

//BERISI PROCEDURE UNTUK CREATE ELEMENT LIST DAN INSERT LAST
//TUJUAN UNTUK MEMPERSINGKAT PENULISAN PADA MENU
void inputParent(List_parent &L){
    string ID, namaCostumer;
    int saldo;

    address_parent P;

    cout << "===================== Menambah Data Costumer ====================" << endl << endl;
    cout << "ID Costumer    : "; cin >> ID; cin.ignore();
    cout << "Nama Costumer  : "; getline(cin, namaCostumer);
    cout << "Saldo          : "; cin >> saldo;
    createParentElmt(P, ID, namaCostumer, saldo);
    insertFirstParent(L, P);
    cout << "=================================================================" << endl;

}

//MENAMPILKAN DATA PARENT HANYA NAMA DAN ID
void printInfoParentOnlyNameAndId(List_parent L){
    cout << "==================== Menampilkan Data Costumer ==================" << endl << endl;
    address_parent P = first(L);
    if(listParentEmpty(L)){
        cout << "Maaf tidak ada data";
    }else{
        while(P != NULL){
            cout <<"ID Costumer     : " << info(P).id << endl;
            cout <<"Nama Costumer   : " << info(P).nama << endl;
            P = next(P);
        }
    cout<< endl << "=================================================================" << endl;
    }
}
