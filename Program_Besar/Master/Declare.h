bool found;
int choose,j,i,search,ctg;
char cvrRp[10];
char UpChar[10];
char rStat[15];
FILE *fp;
FILE *fp1;
FILE *tmp;

typedef struct{
	int id_barang;
	char nama[15];
	int harga;
}Barang;
Barang brg;

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

typedef struct{
	char fname[7];
	char lname[7];
	char NIK[16];
	char alamat[10];
	int expd, expm, expy;
	int active_status;
}Member;
//char tmpNIK[16];
Member mbr;

typedef struct{
	int no_kamar;
	char tipe_kamar[15];
	int harga;
	int lantai;
	int status;
}Kamar;
Kamar kmr;

typedef struct{
	int id_fasilitas;
	char nama[15];
	int harga;
	int status;
}Fasilitas;
Fasilitas fsl;

typedef struct{
	int id_menu;
	char nama[15];
	char category[10];
	int harga;
}Menu;
Menu mnu;

typedef struct{
	int id_paket;
	int id_menu;
	int jumlah;
	char nama_paket[15];
	int harga;
}Paket;
Paket pkt;

