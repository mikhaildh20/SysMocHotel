#include <stdio.h>
#include <windows.h>
#include <dos.h>
#include <winuser.h>
#include <conio.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <MMsystem.h>
#include <pthread.h>
#include "Declare.h"
#include "design.h"
#include "lib.h"
#include "config.h"
#include "Master/Denda.h"
#include "Master/Karyawan.h"
#include "Master/Member.h"
#include "Master/Kamar.h"
#include "Master/Fasilitas.h"
#include "Master/Menu.h"
#include "Master/Paket.h"
#include "login.h"
#include "compactMenu.h"
//#include "musicprep.h"


int w,h;

int main(){
//	pthread_t t1, t2;
//	
//	pthread_create(&t1,NULL,mainTask,NULL);
//	pthread_create(&t2,NULL,backgroundMusic,NULL);
//	
//	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);



	fullscreen();

	dDashboard("Imam");
	UpdateKmr();
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
//	vLogin();
//	default_res(w,h);
}
