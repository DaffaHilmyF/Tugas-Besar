#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

#define info(A) A->info
#define next(A) A->next
#define prev(A) A->prev
#define first(A) A.first
#define last(A) A.last

using namespace std;

struct pembeli{
    string id;
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

void createListParent(List_parent &L);
void createParentElmt(address_parent &P, string customerID, string customerName, int saldo);
bool listParentEmpty(List_parent L);
void insertFirstParent(List_parent &L, address_parent P);
void deleteByParent(List_parent &L, address_parent &P, string namaCostumer);
void deleteLastParent(List_parent &L, address_parent &P);
void deleteFirstParent(List_parent &L, address_parent &P);
void printInfoParent(List_parent L);
address_parent findElmParent(List_parent L, string X);
void inputParent(List_parent &L);



#endif // PARENT_H_INCLUDED
