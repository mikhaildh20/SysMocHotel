bool found;
bool EscPressed;
bool valid;
bool MusicOn;
bool delconf;
bool updconf;
int choose,j,i,search,ctg,x,y,pressed,selectedOption,tPayment,bayar,lama;
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
	char category[30];
	int nominal;
	char ket[80];
}Denda;
Denda dnd;

typedef struct{
	int id_karyawan;
	char username[30];
	char password[30];
	char fname[30];
	char lname[30];
	char role[30];
	char no_telp[25];
}Karyawan;
Karyawan kry;

typedef struct{
	int no_kamar;
	char tipe_kamar[30];
	int harga;
	int lantai;
	int status;
}Kamar;
Kamar kmr;

typedef struct{
	int id_fasilitas;
	char nama[30];
	int harga;
	int status;
}Fasilitas;
Fasilitas fsl;

typedef struct{
	int id_menu;
	char nama[30];
	char category[30];
	int harga;
	int status;
}Menu;
Menu mnu;

typedef struct{
	int id_paket;
	char nama[30];
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
	char nama_karyawan[30];
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
	char nama_karyawan[30];
	char nama[30];
	char nik[25];
	char telp[25];
	int jdate,jmonth,jyear;
	int xdate,xmonth,xyear;
	int total_harga;
	int status;
}TransaksiMember;
TransaksiMember trm;

typedef struct{
	int term;
	char telp[25];
	char nik[25];
}vTmember;
vTmember vtm[100];
