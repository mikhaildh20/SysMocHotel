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
	printf("MENU ID\t: MNU%d\n",mnu.id_menu);
	printf("FOOD NAME\t: ");getletter(mnu.nama,15);
	strupr(mnu.nama);
	while(1){
		gotoxy(18,2);
		printf("              ");
		gotoxy(0,2);
		printf("\nCATEGORY: ");getletter(mnu.category,10);
		strupr(mnu.category);
		if(strcmp(mnu.category,"FOOD")==0 || strcmp(mnu.category,"DRINK")==0){
			break;
		}
	}
	printf("\nPRICE\t: Rp");getRp(&mnu.harga,4,8,21,3);
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
				i++;
			}
		}
		getch();
	}
	fclose(fp);
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
				
			break;
			case 4:
				
			break;
			case 5:
				
			break;
		}
	}
}
