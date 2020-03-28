#include "child.h"

void createListChild (list &L) {
    first(L) = NULL;
    last(L) = NULL;
}

bool listChildIsEmpty(list L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    }else{
        return false;
    }
}

address findChildElmt(list L, string X){
    address P = first(L);
    if (listChildIsEmpty(L) != true) {
        while (P != NULL && info(P).id_Barang != X) {
            if (info(P).id_Barang == X){
                return P;
            }else{
                P = next(P);
            }
        }
        return NULL;
}

void createChildElmt(address &P, string ID, string namaBarang, int stockBarang, int hargaBarang){
    P = new elmlist;
    info(P).id_Barang = ID;
    info(P).nama_Barang = namaBarang;
    info(P).stock_Barang = stockBarang;
    info(P).harga_Barang = hargaBarang;
    next(P) = P;
    prev(P) = P;
}
void insertLastChild(list &L, address P){
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
void deleteAfterChild(list &L, address Prec, address &P){

}
void printChildList(list L){
    address P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang"
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
