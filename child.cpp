#include "child.h"

/** LIST CHILD DOUBLE CIRCULAR LIST && INSERT LAST **/


//MENGECEK LIST CHILD
bool listChildIsEmpty(List_child L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    }else{
        return false;
    }
}


//MEMBUAT LIST CHILD
void createListChild(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

//PROCEDURE INPUT BERISI PROCEDURE CREATE ELEMENT LIST & PROCEDURE INSERT LAST
//BERTUJUAN MEMPERSINGKAT PENULISAN CODE PADA MENU
void inputChild(List_child &L){
    string ID, namaBarang;
    int stockBarang, hargaBarang;
    address_child P;

    cout << "===================== Menambah Data Barang  =====================" << endl << endl;
    cout << "ID barang      : "; cin >> ID; cin.ignore();
    cout << "Nama barang    : "; getline(cin, namaBarang);
    cout << "Stock barang   : "; cin >> stockBarang;
    cout << "Harga barang   : "; cin >> hargaBarang;
    createChildElmt(P, ID, namaBarang, stockBarang, hargaBarang);
    insertLastChild(L, P);
    cout << "=================================================================" << endl;

}


//MEMBUAT ELEMENT LIST TIPE DOUBLE CIRCULAR LIST
void createChildElmt(address_child &P, string ID, string namaBarang, int stockBarang, int hargaBarang){

    P = new elmlist_child;
    info(P).id_Barang = ID;
    info(P).nama_Barang = namaBarang;
    info(P).stock_Barang = stockBarang;
    info(P).harga_Barang = hargaBarang;
    info(P).jumlah_Terambil = 0;
    next(P) = P;
    prev(P) = P;

    cout << endl;
}


//MENCARI ADDRESS ELEMENT DENGAN INPUT STRING NAMA BARANG
address_child findElmChild_Barang(List_child L, string X) {
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

//MENCARI ADDRESS ELEMENT DENGAN INPUT STRING ID
address_child findElmChild_Id(List_child L, string X) {
    address_child P = first(L);


    while(next(P) != first(L) && info(P).id_Barang != X){
        if (info(P).id_Barang == X){
            return P;
        }else{
            P = next(P);
        }

    }
        if (info(P).id_Barang == X){
            return P;
        }else{
            return NULL;
        }
}


//MEMASUKAN ELEMENT BARU DIAKHIR
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

//MENGHAPUS ELEMENT YANG BERADA DI AWAL LIST
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


//MENGHAPUS ELEMENT YANG BERADA DI AKHIR LIST
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


//MENGHAPUS ELEMENT DENGAN MENGGUNAKAN INPUT STRING NAMA BARANG
//IMPLEMENTASI DAN MODIFIKASI DARI DELETE AFTER
void deleteByName(List_child &L, address_child &P, string namaBarang){
    address_child Q;
    P = findElmChild_Barang(L, namaBarang);

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


//MENAMPILKAN DATA PADA ELEMEN YANG TERSEDIA
void printInfoChild(List_child L){
    cout << "================== Menampilkan Data Barang ===================" << endl << endl;
    address_child P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang";
    }else{
        while(next(P) != first(L)){
            cout <<"ID              : " << info(P).id_Barang << endl;
            cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
            cout <<"Stock           : " << info(P).stock_Barang << endl;
            cout <<"Harga           : " << info(P).harga_Barang << endl << endl;

            P = next(P);
        }
        cout <<"ID              : " << info(P).id_Barang << endl;
        cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
        cout <<"Stock           : " << info(P).stock_Barang << endl;
        cout <<"Harga           : " << info(P).harga_Barang << endl << endl;

        }
cout << "=================================================================" << endl;
}


//MENAMPILKAN JUMLAH BARANG TERBANYAK DAN TERSEDIKIT YANG DIBELI OLEH COSTUMER
void printTotalGoods(List_child L){
cout << "============== Menampilkan Jumlah Barang Terambil ===============" << endl << endl;
    address_child P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang";
    }else{
        while(next(P) != first(L)){
            cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
            cout <<"Jumlah Terambil : " << info(P).jumlah_Terambil << endl;


            P = next(P);
        }
        cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
        cout <<"Jumlah Terambil : " << info(P).jumlah_Terambil << endl;

        }
cout << "=================================================================" << endl;



}


//MENAMPILKAN DATA PADA ELEMEN YANG TERSEDIA HANYA NAMA DAN ID
void printInfoChildOnlyNameAndId(List_child L){
    address_child P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang";
    }else{
        while(next(P) != first(L)){
            cout <<"ID              : " << info(P).id_Barang << endl;
            cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
            P = next(P);
        }
        cout <<"ID              : " << info(P).id_Barang << endl;
        cout <<"Nama Barang     : " << info(P).nama_Barang << endl;
        }
}
