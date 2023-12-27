void CreateKmr(){
	system("cls");
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
	printf("ROOM NUMBER\t: KMR%d\n",kmr.no_kamar);
	while(1){
		gotoxy(18,1);
		printf("                  ");
		gotoxy(0,1);
		printf("ROOM TYPE\t: ");getletter(kmr.tipe_kamar,15);
		strupr(kmr.tipe_kamar);
		if(strcmp(kmr.tipe_kamar,"STANDARD")==0 || strcmp(kmr.tipe_kamar,"DOUBLE")==0 || strcmp(kmr.tipe_kamar,"SUITE")==0 || strcmp(kmr.tipe_kamar,"EXECUTIVE")==0){
			break;			
		}
	}
	printf("\nFLOOR\t\t: ");getnummin(&kmr.lantai,1,1);
	if(strcmp(kmr.tipe_kamar,"STANDARD")==0){
		kmr.harga = 100000;
	}else if(strcmp(kmr.tipe_kamar,"DOUBLE")==0){
		kmr.harga = 250000;
	}else if(strcmp(kmr.tipe_kamar,"SUITE")==0){
		kmr.harga = 400000;
	}else{
		kmr.harga = 600000;
	}
	kmr.status = 1;
	fwrite(&kmr,sizeof(kmr),1,fp);
	fclose(fp);
}

void ReadKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&kmr,sizeof(kmr),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("KMR%d",kmr.no_kamar);
				gotoxy(10,i);
				printf("%s",kmr.tipe_kamar);
				gotoxy(30,i);
				printf("%d",kmr.lantai);
				rupiah(kmr.harga,cvrRp);
				gotoxy(35,i);
				printf("Rp%s",cvrRp);
				switch(kmr.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
					break;
				}
				gotoxy(55,i);
				printf("%s",rStat);
				i++;	
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayKmrData(int id, char tipe[], int harga, int lantai, int status){
	printf("KMR%d\n",id);
	printf("%s\n",tipe);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
	printf("%d\n",lantai);
	switch(status){
		case 0:
			strcpy(rStat,"UNAVAILABLE");
		break;
		case 1:
			strcpy(rStat,"AVAILABLE");
		break;
	}
	printf("%s",rStat);
}

void UpdateDisplayKmr(){
	printf("[1]Room Type\n");
	printf("[2]Floor\n");
	printf("[3]Back\n");
}


void UpdateTypeKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			while(1){
				system("cls");
				DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
				gotoxy(0,1);
				printf("                 ");
				gotoxy(0,1);
				getletter(kmr.tipe_kamar,15);
				strupr(kmr.tipe_kamar);
				if(strcmp(kmr.tipe_kamar,"STANDARD")==0 || strcmp(kmr.tipe_kamar,"DOUBLE")==0 || strcmp(kmr.tipe_kamar,"SUITE")==0 || strcmp(kmr.tipe_kamar,"EXECUTIVE")==0){
					break;			
				}
			}
			if(strcmp(kmr.tipe_kamar,"STANDARD")==0){
				kmr.harga = 100000;
			}else if(strcmp(kmr.tipe_kamar,"DOUBLE")==0){
				kmr.harga = 250000;
			}else if(strcmp(kmr.tipe_kamar,"SUITE")==0){
				kmr.harga = 400000;
			}else{
				kmr.harga = 600000;
			}
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
	system("cls");
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			system("cls");
			DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
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
	while(1){
		system("cls");
		UpdateDisplayKmr();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateTypeKmr();
		}else if(choose==2){
			UpdateFloorKmr();
		}else if(choose==3){
			break;
		}
	}	
}


void UpdateKmr(){
	while(1){
		system("cls");
		found = false;
		printf("Room's ID\t: KMR");getnummin(&search,1,3);
		if(search==0){
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
				UpdateMenuKmr();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteKmr(){
	while(1){
		system("cls");
		found = false;
		printf("Room's ID\t: KMR");getnummin(&search,1,3);
		if(search==0){
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
				fp = fopen("Dat/Kamar.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&kmr,sizeof(kmr),1,fp)==1){
					if(search==kmr.no_kamar){
						while(1){
							system("cls");
							DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
							printf("\nDelete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&kmr,sizeof(kmr),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&kmr,sizeof(kmr),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Kamar.dat");
				rename("Dat/Tmp.dat","Dat/Kamar.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuKamar(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
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
			case 5:
				
			break;
		}
	}
}
