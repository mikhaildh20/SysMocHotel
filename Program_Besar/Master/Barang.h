void MainMen(){
	printf("[1] Create\n");
	printf("[2] Read\n");
	printf("[3] Update\n");
	printf("[4] Delete\n");
	printf("[5] Back\n");
	printf("Choose: ");
}

void CreateBrg(){
	system("cls");
	fp = fopen("Dat/Barang.dat", "ab+");
	if(fread(&brg,sizeof(brg),1,fp)==0){
		brg.id_barang = 1;
	}else{
		while(!feof(fp)){
			fread(&brg,sizeof(brg),1,fp);
			if(feof(fp)){
				brg.id_barang+=1;
			}
		}
	}
	printf("ID Barang\t: BRG%d\n",brg.id_barang);
	printf("Nama Barang\t: ");getletter(brg.nama,15);
	strupr(brg.nama);
	printf("\nHarga Barang\t: Rp");getRp(&brg.harga,4,8,21,2);
	fwrite(&brg,sizeof(brg),1,fp);
	fclose(fp);
}

void ReadBrg(){
	system("cls");
	fp = fopen("Dat/Barang.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&brg,sizeof(brg),1,fp);
			if(!feof(fp)){
				rupiah(brg.harga,cvrRp);
				gotoxy(0,i);
				printf("BRG%d",brg.id_barang);
				gotoxy(10,i);
				printf("%s",brg.nama);
				gotoxy(30,i);
				printf("Rp%s",cvrRp);
				i++;
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayBrgData(int id, char nama[], int harga){
	printf("BRG%d\n",id);
	printf("%s\n",nama);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
}

void UpdateDisplayBrg(){
	printf("[1]Item Name\n");
	printf("[2]Price\n");
	printf("[3]Back\n");
}

void UpdateNameBrg(){
	system("cls");
	fp = fopen("Dat/Barang.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&brg,sizeof(brg),1,fp)==1){
		if(search==brg.id_barang){
			system("cls");
			DisplayBrgData(brg.id_barang,brg.nama,brg.harga);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(brg.nama,15);
			strupr(brg.nama);
			fwrite(&brg,sizeof(brg),1,tmp);
		}else{
			fwrite(&brg,sizeof(brg),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Barang.dat");
	rename("Dat/Tmp.dat","Dat/Barang.dat");
}

void UpdatePriceBrg(){
	system("cls");
	fp = fopen("Dat/Barang.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&brg,sizeof(brg),1,fp)==1){
		if(search==brg.id_barang){
			system("cls");
			DisplayBrgData(brg.id_barang,brg.nama,brg.harga);
			gotoxy(0,2);
			printf("                 ");
			gotoxy(0,2);
			printf("Rp ");getRp(&brg.harga,4,8,2,2);
			fwrite(&brg,sizeof(brg),1,tmp);
		}else{
			fwrite(&brg,sizeof(brg),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Barang.dat");
	rename("Dat/Tmp.dat","Dat/Barang.dat");
}

void UpdateMenuBrg(){
	while(1){
		system("cls");
		UpdateDisplayBrg();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateNameBrg();
		}else if(choose==2){
			UpdatePriceBrg();
		}else if(choose==3){
			break;
		}
	}	
}

void UpdateBrg(){
	while(1){
		system("cls");
		found = false;
		printf("Item's ID\t: BRG");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Barang.dat","rb");
			while(fread(&brg,sizeof(brg),1,fp)==1){
				if(search==brg.id_barang){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuBrg();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteBrg(){
	while(1){
		system("cls");
		found = false;
		printf("Item's ID\t: BRG");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Barang.dat","rb");
			while(fread(&brg,sizeof(brg),1,fp)==1){
				if(search==brg.id_barang){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Barang.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&brg,sizeof(brg),1,fp)==1){
					if(search==brg.id_barang){
						while(1){
							system("cls");
							DisplayBrgData(brg.id_barang,brg.nama,brg.harga);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&brg,sizeof(brg),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&brg,sizeof(brg),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Barang.dat");
				rename("Dat/Tmp.dat","Dat/Barang.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuBarang(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateBrg();
			break;
			case 2:
				ReadBrg();
			break;
			case 3:
				UpdateBrg();
			break;
			case 4:
				DeleteBrg();
			break;
			case 5:
				//main menu
			break;
		}
	}
}
