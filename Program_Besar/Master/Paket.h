void CreatePkt(){
	while(1){
		clrDb();
		PkCreateForm();
			
		next:
			
		fp = fopen("Dat/Paket.dat", "ab+");
		if(fread(&pkt,sizeof(pkt),1,fp)==0){
			pkt.id_paket = 1;
		}else{
			while(!feof(fp)){
				fread(&pkt,sizeof(pkt),1,fp);
				if(feof(fp)){
					pkt.id_paket+=1;
				}
			}
		}
		
		gotoxy(63,24);
		printf("BDL%03d",pkt.id_paket);
		
		reset:
		
		fflush(stdin);
		gotoxy(63,29);
		getletter(pkt.nama,20);
		strupr(pkt.nama);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(101,29);
		printf("Rp");getRp(&pkt.harga,5,8,104,29);
		
		if(EscPressed){
			fclose(fp);
			break;
		}
		
		fflush(stdin);
		gotoxy(63,34);
		textAreaInput(pkt.desc,5,40,63,34,20);
		
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
			gotoxy(63,29);
			printf("                    ");
			gotoxy(104,29);
			printf("            ");
			customClr(20,2,63,34);
			customClr(24,1,86,40);
			goto reset;
		break;
		case 2:
			pkt.status = 1;
			fwrite(&pkt,sizeof(pkt),1,fp);
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
			gotoxy(63,29);
			printf("                    ");
			gotoxy(104,29);
			printf("            ");
			customClr(20,2,63,34);
			customClr(24,1,86,40);
			goto next;
		}		
	}
}

void ReadPkt(){
	clrDb();
	PkViewForm();
	fp = fopen("Dat/Paket.dat", "rb");
	if(fp==NULL){
		gotoxy(44,21);
		printf("Belum ada Data");
	}else{
		found = false;
		i=21;
		while(!feof(fp)){
			fread(&pkt,sizeof(pkt),1,fp);
			if(!feof(fp)){
				gotoxy(44,i);
				if(pkt.id_paket<10){
					printf("BDL00%d",pkt.id_paket);
				}else if(pkt.id_paket>=10){
					printf("BDL0%d",pkt.id_paket);
				}else{
					printf("BDL%d",pkt.id_paket);	
				}
				gotoxy(65,i);
				printf("%s",pkt.nama);
				rupiah(pkt.harga,cvrRp);
				gotoxy(95,i);
				printf("Rp%s",cvrRp);
				gotoxy(110,i);
				printf("%.7s..",pkt.desc);
				switch(pkt.status){
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

void DisplayPktData(char name[], int rp[], char desc[]){
	gotoxy(63,29);
	printf("%s",name);
	rupiah(pkt.harga,cvrRp);
	gotoxy(101,29);
	printf("Rp%s",cvrRp);
	gotoxy(63,34);
	for(i=0;desc[i]!='\0';i++){
		if(i==20){
			gotoxy(63,35);
			printf("%c",desc[i]);
		}else{
			printf("%c",desc[i]);
		}	
	}
}

void UpdateNamePkt(){
	updconf = false;
	goback:
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			gotoxy(63,29);
			printf("                    ");
			fflush(stdin);
			gotoxy(63,29);
			getletter(tUpdate,20);
			strupr(tUpdate);
			
			if(EscPressed){
				gotoxy(63,29);
				printf("                  ");
				gotoxy(63,29);
				printf("%s",pkt.nama);
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
					strcpy(pkt.nama,tUpdate);
					gotoxy(94,43);
					printf("updating..");
					sleep(2);
					fwrite(&pkt,sizeof(pkt),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(1);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,29);
					printf("                  ");
					gotoxy(63,29);
					printf("%s",pkt.nama);
					updconf = true;
				break;
			}
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Paket.dat");
		rename("Dat/Tmp.dat","Dat/Paket.dat");
	}
}

void UpdatePricePkt(){
	updconf = false;
	goback:
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			gotoxy(103,29);
			printf("                    ");
			fflush(stdin);
			gotoxy(101,29);
			printf("Rp");getRp(&tiUpdate,5,8,104,29);
			
			if(EscPressed){
				gotoxy(103,29);
				printf("                  ");
				rupiah(pkt.harga,cvrRp);
				gotoxy(103,29);
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
					pkt.harga = tiUpdate;
					gotoxy(94,43);
					printf("updating..");
					sleep(3);
					fwrite(&pkt,sizeof(pkt),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(2);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(103,29);
					printf("                  ");
					rupiah(pkt.harga,cvrRp);
					gotoxy(103,29);
					printf("%s",cvrRp);
					updconf = true;
				break;
			}
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Paket.dat");
		rename("Dat/Tmp.dat","Dat/Paket.dat");
	}
}

void UpdateDescPkt(){
	updconf = false;
	goback:
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			customClr(20,2,63,34);
			fflush(stdin);
			gotoxy(63,34);
			textAreaInput(tUpdate,5,40,63,34,20);
			
			if(EscPressed){
				customClr(20,2,63,34);
				gotoxy(63,34);
				for(i=0;pkt.desc[i]!='\0';i++){
					if(i==20){
						gotoxy(63,35);
						printf("%c",pkt.desc[i]);
					}else{
						printf("%c",pkt.desc[i]);
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
					customClr(20,2,63,34);
					goto goback;
				break;
				case 2:
					strcpy(pkt.desc,tUpdate);
					gotoxy(94,43);
					printf("updating..");
					sleep(3);
					fwrite(&pkt,sizeof(pkt),1,tmp);
					gotoxy(80,43);
					printf("record has been updated successfully.");
					Beep(1100,200);
					sleep(2);
					gotoxy(80,43);
					printf("                                     ");
					customClr(24,1,86,40);
					gotoxy(63,34);
					for(i=0;pkt.desc[i]!='\0';i++){
						if(i==20){
							gotoxy(63,35);
							printf("%c",pkt.desc[i]);
						}else{
							printf("%c",pkt.desc[i]);
						}	
					}
					updconf = true;
				break;
			}
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	
	fclose(fp);
	fclose(tmp);
	
	if(updconf){
		remove("Dat/Paket.dat");
		rename("Dat/Tmp.dat","Dat/Paket.dat");
	}
}

void UpdateMenuPkt(){
	PrintAdUpBundle();
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
				UpdateNamePkt();
			break;
			case 2:
				UpdatePricePkt();
			break;
			case 3:
				UpdateDescPkt();	
			break;
		}
	}	
}

void UpdatePkt(){
	while(1){
		clrDb();
		PkUpdateForm();
		goback:
		found = false;
		gotoxy(63,24);
		printf("BDL");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,24);
			printf("%03d",search);
			fp = fopen("Dat/Paket.dat","rb");
			while(fread(&pkt,sizeof(pkt),1,fp)==1){
				if(search==pkt.id_paket){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				selectedOption = 1;
				clrMainMenu();
				clrMenArrow(12,28,20);
				DisplayPktData(pkt.nama,pkt.harga,pkt.desc);
				UpdateMenuPkt();
			}else{
				gotoxy(63,24);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,24);
				printf("             ");
				goto goback;
			}	
		}	
	}
}

void DeletePkt(){
	while(1){
		clrDb();
		PkDeleteForm();
		goback:
		found = false;
		gotoxy(63,24);
		printf("BDL");getnummin(&search,1,3);
		Beep(900,125);
		if(EscPressed){
			break;
		}else{
			gotoxy(66,24);
			printf("%03d",search);
			fp = fopen("Dat/Paket.dat","rb");
			while(fread(&pkt,sizeof(pkt),1,fp)==1){
				if(search==pkt.id_paket){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				delconf = false;
				fp = fopen("Dat/Paket.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&pkt,sizeof(pkt),1,fp)==1){
					if(search==pkt.id_paket){
						DisplayPktData(pkt.nama,pkt.harga,pkt.desc);
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
								gotoxy(66,24);
								printf("   ");
								gotoxy(63,29);
								printf("                    ");
								gotoxy(103,29);
								printf("            ");
								customClr(20,2,63,34);
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
								gotoxy(66,24);
								printf("   ");
								gotoxy(63,29);
								printf("                    ");
								gotoxy(103,29);
								printf("            ");
								customClr(20,2,63,34);
								customClr(24,1,86,40);
								delconf = true;
							break;
						}
					}else{
						fwrite(&pkt,sizeof(pkt),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				if(delconf){
					remove("Dat/Paket.dat");
					rename("Dat/Tmp.dat","Dat/Paket.dat");
				}
				goto goback;
			}else{
				gotoxy(63,24);
				printf("ID Not Found!");
				sleep(1);
				gotoxy(63,24);
				printf("             ");
				goto goback;
			}	
		}	
	}
}


void MenuPaket(){
	selectedOption = 1;
	pressed = 2;
	PrintAdBundle();
	while(1){
		clrDb();
		BdDb();
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
				CreatePkt();
			break;
			case 2:
				ReadPkt();
			break;
			case 3:
				UpdatePkt();
			break;
			case 4:
				DeletePkt();
			break;
		}
		selectedOption = 1;
	}
}
