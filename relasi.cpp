#include "relasi.h"

void createListRelasi(List_relasi &L) {
    first(L) = NULL;
}

void createElemenRelasi(address_parent P, address_child C, address_relasi &Q){
    Q = new elmlist_relasi;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
}


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


bool isEmptyRelasi(List_relasi L){
    if(first(L) == NULL){
        return true;
    }else{
        return false;
    }

}

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

address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C){
    address_relasi Q = first(L);
    
    if(isEmptyRelasi(L) == true){
        cout << "Tidak ada data" << endl;
    }else{
        while(Q != NULL) {
            if(parent(Q)==P && child(Q)== C) {
                return Q;
            }else{
                Q = next(Q);
            }
        }
    }
    
    return NULL;
}

void printInfoRelasi(List_relasi L) {
   address_relasi P = first(L);
   int i = 0;
   cout << "======================= Menampilkan Relasi ======================" << endl << endl;
    
   while(P !=NULL) {
       i = i + 1;
       cout << i << ". " << info(parent(P)).nama << " : " << info(child(P)).nama_Barang << endl;
       P = next(P);
    }
    cout << "=================================================================" << endl;
}
