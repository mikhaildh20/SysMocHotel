bool found;
bool EscPressed;
bool valid;
bool MusicOn;
bool delconf;
bool updconf;
int choose,j,i,search,ctg,x,y,pressed,selectedOption,tPayment;
char cvrRp[10];
char rStat[15];
char sNIK[16];
char confirm[5];
char tUpdate[50];
int tiUpdate;
char key;
FILE *fp;
FILE *fp1;
FILE *tmp;

typedef struct{
	int id_denda;
	char category[15];
	int nominal;
	char ket[40];
}Denda;
Denda dnd;

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
	int status;
}Menu;
Menu mnu;

typedef struct{
	int id_paket;
	char nama[20];
	int harga;
	char desc[30];
	int status;
}Paket;
Paket pkt;

typedef struct{
	int dd;
	int mm;
	int yy;
}presentDate;
presentDate prdate;

typedef struct{
	int id;
	char nama_karyawan[15];
	int id_member;
	int day,month,year;
	char item[50];
	int qty;
	int price;
	int total_price;
}TransaksiResto;
TransaksiResto trr;

typedef struct{
	char nama[50];
	int harga;
}vTresto;
vTresto vtr[100];

typedef struct{
	int id;
	char nama[15];
	char telp[13];
	char nik[16];
}TransaksiMember;
TransaksiMember trm;

typedef struct{
	char telp[13];
	char nik[16];
}vTmember;
vTmember vtm[100];
