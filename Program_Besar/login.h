const char admUser[] = "admin";
const char admPass[] = "admin";
char uname[15];
char passwd[15];
int attempt;
bool match;
bool afLogin;
attempt = 3;

void vLogin(){
	match = false;
	while(1){
		loadingAnimation();
		if(EscPressed){
			exit(1);
		}
		while(1){
			//login
			if(!EscPressed){
				system("cls");
				selectedOption = 1;
				formLogin();
				while(attempt!=0 && !match){
					customClr(7,1,106,23);
					gotoxy(106,23);
					if(attempt == 3){
						printf("%c %c %c",3,3,3);
					}else if(attempt == 2){
						printf("%c %c",3,3);
					}else{
						printf("%c",3);
					}
					afLogin = false;
					gotoxy(65,25);
					printf("               ");
					gotoxy(65,29);
					printf("               ");
					gotoxy(65,25);
					getteks(uname,15);
					
					if(EscPressed){
						break;
					}
					
					gotoxy(65,29);
					getpass(passwd,15);
					
					if(EscPressed){
						break;
					}
					
					fp = fopen("Dat/Karyawan.dat", "rb");
					while(fread(&kry,sizeof(kry),1,fp)==1){
						if(strcmp(uname,kry.username)==0 && strcmp(passwd,kry.password)==0){
							fclose(fp);
							customClr(27,1,64,32);
							gotoxy(99,32);
							printf("Logging In..");
							sleep(2);
							system("cls");
							match = true;
							if(strcmp(kry.role, "CASHIER")==0){
								CashierArrMen(kry.fname);
							}else if(strcmp(kry.role, "MANAGER")==0){
								ManagerArrMen(kry.fname);
							}else if(strcmp(kry.role, "RECEPTIONIST")==0){
								ReceptionistArrMen(kry.fname);
							}
							afLogin = true;
							break;
						}
					}
					fclose(fp);
					if(strcmp(uname,admUser)==0 && strcmp(passwd,admPass)==0){
						customClr(27,1,64,32);
						gotoxy(99,32);
						printf("Logging In..");
						sleep(1);
						system("cls");
						match = true;
						AdminMenArr(admUser);
						afLogin = true;
					}
					if(afLogin){
						attempt = 3;
						match = false;
						EscPressed = false;
						break;
					}
					if(!match){
						attempt--;
						gotoxy(64,32);
						printf("Invalid, %d attempt left.",attempt);
					}
				}
				if(attempt == 0){
					exit(1);
				}	
			}else{
				break;
			}
		}	
	}
}


