void CreateKry(){
	while(1){
		clrDb();
		KrCreateForm();
		
		next:
		
		fp = fopen("Dat/Karyawan.dat", "ab+");
		if(fread(&kry,sizeof(kry),1,fp)==0){
			kry.id_karyawan = 1;
		}else{
			while(!feof(fp)){
				fread(&kry,sizeof(kry),1,fp);
				if(feof(fp)){
					kry.id_karyawan+=1;
				}
			}
		}
		
		gotoxy(63,23);
		if(kry.id_karyawan<10){
			printf("EMP00%d",kry.id_karyawan);
		}else if(kry.id_karyawan>=10){
			printf("EMP0%d",kry.id_karyawan);
		}else{
			printf("EMP%d",kry.id_karyawan);	
		}
		
		reset:
		
		gotoxy(100,23);
		getteksnummin(&kry.no_telp,11,13);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		gotoxy(63,28);
		getletter(kry.fname,5);
		strupr(kry.fname);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		gotoxy(100,28);
		getletter(kry.lname,5);
		strupr(kry.lname);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		gotoxy(63,33);
		getteks(kry.username,7);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		gotoxy(100,33);
		getpass(kry.password,10);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		
		selectedOption = 1;
		pressed = 2;
		do {
			customClr(70,1,65,37);
		       switch(selectedOption){
		       	case 1:
		       		gotoxy(65,37);
		       		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(95,37);
		       		printf("%c",42);
		       	break;
		       	case 3:
		       		gotoxy(127,37);
		       		printf("%c",42);
		       	break;
			}
		
			key = getch();
			
			if(key == 13){
				pressed = 1;
			}else if(key == 27){
				pressed = 0;
			}else{
				switch (key) {
		           case 75:
		               if (selectedOption > 1) {
		                   selectedOption--;
		                   Beep(800,125);
		               }
		               break;
		           case 77:
		               if (selectedOption < 3) {
		                   selectedOption++;
		                   Beep(800,125);
		               }
		            break;
		       	}	
			}
		} while (pressed == 2);
		Beep(900,125);
			
		if(pressed==0){
			customClr(70,1,65,37);
			fclose(fp);
			break;
		}
		
		switch(selectedOption){
			case 1:
				strcpy(kry.role,"MANAGER");
			break;
			case 2:
				strcpy(kry.role,"CASHIER");
			break;
			case 3:
				strcpy(kry.role,"RECEPTIONIST");
			break;
		}
		
		selectedOption = 2;
		pressed = 2;
		do {
			customClr(70,1,65,40);
		       switch(selectedOption){
		       	case 1:
		       		gotoxy(88,40);
		       		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(108,40);
		       		printf("%c",42);
		       	break;
			}
					key = getch();
			
			if(key == 13){
				pressed = 1;
			}else if(key == 27){
				pressed = 0;
			}else{
				switch (key) {
		           case 75:
		               if (selectedOption > 1) {
		                   selectedOption--;
		                   Beep(800,125);
		               }
		               break;
		           case 77:
		               if (selectedOption < 2) {
		                   selectedOption++;
		                   Beep(800,125);
		               }
		            break;
		       	}	
			}
		} while (pressed == 2);
		Beep(900,125);
		
		if(pressed == 0){
			fclose(fp);
			break;
		}
		
		
		
		switch(selectedOption){
		case 1:
			gotoxy(100,23);
			printf("              ");
			gotoxy(63,28);
			printf("      ");
			gotoxy(100,28);
			printf("      ");
			gotoxy(63,33);
			printf("          ");
			gotoxy(100,33);
			printf("          ");
			customClr(70,1,65,37);
			customClr(70,1,65,40);
			goto reset;
		break;
		case 2:
			fwrite(&kry,sizeof(kry),1,fp);
			fclose(fp);
			gotoxy(96,43);
			printf("saving..");
			sleep(3);
			gotoxy(82,43);
			printf("record has been saved successfully.");
			Beep(1100,200);
			sleep(2);
			gotoxy(82,43);
			printf("                                    ");
			gotoxy(63,23);
			printf("       ");
			gotoxy(100,23);
			printf("              ");
			gotoxy(63,28);
			printf("      ");
			gotoxy(100,28);
			printf("      ");
			gotoxy(63,33);
			printf("          ");
			gotoxy(100,33);
			printf("          ");
			customClr(70,1,65,37);
			customClr(70,1,65,40);
			goto next;
		}
	}
}

void ReadKry(){
	clrDb();
	KrViewForm();
	fp = fopen("Dat/Karyawan.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&kry,sizeof(kry),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				if(kry.id_karyawan<10){
					printf("EMP00%d",kry.id_karyawan);
				}else if(kry.id_karyawan>=10){
					printf("EMP0%d",kry.id_karyawan);
				}else{
					printf("EMP%d",kry.id_karyawan);	
				}
				gotoxy(75,i);
				printf("%s %s",kry.fname,kry.lname);
				gotoxy(105,i);
				printf("%s",kry.role);
				gotoxy(135,i);
				printf("%s",kry.no_telp);
				i++;	
			}
		}
	}
	getch();
	fclose(fp);
}

void DisplayKryData(char fname[], char lname[],char role[],char telp[]){
	gotoxy(100,27);
	printf("%s",telp);
	gotoxy(63,32);
	printf("%s",fname);
	gotoxy(100,32);
	printf("%s",lname);
	gotoxy(63,37);
	printf("%s",role);
}

void UpdateFnameKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			gotoxy(0,1);
			printf("                 ");
			fflush(stdin);
			gotoxy(0,1);
			gets(kry.fname);
			strupr(kry.fname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateLnameKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			gotoxy(0,2);
			printf("                 ");
			fflush(stdin);
			gotoxy(0,2);
			gets(kry.lname);
			strupr(kry.lname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateRoleKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			while(1){
				system("cls");
				gotoxy(0,3);
				printf("                        ");
				gotoxy(0,3);
				getletter(kry.role,15);
				strupr(kry.role);
				if(strcmp(kry.role, "RECEPTIONIST")==0 || strcmp(kry.role, "MANAGER")==0 || strcmp(kry.role, "CASHIER")==0){
					break;
				}	
			}
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateTelpKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			gotoxy(0,4);
			printf("                 ");
			gotoxy(0,4);
			getteksnummin(kry.no_telp,11,13);
			strupr(kry.lname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateMenuKry(){
	while(1){
		system("cls");
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateFnameKry();
		}else if(choose==2){
			UpdateLnameKry();
		}else if(choose==3){
			UpdateRoleKry();
		}else if(choose==4){
			UpdateTelpKry();
		}else if(choose==5){
			break;
		}
	}	
}

void UpdateKry(){
	while(1){
		system("cls");
		found = false;
		printf("Employee's ID\t: KRY");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Karyawan.dat","rb");
			while(fread(&kry,sizeof(kry),1,fp)==1){
				if(search==kry.id_karyawan){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuKry();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteKry(){
	while(1){
		clrDb();
		KrDeleteForm();
		goback:
		found = false;
		gotoxy(63,27);
		printf("EMP");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Karyawan.dat","rb");
			while(fread(&kry,sizeof(kry),1,fp)==1){
				if(search==kry.id_karyawan){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				delconf = false;
				fp = fopen("Dat/Karyawan.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&kmr,sizeof(kmr),1,fp)==1){
					if(search==kmr.no_kamar){
						DisplayKryData(kry.fname,kry.lname,kry.role,kry.no_telp);
						selectedOption = 2;
						pressed = 2;
						do {
							customClr(70,1,65,40);
						       switch(selectedOption){
						       	case 1:
						       		gotoxy(88,40);
						       		printf("%c",42);
						       	break;
						       	case 2:
						       		gotoxy(108,40);
						       		printf("%c",42);
						       	break;
							}
							
							key = getch();
							
							switch (key) {
						        case 75:
						            if (selectedOption > 1) {
						                selectedOption--;
						                Beep(800,125);
						            }
						        break;
						        case 77:
						            if (selectedOption < 2) {
						                selectedOption++;
						                Beep(800,125);
						            }
						        break;
						    }	
						} while (key != 13);
						Beep(900,125);
						
						switch(selectedOption){
							case 1:
								fclose(fp);
								fclose(tmp);
								gotoxy(66,27);
								printf("          ");
								gotoxy(100,27);
								printf("              ");
								gotoxy(63,32);
								printf("       ");
								gotoxy(100,32);
								printf("        ");
								gotoxy(63,37);
								printf("                 ");
								customClr(24,1,86,40);
								goto goback;
							break;
							case 2:
								gotoxy(94,43);
								printf("deleting..");
								sleep(3);
								gotoxy(80,43);
								printf("record has been removed successfully.");
								Beep(1100,200);
								sleep(2);
								gotoxy(80,43);
								printf("                                     ");
								gotoxy(66,27);
								printf("          ");
								gotoxy(100,27);
								printf("              ");
								gotoxy(63,32);
								printf("       ");
								gotoxy(100,32);
								printf("        ");
								gotoxy(63,37);
								printf("                 ");
								customClr(24,1,86,40);
								delconf = true;
							break;
						}
					}else{
						fwrite(&kry,sizeof(kry),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Karyawan.dat");
					rename("Dat/Tmp.dat","Dat/Karyawan.dat");
				}
				goto goback;
			}else{
				gotoxy(63,27);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,27);
				printf("             ");
				goto goback;
			}	
		}	
	}
}


void MenuKaryawan(){
	selectedOption = 1;
	pressed = 2;
	PrintAdKaryawan();
	while(1){
		clrDb();
		do {
			KrDb();
			clrMenArrow(12,28,18);
	        switch(selectedOption){
	        	case 1:
	        		gotoxy(28,18);
	        		printf("%c",174);
	        	break;
	        	case 2:
	        		gotoxy(28,20);
	        		printf("%c",174);
	        	break;
	        	case 3:
	        		gotoxy(28,22);
	        		printf("%c",174);
	        	break;
	        	case 4:
	        		gotoxy(28,24);
	        		printf("%c",174);
	        	break;
	        	case 5:
	        		gotoxy(28,26);
	        		printf("%c",174);
	        	break;
			}
	
			key = getch();
			
				switch (key) {
	            case 72: // Up arrow key
	                if (selectedOption > 1) {
	                    selectedOption--;
	                    Beep(800,125);
	                }
	                break;
	            case 80: // Down arrow key
	                if (selectedOption < 5) {
	                    selectedOption++;
	                    Beep(800,125);
	                }
	                break;
	        	}
	    } while (key!=13);
		Beep(900,125);
		clrMenArrow(12,28,18);
		
		if(selectedOption==5){
			clrMainMenu();
			PrintAdMen();
			clrDb();
			break;
		}
		
		switch(selectedOption){
			case 1:
				CreateKry();
			break;
			case 2:
				ReadKry();
			break;
			case 3:
				UpdateKry();
			break;
			case 4:
				DeleteKry();
			break;
		}
		selectedOption = 1;
	}
}
