void MainMen(){
	printf("[1] Create\n");
	printf("[2] Read\n");
	printf("[3] Update\n");
	printf("[4] Delete\n");
	printf("[5] Back\n");
	printf("Choose: ");
}

void CreateDnd(){
	system("cls");
	fp = fopen("Dat/Denda.dat", "ab+");
	if(fread(&dnd,sizeof(dnd),1,fp)==0){
		dnd.id_denda = 1;
	}else{
		while(!feof(fp)){
			fread(&dnd,sizeof(dnd),1,fp);
			if(feof(fp)){
				dnd.id_denda+=1;
			}
		}
	}
	printf("ID Denda\t: DND%d\n",dnd.id_denda);
	printf("Category\t: ");getletter(dnd.category,15);
	strupr(dnd.category);
	printf("\nNominal\t\t: Rp");getRp(&dnd.nominal,4,8,21,2);
	fflush(stdin);
	printf("\nKeterangan\t: ");gets(dnd.ket);
	fwrite(&dnd,sizeof(dnd),1,fp);
	fclose(fp);
}

void ReadDnd(){
	system("cls");
	fp = fopen("Dat/Denda.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&dnd,sizeof(dnd),1,fp);
			if(!feof(fp)){
				rupiah(dnd.nominal,cvrRp);
				gotoxy(0,i);
				printf("DND%d",dnd.id_denda);
				gotoxy(10,i);
				printf("%s",dnd.category);
				gotoxy(30,i);
				printf("Rp%s",cvrRp);
				gotoxy(45,i);
				printf("%.10s..",dnd.ket);
				i++;
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayDndData(int id, char category[], int nominal, char ket[]){
	printf("DND%d\n",id);
	printf("%s\n",category);
	rupiah(nominal,cvrRp);
	printf("Rp%s\n",cvrRp);
	printf("%s\n",ket);
}

void UpdateDisplayDnd(){
	printf("[1]Category\n");
	printf("[2]Fee\n");
	printf("[3]Desc\n");
	printf("[4]Back\n");
}

void UpdateCategoryDnd(){
	system("cls");
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			system("cls");
			DisplayDndData(dnd.id_denda,dnd.category,dnd.nominal,dnd.ket);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(dnd.category,15);
			strupr(dnd.category);
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Denda.dat");
	rename("Dat/Tmp.dat","Dat/Denda.dat");
}

void UpdatePriceDnd(){
	system("cls");
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			system("cls");
			DisplayDndData(dnd.id_denda,dnd.category,dnd.nominal,dnd.ket);
			gotoxy(0,2);
			printf("                 ");
			gotoxy(0,2);
			printf("Rp ");getRp(&dnd.nominal,4,8,3,2);
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Denda.dat");
	rename("Dat/Tmp.dat","Dat/Denda.dat");
}

void UpdateDescDnd(){
	system("cls");
	fp = fopen("Dat/Denda.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		if(search==dnd.id_denda){
			system("cls");
			DisplayDndData(dnd.id_denda,dnd.category,dnd.nominal,dnd.ket);
			gotoxy(0,3);
			printf("                                       ");
			gotoxy(0,3);
			gets(dnd.ket);
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}else{
			fwrite(&dnd,sizeof(dnd),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Denda.dat");
	rename("Dat/Tmp.dat","Dat/Denda.dat");
}

void UpdateMenuDnd(){
	while(1){
		system("cls");
		UpdateDisplayDnd();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateCategoryDnd();
		}else if(choose==2){
			UpdatePriceDnd();
		}else if(choose==3){
			UpdateDescDnd();
		}else if(choose==4){
			break;
		}
	}	
}

void UpdateDnd(){
	while(1){
		system("cls");
		found = false;
		printf("Penalties ID\t: DND");getnummin(&search,1,3);
		if(search==0){
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
				UpdateMenuDnd();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteDnd(){
	while(1){
		system("cls");
		found = false;
		printf("Penalties ID\t: DND");getnummin(&search,1,3);
		if(search==0){
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
				fp = fopen("Dat/Denda.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&dnd,sizeof(dnd),1,fp)==1){
					if(search==dnd.id_denda){
						while(1){
							system("cls");
							DisplayDndData(dnd.id_denda,dnd.category,dnd.nominal,dnd.ket);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&dnd,sizeof(dnd),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&dnd,sizeof(dnd),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Denda.dat");
				rename("Dat/Tmp.dat","Dat/Denda.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuDenda(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
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
			case 5:
				//main menu
			break;
		}
	}
}
