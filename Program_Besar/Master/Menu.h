void CreateMnu(){
	while(1){
		clrDb();
		MnCreateForm();
			
		next:
			
		fp = fopen("Dat/Menu.dat", "ab+");
		if(fread(&mnu,sizeof(mnu),1,fp)==0){
			mnu.id_menu = 1;
		}else{
			while(!feof(fp)){
				fread(&mnu,sizeof(mnu),1,fp);
				if(feof(fp)){
					mnu.id_menu+=1;
				}
			}
		}
		
		gotoxy(63,26);
		printf("MNU%03d",mnu.id_menu);
		
		reset:
		
		fflush(stdin);
		gotoxy(63,31);
		getletter(mnu.nama,20);
		strupr(mnu.nama);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		selectedOption = 1;
		pressed = 2;
		do {
			gotoxy(63,36);
			printf("     ");
		       switch(selectedOption){
		       	case 1:
		       		gotoxy(63,36);
		       		printf("FOOD");
		       	break;
		       	case 2:
		       		gotoxy(63,36);
		       		printf("DRINK");
		       	break;
			}
		
			key = getch();
			
			if(key == 13){
				pressed = 1;
			}else if(key == 27){
				pressed = 0;
			}else{
				switch (key) {
		           case 72:
		               if (selectedOption > 1) {
		                   selectedOption--;
		                   Beep(800,125);
		               }
		               break;
		           case 80:
		               if (selectedOption < 2) {
		                   selectedOption++;
		                   Beep(800,125);
		               }
		            break;
		       	}	
			}
		} while (pressed == 2);
		Beep(900,125);
			
		if(pressed==0){
			fclose(fp);
			break;
		}
		
		fflush(stdin);	
		switch(selectedOption){
			case 1:
				strcpy(mnu.category,"FOOD");
			break;
			case 2:
				strcpy(mnu.category,"DRINK");
			break;
		}
		
		fflush(stdin);
		gotoxy(101,36);
		printf("Rp");
		getRp(&mnu.harga,5,8,104,36);
		
		if(EscPressed){
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
			gotoxy(63,31);
			printf("                ");
			gotoxy(63,36);
			printf("       ");
			gotoxy(103,36);
			printf("                ");
			customClr(24,1,86,40);
			goto reset;
		break;
		case 2:
			mnu.status = 1;
			fwrite(&mnu,sizeof(mnu),1,fp);
			fclose(fp);
			gotoxy(96,43);
			printf("saving..");
			sleep(3);
			gotoxy(82,43);
			printf("record has been saved successfully.");
			Beep(1100,200);
			sleep(2);
			gotoxy(80,43);
			printf("                                     ");
			gotoxy(63,31);
			printf("                ");
			gotoxy(63,36);
			printf("     ");
			gotoxy(103,36);
			printf("                ");
			customClr(24,1,86,40);
			goto next;
		}		
	}
}

void ReadMnu(){
	clrDb();
	MnViewForm();
	fp = fopen("Dat/Menu.dat", "rb");
	if(fp==NULL){
		gotoxy(44,21);
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&mnu,sizeof(mnu),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				if(mnu.id_menu<10){
					printf("MNU00%d",mnu.id_menu);
				}else if(mnu.id_menu>=10){
					printf("MNU0%d",mnu.id_menu);
				}else{
					printf("MNU%d",mnu.id_menu);	
				}
				gotoxy(65,i);
				printf("%s",mnu.nama);
				gotoxy(89,i);
				printf("%s",mnu.category);
				rupiah(mnu.harga,cvrRp);
				gotoxy(110,i);
				printf("Rp%s",cvrRp);
				switch(mnu.status){
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

void DisplayMnuData(char nama[],char category[], int harga){
	gotoxy(63,31);
	printf("%s",nama);
	gotoxy(63,36);
	printf("%s",category);
	rupiah(harga,cvrRp);
	gotoxy(101,36);
	printf("Rp%s",cvrRp);
}

void UpdateNameMnu(){
	updconf = false;
	goback:
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(search==mnu.id_menu){
			gotoxy(63,31);
			printf("             ");
			fflush(stdin);
			gotoxy(63,31);
			getletter(tUpdate,20);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(63,31);
				printf("              ");
				gotoxy(63,31);
				printf("%s",mnu.nama);
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
					strcpy(mnu.nama,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&mnu,sizeof(mnu),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					gotoxy(63,31);
					printf("%s",mnu.nama);
					updconf = true;
				break;
			}
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Menu.dat");
		rename("Dat/Tmp.dat","Dat/Menu.dat");
	}
}

void UpdateCategoryMnu(){
		updconf = false;
		goback:
		fp = fopen("Dat/Menu.dat","rb");
		tmp = fopen("Dat/Tmp.dat", "wb");
		while(fread(&mnu,sizeof(mnu),1,fp)==1){
			if(search==mnu.id_menu){
			selectedOption = 1;
			pressed = 2;
			do {
				gotoxy(63,36);
				printf("     ");
			       switch(selectedOption){
			       	case 1:
			       		gotoxy(63,36);
			       		printf("FOOD");
			       	break;
			       	case 2:
			       		gotoxy(63,36);
			       		printf("DRINK");
			       	break;
				}
			
				key = getch();
				
				if(key == 13){
					pressed = 1;
				}else if(key == 27){
					pressed = 0;
				}else{
					switch (key) {
			           case 72:
			               if (selectedOption > 1) {
			                   selectedOption--;
			                   Beep(800,125);
			               }
			               break;
			           case 80:
			               if (selectedOption < 2) {
			                   selectedOption++;
			                   Beep(800,125);
			               }
			            break;
			       	}	
				}
			} while (pressed == 2);
			Beep(900,125);
				
			if(pressed==0){
				fclose(fp);
				break;
			}
			
			fflush(stdin);	
			switch(selectedOption){
				case 1:
					strcpy(tUpdate,"FOOD");
				break;
				case 2:
					strcpy(tUpdate,"DRINK");
				break;
			}
			
			if(pressed==0){
				gotoxy(63,31);
				printf("      ");
				gotoxy(63,31);
				printf("%s",mnu.category);
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
					strcpy(mnu.category,tUpdate);
					gotoxy(92,43);
					printf("updating..");
					sleep(3);
					fwrite(&mnu,sizeof(mnu),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(2);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,36);
					printf("%s",mnu.category);
					updconf = true;
				break;
			}
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Menu.dat");
		rename("Dat/Tmp.dat","Dat/Menu.dat");
	}
}

void UpdatePriceMnu(){
	updconf = false;
	goback:
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(search==mnu.id_menu){
			gotoxy(103,36);
			printf("                    ");
			fflush(stdin);
			gotoxy(101,36);
			printf("Rp");
			getRp(&tiUpdate,5,8,104,36);
			
			if(EscPressed){
				gotoxy(103,36);
				printf("                    ");
				rupiah(mnu.harga,cvrRp);
				gotoxy(101,36);
				printf("Rp%s",cvrRp);
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
					mnu.harga = tiUpdate;
					gotoxy(92,43);
					printf("updating..");
					sleep(2);
					fwrite(&mnu,sizeof(mnu),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(103,36);
					printf("                    ");
					rupiah(mnu.harga,cvrRp);
					gotoxy(101,36);
					printf("Rp%s",cvrRp);
					updconf = true;
				break;
			}
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Menu.dat");
		rename("Dat/Tmp.dat","Dat/Menu.dat");
	}
}

void UpdateMenuMnu(){
	PrintAdUpMenu();
	while(1){
    	if(selectedOption==4){
    		clrMainMenu();
			clrMenArrow(12,28,20);
			PrintAdMenu();
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
				UpdateNameMnu();
			break;
			case 2:
				UpdatePriceMnu();
			break;
			case 3:
				UpdateCategoryMnu();	
			break;
		}
	}	
}

void UpdateMnu(){
	while(1){
		clrDb();
		MnUpdateForm();
		goback:
		found = false;
		gotoxy(63,26);
		printf("MNU");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,26);
			printf("%03d",search);
			fp = fopen("Dat/Menu.dat","rb");
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				selectedOption = 1;
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayMnuData(mnu.nama,mnu.category,mnu.harga);
				UpdateMenuMnu();
			}else{
				gotoxy(63,26);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,26);
				printf("             ");
				goto goback;
			}	
		}	
	}
}

void DeleteMnu(){
	while(1){
		clrDb();
		MnDeleteForm();
		goback:
		found = false;
		gotoxy(63,26);
		printf("MNU");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,26);
			printf("%03d",search);
			fp = fopen("Dat/Menu.dat","rb");
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				delconf = false;
				fp = fopen("Dat/Menu.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&mnu,sizeof(mnu),1,fp)==1){
					if(search==mnu.id_menu){
						DisplayMnuData(mnu.nama,mnu.category,mnu.harga);
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
								gotoxy(66,26);
								printf("          ");
								gotoxy(63,31);
								printf("                ");
								gotoxy(63,36);
								printf("       ");
								gotoxy(103,36);
								printf("               ");
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
								gotoxy(66,26);
								printf("          ");
								gotoxy(63,31);
								printf("                ");
								gotoxy(63,36);
								printf("       ");
								gotoxy(103,36);
								printf("               ");
								customClr(24,1,86,40);
								delconf = true;
							break;
						}
					}else{
						fwrite(&mnu,sizeof(mnu),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Menu.dat");
					rename("Dat/Tmp.dat","Dat/Menu.dat");
				}
				goto goback;
			}else{
				gotoxy(63,26);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,26);
				printf("             ");
				goto goback;
			}	
		}	
	}
}

void MenuMenu(){
	selectedOption = 1;
	pressed = 2;
	PrintAdMenu();
	while(1){
		clrDb();
		MnDb();
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
				CreateMnu();
			break;
			case 2:
				ReadMnu();
			break;
			case 3:
				UpdateMnu();
			break;
			case 4:
				DeleteMnu();
			break;
		}
		selectedOption = 1;
	}
}
