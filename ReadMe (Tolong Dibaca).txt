=================================================================================================
TUGAS BESAR	: Data Perbelanjaan
Team 		: Daffa Hilmy Fadhlurrohman 	1302194004
		  Rana Ramadhani 		1302194100
=================================================================================================
Deskripsi : 	implementasikan multi linked-list yang memodelkan data pembeli
		dan data barang yang dibelinya di suatu toko. Seorang pembeli bisa membeli banyak
		barang tertentu selama total harga barang yang dibeli tidak melebihi saldo yang
		dimilikinya. Sedangkan suatu barang bisa dibeli oleh siapapun, selama persedian
		barang tersebut masih ada.
=================================================================================================
Ketika ingin membuat relasi, masuk menu no 1, nanti di check nama yang ada didatabase,
jika nama tersebut ada pada database maka bisa lanjut membeli(membuat relasi) barang.
jika nama tersebut tidak ada maka akan diberi pilihan antara membuat akun atau kembali ke menu.


Fungsionalitas :

	----------------------------------		        
	a. Penambahan data pembeli.			
		interface.cpp : 86, 141
		parent.cpp    : 139
	----------------------------------
	
	----------------------------------
	 b. Penambahan data barang.
		interface.cpp : 104
		child.cpp     : 24
	----------------------------------

	----------------------------------
	c. Penentuan relasi antara pembeli 
 	   dan barang yang dibelinya

		interface.cpp : 180-181
		relasi.cpp    : 12, 20 
	----------------------------------

	----------------------------------
	d. Menghapus data pembeli tertentu.

		interface.cpp : 233
		parent.cpp    : 79
	----------------------------------


	----------------------------------
	e. Manghapus data barang tertentu.

		interface.cpp : 246
		child.cpp     : 159
	----------------------------------

	----------------------------------
	f. Menampilkan data keseluruhan 
	   pembeli beserta data barang 
	   yang dibelinya.

		interface.cpp : 298
		relasi.cpp    : 206
	----------------------------------


	----------------------------------
	g. Menampilkan data pembeli yang 
	   mengambil barang tertentu.

		interface.cpp : 310
		relasi.cpp    : 129
	----------------------------------

	----------------------------------
	h. Menampilkan data barang yang
           dibeli oleh seseorang.

		interface.cpp : 316, 355
		relasi.cpp    : 155
	----------------------------------

	----------------------------------
	i. Menampilkan data barang yang 
 	   paling banyak dibeli dan juga 
	   paling sedikit dibeli.

		interface.cpp : 304, 347
		child.cpp     : 212
	----------------------------------

==================================================================
Semoga Bapak, Akang/Teteh dapat terbantu dengan adanya readme ini. 
==================================================================





