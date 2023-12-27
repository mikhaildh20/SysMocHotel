void CreateMnu(){
	system("cls");
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
	printf("MENU ID\t\t: MNU%d\n",mnu.id_menu);
	printf("FOOD NAME\t: ");getletter(mnu.nama,15);
	strupr(mnu.nama);
	while(1){
		gotoxy(18,2);
		printf("              ");
		gotoxy(0,2);
		printf("CATEGORY\t: ");getletter(mnu.category,10);
		strupr(mnu.category);
		if(strcmp(mnu.category,"FOOD")==0 || strcmp(mnu.category,"DRINK")==0){
			break;
		}
	}
	printf("\nPRICE\t\t: Rp");getRp(&mnu.harga,4,8,21,3);
	fwrite(&mnu,sizeof(mnu),1,fp);
	fclose(fp);
}

void ReadMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&mnu,sizeof(mnu),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("MNU%d",mnu.id_menu);
				gotoxy(10,i);
				printf("%s",mnu.nama);
				gotoxy(30,i);
				printf("%s",mnu.category);
				rupiah(mnu.harga,cvrRp);
				gotoxy(45,i);
				printf("Rp%s",cvrRp);
				i++;
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayMnuData(int id, char nama[],char category[], int harga){
	printf("MNU%d\n",id);
	printf("%s\n",nama);
	printf("%s\n",category);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
}

void UpdateDisplayMnu(){
	printf("[1]Menu Name\n");
	printf("[2]Category\n");
	printf("[3]Price\n");
	printf("[4]Back\n");
}

void UpdateNameMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(search==mnu.id_menu){
			system("cls");
			DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(mnu.nama,15);
			strupr(mnu.nama);
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}

void UpdateCategoryMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(search==mnu.id_menu){
			while(1){
				system("cls");
				DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
				gotoxy(0,2);
				printf("                 ");
				gotoxy(0,2);
				getletter(mnu.category,10);
				strupr(mnu.category);
				if(strcmp(mnu.category,"FOOD")==0 || strcmp(mnu.category,"DRINK")==0){
					break;
				}	
			}
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}

void UpdatePriceMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(search==mnu.id_menu){
			system("cls");
			DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
			gotoxy(0,3);
			printf("                 ");
			gotoxy(0,3);
			printf("Rp ");getRp(&mnu.harga,4,8,3,3);
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}

void UpdateMenuMnu(){
	while(1){
		system("cls");
		UpdateDisplayMnu();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateNameMnu();
		}else if(choose==2){
			UpdateCategoryMnu();
		}else if(choose==3){
			UpdatePriceMnu();
		}else if(choose==4){
			break;
		}
	}	
}

void UpdateMnu(){
	while(1){
		system("cls");
		found = false;
		printf("Menu's ID\t: MNU");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Menu.dat","rb");
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuMnu();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteMnu(){
	while(1){
		system("cls");
		found = false;
		printf("Menu's ID\t: MNU");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Menu.dat","rb");
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Menu.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&mnu,sizeof(mnu),1,fp)==1){
					if(search==mnu.id_menu){
						while(1){
							system("cls");
							DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&mnu,sizeof(mnu),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&mnu,sizeof(mnu),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Menu.dat");
				rename("Dat/Tmp.dat","Dat/Menu.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuMenu(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
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
			case 5:
				//main menu
			break;
		}
	}
}
