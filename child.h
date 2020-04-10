#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
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
    int jumlah_Terambil;
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
void insertLastChild(List_child &L, address_child P);
void deleteFirstChild(List_child &L, address_child &P);
void deleteByName(List_child &L,address_child &P, string namaBarang);
void deleteLastChild(List_child &L, address_child &P);
address_child findElmChild_Barang(List_child L, string x);
address_child findElmChild_Id(List_child L, string x);
void printTotalGoods(List_child L);
void printInfoChild(List_child L);
void inputChild(List_child &L);



#endif // CHILD_H_INCLUDED

