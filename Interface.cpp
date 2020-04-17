#include "Interface.h"

/** HANYA MENU DOANG **/

//MENAMPILAN MENU AWAL PADA CMD
void showMenu(List_child &C, List_parent &P, List_relasi &R){

    //NAMA MENU DITAMPILKAN DENGAN ARRAY
    const int nMax = 7;
    string Menu[nMax] = {"1. Beli Barang", "2. Input Data Costumer / Barang", "3. Hapus Data Costumer / Barang",
                         "4. Relasi Costumer dan Barang",  "5. Cari Data", "6. Tampil Data", "7. Exit" };
    int option;
    string nama;



    cout <<" ================ SELAMAT DATANG DI BETAMART ================ "<< endl;
    int i = 0;
    while (i <= nMax-1){
        cout << Menu[i] << endl;
        i++;
    }
    cout << "Menu : "; cin >> option;



    switch (option){
    case 1 :
            subMenuBuy(C,P,R);
    case 2 :
            subMenuInput(C,P,R);
    case 3 :
            subMenuDelete(C,P,R);
    case 4 :
            subMenuRelation(C, P, R);
    case 5 :
            subMenuSearch(C, P, R);
    case 6 :
            subMenuDisplay(C,P,R);
    case 7 :
        system("CLS");
        cout << "===================================================================" << endl;
        cout << "=                       ARIGATOU GOZAIMUCH                        =" << endl;
        cout << "=                                                                 =" << endl;
        cout << "=                                                                 =" << endl;
        cout << "=    CREATED AND DEVELOPED BY :                                   =" << endl;
        cout << "=    RANA RAMADHANI NUR FITRIANA                     1302194100   =" << endl;
        cout << "=    DAFFA HILMY FADHLURROHMAN                       1302194004   =" << endl;
        cout << "===================================================================" << endl;
        exit(0);
    default :
        showMenu(C, P, R);
    }

}


//MENAMPILKAN SUBMENU INPUT
// A. PENAMBAHAN DATA PEMBELI
// B. PENAMBAHAN DATA BARANG
void subMenuInput(List_child &C, List_parent &P, List_relasi &R){
address_parent aP;
address_child aC;
address_relasi aR;



system("CLS");
        int inputData;
        cout << "======================== INPUT BARANG ==========================="<< endl;
        cout << "1. Input Data Costumer" <<endl << "2. Input Data Barang" << endl;
        cout << "=================================================================" << endl;
        cout << "Pilih Menu : "; cin >> inputData;
            while(inputData != 1 || inputData != 2){
                if(inputData == 1){
                    system("CLS");
                    cout << "======================== INPUT PEMBELI =========================="<< endl;
                                        /** A. PENAMBAHAN DATA PEMBELI **/
                    cout << "ID yang telah ada : ";
                    aP = first(P);
                    while (aP != NULL){
                        cout << info(aP).id << ", ";
                        aP = next(aP);
                    } cout << endl;

                    inputParent(P);
                    cout << "Data Telah teregistrasi" << endl;
                    system("PAUSE");
                    cout << "=================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);
                }else if(inputData == 2){
                    system("CLS");
                    cout << "======================== INPUT BARANG ==========================="<< endl;
                                        /** B. PENAMBAHAN DATA BARANG **/
                    cout << "ID yang telah ada : ";
                    aC = first(C);
                    while (next(aC) != first(C)){
                        cout << info(aC).id_Barang << ", ";
                        aC = next(aC);
                    }
                        cout << info(aC).id_Barang << endl;

                    inputChild(C);
                    cout << "Data Telah teregistrasi" << endl;
                    system("PAUSE");
                    cout << "=================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);   // ini penyebabnya
                }


            }

    }


//MENAMPILKAN SUBMENU BUY
// C. PENENTUAN RELASI ANTARA PEMBELI DAN BARANG YANG DIBELINYA
void subMenuBuy (List_child &C, List_parent &P, List_relasi &R){
address_parent aP;
address_child aC;
address_relasi aR;

        system("CLS");
        string yesOrNo, nama;

        cout << "========================== SYSTEM CHECK ========================= "<< endl;

        cout << "Sistem Check" << endl << "Masukan Nama : "; cin.ignore(); getline(cin, nama);
        aP = findElmParent(P, nama);
        cout << "=================================================================" << endl;
        system("CLS");

        if(aP == 0){
                cout << "=================================================================" << endl;
                cout << "Nama Anda tidak ada dalam database"  << endl;
                cout << "Ingin Membuat akun ? Y/N " << endl << "Input : "; cin >> yesOrNo;
                while (yesOrNo != "Y" || yesOrNo != "N" ){
                    if (yesOrNo == "Y"){
                        // A. PENAMBAHAN DATA PEMBELI
                        inputParent(P);
                        cout << endl << "Data telah teregister" << endl;
                        cout << "=================================================================" << endl;
                        system("PAUSE");
                        system("CLS");
                        showMenu(C,P,R);
                    }else if(yesOrNo == "N"){
                        system("CLS");
                        showMenu(C,P,R);

                    }else{
                        cout << "Input anda salah"<<endl;
                        cout << "=================================================================" << endl;
                        system("CLS");
                    }
                }


        }else if ( info(aP).nama == nama){

            string idBarang;
            cout <<endl<<"=========================== PILIH BARANG ======================== "<< endl;

                while (yesOrNo != "N" ){
                        printInfoChild(C);

                    cout << "Pilih Barang berdasarkan ID : "; cin >> idBarang;


                        aC = findElmChild_Id(C, idBarang);
                        if (info(aP).saldo <= info(aC).harga_Barang && info(aC).stock_Barang == 0){
                            /** PEMBELI BISA MEMBELI BANYAK BARANG SELAMA TOTAL HARGA YANG DIBELI TIDAK MELEBIHI SALDO YANG DIMILIKINYA.
                                SEDANGKAN SUATU BARANG BISA DIBELI OLEH SIAPAPUN SELAMA PERSEDIAAN BARANG BARANG MASIH ADA **/
                                cout << "Saldo anda tidak cukup atau barang telah habis"<<endl;
                                break;
                        }

                        // C. PENENTUAN RELASI ANTARA PEMBELI DAN BARANG YANG DIBELINYA
                        createElemenRelasi(aP, aC, aR);
                        insertLastRelasi(R, aR);

                        /** Mengurangi saldo Costumer dan Stock Barang jika kondisi diatas false **/
                        info(aC).stock_Barang--;
                        info(aP).saldo = info(aP).saldo - info(aC).harga_Barang;
                        info(aC).jumlah_Terambil++;
                        cout << "=================================================================" << endl;

                        cout <<"Sisa saldo anda adalah " << info(aP).saldo  << " Rupiah," << endl;
                        if( info(aP).saldo <= 0){
                            cout << "Anda tidak dapat melanjutkan pembelian," << endl;
                            cout << "harap mengisi saldo anda kembali :)" << endl << endl;

                            cout << "=================================================================" << endl;
                            system("PAUSE");
                            system("CLS");
                            showMenu(C,P,R);
                        }


                    cout << "Lanjut Membeli (Y/N) : "; cin >> yesOrNo;
                    system("PAUSE");
                    system("CLS");
                }
                showMenu(C,P,R);
            }

    }


//MENAMPILKAN SUBMENU INPUT
// D. MENGHAPUS DATA PEMBELI TERTENTU
// E. MENGHAPUS DATA BARANG TERTENTU
void subMenuDelete(List_child &C, List_parent &P, List_relasi &R){
address_parent aP;
address_child aC;
address_relasi aR;


    system("CLS");
        int inputID;
        string nama;
        cout << "============================= PILIH DELETE ====================== "<< endl;
        cout << "1. Hapus Data Costumer" <<endl << "2. Hapus Data Barang" << endl;
        cout << "=================================================================" << endl;
        cout << "Pilih Menu : "; cin >> inputID;
            while(inputID != 1 || inputID != 2){
                if(inputID == 1){
                    system("CLS");
                    cout << "============================= PILIH DELETE ====================== "<< endl <<endl;
                                        /** D. MENGHAPUS DATA PEMBELI TERTENTU **/

                    printInfoParent(P);

                    cout << "Pilih nama yang mau dihapus : "; cin.ignore(); getline(cin, nama);
                    deleteByParent(P, aP, nama);
                    cout << "Data Telah Terhapus" << endl;
                    system("PAUSE");
                    cout << "=================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);
                }else if(inputID == 2){
                    system("CLS");
                    cout << "============================= PILIH DELETE ====================== "<< endl;
                                        /** E. MENGHAPUS DATA BARANG TERTENTU **/
                    printInfoChild(C);

                    cout << "Pilih nama yang mau dihapus : "; cin.ignore(); getline(cin, nama);
                    deleteByName(C, aC, nama);

                    cout << "Data Telah Terhapus" << endl;
                    system("PAUSE");
                    cout << "=================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);   // ini penyebabnya
                }


        }
}


//MENAMPILKAN SUBMENU DISPLAY
//F. MENAMPILKAN DATA KESELURUHAN PEMBELI BESERTA DATA BARANG YANG DIBELINYA
//G. MENAMPILKAN DATA PEMBELI YANG MENGAMBIL BARANG TERTENTU
//H. MENAMPILKAN DATA BARANG YANG DIBELI OLEH SESEORANG
//I. MENAMPILKAN DATA BARANG YANG PALING BANYAK DIBELI DAN PALING SEDIKIT
void subMenuDisplay(List_child C, List_parent P, List_relasi R){
address_parent aP;
address_child aC;
address_relasi aR;



    system("CLS");
        int inputShow;
        string nama;

        cout << "======================== PILIH TAMPIL DATA ====================== "<< endl;
        cout << "1. Tampil Data Costumer" <<endl << "2. Tampil Data Barang" << endl << "3. Tampil keseluruhan " << endl <<
                "4. Tampil Data Terbanyak dan Sedikit" << endl << "5. Tampil costumer yang mengambil barang" <<  endl <<
                "6. Tampil barang yang dibeli oleh seseorang"<< endl;
        cout << "=================================================================" << endl;
        cout << "Pilih Menu : "; cin >> inputShow;
        while(inputShow != 1 || inputShow != 2 || inputShow != 3 || inputShow != 4 || inputShow != 5 || inputShow != 6 ){
            if (inputShow == 1){
                printInfoParent(P);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }else if(inputShow == 2){
                printInfoChild(C);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }else if(inputShow == 3){
                //F. MENAMPILKAN DATA KESELURUHAN PEMBELI BESERTA DATA BARANG YANG DIBELINYA
                printInfoRelasi(R);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }else if(inputShow == 4){
                //I. MENAMPILKAN DATA BARANG YANG PALING BANYAK DIBELI DAN PALING SEDIKIT
                printTotalGoods(C);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }else if(inputShow == 5){
                 //G. MENAMPILKAN DATA PEMBELI YANG MENGAMBIL BARANG TERTENTU
                showRelationParent(R, C, P);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }else if(inputShow == 6){
                //H. MENAMPILKAN DATA BARANG YANG DIBELI OLEH SESEORANG
                showRelationChild(R, C, P);
                system("PAUSE");
                system("CLS");
                showMenu(C,P,R);
            }

    }

}


//MENAMPILKAN SUBMENU RELASI
// I. MENAMPILKAN DATA PEMBELI YANG MENGAMBIL BARANG TERTENTU
// H. MENAMPILKAN DATA BARANG YANG DIBELI OLEH SESERORANG
void subMenuRelation(List_child C, List_parent P, List_relasi R){
address_parent aP;
address_child aC;
address_relasi aR;

system("CLS");
        int inputData;
        string nama;
        cout << "======================== RELASI BARANG ==========================="<< endl;
        cout << "1. Relasi Costumer" <<endl << "2. Relasi Barang" << endl;
        cout << "==================================================================" << endl;
        cout << "Pilih Menu : "; cin >> inputData;
            while(inputData != 1 || inputData != 2){
                if(inputData == 1){
                    system("CLS");
                    cout << "======================== RELASI COSTUMER ==========================="<< endl;
                              /** I. MENAMPILKAN DATA PEMBELI YANG MENGAMBIL BARANG TERTENTU **/
                    showRelationParent(R,C,P);
                    system("PAUSE");
                    cout << "==================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);
                }else if(inputData == 2){
                    system("CLS");
                    cout << "======================== RELASI BARANG ============================"<< endl;
                                /** H. MENAMPILKAN DATA BARANG YANG DIBELI OLEH SESERORANG **/
                    showRelationChild(R, C, P);
                    system("PAUSE");
                    cout << "===================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);
                }


            }

}


//MENAMPILKAN SUBMENU CARI BARANG
void subMenuSearch(List_child C, List_parent P, List_relasi R){
    address_parent aP;
    address_child aC;
    address_relasi aR;
    int inputData;
    string nama;

        system("CLS");
        cout << "======================== CARI BARANG ==========================="<< endl;
        cout << "1. Cari Data Costumer" <<endl << "2. Cari Data Barang" << endl;
        cout << "=================================================================" << endl;
        cout << "Pilih Menu : "; cin >> inputData;
            while(inputData != 1 || inputData != 2){
                if(inputData == 1){
                    system("CLS");
                    cout << "======================== CARI COSTUMER ==========================="<< endl;
                    cout << "Masukan Nama : "; cin.ignore(); getline(cin, nama);
                    aP = findElmParent(P, nama);
                    if (aP != NULL){
                        cout << "Nama   : " << info(aP).nama<<endl;
                        cout << "Saldo  : " << info(aP).saldo<<endl;
                    }else{
                        cout << "Nama tidak ada dalam database."<<endl;
                    }
                    system("PAUSE");
                    cout << "==================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);  // ini penyebabnya
                }else if(inputData == 2){
                    system("CLS");
                    cout << "======================== CARI BARANG ============================"<< endl;
                    cout << "Masukan Nama : "; cin.ignore(); getline(cin, nama);
                    aC = findElmChild_Barang(C, nama);
                    if (aC != NULL){
                        cout << "Nama   : " << info(aC).nama_Barang<<endl;
                        cout << "Harga  : " << info(aC).harga_Barang<<endl;
                        cout << "Stock  : " << info(aC).stock_Barang<<endl;
                    }else{
                        cout << "Nama tidak ada dalam database."<<endl;
                    }
                    system("PAUSE");
                    cout << "=================================================================" << endl;
                    system("CLS");
                    showMenu(C,P,R);   // ini penyebabnya
                }


            }





}
