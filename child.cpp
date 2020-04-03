#include "child.h"

bool listChildIsEmpty(List_child L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    }else{
        return false;
    }
}


void createListChild(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}


void createChildElmt(address_child &P){
    string ID, namaBarang;
    int stockBarang, hargaBarang;


    cout << "================ " << "Menambah Data Barang" << " ================" << endl << endl;


    P = new elmlist_child;
    cout << "ID barang      : "; cin >> ID; cin.ignore();
    cout << "Nama barang    : "; getline(cin, namaBarang);
    cout << "Stock barang   : "; cin >> stockBarang;
    cout << "Harga barang   : "; cin >> hargaBarang;

    info(P).id_Barang = ID;
    info(P).nama_Barang = namaBarang;
    info(P).stock_Barang = stockBarang;
    info(P).harga_Barang = hargaBarang;
    next(P) = P;
    prev(P) = P;

    cout << endl;
}


address_child findElm(List_child L, string X) {
    address_child P = first(L);

    if (listChildIsEmpty(L) != true) {
        while (P != NULL && info(P).id_Barang != X) {
            if (info(P).id_Barang == X){
                return P;
            }else{
                P = next(P);
            }
        }
    }
    return NULL;
}



void insertLastChild(List_child &L, address_child P){
    if(listChildIsEmpty(L) == true){
        first(L) = P;
        last(L) = P;
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        prev(first(L)) = P;
        next(P) = first(L);
        last(L) = P;
    }

}

void deleteLastChild(List_child &L, address_child &P){



}

void printInfoChild(List_child L){
    cout << "============== " << "Menampilkan Data Barang" << " ===============" << endl << endl;
    address_child P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang";
    }else{
        while(next(P) != first(L)){
            cout <<"ID          : " << info(P).id_Barang << endl;
            cout <<"Nama Barang : " << info(P).nama_Barang << endl;
            cout <<"Stock       : " << info(P).stock_Barang << endl;
            cout <<"Harga       : " << info(P).harga_Barang << endl;
            P = next(P);
        }
            cout <<"ID          : " << info(P).id_Barang << endl;
            cout <<"Nama Barang : " << info(P).nama_Barang << endl;
            cout <<"Stock       : " << info(P).stock_Barang << endl;
            cout <<"Harga       : " << info(P).harga_Barang << endl;
        }
}
