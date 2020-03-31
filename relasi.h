#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "list_relasi.h"
#include "list_child.h"
#include "list_parent.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct List_relasi{
    address_relasi first, last;
};


void createListRelasi(List_relasi &L);
void insertLastRelasi(List_relasi &L, address_relasi P);
void createElemenRelasi(address_parent P, address_child C);

#endif // LIST_RELASI_H_INCLUDED
