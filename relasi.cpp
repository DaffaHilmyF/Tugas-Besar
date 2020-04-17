#include "relasi.h"

/** LIST RELASI TIPE SINGLE LIST && INSERT LAST **/


//MEMBUAT LIST
void createListRelasi(List_relasi &L) {
    first(L) = NULL;
}

//MEMBUAT ELEMENT BARU
void createElemenRelasi(address_parent P, address_child C, address_relasi &Q){
    Q = new elmlist_relasi;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
}

//MENAMBAHKAN DATA KE LIST MENGGUNAKAN INSERT LAST
void insertLastRelasi(List_relasi &L, address_relasi P){
    if(isEmptyRelasi(L) == true){
        first(L) = P;
    }else{
        address_relasi Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }

        next(Q) = P;
        next(P) = NULL;

    }
}

//MENGECEK LIST RELASI
bool isEmptyRelasi(List_relasi L){
    if(first(L) == NULL){
        return true;
    }else{
        return false;
    }

}


//MENGHAPUS ELEMENT PERTAMA PADA LIST
void deleteFirstRelasi(List_relasi &L, address_relasi &P){

    if(isEmptyRelasi(L) == true){
        cout << "Relasi tidak ada" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
        P = first(L);
        first(L) = NULL;
        next(P) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }

}


//MENGHAPUS ELEMENT YANG BERADA PADA AKHIR LIST
void deleteLastRelasi(List_relasi &L, address_relasi &P){
    if(isEmptyRelasi(L) == true){
        cout << "Relasi tidak ada" << endl;
        P = NULL;
    }else if (next(first(L)) == NULL){
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


//MENGHAPUS RELASI BERDASARKAN ADDRESS PARENT DAN ADDRESS CHILD YANG TELAH DICARI
//IMPLEMENTASI DAN MODIFIKASI DARI DELETE AFTER
void deleteByRelasi(List_relasi &L, address_parent &orgTua, address_child &anak, address_relasi &P){
    address_relasi Prec = findElmRelasi(L, orgTua, anak);
    address_relasi R;


    address_relasi Q = first(L);
    while(next(Q) != NULL){
        Q = next(Q);
    }
    if(Prec == NULL){ // Data Prec tidak ditemukan
        cout << "Data tidak ada";
        P = NULL;
    }else if(Prec == first(L) && next(Prec) == NULL){

        first(L) = NULL;
        P = NULL;
    }else if (Prec == Q){
        P = Prec;
        deleteLastRelasi(L, P);

    }else if (Prec == first(L)){
        P = Prec;
        deleteFirstRelasi(L, P);

    }else {
        R = first(L);
        while(next(R) != Prec){
            R = next(R);
        }
        P = Prec;
        next(R) = next(P);
        next(P) = NULL;
    }


}


//MENAMPILKAN RELASI YANG TELAH ADA BERDASARKAN COSTUMER TERHADAP BARANG
void showRelationParent(List_relasi R, List_child C, List_parent P){
    string nama;
    address_parent aP;
    address_relasi aR = first(R);

    printInfoParentOnlyNameAndId(P);
    cout << endl << "Masukan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
    aP = findElmParent(P, nama);
    cout << "Membeli : " ;
    if(aP != NULL){
        while(aR != NULL){
            if(info(parent(aR)).nama == nama){
                cout <<info(child(aR)).nama_Barang << ", ";
            }
            aR = next(aR);
        }

    }else{
        cout << "Tidak ada Relasi" <<endl;

    }
    cout << "\n====================================================================" << endl;

}

//MENAMPILKAN RELASI YANG TELAH ADA BERDASARKAN BARANG TERHADAP COSTUMER
void showRelationChild(List_relasi R, List_child C, List_parent P){
    string nama;
    address_child aC;
    address_relasi aR = first(R);

    printInfoChildOnlyNameAndId(C);
    cout << endl << "Masukan Nama : "; cin.ignore(); getline(cin, nama); cout << endl;
    aC= findElmChild_Barang(C, nama);
    cout << "Dibeli oleh : " ;
    if(aC != NULL){
        while(aR != NULL){
            if(info(child(aR)).nama_Barang == nama){
                cout <<info(parent(aR)).nama<< ", ";
            }
            aR = next(aR);
        }

    }else{
        cout << "Tidak ada Relasi" <<endl;

    }
    cout << "\n====================================================================" << endl;

}


//MENCARI ADDRESS RELASI DENGAN INPUT PARENT DAN CHILD
address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C){
    address_relasi Q = first(L);

    if(isEmptyRelasi(L) == true){
        cout << "Tidak ada data" << endl;
    }else{
    while(Q != NULL) {
        if(parent(Q)== P && child(Q)== C) {
            return Q;
        }else{
            Q = next(Q);
        }

    }
    return NULL;

    }




}

//MENAMPILAN ISI RELASI YANG TELAH DIBUAT
void printInfoRelasi(List_relasi L) {

    address_relasi P = first(L);


    cout << "======================= Menampilkan Relasi ======================" << endl << endl;
    while (P != NULL){
            cout << info(parent(P)).nama << " : " << info(child(P)).nama_Barang<<", ";

            P = next(P);
            cout << endl;

    }

    cout << "=================================================================" << endl;
    }



