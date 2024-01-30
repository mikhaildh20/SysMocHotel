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
		printf("EMP%03d",kry.id_karyawan);
		
		reset:
		
		fflush(stdin);
		gotoxy(100,23);
		getteksnummin(&kry.no_telp,11,13);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(63,28);
		getletter(kry.fname,6);
		strupr(kry.fname);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(100,28);
		getletter(kry.lname,6);
		strupr(kry.lname);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(63,33);
		getteks(kry.username,8);
		
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
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
		
		fflush(stdin);
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
		gotoxy(44,21);
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
	updconf = false;
	goback:
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			gotoxy(63,32);
			printf("             ");
			fflush(stdin);
			gotoxy(63,32);
			getletter(tUpdate,6);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(63,32);
				printf("              ");
				gotoxy(63,32);
				printf("%s",kry.fname);
				fclose(fp);
				break;
			}
			
			selectedOption = 2;
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
					customClr(24,1,86,40);
					goto goback;
				break;
				case 2:
					strcpy(kry.fname,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&kry,sizeof(kry),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,32);
					printf("%s",kry.fname);
					updconf = true;
				break;
			}
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Karyawan.dat");
		rename("Dat/Tmp.dat","Dat/Karyawan.dat");
	}
}

void UpdateLnameKry(){
	updconf = false;
	goback:
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			gotoxy(100,32);
			printf("             ");
			fflush(stdin);
			gotoxy(100,32);
			getletter(tUpdate,6);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(100,32);
				printf("              ");
				gotoxy(100,32);
				printf("%s",kry.lname);
				fclose(fp);
				break;
			}
			
			selectedOption = 2;
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
					customClr(24,1,86,40);
					goto goback;
				break;
				case 2:
					strcpy(kry.lname,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&kry,sizeof(kry),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(100,32);
					printf("%s",kry.lname);
					updconf = true;
				break;
			}
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Karyawan.dat");
		rename("Dat/Tmp.dat","Dat/Karyawan.dat");
	}
}

void UpdateRoleKry(){
	updconf = false;
	goback:
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			customClr(73,3,62,36);
			gotoxy(62,37);
			printf("MANAGER                       CASHIER                       RECEPTIONIST");
			selectedOption = 1;
			pressed = 2;
			do {
				customClr(70,1,65,36);
			       switch(selectedOption){
			       	case 1:
			       		gotoxy(65,36);
			       		printf("%c",42);
			       	break;
			       	case 2:
			       		gotoxy(95,36);
			       		printf("%c",42);
			       	break;
			       	case 3:
			       		gotoxy(127,36);
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
				customClr(70,1,65,36);
				drawBox(62,36,73,3,218,196,191,179,192,217);
				gotoxy(63,37);
				printf("%s",kry.role);
				fclose(fp);
				break;
			}
			
			fflush(stdin);
			switch(selectedOption){
				case 1:
					strcpy(tUpdate,"MANAGER");
				break;
				case 2:
					strcpy(tUpdate,"CASHIER");
				break;
				case 3:
					strcpy(tUpdate,"RECEPTIONIST");
				break;
			}
			
			selectedOption = 2;
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
					customClr(24,1,86,40);
					goto goback;
				break;
				case 2:
					strcpy(kry.role,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&kry,sizeof(kry),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					customClr(70,1,65,36);
					drawBox(62,36,73,3,218,196,191,179,192,217);
					gotoxy(63,37);
					printf("%s",kry.role);
					updconf = true;
				break;
			}
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Karyawan.dat");
		rename("Dat/Tmp.dat","Dat/Karyawan.dat");
	}	
}

void UpdateTelpKry(){
	updconf = false;
	goback:
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			gotoxy(100,27);
			printf("             ");
			fflush(stdin);
			gotoxy(100,27);
			getteksnummin(tUpdate,11,13);
			
			if(EscPressed){
				gotoxy(100,27);
				printf("              ");
				gotoxy(100,27);
				printf("%s",kry.no_telp);
				fclose(fp);
				break;
			}
			
			selectedOption = 2;
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
					customClr(24,1,86,40);
					goto goback;
				break;
				case 2:
					strcpy(kry.no_telp,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&kry,sizeof(kry),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(100,27);
					printf("%s",kry.no_telp);
					updconf = true;
				break;
			}
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Karyawan.dat");
		rename("Dat/Tmp.dat","Dat/Karyawan.dat");
	}
}

void UpdateMenuKry(){
	PrintAdUpEmployee();
	while(1){
    	if(selectedOption==5){
    		clrMainMenu();
			clrMenArrow(12,28,20);
			PrintAdKaryawan();
			break;
		}
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
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
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				UpdateFnameKry();
			break;
			case 2:
				UpdateLnameKry();
			break;
			case 3:
				UpdateRoleKry();	
			break;
			case 4:
				UpdateTelpKry();
			break;
		}
	}
}

void UpdateKry(){
	while(1){
		clrDb();
		KrUpdateForm();
		goback:
		found = false;
		gotoxy(63,27);
		printf("EMP");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,27);
			printf("%03d",search);
			fp = fopen("Dat/Karyawan.dat","rb");
			while(fread(&kry,sizeof(kry),1,fp)==1){
				if(search==kry.id_karyawan){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				selectedOption = 1;
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayKryData(kry.fname,kry.lname,kry.role,kry.no_telp);
				UpdateMenuKry();
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
			gotoxy(66,27);
			printf("%03d",search);
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
				while(fread(&kry,sizeof(kry),1,fp)==1){
					if(search==kry.id_karyawan){
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
		KrDb();
		do {
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
