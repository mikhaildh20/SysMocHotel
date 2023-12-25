bool found;
int choose,j,i;
int search;
char cvrRp[10];
char UpChar[10];
FILE *fp1;
FILE *fp2
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
	char NIK[16];
	char fname[10];
	char lname[10];
	char no_telp[13];
	int hari, bulan, tahun;
}Member;
Member mbr;

typedef struct{
	int no_kamar;
	char tipe_kamar[15];
	int harga;
	int lantai;
	bool status;
}Kamar;
Kamar kmr;

typedef struct{
	int id_fasilitas;
	char nama[15];
	int harga;
}Fasilitas;
Fasilitas fsl;

typedef struct{
	int id_menu;
	char nama[15];
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

void MainMen(){
	printf("[1] Create\n");
	printf("[2] Read\n");
	printf("[3] Update\n");
	printf("[4] Delete\n");
	printf("Choose: ");
}

