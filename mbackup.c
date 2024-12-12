#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <winuser.h>
#include <conio.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "Master/Declare.h"
#include "design.h"
#include "lib.h"
#include "config.h"
#include "Master/Barang.h"
#include "Master/Karyawan.h"
#include "Master/Member.h"
#include "Master/Kamar.h"
#include "Master/Fasilitas.h"
#include "Master/Menu.h"
#include "Master/Paket.h"
#include "login.h"
#include "compactMenu.h"

int w,h;

int main(){
	fullscreen();	
//	dDashboard("Imam");
//	RmCreateForm();
//	CreateKmr();
//	ReadKmr();
//	RmViewForm();
//	RmCreateForm();
//	RmDeleteForm();
//	RmUpdateForm();
//	getch();
//	PrintAdMen();
//	AdminMenArr();
//	PaketPaket();
//	MenuMember();
//	MenuMenu();
//	MenuFasilitas();
//	MenuKamar();
//	MenuMember();
//	MenuBarang();
//	MenuKaryawan();
//	getRes(&w,&h);
//	formLogin();
	vLogin();
//	default_res(w,h);
}
