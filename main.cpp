#include <iostream>

using namespace std;
#include "list_child.h"
#include <stdlib.h>


int main()
{
   List_child LC;
   address_child PC;
   string ID, namaBarang;
   int stockBarang, hargaBarang, opsi;
   string menu[2] = {"1. Masukan Data Barang", "2. Tampilkan Data"};



    createListChild(LC);
    cout << "Menu" << endl;
    for (int i = 0 ; i < 2 ; i++){
        cout << menu[i] << endl;
    }
    cout << "Pilih Menu : "; cin >> opsi;

    switch(opsi) {
        case 1  :
            
            cout<< "Masukan data barang" << endl;
            cin >> ID >> namaBarang >> stockBarang >> hargaBarang;
            createChildElmt(PC, ID, namaBarang, stockBarang, hargaBarang);
            insertLastChild(LC, PC);
            main();

        case 2  :
            printInfo(LC);

        default :
            cout << endl;
            main();
        }

}
