void CreatePkt(){
	system("cls");
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
	printf("ID Paket\t: PKT%d\n",pkt.id_paket);
	fflush(stdin);
	printf("Nama Paket\t: ");gets(pkt.nama);
	strupr(pkt.nama);
	printf("Harga\t\t: Rp");getRp(&pkt.harga,4,8,21,2);
	fflush(stdin);
	printf("\nKeterangan\t: ");gets(pkt.desc);
	pkt.status = 1;
	fwrite(&pkt,sizeof(pkt),1,fp);
	fclose(fp);
}

void ReadPkt(){
	system("cls");
	fp = fopen("Dat/Paket.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&pkt,sizeof(pkt),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("PKT%d", pkt.id_paket);
				gotoxy(10,i);
				printf("%.15s",pkt.nama);
				rupiah(pkt.harga,cvrRp);
				gotoxy(30,i);
				printf("Rp%s",cvrRp);
				gotoxy(50,i);
				printf("%.15s..",pkt.desc);
				gotoxy(70,i);
				switch(pkt.status){
					case 0:
						printf("UNAVAILABLE");
					break;
					case 1:
						printf("AVAILABLE");;
					break;
				}
				i++;	
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayPktData(int id, char name[], int rp[], char desc[], int status){
	printf("PKT%d\n",id);
	printf("%s\n",name);
	rupiah(pkt.harga,cvrRp);
	printf("Rp%s\n",cvrRp);
	printf("%s\n",desc);
	switch(pkt.status){
		case 0:
			printf("UNAVAILABLE");
		break;
		case 1:
			printf("AVAILABLE");
		break;
	}
}

void UpdateDisplayPkt(){
	printf("[1]Name\n");
	printf("[2]Price\n");
	printf("[3]Desc\n");
	printf("[4]Status\n");
	printf("[5]Back\n");
}

void UpdateNamePkt(){
	system("cls");
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			system("cls");
			DisplayPktData(pkt.id_paket,pkt.nama,pkt.harga,pkt.desc,pkt.status);
			gotoxy(0,1);
			printf("                     ");
			fflush(stdin);
			gotoxy(0,1);
			gets(pkt.nama);
			strupr(pkt.nama);
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Paket.dat");
	rename("Dat/Tmp.dat","Dat/Paket.dat");
}

void UpdatePricePkt(){
	system("cls");
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			system("cls");
			DisplayPktData(pkt.id_paket,pkt.nama,pkt.harga,pkt.desc,pkt.status);
			gotoxy(0,2);
			printf("                 ");
			fflush(stdin);
			gotoxy(0,2);
			printf("Rp");getRp(&pkt.harga,4,8,3,2);
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Paket.dat");
	rename("Dat/Tmp.dat","Dat/Paket.dat");
}

void UpdateDescPkt(){
	system("cls");
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			system("cls");
			DisplayPktData(pkt.id_paket,pkt.nama,pkt.harga,pkt.desc,pkt.status);
			gotoxy(0,3);
			printf("                                          ");
			gotoxy(0,3);
			gets(pkt.desc);
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Paket.dat");
	rename("Dat/Tmp.dat","Dat/Paket.dat");
}

void UpdateStatusPkt(){
	system("cls");
	fp = fopen("Dat/Paket.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(search==pkt.id_paket){
			system("cls");
			DisplayPktData(pkt.id_paket,pkt.nama,pkt.harga,pkt.desc,pkt.status);
			gotoxy(0,4);
			printf("                 ");
			gotoxy(0,4);
			scanf("%d",&pkt.status);
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}else{
			fwrite(&pkt,sizeof(pkt),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Paket.dat");
	rename("Dat/Tmp.dat","Dat/Paket.dat");
}

void UpdateMenuPkt(){
	while(1){
		system("cls");
		UpdateDisplayPkt();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateNamePkt();
		}else if(choose==2){
			UpdatePricePkt();
		}else if(choose==3){
			UpdateDescPkt();
		}else if(choose==4){
			UpdateStatusPkt();
		}else if(choose==5){
			break;
		}
	}	
}

void UpdatePkt(){
	while(1){
		system("cls");
		found = false;
		printf("Bundle's ID\t: PKT");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Paket.dat","rb");
			while(fread(&pkt,sizeof(pkt),1,fp)==1){
				if(search==pkt.id_paket){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuPkt();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeletePkt(){
	while(1){
		system("cls");
		found = false;
		printf("Bundle's ID\t: PKT");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Paket.dat","rb");
			while(fread(&pkt,sizeof(pkt),1,fp)==1){
				if(search==pkt.id_paket){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Paket.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&pkt,sizeof(pkt),1,fp)==1){
					if(search==pkt.id_paket){
						while(1){
							system("cls");
							DisplayPktData(pkt.id_paket,pkt.nama,pkt.harga,pkt.desc,pkt.status);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&pkt,sizeof(pkt),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&pkt,sizeof(pkt),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Paket.dat");
				rename("Dat/Tmp.dat","Dat/Paket.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}


void MenuPaket(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
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
			case 5:
				//main menu
			break;
		}
	}
}
