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


address_child findElmChild(List_child L, string X) {
    address_child P = first(L);

    while(next(P) != first(L) && info(P).nama_Barang != X){
        if (info(P).nama_Barang == X){
            return P;
        }else{
            P = next(P);
        }

    }
        if (info(P).nama_Barang == X){
            return P;
        }else{
            return NULL;
        }
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
void deleteFirstChild(List_child &L, address_child &P){
    if(listChildIsEmpty(L) == true){
        cout << "Tidak ada data dalam database"<<endl;
        P = NULL;
    }else if (first(L) == last(L)) {
        P = last(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
        next(P) = P;
        prev(P) = P;

    }

}

void deleteLastChild(List_child &L, address_child &P){
    if(listChildIsEmpty(L) == true){
        cout << "Tidak ada data dalam database"<<endl;
        P = NULL;
    }else if (first(L) == last(L)) {
        P = last(L);
        first(L) = NULL;
        last(L) = NULL;
    }else{
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(P) = P;
        prev(P) = P;
    }


}

void deleteByName(List_child &L, address_child &P, string namaBarang){
    address_child Q;
    P = findElmChild(L, namaBarang);

    if(P == NULL){
        cout << "Data tidak ditemukan." << endl << "Data gagal dihapus." << endl;
        P = NULL;
    }else if (next(P) == P || prev(P) == P){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        if(P == last(L)){
            deleteLastChild(L, P);
        }else if(P == first(L)){
            deleteFirstChild(L, P);
        }else{
            Q = prev(P);
            next(Q) = next(P);
            prev(next(P)) = Q;
            next(P) = P;
            prev(P) = P;
        }

    }
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
        cout << "========================================" << endl;
}
