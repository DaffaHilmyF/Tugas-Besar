#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#define info(A) A->info
#define next(A) A->next
#define prev(A) A->prev
#define first(A) A.first
#define last(A) A.last

using namespace std;

struct pembeli{
    int id;
    string nama;
    float saldo;
};

typedef struct elmList *address;

struct elmList{
    pembeli info;
    address next;
    address prev;
};

struct list{
    address first;
    address last;
};

void buatlist(list &l);
void createElement(address &p, string nama, int id, float saldo);
bool listkosong(list l);
void tambahdatapertama(list &l,address p);
void hapusdataterakhir(list &l,address &p);
void tambahdatasetelah(list &l,address p,address prec)
void tampildata(list l);

#endif // PARENT_H_INCLUDED
