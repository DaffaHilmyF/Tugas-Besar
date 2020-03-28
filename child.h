#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
using namespace std;

struct barang {
    string id_Barang;
    string nama_Barang;
    int stock_Barang;
    int harga_barang
};

typedef struct barang infotype;
 struct elmlist *address;

struct elmlist{
    infotype info;
    address next;
};

struct list{
    address first;
    address last;
};



#endif // CHILD_H_INCLUDED
