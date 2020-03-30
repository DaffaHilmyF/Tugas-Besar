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

typedef pembeli infotype_parent;
typedef struct elmlist_parent *address_parent;

struct elmlist_parent {
    infotype_parent info;
    List_relasi child;
    address_parent next, prev;
};

struct List_parent {
    address_parent first;
    address_parent last;
}; 

void createList(List_parent &L);
void createParentElmt(address_parent &P, string costumerID, string costumerName, int saldo);
bool listParentEmpty(List_parent L);
void insertAfterParent(List_parent &L, address_parent P,address_parent Prec);
void insertFirstParent(List_parent &L, address_parent P);
void deleteLastParent(List_parent &L, address_parent &P);
void printInfo(List_parent L);
address_parent findElmParent(List_parent L, string X);

#endif // PARENT_H_INCLUDED
