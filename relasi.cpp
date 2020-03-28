.void printChildList(listChild L){
    address P = first(L);
    if(listChildIsEmpty(L) == true){
        cout << "Maaf tidak ada barang" << endl;
    }else{
        cout << endl;
        while(next(P) != first(L)){
            cout <<"ID          : " << info(P).id_Barang << endl;
            cout <<"Nama Barang : " << info(P).nama_Barang << endl;
            cout <<"Stock       : " << info(P).stock_Barang << endl;
            cout <<"Harga       : " << info(P).harga_Barang << endl;
            P = next(P);
        }
            cout <<"ID          : " << info(P).id_Barang << endl;
            cout <<"Nama Barang : " << info(P).nama_Barang << endl;
            cout <<"Stock       : " << info(P).stock_Barang << endl;
            cout <<"Harga       : " << info(P).harga_Barang << endl;
    }
}
