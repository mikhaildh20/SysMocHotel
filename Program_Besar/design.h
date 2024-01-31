//Animasi Loading
 void loadingAnimation() {
	char start;
	EscPressed = false;
	system("cls");
	PrintFile("Asset/Logo.txt", 45,10);
    gotoxy(71,42);
    printf("Press Enter To Start");
    EnterEsc(&start);
    if(start == 13){
    	int i,x;
    	int totalFrames = 23;
        printf("                      ");
		gotoxy(77,40);
    	printf("Loading");
		x = 69;
		for(i=1;i<=25;i++){
		gotoxy(x,41);
			if(i==1){
				printf("%c", 201);
			}else if(i>=2 && i<=24){
				printf("%c", 205);
			}else if(i==25){
				printf("%c\n", 187);
			}
			x++;
		}
		x = 69;
		for(i=1;i<=25;i++){
			gotoxy(x,42);
			if(i==1 || i==25){
				printf("%c", 186);
			}else{
				printf(" ");
			}
		x++;
		}
		x = 69;
		for(i=1;i<=25;i++){
			gotoxy(x,43);
			if(i==1){
				printf("%c", 200);
			}else if(i>=2 && i<=24){
				printf("%c", 205);
			}else if(i==25){
				printf("%c\n", 188);
			}
		x++;
		}
		x = 70;
   		for (i = 0; i < totalFrames; ++i) {
    		gotoxy(x,42);
     	 	printf("%c", 219);
       		fflush(stdout);  // Flush the output buffer to immediately display the animation
       		usleep(10000);
			x++;
  		}
		gotoxy(76,44);
    	printf("Completed!");Beep(800,125);
    	sleep(2);
    	system("cls");
	}else if(start == 27){
		EscPressed = true;
	}
}

//design login
void formLogin(){
	PrintFile("Asset/LOGINPAGE.txt", 1,0);
	drawBox(45,20,72,15,201,205,187,186,200,188);
	gotoxy(50,25);
	printf("USERNAME");
	drawBox(64,24,48,3,218,196,191,179,192,217);
	gotoxy(50,29);
	printf("PASSWORD");
	drawBox(64,28,48,3,218,196,191,179,192,217);
}

void dDashboard(char fname[]){
	PrintFile("Asset/DLOGO.txt",3,0);
	for(x=0;x<160;x++){
		gotoxy(x,13);
		printf("%c",220);
	}
	x = 35;
	for(y=14;y<50;y++){
		gotoxy(x,y);
		printf("%c",219);
	}
	gotoxy(133,15);
	setPrsDate();
	gotoxy(38,15);
	printf("Welcome, %s", fname);
	PrintFile("Asset/SLOGO.txt",12,38);
	gotoxy(9,46);
	printf("J A T I P I L A R");
	gotoxy(10,15);
	printf("-  M  E  N  U  -");
	gotoxy(112,48);
	printf("[ENTER]CONFIRM");
	gotoxy(129,48);
	printf("[UP/DOWN]CHOOSE");
	gotoxy(147,48);
	printf("[ESC]CANCEL");
	gotoxy(3,48);
	printf("Designed By Harapan Orang Tua");
}

void PrintAdMen(){
	gotoxy(12,18);
	printf("Manage Room");
	gotoxy(12,20);
	printf("Manage Facility");
	gotoxy(12,22);
	printf("Manage Employee");
	gotoxy(12,24);
	printf("Manage Bundle");
	gotoxy(12,26);
	printf("Manage F&Bs");
	gotoxy(12,28);
	printf("Manage Fines");
	gotoxy(12,30);;
	printf("Log out");
}

void PrintAdRoom(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Add Room");
	gotoxy(12,20);
	printf("View Room");
	gotoxy(12,22);
	printf("Update Room");
	gotoxy(12,24);
	printf("Remove Room");
	gotoxy(12,26);
	printf("Back");
}

void PrintAdFacility(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Add Facility");
	gotoxy(12,20);
	printf("View Facility");
	gotoxy(12,22);
	printf("Update Facility");
	gotoxy(12,24);
	printf("Remove Facility");
	gotoxy(12,26);
	printf("Back");
}

void PrintAdKaryawan(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Add Employee");
	gotoxy(12,20);
	printf("View Employee");
	gotoxy(12,22);
	printf("Change Employee");
	gotoxy(12,24);
	printf("Remove Employee");
	gotoxy(12,26);
	printf("Back");
}

void PrintAdBundle(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Create Bundle");
	gotoxy(12,20);
	printf("View Bundle");
	gotoxy(12,22);
	printf("Update Bundle");
	gotoxy(12,24);
	printf("Remove Bundle");
	gotoxy(12,26);
	printf("Back");
}

void countRoomData(){
	i = 0;
	fp = fopen("Dat/Kamar.dat","rb");
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void countFacilityData(){
	i = 0;
	fp = fopen("Dat/Fasilitas.dat","rb");
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void countFinesData(){
	i = 0;
	fp = fopen("Dat/Denda.dat","rb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void countBundleData(){
	i = 0;
	fp = fopen("Dat/Paket.dat","rb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void countFoodData(){
	i = 0;
	fp = fopen("Dat/Menu.dat","rb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void countEmployeeData(){
	i = 0;
	fp = fopen("Dat/Karyawan.dat","rb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void Dashboard(){
	drawBox(53,20,90,26,201,205,187,186,200,188);
	PrintFile("Asset/DASHBOARD.txt",72,22);
	//box1
	drawBox(57,28,25,7,201,205,187,186,200,188);
	//box2
	drawBox(86,28,25,7,201,205,187,186,200,188);
	//box3
	drawBox(115,28,25,7,201,205,187,186,200,188);
	//box4
	drawBox(57,36,25,7,201,205,187,186,200,188);
	//box5
	drawBox(86,36,25,7,201,205,187,186,200,188);
	//box6
	drawBox(115,36,25,7,201,205,187,186,200,188);
	gotoxy(67,30);
	printf("ROOMS");
	countRoomData();
	gotoxy(68,31);
	printf("%03d",i);
	gotoxy(94,30);	
	printf("FACILITIES");
	countFacilityData();
	gotoxy(97,31);
	printf("%03d",i);
	gotoxy(125,30);	
	printf("FINES");
	countFinesData();
	gotoxy(126,31);
	printf("%03d",i);
	gotoxy(66,38);
	printf("BUNDLES");
	countBundleData();
	gotoxy(68,39);
	printf("%03d",i);
	gotoxy(96,38);
	printf("FnB's");
	countFoodData();
	gotoxy(97,39);
	printf("%03d",i);
	gotoxy(123,38);
	printf("EMPLOYEES");
	countEmployeeData();
	gotoxy(126,39);
	printf("%03d",i);
}

void PrintAdFines(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Add Fines");
	gotoxy(12,20);
	printf("View Fines");
	gotoxy(12,22);
	printf("Update Fines");
	gotoxy(12,24);
	printf("Remove Fines");
	gotoxy(12,26);
	printf("Back");
}

void PrintAdMenu(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Create Menu");
	gotoxy(12,20);
	printf("View Menu");
	gotoxy(12,22);
	printf("Update Menu");
	gotoxy(12,24);
	printf("Remove Menu");
	gotoxy(12,26);
	printf("Back");
}

void PrintAdUpBundle(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Name");
	gotoxy(12,20);
	printf("Price");
	gotoxy(12,22);
	printf("Desc");
	gotoxy(12,24);
	printf("Back");
}

void PrintAdUpFines(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Category");
	gotoxy(12,20);
	printf("Price");
	gotoxy(12,22);
	printf("Desc");
	gotoxy(12,24);
	printf("Back");
}

void PrintAdUpMenu(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Name");
	gotoxy(12,20);
	printf("Price");
	gotoxy(12,22);
	printf("Category");
	gotoxy(12,24);
	printf("Back");
}

void PrintAdUpRoom(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Room Type");
	gotoxy(12,20);
	printf("Floor");
	gotoxy(12,22);
	printf("Price");
	gotoxy(12,24);
	printf("Back");
}

void PrintAdUpFacility(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Name");
	gotoxy(12,20);
	printf("Price");
	gotoxy(12,22);
	printf("Back");
}

void PrintAdUpEmployee(){
	clrMainMenu();
	gotoxy(12,18);
	printf("First Name");
	gotoxy(12,20);
	printf("Last Name");
	gotoxy(12,22);
	printf("Role");
	gotoxy(12,24);
	printf("Telephone");
	gotoxy(12,26);
	printf("Back");
}

void RmCreateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("ROOM ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,29);
	printf("SELECT ROOM TYPE[LEFT/RIGHT]");
	gotoxy(62,31);
	printf("STANDARD               DOUBLE               SUITE               EXECUTIVE");
	gotoxy(62,34);
	printf("FLOOR");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("TOTAL PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Saves");
}

void RmViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("ROOM ID");
	gotoxy(65,19);
	printf("ROOM TYPE");
	gotoxy(95,19);
	printf("FLOOR");
	gotoxy(110,19);
	printf("PRICE");
	gotoxy(140,19);
	printf("STATUS");
}

void RmUpdateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("ROOM ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("ROOM TYPE[LEFT/RIGHT]");
	drawBox(62,29,73,3,218,196,191,179,192,217);
	gotoxy(62,34);
	printf("FLOOR");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("TOTAL PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(101,41);
	printf("Save Changes");
}

void RmDeleteForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("ROOM ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("ROOM TYPE[LEFT/RIGHT]");
	drawBox(62,29,73,3,218,196,191,179,192,217);
	gotoxy(62,34);
	printf("FLOOR");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("TOTAL PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Delete");
}

void RmDb(){
	PrintFile("Asset/ROOMDB.txt",67,27);
}

void FcCreateForm(){
	drawBox(53,19,90,25,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("FACILIY ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("NAME");
	drawBox(62,29,73,3,218,196,191,179,192,217);
	gotoxy(62,33);
	printf("TOTAL PRICE");
	drawBox(62,34,73,3,218,196,191,179,192,217);
	gotoxy(86,39);
	printf("Reset");
	gotoxy(106,39);
	printf("Saves");
}

void FcDeleteForm(){
	drawBox(53,19,90,25,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("FACILIY ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("NAME");
	drawBox(62,29,73,3,218,196,191,179,192,217);
	gotoxy(62,33);
	printf("TOTAL PRICE");
	drawBox(62,34,73,3,218,196,191,179,192,217);
	gotoxy(86,39);
	printf("Reset");
	gotoxy(106,39);
	printf("Delete");
}

void FcUpdateForm(){
	drawBox(53,19,90,25,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("FACILIY ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("NAME");
	drawBox(62,29,73,3,218,196,191,179,192,217);
	gotoxy(62,33);
	printf("TOTAL PRICE");
	drawBox(62,34,73,3,218,196,191,179,192,217);
	gotoxy(86,39);
	printf("Reset");
	gotoxy(101,39);
	printf("Save Changes");
}

void FcViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("FACILITY ID");
	gotoxy(75,19);
	printf("NAME");
	gotoxy(105,19);
	printf("PRICE");
	gotoxy(135,19);
	printf("STATUS");
}

void FcDb(){
	PrintFile("Asset/FACILITYDB.txt",63,27);
}

void KrDb(){
	PrintFile("Asset/KARYAWANDB.txt",52,27);
}

void KrCreateForm(){
	drawBox(53,18,90,28,201,205,187,186,200,188);
	gotoxy(62,21);
	printf("EMPLOYEE ID");
	drawBox(62,22,36,3,218,196,191,179,192,217);
	gotoxy(99,21);
	printf("TELEPHONE");
	drawBox(99,22,36,3,218,196,191,179,192,217);
	gotoxy(62,26);
	printf("FIRST NAME");
	drawBox(62,27,36,3,218,196,191,179,192,217);
	gotoxy(99,26);
	printf("LAST NAME");
	drawBox(99,27,36,3,218,196,191,179,192,217);
	gotoxy(62,31);
	printf("USERNAME");
	drawBox(62,32,36,3,218,196,191,179,192,217);
	gotoxy(99,31);
	printf("PASSWORD");
	drawBox(99,32,36,3,218,196,191,179,192,217);
	gotoxy(62,36);
	printf("SELECT ROLE[LEFT/RIGHT]");
	gotoxy(62,38);
	printf("MANAGER                       CASHIER                       RECEPTIONIST");
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Saves");
}

void KrViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("EMPLOYEE ID");
	gotoxy(75,19);
	printf("NAME");
	gotoxy(105,19);
	printf("ROLE");
	gotoxy(135,19);
	printf("TELEPHONE");
}

void KrUpdateForm(){
	drawBox(53,21,90,24,201,205,187,186,200,188);
	gotoxy(62,25);
	printf("EMPLOYEE ID");
	drawBox(62,26,36,3,218,196,191,179,192,217);
	gotoxy(99,26);
	printf("TELEPHONE");
	drawBox(99,26,36,3,218,196,191,179,192,217);
	gotoxy(62,30);
	printf("FIRST NAME");
	drawBox(62,31,36,3,218,196,191,179,192,217);
	gotoxy(99,30);
	printf("LAST NAME");
	drawBox(99,31,36,3,218,196,191,179,192,217);
	gotoxy(62,35);
	printf("ROLE[LEFT/RIGHT]");
	drawBox(62,36,73,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(101,41);
	printf("Save Changes");
}

void KrDeleteForm(){
	drawBox(53,21,90,24,201,205,187,186,200,188);
	gotoxy(62,25);
	printf("EMPLOYEE ID");
	drawBox(62,26,36,3,218,196,191,179,192,217);
	gotoxy(99,26);
	printf("TELEPHONE");
	drawBox(99,26,36,3,218,196,191,179,192,217);
	gotoxy(62,30);
	printf("FIRST NAME");
	drawBox(62,31,36,3,218,196,191,179,192,217);
	gotoxy(99,30);
	printf("LAST NAME");
	drawBox(99,31,36,3,218,196,191,179,192,217);
	gotoxy(62,35);
	printf("ROLE");
	drawBox(62,36,73,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Delete");
}

void PkCreateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,22);
	printf("BUNDLE ID");
	drawBox(62,23,73,3,218,196,191,179,192,217);
	gotoxy(62,27);
	printf("NAME");
	drawBox(62,28,35,3,218,196,191,179,192,217);
	gotoxy(100,27);
	printf("PRICE");
	drawBox(100,28,35,3,218,196,191,179,192,217);
	gotoxy(62,32);
	printf("DESCRIPTION");
	drawBox(62,33,73,6,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Saves");
}

void PkViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("BUNDLE ID");
	gotoxy(65,19);
	printf("NAME");
	gotoxy(95,19);
	printf("PRICE");
	gotoxy(110,19);
	printf("DESC");
	gotoxy(140,19);
	printf("STATUS");
}

void PkUpdateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,22);
	printf("BUNDLE ID");
	drawBox(62,23,73,3,218,196,191,179,192,217);
	gotoxy(62,27);
	printf("NAME");
	drawBox(62,28,35,3,218,196,191,179,192,217);
	gotoxy(100,27);
	printf("PRICE");
	drawBox(100,28,35,3,218,196,191,179,192,217);
	gotoxy(62,32);
	printf("DESCRIPTION");
	drawBox(62,33,73,6,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(102,41);
	printf("Save Changes");
}

void PkDeleteForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,22);
	printf("BUNDLE ID");
	drawBox(62,23,73,3,218,196,191,179,192,217);
	gotoxy(62,27);
	printf("NAME");
	drawBox(62,28,35,3,218,196,191,179,192,217);
	gotoxy(100,27);
	printf("PRICE");
	drawBox(100,28,35,3,218,196,191,179,192,217);
	gotoxy(62,32);
	printf("DESCRIPTION");
	drawBox(62,33,73,6,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Delete");
}

void BdDb(){
	PrintFile("Asset/BUNDLEDB.txt",63,27);
}

void MnDb(){
	PrintFile("Asset/MENUDB.txt",63,27);
}

void MnCreateForm(){
	drawBox(53,20,90,25,201,205,187,186,200,188);
	gotoxy(62,24);
	printf("MENU ID");
	drawBox(62,25,73,3,218,196,191,179,192,217);
	gotoxy(62,29);
	printf("NAME");
	drawBox(62,30,73,3,218,196,191,179,192,217);
	gotoxy(62,34);
	printf("CATEGORY[UP/DOWN]");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Saves");
}


void MnViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("MENU ID");
	gotoxy(65,19);
	printf("NAME");
	gotoxy(89,19);
	printf("CATEGORY");
	gotoxy(110,19);
	printf("PRICE");
	gotoxy(140,19);
	printf("STATUS");
}


void MnUpdateForm(){
	drawBox(53,20,90,25,201,205,187,186,200,188);
	gotoxy(62,24);
	printf("MENU ID");
	drawBox(62,25,73,3,218,196,191,179,192,217);
	gotoxy(62,29);
	printf("NAME");
	drawBox(62,30,73,3,218,196,191,179,192,217);
	gotoxy(62,34);
	printf("CATEGORY[UP/DOWN]");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(102,41);
	printf("Save Changes");
}

void MnDeleteForm(){
	drawBox(53,20,90,25,201,205,187,186,200,188);
	gotoxy(62,24);
	printf("MENU ID");
	drawBox(62,25,73,3,218,196,191,179,192,217);
	gotoxy(62,29);
	printf("NAME");
	drawBox(62,30,73,3,218,196,191,179,192,217);
	gotoxy(62,34);
	printf("CATEGORY");
	drawBox(62,35,35,3,218,196,191,179,192,217);
	gotoxy(100,34);
	printf("PRICE");
	drawBox(100,35,35,3,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Delete");
}

void FnDb(){
	PrintFile("Asset/FINESDB.txt",63,27);
}

void FnCreateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("FINES ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("FINES CATEGORY");
	drawBox(62,29,35,3,218,196,191,179,192,217);
	gotoxy(100,28);
	printf("VALUE");
	drawBox(100,29,35,3,218,196,191,179,192,217);
	gotoxy(62,33);
	printf("DESCRIPTION");
	drawBox(62,34,73,6,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(106,41);
	printf("Saves");
}

void FnViewForm(){
	drawBox(40,18,116,30,201,205,187,186,200,188);
	drawBox(40,18,116,3,201,205,187,186,204,185);
	gotoxy(44,19);
	printf("FINES ID");
	gotoxy(75,19);
	printf("CATEGORY");
	gotoxy(105,19);
	printf("VALUE");
	gotoxy(135,19);
	printf("DESCRIPTION");
}

void FnUpdateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("FINES ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("FINES CATEGORY");
	drawBox(62,29,35,3,218,196,191,179,192,217);
	gotoxy(100,28);
	printf("VALUE");
	drawBox(100,29,35,3,218,196,191,179,192,217);
	gotoxy(62,33);
	printf("DESCRIPTION");
	drawBox(62,34,73,6,218,196,191,179,192,217);
	gotoxy(86,41);
	printf("Reset");
	gotoxy(101,41);
	printf("Save Changes");
}

void FnDeleteForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);printf("FINES ID");drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);printf("FINES CATEGORY");drawBox(62,29,35,3,218,196,191,179,192,217);
	gotoxy(100,28);printf("VALUE");drawBox(100,29,35,3,218,196,191,179,192,217);
	gotoxy(62,33);printf("DESCRIPTION");drawBox(62,34,73,6,218,196,191,179,192,217);
	gotoxy(86,41);printf("Reset");
	gotoxy(104,41);printf("Delete");
}

void RReserveForm(){
	drawBox(46,20,104,25,201,205,187,186,200,188);
	gotoxy(54,22);printf("-- R E S E R V A T I O N --");
	gotoxy(54,24);printf("RESERVE ID"); gotoxy(68,24);printf(": TRK");
	gotoxy(54,26);printf("CHECKIN"); gotoxy(68,26);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,28);printf("DURATION");gotoxy(68,28);printf(":     DAY(S)");
	gotoxy(54,30);printf("CHECKOUT");gotoxy(68,30);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,32);printf("ROOM ID");gotoxy(68,32);printf(": KMR");
	gotoxy(54,34);printf("TYPE");gotoxy(68,34);printf(": ");
	gotoxy(54,38);printf("-- C U S T O M E R  D E T A I L S --");
	gotoxy(54,40);printf("NIK");gotoxy(68,40);printf(": ");
	gotoxy(54,42);printf("NAME");gotoxy(68,42);printf(": ");
	gotoxy(102,22);printf("-- T O T A L  P A Y M E N T --");
	gotoxy(102,24);printf("TOTAL");gotoxy(116,24);printf(": Rp");
	gotoxy(102,26);printf("DOWN PAYMENT");gotoxy(116,26);printf(": Rp");
	gotoxy(102,34);printf("-- P A Y M E N T --");
	gotoxy(102,36);printf("PAY");gotoxy(116,36);printf(": Rp");
	gotoxy(102,38);printf("DEBT");gotoxy(116,38);printf(": Rp");
	gotoxy(102,40);printf("CHANGE");gotoxy(116,40);printf(": Rp");
}

void FReserveForm(){
	drawBox(46,20,104,25,201,205,187,186,200,188);
	gotoxy(54,22);printf("-- R E S E R V A T I O N --");
	gotoxy(54,24);printf("RESERVE ID"); gotoxy(68,24);printf(": TRF");
	gotoxy(54,26);printf("CHECKIN"); gotoxy(68,26);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,28);printf("DURATION");gotoxy(68,28);printf(":     DAY(S)");
	gotoxy(54,30);printf("CHECKOUT");gotoxy(68,30);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,32);printf("ROOM ID");gotoxy(68,32);printf(": FCL");
	gotoxy(54,34);printf("TYPE");gotoxy(68,34);printf(": ");
	gotoxy(54,38);printf("-- C U S T O M E R  D E T A I L S --");
	gotoxy(54,40);printf("NIK");gotoxy(68,40);printf(": ");
	gotoxy(54,42);printf("NAME");gotoxy(68,42);printf(": ");
	gotoxy(102,22);printf("-- T O T A L  P A Y M E N T --");
	gotoxy(102,24);printf("TOTAL");gotoxy(116,24);printf(": Rp");
	gotoxy(102,26);printf("DOWN PAYMENT");gotoxy(116,26);printf(": Rp");
	gotoxy(102,34);printf("-- P A Y M E N T --");
	gotoxy(102,36);printf("PAY");gotoxy(116,36);printf(": Rp");
	gotoxy(102,38);printf("DEBT");gotoxy(116,38);printf(": Rp");
	gotoxy(102,40);printf("CHANGE");gotoxy(116,40);printf(": Rp");
}

void clrRReserve(){
	//clr reservasi
	gotoxy(70,26);printf("  ");gotoxy(75,26);printf("  ");gotoxy(80,26);printf("    ");
	gotoxy(70,28);printf("   ");
	gotoxy(70,30);printf("  ");gotoxy(75,30);printf("  ");gotoxy(80,30);printf("    ");
	gotoxy(70,32);printf("KMR   ");
	gotoxy(70,34);printf("              ");
}

void clrFReserve(){
	//clr reservasi
	gotoxy(70,26);printf("  ");gotoxy(75,26);printf("  ");gotoxy(80,26);printf("    ");
	gotoxy(70,28);printf("   ");
	gotoxy(70,30);printf("  ");gotoxy(75,30);printf("  ");gotoxy(80,30);printf("    ");
	gotoxy(70,32);printf("FCL   ");
	gotoxy(70,34);printf("              ");
}

void clrAllReserve(){
	//clr reservasi
	gotoxy(73,24);printf("   ");
	gotoxy(70,26);printf("  ");gotoxy(75,26);printf("  ");gotoxy(80,26);printf("    ");
	gotoxy(70,28);printf("   ");
	gotoxy(70,30);printf("  ");gotoxy(75,30);printf("  ");gotoxy(80,30);printf("    ");
	gotoxy(73,32);printf("   ");
	gotoxy(70,34);printf("              ");
	
	//clr detail cust
	gotoxy(70,40);printf("                ");
	gotoxy(70,42);printf("               ");
	
	//clr tpayment
	gotoxy(120,24);printf("          ");
	gotoxy(120,26);printf("          ");
	
	//clr payment
	gotoxy(120,36);printf("          ");
	gotoxy(120,38);printf("          ");
	gotoxy(120,40);printf("          ");
}

void clrRCheckin(){
	//rsv dtl
	gotoxy(73,25);printf("    ");
	gotoxy(70,27);printf("  ");gotoxy(75,27);printf("  ");gotoxy(80,27);printf("     ");
	gotoxy(70,29);printf("  ");gotoxy(75,29);printf("  ");gotoxy(80,29);printf("     ");
	gotoxy(73,31);printf("    ");
	gotoxy(70,33);printf("               ");
}

void clrAllCheckin(){
	//rsv dtl
	gotoxy(73,25);printf("    ");
	gotoxy(70,27);printf("  ");gotoxy(75,27);printf("  ");gotoxy(80,27);printf("     ");
	gotoxy(70,29);printf("  ");gotoxy(75,29);printf("  ");gotoxy(80,29);printf("     ");
	gotoxy(73,31);printf("    ");
	gotoxy(70,33);printf("               ");
	
	//cst dtl
	gotoxy(70,39);printf("                 ");
	gotoxy(70,41);printf("               ");
	
	//pym dtl
	gotoxy(120,25);printf("             ");
	gotoxy(120,27);printf("             ");
	gotoxy(120,29);printf("             ");
	gotoxy(118,31);printf("                ");
	
	//stts
	gotoxy(118,39);printf("                        ");
}

void RCheckinForm(){
	drawBox(46,21,104,23,201,205,187,186,200,188);
	gotoxy(54,23);printf("-- R E S E R V A T I O N  D E T A I L --");
	gotoxy(54,25);printf("RESERVE ID"); gotoxy(68,25);printf(": TRK");
	gotoxy(54,27);printf("CHECKIN");gotoxy(68,27);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,29);printf("CHECKOUT");gotoxy(68,29);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,31);printf("ROOM ID");gotoxy(68,31);printf(": KMR");
	gotoxy(54,33);printf("TYPE");gotoxy(68,33);printf(": ");
	
	gotoxy(54,37);printf("-- C U S T O M E R  D E T A I L --");
	gotoxy(54,39);printf("NIK");gotoxy(68,39);printf(": ");
	gotoxy(54,41);printf("NAME");gotoxy(68,41);printf(": ");
	
	gotoxy(102,23);printf("-- P A Y M E N T  D E T A I L  --");
	gotoxy(102,25);printf("TOTAL");gotoxy(116,25);printf(": Rp");
	gotoxy(102,27);printf("DOWN PAYMENT");gotoxy(116,27);printf(": Rp");
	gotoxy(102,29);printf("DEBT");gotoxy(116,29);printf(": Rp");
	gotoxy(102,31);printf("STATUS");gotoxy(116,31);printf(": ");
	
	gotoxy(102,37);printf("RESET");gotoxy(116,37);printf("CHECKIN");
	gotoxy(102,39);printf("CHECKIN TIME");gotoxy(116,39);printf(": ");
}

void FCheckinForm(){
	drawBox(46,21,104,23,201,205,187,186,200,188);
	gotoxy(54,23);printf("-- R E S E R V A T I O N  D E T A I L --");
	gotoxy(54,25);printf("RESERVE ID"); gotoxy(68,25);printf(": TRF");
	gotoxy(54,27);printf("CHECKIN");gotoxy(68,27);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,29);printf("CHECKOUT");gotoxy(68,29);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,31);printf("FACILITY ID");gotoxy(68,31);printf(": FCL");
	gotoxy(54,33);printf("TYPE");gotoxy(68,33);printf(": ");
	
	gotoxy(54,37);printf("-- C U S T O M E R  D E T A I L --");
	gotoxy(54,39);printf("NIK");gotoxy(68,39);printf(": ");
	gotoxy(54,41);printf("NAME");gotoxy(68,41);printf(": ");
	
	gotoxy(102,23);printf("-- P A Y M E N T  D E T A I L  --");
	gotoxy(102,25);printf("TOTAL");gotoxy(116,25);printf(": Rp");
	gotoxy(102,27);printf("DOWN PAYMENT");gotoxy(116,27);printf(": Rp");
	gotoxy(102,29);printf("DEBT");gotoxy(116,29);printf(": Rp");
	gotoxy(102,31);printf("STATUS");gotoxy(116,31);printf(": ");
	
	gotoxy(102,37);printf("RESET");gotoxy(116,37);printf("CHECKIN");
	gotoxy(102,39);printf("CHECKIN TIME");gotoxy(116,39);printf(": ");
}

void clrAllCheckout(){
	//clr rsv dtl
	gotoxy(73,25);printf("   ");
	gotoxy(70,27);printf("  ");gotoxy(75,27);printf("  ");gotoxy(80,27);printf("    ");
	gotoxy(70,29);printf("  ");gotoxy(75,29);printf("  ");gotoxy(80,29);printf("    ");
	gotoxy(73,31);printf("   ");
	gotoxy(70,33);printf("               ");
	gotoxy(70,35);printf("   ");
	gotoxy(70,37);printf("                ");
	gotoxy(70,39);printf("               ");
	//clr fn dtl
	gotoxy(121,25);printf("   ");
	gotoxy(118,27);printf("              ");
	gotoxy(120,29);printf("          ");
	//clr fpy dtl
	gotoxy(120,33);printf("           ");
	gotoxy(120,35);printf("           ");
	gotoxy(120,37);printf("           ");
	gotoxy(120,39);printf("           ");
	gotoxy(118,41);printf("                       ");
}

void RCheckoutForm(){
	drawBox(46,21,104,23,201,205,187,186,200,188);
	gotoxy(54,23);printf("-- R E S E R V A T I O N  D E T A I L --");
	gotoxy(54,25);printf("RESERVE ID"); gotoxy(68,25);printf(": TRK");
	gotoxy(54,27);printf("CHECKIN");gotoxy(68,27);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,29);printf("CHECKOUT");gotoxy(68,29);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,31);printf("ROOM ID");gotoxy(68,31);printf(": KMR");
	gotoxy(54,33);printf("TYPE");gotoxy(68,33);printf(": ");
	gotoxy(54,35);printf("LATENESS");gotoxy(68,35);printf(":     DAY(S)");
	gotoxy(54,37);printf("NIK");gotoxy(68,37);printf(": ");
	gotoxy(54,39);printf("NAME");gotoxy(68,39);printf(": ");
	gotoxy(54,41);printf("SKIP");gotoxy(68,41);printf("ADD FINES");
	
	gotoxy(102,23);printf("-- F I N E S  D E T A I L  --");
	gotoxy(102,25);printf("FINES ID");gotoxy(116,25);printf(": FNE");
	gotoxy(102,27);printf("CATEGORY");gotoxy(116,27);printf(": ");
	gotoxy(102,29);printf("VALUE");gotoxy(116,29);printf(": Rp");
	
	gotoxy(102,31);printf("-- F I N A L  P A Y M E N T --");
	gotoxy(102,33);printf("DEBT");gotoxy(116,33);printf(": Rp");
	gotoxy(102,35);printf("LATE FINES");gotoxy(116,35);printf(": Rp");
	gotoxy(102,37);printf("TOTAL");gotoxy(116,37);printf(": Rp");
	gotoxy(102,39);printf("PAY");gotoxy(116,39);printf(": Rp");
	gotoxy(102,41);printf("CHANGE");gotoxy(116,41);printf(": Rp");
}

void FCheckoutForm(){
	drawBox(46,21,104,23,201,205,187,186,200,188);
	gotoxy(54,23);printf("-- R E S E R V A T I O N  D E T A I L --");
	gotoxy(54,25);printf("RESERVE ID"); gotoxy(68,25);printf(": TRF");
	gotoxy(54,27);printf("CHECKIN");gotoxy(68,27);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,29);printf("CHECKOUT");gotoxy(68,29);printf(":    -    -        (DD-MM-YY)");
	gotoxy(54,31);printf("ROOM ID");gotoxy(68,31);printf(": FCL");
	gotoxy(54,33);printf("TYPE");gotoxy(68,33);printf(": ");
	gotoxy(54,35);printf("LATENESS");gotoxy(68,35);printf(":     DAY(S)");
	gotoxy(54,37);printf("NIK");gotoxy(68,37);printf(": ");
	gotoxy(54,39);printf("NAME");gotoxy(68,39);printf(": ");
	gotoxy(54,41);printf("SKIP");gotoxy(68,41);printf("ADD FINES");
	
	gotoxy(102,23);printf("-- F I N E S  D E T A I L  --");
	gotoxy(102,25);printf("FINES ID");gotoxy(116,25);printf(": FNE");
	gotoxy(102,27);printf("CATEGORY");gotoxy(116,27);printf(": ");
	gotoxy(102,29);printf("VALUE");gotoxy(116,29);printf(": Rp");
	
	gotoxy(102,31);printf("-- F I N A L  P A Y M E N T --");
	gotoxy(102,33);printf("DEBT");gotoxy(116,33);printf(": Rp");
	gotoxy(102,35);printf("LATE FINES");gotoxy(116,35);printf(": Rp");
	gotoxy(102,37);printf("TOTAL");gotoxy(116,37);printf(": Rp");
	gotoxy(102,39);printf("PAY");gotoxy(116,39);printf(": Rp");
	gotoxy(102,41);printf("CHANGE");gotoxy(116,41);printf(": Rp");
}

void clrAllReg(){
	gotoxy(82,27);printf("   ");
	gotoxy(79,31);printf("                ");
	gotoxy(79,35);printf("             ");
	gotoxy(79,39);printf("               ");
	
	gotoxy(115,27);printf("  ");gotoxy(120,27);printf("  ");gotoxy(125,27);printf("    ");
	gotoxy(117,31);printf("          ");
	gotoxy(117,35);printf("          ");
	gotoxy(117,39);printf("          ");
}

void RegMemberForm(){
	drawBox(60,21,75,23,201,205,187,186,200,188);
	gotoxy(64,23);printf("-- R E G I S T R A T I O N --");
	gotoxy(64,27);printf("MEMBER ID");gotoxy(77,27);printf(": MBR");
	gotoxy(64,31);printf("NIK");gotoxy(77,31);printf(": ");
	gotoxy(64,35);printf("TELEPHONE");gotoxy(77,35);printf(": ");
	gotoxy(64,39);printf("NAME");gotoxy(77,39);printf(": ");
	
	gotoxy(100,23);printf("-- P A Y M E N T --");
	gotoxy(100,27);printf("EXP DATE");gotoxy(113,27);printf(":    -    -");
	gotoxy(100,31);printf("TOTAL");gotoxy(113,31);printf(": Rp");
	gotoxy(100,35);printf("PAY");gotoxy(113,35);printf(": Rp");
	gotoxy(100,39);printf("CHANGE");gotoxy(113,39);printf(": Rp");
}

void clrAllExt(){
	gotoxy(82,27);printf("   ");
	gotoxy(79,29);printf("                ");
	gotoxy(79,31);printf("             ");
	gotoxy(79,33);printf("               ");
	gotoxy(79,35);printf("  ");gotoxy(84,35);printf("  ");gotoxy(89,35);printf("    ");
	gotoxy(79,37);printf("  ");gotoxy(84,37);printf("  ");gotoxy(89,37);printf("    ");
	gotoxy(79,39);printf("   ");
	
	gotoxy(115,27);printf("  ");gotoxy(120,27);printf("  ");gotoxy(125,27);printf("    ");
	gotoxy(117,29);printf("          ");
	gotoxy(117,31);printf("          ");
	gotoxy(117,33);printf("          ");
}

void ExtMemberForm(){
	drawBox(60,22,75,21,201,205,187,186,200,188);
	gotoxy(64,25);printf("-- E X T E N S I O N --");
	gotoxy(64,27);printf("MEMBER ID");gotoxy(77,27);printf(": MBR");
	gotoxy(64,29);printf("NIK");gotoxy(77,29);printf(": ");
	gotoxy(64,31);printf("TELEPHONE");gotoxy(77,31);printf(": ");
	gotoxy(64,33);printf("NAME");gotoxy(77,33);printf(":  ");
	gotoxy(64,35);printf("JOIN DATE");gotoxy(77,35);printf(":  ");
	gotoxy(64,37);printf("EXP. DATE");gotoxy(77,37);printf(":  ");
	gotoxy(64,39);printf("EXTEND");gotoxy(77,39);printf(":      DAY(S)");
	
	gotoxy(100,25);printf("-- P A Y M E N T --");
	gotoxy(100,27);printf("EXTD. DATE");gotoxy(113,27);printf(":    -    -");
	gotoxy(100,29);printf("TOTAL");gotoxy(113,29);printf(": Rp");
	gotoxy(100,31);printf("PAY");gotoxy(113,31);printf(": Rp");
	gotoxy(100,33);printf("CHANGE");gotoxy(113,33);printf(": Rp");
}

void clrAllRestoForm(){
	gotoxy(65,26);printf("   ");
	gotoxy(62,28);printf("               ");
	gotoxy(62,30);printf("   ");
	customClr(15,1,47,32);
	
	customClr(15,1,47,37);
	gotoxy(65,40);printf("   ");
	gotoxy(62,42);printf("                ");
	gotoxy(62,44);printf("               ");
	
	customClr(58,12,93,28);
	gotoxy(104,42);printf("          ");
	gotoxy(104,44);printf("          ");gotoxy(138,44);printf("          ");
}

void RestoForm(){
	drawBox(43,22,47,25,201,205,187,186,200,188);
	gotoxy(47,24);printf("-- T R A N S A C T I O N --");
	gotoxy(47,26);printf("TRASACT ID");gotoxy(60,26);printf(": TRR");
	gotoxy(47,28);printf("ITEM");gotoxy(60,28);printf(": ");
	gotoxy(47,30);printf("QTY");gotoxy(60,30);printf(": ");
	gotoxy(47,33);printf("ADD");gotoxy(60,33);printf("PAY");
	
	gotoxy(47,36);printf("-- M E M B E R --");
	gotoxy(47,38);printf("ADD");gotoxy(60,38);printf("SKIP");
	gotoxy(47,40);printf("MEMBER ID");gotoxy(60,40);printf(": MBR");
	gotoxy(47,42);printf("NIK");gotoxy(60,42);printf(": ");
	gotoxy(47,44);printf("NAME");gotoxy(60,44);printf(": ");
	
	drawBox(89,22,64,25,203,205,187,186,202,188);
	gotoxy(93,24);printf("-- C A R T --");
	gotoxy(93,26);printf("ITEM");gotoxy(110,26);printf("QUANTITY");gotoxy(130,26);printf("SUBTOTAL");
	
	drawBox(89,40,64,7,204,205,185,186,202,188);
	gotoxy(93,42);printf("TOTAL");gotoxy(100,42);printf(": Rp");
	gotoxy(93,44);printf("PAY");gotoxy(100,44);printf(": Rp");gotoxy(124,44);printf("CHANGE");gotoxy(134,44);printf(": Rp");
}
