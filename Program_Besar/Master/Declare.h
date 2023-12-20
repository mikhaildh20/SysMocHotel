bool found;
int choose,j,i;
int search;
char cvrRp[10];
char UpChar[10];
FILE *ArsTmp;

typedef struct{
	int id_barang;
	char nama[15];
	int harga;
}Barang;
Barang brg;
FILE *ArsBrg;

typedef struct{
	int id_karyawan;
	char username[10];
	char password[10];
	char fname[10];
	char lname[10];
	char role[15];
	char no_telp[13];
}Karyawan;
Karyawan kry;
FILE *ArsKry;

typedef struct{
	char NIK[16];
	char fname[10];
	char lname[10];
	char no_telp[13];
	int hari, bulan, tahun;
}Member;
Member mbr;
FILE *ArsMbr;

typedef struct{
	int no_kamar;
	char tipe_kamar[15];
	int harga;
	int lantai;
	bool status;
}Kamar;
Kamar kmr;
FILE *ArsKmr;

typedef struct{
	int id_fasilitas;
	char nama[15];
	int harga;
}Fasilitas;
Fasilitas fsl;
FILE *ArsFsl;

typedef struct{
	int id_makan;
	char nama[15];
	int harga;
}Makanan;
Makanan mkn;
FILE *ArsMkn;

typedef struct{
	int id_catering;
	int id_makan;
	int jumlah;
	char nama[15];
	int harga;
}Catering;
Catering ctr;
FILE *ArsCtr;

