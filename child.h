#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED


#include <iostream>
using namespace std;

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

struct barang {
    string id_Barang;
    string nama_Barang;
    int stock_Barang;
    int harga_Barang;
};

typedef barang infotype_child;
typedef struct elmlist_child *address_child;

struct elmlist_child{
    infotype_child info;
    address_child next;
    address_child prev;
};

struct List_child{
    address_child first;
    address_child last;
};



bool listChildIsEmpty(List_child L);
void createListChild(List_child &L);
void createChildElmt(address_child &P, string ID, string namaBarang, int stockBarang, int hargaBarang);
address_child findElm(List_child L, infotype_child x);
void insertLastChild(List_child &L, address_child P);
void printInfo(List_child L);




#endif // CHILD_H_INCLUDED
