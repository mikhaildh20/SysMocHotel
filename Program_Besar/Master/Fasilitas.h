void CreateFsl(){
	system("cls");
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
	printf("FACILITY ID\t: FSL%d\n",fsl.id_fasilitas);
	printf("FACILITY NAME\t: ");getletter(fsl.nama,15);
	strupr(fsl.nama);
	printf("\nPRICE\t\t: Rp");getRp(&fsl.harga,5,7,21,2);
	fsl.status = 1;
	fwrite(&fsl,sizeof(fsl),1,fp);
	fclose(fp);
}

void ReadFsl(){
	system("cls");
	fp = fopen("Dat/Fasilitas.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&fsl,sizeof(fsl),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("FSL%d",fsl.id_fasilitas);
				gotoxy(10,i);
				printf("%s", fsl.nama);
				rupiah(fsl.harga,cvrRp);
				gotoxy(30,i);
				printf("Rp%s",cvrRp);
				gotoxy(50,i);
				switch(fsl.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
					break;
				}
				printf("%s",rStat);
				i++;	
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayFslData(int id, char nama[], int harga,int status){
	printf("FSL%d\n",id);
	printf("%s\n",nama);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
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

void UpdateDisplayFsl(){
	printf("[1]Facility Name\n");
	printf("[2]Price\n");
	printf("[3]Back\n");
}

void UpdateNameFsl(){
	system("cls");
	fp = fopen("Dat/Fasilitas.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		if(search==fsl.id_fasilitas){
			system("cls");
			DisplayFslData(fsl.id_fasilitas,fsl.nama,fsl.harga,fsl.status);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(fsl.nama,15);
			strupr(fsl.nama);
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}else{
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Fasilitas.dat");
	rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
}

void UpdatePriceFsl(){
	system("cls");
	fp = fopen("Dat/Fasilitas.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		if(search==fsl.id_fasilitas){
			system("cls");
			DisplayFslData(fsl.id_fasilitas,fsl.nama,fsl.harga,fsl.status);
			gotoxy(0,2);
			printf("                 ");
			gotoxy(0,2);
			printf("Rp ");getRp(&fsl.harga,4,8,3,2);
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}else{
			fwrite(&fsl,sizeof(fsl),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Fasilitas.dat");
	rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
}

void UpdateMenuFsl(){
	while(1){
		system("cls");
		UpdateDisplayFsl();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateNameFsl();
		}else if(choose==2){
			UpdatePriceFsl();
		}else if(choose==3){
			break;
		}
	}	
}

void UpdateFsl(){
	while(1){
		system("cls");
		found = false;
		printf("Item's ID\t: FSL");getnummin(&search,1,3);
		if(search==0){
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
				UpdateMenuFsl();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteFsl(){
	while(1){
		system("cls");
		found = false;
		printf("Item's ID\t: FSL");getnummin(&search,1,3);
		if(search==0){
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
				fp = fopen("Dat/Fasilitas.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&fsl,sizeof(fsl),1,fp)==1){
					if(search==fsl.id_fasilitas){
						while(1){
							system("cls");
							DisplayFslData(fsl.id_fasilitas,fsl.nama,fsl.harga,fsl.status);
							printf("\nDelete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&fsl,sizeof(fsl),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&fsl,sizeof(fsl),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Fasilitas.dat");
				rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuFasilitas(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
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
			case 5:
				//main menu
			break;
		}
	}
}
