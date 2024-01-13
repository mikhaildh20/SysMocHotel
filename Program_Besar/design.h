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
	gotoxy(142,15);
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
	printf("Manage Penalty");
	gotoxy(12,30);;
	printf("Log out");
}

void PrintAdRoom(){
	clrMainMenu();
	gotoxy(12,18);
	printf("Create Room");
	gotoxy(12,20);
	printf("View Room");
	gotoxy(12,22);
	printf("Update Room");
	gotoxy(12,24);
	printf("Delete Room");
	gotoxy(12,26);
	printf("Back");
}

void RmCreateForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("ROOM ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,29);
	printf("SELECT ROOM TYPE");
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
	gotoxy(62,18);
	printf("ROOM ID");
	drawBox(62,19,73,3,218,196,191,179,192,217);
	gotoxy(62,24);
	printf("ROOM TYPE");
	drawBox(62,25,73,3,218,196,191,179,192,217);
	gotoxy(62,30);
	printf("TOTAL PRICE");
	drawBox(62,31,73,3,218,196,191,179,192,217);
	gotoxy(62,36);
	printf("ROOM STATUS");
	drawBox(62,37,73,3,218,196,191,179,192,217);
	gotoxy(86,41);;
	printf("Reset");
	gotoxy(100,41);
	printf("Save Changes");
}

void RmDeleteForm(){
	drawBox(53,19,90,27,201,205,187,186,200,188);
	gotoxy(62,23);
	printf("ROOM ID");
	drawBox(62,24,73,3,218,196,191,179,192,217);
	gotoxy(62,28);
	printf("ROOM TYPE");
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

