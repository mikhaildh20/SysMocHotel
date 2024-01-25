void CreateDnd(){
	while(1){
		clrDb();
		FnCreateForm();
			
		next:
			
		fp = fopen("Dat/Denda.dat", "ab+");
		if(fread(&dnd,sizeof(dnd),1,fp)==0){
			pkt.id_paket = 1;
		}else{
			while(!feof(fp)){
				fread(&dnd,sizeof(dnd),1,fp);
				if(feof(fp)){
					dnd.id_denda+=1;
				}
			}
		}
		
		gotoxy(63,25);
		if(dnd.id_denda<10){
			printf("FNE00%d",dnd.id_denda);
		}else if(dnd.id_denda>=10){
			printf("FNE0%d",dnd.id_denda);
		}else{
			printf("FNE%d",dnd.id_denda);	
		}
		
		reset:
		
		fflush(stdin);
		gotoxy(63,30);
		getletter(dnd.category,20);
		strupr(dnd.category);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(101,30);
		printf("Rp");getRp(&dnd.nominal,5,8,104,30);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(63,35);
		textAreaInput(dnd.ket,5,40,63,35,20);
		
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
			gotoxy(63,30);
			printf("                    ");
			gotoxy(104,30);
			printf("            ");
			customClr(20,2,63,35);
			customClr(24,1,86,40);
			goto reset;
		break;
		case 2:			
			fwrite(&dnd,sizeof(dnd),1,fp);
			fclose(fp);
			gotoxy(96,43);
			printf("saving..");
			sleep(2);
			gotoxy(82,43);
			printf("record has been saved successfully.");
			Beep(1100,200);
			sleep(1);
			gotoxy(80,43);
			printf("                                     ");
			gotoxy(63,30);
			printf("                    ");
			gotoxy(104,30);
			printf("            ");
			customClr(20,2,63,35);
			customClr(24,1,86,40);
			goto next;
		}		
	}
}

void ReadDnd(){
	clrDb();
	FnViewForm();
	fp = fopen("Dat/Denda.dat", "rb");
	if(fp==NULL){
		gotoxy(44,21);
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&dnd,sizeof(dnd),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				if(dnd.id_denda<10){
					printf("FNE00%d",dnd.id_denda);
				}else if(dnd.id_denda>=10){
					printf("FNE0%d",dnd.id_denda);
				}else{
					printf("FNE%d",dnd.id_denda);	
				}
				gotoxy(75,i);
				printf("%s",dnd.category);
				rupiah(dnd.nominal,cvrRp);
				gotoxy(105,i);
				printf("Rp%s",cvrRp);
				gotoxy(135,i);
				printf("%.7s..",dnd.ket);
				i++;	
			}
		}
	}
	getch();
	fclose(fp);
}

void DisplayDndData(char category[], int nominal, char desc[]){
	gotoxy(63,30);
	printf("%s",category);
	rupiah(nominal,cvrRp);
	gotoxy(101,30);
	printf("Rp%s",cvrRp);
	gotoxy(63,35);
	for(i=0;desc[i]!='\0';i++){
		if(i==20){
			gotoxy(63,36);
			printf("%c",desc[i]);
		}else{
			printf("%c",desc[i]);
		}	
	}
}

void UpdateCategoryDnd(){
	updconf = false;
	goback:
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			gotoxy(63,30);
			printf("                    ");
			fflush(stdin);
			gotoxy(63,30);
			getletter(tUpdate,20);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(63,30);
				printf("                  ");
				gotoxy(63,30);
				printf("%s",dnd.category);
				break;
			}
			
			selectedOption = 2;
			do{
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
					strcpy(dnd.category,tUpdate);
					gotoxy(94,43);
					printf("updating..");
					sleep(2);
					fwrite(&dnd,sizeof(dnd),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,30);
					printf("                  ");
					gotoxy(63,30);
					printf("%s",dnd.category);
					updconf = true;
				break;
			}
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Denda.dat");
		rename("Dat/Tmp.dat","Dat/Denda.dat");
	}
}

void UpdatePriceDnd(){
	updconf = false;
	goback:
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			gotoxy(103,30);
			printf("                    ");
			fflush(stdin);
			gotoxy(101,30);
			printf("Rp");getRp(&tiUpdate,5,8,104,30);
			
			if(EscPressed){
				gotoxy(103,30);
				printf("                  ");
				rupiah(dnd.nominal,cvrRp);
				gotoxy(103,30);
				printf("%s",cvrRp);
				break;
			}
			
			selectedOption = 2;
			do{
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
					dnd.nominal = tiUpdate;
					gotoxy(94,43);
					printf("updating..");
					sleep(2);
					fwrite(&dnd,sizeof(dnd),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(103,30);
					printf("                  ");
					rupiah(dnd.nominal,cvrRp);
					gotoxy(103,30);
					printf("%s",cvrRp);
					updconf = true;
				break;
			}
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Denda.dat");
		rename("Dat/Tmp.dat","Dat/Denda.dat");
	}
}

void UpdateDescDnd(){
	updconf = false;
	goback:
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			customClr(20,2,63,35);
			fflush(stdin);
			gotoxy(63,35);
			textAreaInput(tUpdate,5,40,63,35,20);
			
			if(EscPressed){
				customClr(20,2,63,35);
				gotoxy(63,35);
				for(i=0;dnd.ket[i]!='\0';i++){
					if(i==20){
						gotoxy(63,36);
						printf("%c",dnd.ket[i]);
					}else{
						printf("%c",dnd.ket[i]);
					}	
				}
				break;
			}
			
			selectedOption = 2;
			do{
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
					customClr(20,2,63,35);
					goto goback;
				break;
				case 2:
					strcpy(dnd.ket,tUpdate);
					gotoxy(94,43);
					printf("updating..");
					sleep(2);
					fwrite(&dnd,sizeof(dnd),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,35);
					for(i=0;dnd.ket[i]!='\0';i++){
						if(i==20){
							gotoxy(63,36);
							printf("%c",dnd.ket[i]);
						}else{
							printf("%c",dnd.ket[i]);
						}	
					}
					updconf = true;
				break;
			}
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Denda.dat");
		rename("Dat/Tmp.dat","Dat/Denda.dat");
	}
}

void UpdateMenuDnd(){
	PrintAdUpFines();
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
				UpdateCategoryDnd();
			break;
			case 2:
				UpdatePriceDnd();
			break;
			case 3:
				UpdateDescDnd();	
			break;
		}
	}
}

void UpdateDnd(){
	while(1){
		clrDb();
		FnUpdateForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("FNE");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,25);
			printf("%03d",search);
			fp = fopen("Dat/Denda.dat","rb");
			while(fread(&dnd,sizeof(dnd),1,fp)==1){
				if(search==dnd.id_denda){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				selectedOption = 1;
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayDndData(dnd.category,dnd.nominal,dnd.ket);
				UpdateMenuDnd();
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

void DeleteDnd(){
	while(1){
		clrDb();
		FnDeleteForm();
		goback:
		found = false;
		gotoxy(63,25);
		printf("FNE");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			fp = fopen("Dat/Denda.dat","rb");
			while(fread(&dnd,sizeof(dnd),1,fp)==1){
				if(search==dnd.id_denda){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				gotoxy(66,25);
				printf("%03d",search);
				delconf = false;
				fp = fopen("Dat/Denda.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&dnd,sizeof(dnd),1,fp)==1){
					if(search==dnd.id_denda){
						DisplayDndData(dnd.category,dnd.nominal,dnd.ket);
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
								printf("    ");
								gotoxy(63,30);
								printf("                    ");
								gotoxy(103,30);
								printf("                    ");
								customClr(20,2,63,35);
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
								printf("    ");
								gotoxy(63,30);
								printf("                    ");
								gotoxy(103,30);
								printf("                    ");
								customClr(20,2,63,35);
								customClr(24,1,86,40);
								delconf = true;
							break;
						}
					}else{
						fwrite(&dnd,sizeof(dnd),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Denda.dat");
					rename("Dat/Tmp.dat","Dat/Denda.dat");
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

void MenuDenda(){
	selectedOption = 1;
	pressed = 2;
	PrintAdFines();
	while(1){
		clrDb();
		FnDb();
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
				CreateDnd();
			break;
			case 2:
				ReadDnd();
			break;
			case 3:
				UpdateDnd();
			break;
			case 4:
				DeleteDnd();
			break;
		}
		selectedOption = 1;
	}
}
