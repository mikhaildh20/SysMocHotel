//Prosedur cetak panah
void DisplayMenu(int pos){
	customClr(3,10,88,22);
	switch(pos){
		case 1:
			gotoxy(89,23);
			printf("%c", 174);
		break;
		case 2:
			gotoxy(89,25);
			printf("%c", 174);
		break;
		case 3:
			gotoxy(89,27);
			printf("%c", 174);
		break;
		case 4:
			gotoxy(89,29);
			printf("%c", 174);
		break;
	}
}

//Prosedur arrow control
void selArrow(){
	    int selectedOption = 1;
    	char key;
		int select = 2;
    do {
    //    system("cls"); // Clear the console (Windows specific)

        DisplayMenu(selectedOption);
		//DisplayLMenu(selectedOption);

		key = getch(); // Get a character without waiting for Enter
		
		if(key == 13){
			select = 1;
			//selected menu logic
		}else if(key == 27){
			select = 0;
			//back menu logic
		}else{
			switch (key) {
            case 72: // Up arrow key
                if (selectedOption > 1) {
                    selectedOption--;
                    //printf("Selected Option: %d", selectedOption);
                    Beep(800,125);
                }
                break;
            case 80: // Down arrow key
                if (selectedOption < 4) {
                    selectedOption++;
                    //printf("Selected Option: %d", selectedOption);
                    Beep(800,125);
                }
                break;
        	}	
		}
    } while (select == 2); // 13 is the ASCII code for Enter key
	Beep(900,125);
}

//Prosedur print option menu
void PrintMOption(){
	gotoxy(78,23);
	printf("MANAGER");
	gotoxy(79,25);
	printf("ADMIN");
	gotoxy(76,27);
	printf("RECEPTIONIST");
	gotoxy(80,29);
	printf("QUIT");
}


//Prosedur cetak UI
void DisplayOption(){
	PrintFile("Asset/LOGINPAGE.txt",1,0);
	gotoxy(73,20);
	printf("-- SELECT USER --");
	PrintMOption();
	selArrow();
}

//Animasi Loading
 void loadingAnimation() {
	char start;
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
       		usleep(100000);
			x++;
  		}
		gotoxy(76,44);
    	printf("Completed!");Beep(800,125);
    	sleep(1);
    	system("cls");
    	DisplayOption();
	}else if(start == 27){
		return 0;
	}
}

//void LoginMenu(){
//	PrintFile("Asset/User.txt", 5,2);
//}

//void selectLogin(){
//	gotoxy(12,5);
//	printf("Owner");
//	gotoxy(11,9);
//	printf("Manager");
//	gotoxy(12,13);
//	printf("Admin");
//	gotoxy(11,17);
//	printf("Cashier");
//	gotoxy(12,21);
//	printf("Quit");
//}

//void DisplayLMenu(int selected){
//	system("color 74");
//	printBox(15,20,4,7,7,4);
//	selectLogin();
//	switch(selected){
//		case 1: 
//		printBox(15,3,7,4,7,4);
//		break;
//		case 2:
//		printBox(15,3,7,4,7,8);	
//		break;
//		case 3:
//		printBox(15,3,7,4,7,12);
//		break;
//		case 4: 
//		printBox(15,3,7,4,7,16);
//		break;
//		case 5: 
//		printBox(15,3,7,4,7,20);
//		break;
//	}
//}


//void ownOpt(){	
//	printBox(15,3,7,4,7,4);
//}
//
//void manOpt(){
//	printBox(15,3,7,4,7,8);
//}
//
//void admOpt(){
//	printBox(15,3,7,4,7,12);
//}
//
//void rcpOpt(){
//	printBox(15,3,7,4,7,16);
//}
//
//void lmeOpt(){
//	printBox(15,3,7,4,7,20);
//}

//void Lfocus(int selected){
//	clrBox(15,20,7,4);
//	switch(selected){
//		case 1: 
//		printBox(15,3,7,4,7,4);
//		break;
//		case 2:
//		printBox(15,3,7,4,7,8);	
//		break;
//		case 3:
//		printBox(15,3,7,4,7,12);
//		break;
//		case 4: 
//		printBox(15,3,7,4,7,16);
//		break;
//		case 5: 
//		printBox(15,3,7,4,7,20);
//		break;
//	}
//}
