void CreateFsl(){
	while(1){
		clrDb();
		FcCreateForm();
		
		next:
			
		fp = fopen("Dat/Fasilitas.dat", "ab+");
		if(fread(&fsl,sizeof(fsl),1,fp)==0){
			fsl.id_fasilitas = 1;
		}else{
			while(!feof(fp)){
				fread(&fsl,sizeof(fsl),1,fp);
				if(feof(fp)){
					fsl.id_fasilitas+=1;
				}
			}
		}
		gotoxy(63,25);
		if(fsl.id_fasilitas<10){
			printf("FCL00%d",fsl.id_fasilitas);
		}else if(fsl.id_fasilitas>=10){
			printf("FCL0%d",fsl.id_fasilitas);
		}else{
			printf("FCL%d",fsl.id_fasilitas);	
		}
		
		reset:
			
		gotoxy(63,30);
		getletter(fsl.nama,15);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		strupr(fsl.nama);
		
		gotoxy(63,35);
		printf("Rp");getRp(&fsl.harga,5,7,66,35);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		selectedOption = 2;
		pressed = 2;
		do {
			customClr(70,1,65,38);
		       switch(selectedOption){
		       	case 1:
		       		gotoxy(88,38);
		       		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(108,38);
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
			gotoxy(63,30);
			printf("                             ");
			gotoxy(66,35);
			printf("                ");
			customClr(24,1,86,38);
			goto reset;
		break;
		case 2:
			fsl.status = 1;
			fwrite(&fsl,sizeof(fsl),1,fp);
			fclose(fp);
			gotoxy(96,41);
			printf("saving..");
			sleep(3);
			gotoxy(82,41);
			printf("record has been saved successfully.");
			Beep(1100,200);
			sleep(2);
			gotoxy(80,41);
			printf("                                     ");
			gotoxy(63,25);
			printf("         ");
			gotoxy(63,30);
			printf("                             ");
			gotoxy(66,35);
			printf("                ");
			customClr(24,1,86,38);
			goto next;
		}
	}
}

void ReadFsl(){
	clrDb();
	FcViewForm();
	fp = fopen("Dat/Fasilitas.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&fsl,sizeof(fsl),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				if(fsl.id_fasilitas<10){
					printf("FCL00%d",fsl.id_fasilitas);
				}else if(fsl.id_fasilitas>=10){
					printf("FCL0%d",fsl.id_fasilitas);
				}else{
					printf("FCL%d",fsl.id_fasilitas);	
				}
				gotoxy(75,i);
				printf("%s",fsl.nama);
				rupiah(fsl.harga,cvrRp);
				gotoxy(105,i);
				printf("Rp%s",cvrRp);
				switch(fsl.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
					break;
				}
				gotoxy(135,i);
				printf("%s",rStat);
				i++;	
			}
		}
	}
	getch();
	fclose(fp);
}

void DisplayFslData(char nama[], int harga){
	gotoxy(63,30);
	printf("%s",nama);
	rupiah(harga,cvrRp);
	gotoxy(63,35);
	printf("Rp%s",cvrRp);
}


void UpdateNameFsl(){
	updconf = false;
	goback:
	fp = fopen("Dat/Fasilitas.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		if(search==fsl.id_fasilitas){
			gotoxy(63,30);
			printf("                      ");
			gotoxy(63,30);
			getletter(tUpdate,15);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(63,30);
				printf("                        ");
				gotoxy(63,30);
				printf("%s",fsl.nama);
				fclose(fp);
				break;
			}
			
			selectedOption = 2;
			do{
				customClr(70,1,65,38);
			    switch(selectedOption){
			       	case 1:
			       		gotoxy(88,38);
			       		printf("%c",42);
			       	break;
			       	case 2:
			       		gotoxy(108,38);
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
					customClr(24,1,86,38);
					goto goback;
				break;
				case 2:
					strcpy(fsl.nama,tUpdate);
					gotoxy(92,41);
					printf("updating..");
					sleep(3);
					fwrite(&fsl,sizeof(fsl),1,tmp);
					gotoxy(80,41);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(2);
					gotoxy(80,41);
					printf("                                     ");
					customClr(24,1,86,38);
					gotoxy(63,30);
					printf("%s",fsl.nama);
					updconf = true;
				break;
			}
		}else{
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Fasilitas.dat");
		rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
	}
}

void UpdatePriceFsl(){
	updconf = false;
	goback:
	fp = fopen("Dat/Fasilitas.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		if(search==fsl.id_fasilitas){
			gotoxy(65,35);
			printf("                              ");
			gotoxy(63,35);
			printf("Rp");
			getRp(&tiUpdate,5,8,66,35);
			
			if(EscPressed){
				gotoxy(63,35);
				printf("                       ");
				rupiah(fsl.harga,cvrRp);
				gotoxy(63,35);
				printf("Rp%s",cvrRp);
				fclose(fp);
				break;
			}
			
			selectedOption = 2;
			do {
				customClr(70,1,65,38);
			    switch(selectedOption){
			       	case 1:
			       		gotoxy(88,38);
			       		printf("%c",42);
			       	break;
			       	case 2:
			       		gotoxy(108,38);
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
					customClr(24,1,86,38);
					goto goback;
				break;
				case 2:
					fsl.harga = tiUpdate;
					gotoxy(92,41);
					printf("updating..");
					sleep(3);
					fwrite(&fsl,sizeof(fsl),1,tmp);
					gotoxy(80,41);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(2);
					gotoxy(80,41);
					printf("                                     ");
					customClr(24,1,86,38);
					rupiah(fsl.harga,cvrRp);
					gotoxy(65,35);
					printf("                      ");
					gotoxy(63,35);
					printf("Rp%s",cvrRp);
					updconf = true;
				break;
			}
		}else{
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Fasilitas.dat");
		rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
	}
}

void UpdateMenuFsl(){
	PrintAdUpFacility();
	while(1){
    	if(selectedOption==3){
    		clrMainMenu();
			clrMenArrow(12,28,20);
			PrintAdFacility();
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
		        	   if (selectedOption < 3) {
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
				UpdateNameFsl();
			break;
			case 2:
				UpdatePriceFsl();
			break;
		}
	}
}

void UpdateFsl(){
	while(1){
		FcUpdateForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("FCL");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Fasilitas.dat","rb");
			while(fread(&fsl,sizeof(fsl),1,fp)==1){
				if(search==fsl.id_fasilitas){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				selectedOption = 1;
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayFslData(fsl.nama,fsl.harga);
				UpdateMenuFsl();
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

void DeleteFsl(){
	while(1){
		clrDb();
		FcDeleteForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("FCL");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Fasilitas.dat","rb");
			while(fread(&fsl,sizeof(fsl),1,fp)==1){
				if(search==fsl.id_fasilitas){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				delconf = false;
				fp = fopen("Dat/Fasilitas.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&fsl,sizeof(fsl),1,fp)==1){
					if(search==fsl.id_fasilitas){
						DisplayFslData(fsl.nama,fsl.harga);
						selectedOption = 2;
						pressed = 2;
						do {
							customClr(70,1,65,38);
						       switch(selectedOption){
						       	case 1:
						       		gotoxy(88,38);
						       		printf("%c",42);
						       	break;
						       	case 2:
						       		gotoxy(108,38);
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
								gotoxy(63,25);
								printf("         ");
								gotoxy(63,30);
								printf("                             ");
								gotoxy(63,35);
								printf("                ");
								customClr(24,1,86,38);
								goto goback;
							break;
							case 2:
								gotoxy(94,41);
								printf("deleting..");
								sleep(3);
								gotoxy(80,41);
								printf("record has been removed successfully.");
								Beep(1100,200);
								sleep(2);
								gotoxy(80,41);
								printf("                                     ");
								gotoxy(63,25);
								printf("         ");
								gotoxy(63,30);
								printf("                             ");
								gotoxy(63,35);
								printf("                ");
								customClr(24,1,86,38);
								delconf = true;
							break;
						}
					}else{
						fwrite(&fsl,sizeof(fsl),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Fasilitas.dat");
					rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
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

void MenuFasilitas(){
	selectedOption = 1;
	pressed = 2;
	PrintAdFacility();
	while(1){
		clrDb();
		do {
			FcDb();
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
				CreateFsl();
			break;
			case 2:
				ReadFsl();
			break;
			case 3:
				UpdateFsl();
			break;
			case 4:
				DeleteFsl();
			break;
		}
		selectedOption = 1;
	}
}
