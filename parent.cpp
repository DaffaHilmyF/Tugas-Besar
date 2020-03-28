#include "parent.h"

void buatlist(list &l) {
    first(l) = NULL;
    last(l) = NULL;
}

bool listkosong(list l) {
    if (first(l) == NULL && last(l) == NULL) {
        return true;
    } else {
        return false;
    }
}

void tambahdatapertama(list &l,address p) {
    if(listkosong(l)==true) {
        first(l)= p;
        last(l) = p;
    } else {
        next(p) = first(l);
        prev(first(l)) = p;
        first(l) = p;
    }
}

void hapusdataterakhir(list &l,address &p) {
    if (listkosong(l) == true) {
        cout << "data Kosong";
        cout << endl;
        p = NULL;
    } else if (next(first(l)) == NULL && next(last(l)) == NULL) {
        p = first(l);
        first(l) = NULL;
        last(l) = NULL;
    } else {
        p = last(l);
        last(l) = prev(p);
        prev(p) = NULL;
        next(last(l)) = NULL;
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

void tampildata(list l) {
    address p;
    p = first(l);
    while (p != NULL ) {
        cout << info(p)<< " " ;
        p = next(p);
    }

    cout << endl;
}
