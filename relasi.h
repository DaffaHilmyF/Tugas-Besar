#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED


#include "relasi.h"
#include "child.h"
#include "parent.h"



#define next(P) P->next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent


typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_child child;
    address_parent parent;
};

typedef struct List_relasi{
    address_relasi first;
};

bool isEmptyRelasi(List_relasi L);
void createElemenRelasi(address_parent P, address_child C, address_relasi &Q);
void createListRelasi(List_relasi &L);
void insertLastRelasi(List_relasi &L, address_relasi P);
void deleteFirstRelasi(List_relasi &L, address_relasi &P);
void deleteLastRelasi(List_relasi &L, address_relasi &P);
void deleteByRelasi(List_relasi &L, address_parent &orgTua, address_child &anak, address_relasi &P);
address_relasi findElmRelasi(List_relasi L, address_parent P, address_child C);
void printInfoRelasi(List_relasi L) ;
void showRelationParent(List_relasi R, List_child C, List_parent P);
void showRelationChild(List_relasi R, List_child C, List_parent P);



#endif // RELASI_H_INCLUDED
