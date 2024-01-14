void CreateKmr(){
	while(1){
		clrDb();
		RmCreateForm();
			
		next:
			
		fp = fopen("Dat/Kamar.dat", "ab+");
		if(fread(&kmr,sizeof(kmr),1,fp)==0){
			kmr.no_kamar = 1;
		}else{
			while(!feof(fp)){
				fread(&kmr,sizeof(kmr),1,fp);
				if(feof(fp)){
					kmr.no_kamar+=1;
				}
			}
		}
		
		gotoxy(63,25);
		if(kmr.no_kamar<10){
			printf("KMR00%d",kmr.no_kamar);
		}else if(kmr.no_kamar>=10){
			printf("KMR0%d",kmr.no_kamar);
		}else{
			printf("KMR%d",kmr.no_kamar);	
		}
		
		reset:
		
		selectedOption = 1;
		pressed = 2;
		do {
			customClr(70,1,65,30);
		       switch(selectedOption){
		       	case 1:
		       		gotoxy(65,30);
		       		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(87,30);
		       		printf("%c",42);
		       	break;
		       	case 3:
		       		gotoxy(108,30);
		       		printf("%c",42);
		       	break;
		       	case 4:
		       		gotoxy(130,30);
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
		               if (selectedOption < 4) {
		                   selectedOption++;
		                   Beep(800,125);
		               }
		            break;
		       	}	
			}
		} while (pressed == 2);
		Beep(900,125);
			
		if(pressed==0){
			customClr(70,1,65,30);
			fclose(fp);
			break;
		}
			
		switch(selectedOption){
			case 1:
				strcpy(kmr.tipe_kamar,"STANDARD");
			break;
			case 2:
				strcpy(kmr.tipe_kamar,"DOUBLE");
			break;
			case 3:
				strcpy(kmr.tipe_kamar,"SUITE");
			break;
			case 4:
				strcpy(kmr.tipe_kamar,"EXECUTIVE");
			break;
		}
		
		gotoxy(63,36);
		getnummin(&kmr.lantai,1,2);
		
		if(EscPressed){
			customClr(70,1,65,30);
			fclose(fp);
			break;
		}
		
		gotoxy(101,36);
		printf("Rp");
		getRp(&kmr.harga,5,8,104,36);
		
		if(EscPressed){
			customClr(70,1,65,30);
			fclose(fp);
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
			gotoxy(63,36);
			printf("     ");
			gotoxy(104,36);
			printf("            ");
			customClr(24,1,86,40);
			goto reset;
		break;
		case 2:
			kmr.status = 1;
			fwrite(&kmr,sizeof(kmr),1,fp);
			fclose(fp);
			gotoxy(63,25);
			printf("                   ");
			gotoxy(63,36);
			printf("     ");
			gotoxy(104,36);
			printf("            ");
			gotoxy(96,43);
			printf("saving..");
			sleep(3);
			gotoxy(80,43);
			printf("record has been saved successfully.");
			Beep(1100,200);
			sleep(2);
			gotoxy(80,43);
			printf("                                     ");
			customClr(24,1,86,40);
			goto next;
		}		
	}
}

void ReadKmr(){
	clrDb();
	RmViewForm();
	fp = fopen("Dat/Kamar.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&kmr,sizeof(kmr),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				printf("KMR%d",kmr.no_kamar);
				gotoxy(65,i);
				printf("%s",kmr.tipe_kamar);
				gotoxy(95,i);
				printf("%d",kmr.lantai);
				rupiah(kmr.harga,cvrRp);
				gotoxy(110,i);
				printf("Rp%s",cvrRp);
				switch(kmr.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
					break;
				}
				gotoxy(140,i);
				printf("%s",rStat);
				i++;	
			}
		}
	}
	getch();
	fclose(fp);
}

void DisplayKmrData(char tipe[], int harga, int lantai){
	gotoxy(63,30);
	printf("%s\n",tipe);
	gotoxy(63,36);
	printf("%d\n",lantai);
	rupiah(harga,cvrRp);
	gotoxy(101,36);
	printf("Rp%s\n",cvrRp);
}



void UpdateTypeKmr(){
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}else{
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Kamar.dat");
	rename("Dat/Tmp.dat","Dat/Kamar.dat");
}

void UpdateFloorKmr(){
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			gotoxy(0,3);
			printf("                 ");
			gotoxy(0,3);
			getnummin(&kmr.lantai,1,1);
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}else{
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Kamar.dat");
	rename("Dat/Tmp.dat","Dat/Kamar.dat");
}

void UpdateMenuKmr(){
	PrintAdUpRoom();
	while(1){
    	if(selectedOption==4){
    		clrMainMenu();
			clrMenArrow(12,28,20);
			PrintAdRoom();
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
		        	   if (selectedOption < 4) {
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
				
			break;
			case 2:
				
			break;
			case 3:
					
			break;
		}
	}
}


void UpdateKmr(){
	while(1){
		clrDb();
		RmUpdateForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("KMR");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Kamar.dat","rb");
			while(fread(&kmr,sizeof(kmr),1,fp)==1){
				if(search==kmr.no_kamar){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayKmrData(kmr.tipe_kamar,kmr.harga,kmr.lantai);
				UpdateMenuKmr();
			}else{
				gotoxy(63,25);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,25);
				printf("             ");
				goto goback;
			}	
		}	
	}
}

void DeleteKmr(){
	while(1){
		clrDb();
		RmDeleteForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("KMR");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Kamar.dat","rb");
			while(fread(&kmr,sizeof(kmr),1,fp)==1){
				if(search==kmr.no_kamar){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				delconf = false;
				fp = fopen("Dat/Kamar.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&kmr,sizeof(kmr),1,fp)==1){
					if(search==kmr.no_kamar){
						DisplayKmrData(kmr.tipe_kamar,kmr.harga,kmr.lantai);
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
								gotoxy(66,25);
								printf("          ");
								gotoxy(63,30);
								printf("               ");
								gotoxy(63,36);
								printf("   ");
								gotoxy(101,36);
								printf("            ");
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
								gotoxy(66,25);
								printf("          ");
								gotoxy(63,30);
								printf("               ");
								gotoxy(63,36);
								printf("   ");
								gotoxy(101,36);
								printf("            ");
								customClr(24,1,86,40);
								delconf = true;
							break;
						}
					}else{
						fwrite(&kmr,sizeof(kmr),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Kamar.dat");
					rename("Dat/Tmp.dat","Dat/Kamar.dat");
				}
				goto goback;
			}else{
				gotoxy(63,25);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,25);
				printf("             ");
				goto goback;
			}	
		}	
	}
}

void MenuKamar(){
    selectedOption = 1;
	pressed = 2;
	PrintAdRoom();
	while(1){
		clrDb();
		do {
			RmDb();
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
				CreateKmr();
			break;
			case 2:
				ReadKmr();
			break;
			case 3:
				UpdateKmr();
			break;
			case 4:
				DeleteKmr();
			break;
		}
		selectedOption = 1;
	}
}
