void CreateKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat", "ab+");
	if(fread(&kry,sizeof(kry),1,fp)==0){
		kry.id_karyawan = 1;
	}else{
		while(!feof(fp)){
			fread(&kry,sizeof(kry),1,fp);
			if(feof(fp)){
				kry.id_karyawan+=1;
			}
		}
	}
	printf("ID Karyawan\t: KRY%d\n",kry.id_karyawan);
	printf("Username\t: ");getteks(kry.username,10);
	printf("\nPassword\t: ");getpass(kry.password,10);
	printf("\nFront Name\t: ");getletter(kry.fname,10);
	strupr(kry.fname);
	printf("\nLast Name\t: ");getletter(kry.lname,10);
	strupr(kry.lname);
	while(1){
		gotoxy(18,5);
		printf("                             ");
		gotoxy(0,5);
		printf("ROLE\t\t: ");getletter(kry.role,15);
		strupr(kry.role);
		if(strcmp(kry.role, "RECEPTIONIST")==0 || strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "CASHIER")==0){
			break;
		}
	}
	printf("\nTelephone\t: ");getteksnummin(&kry.no_telp,11,13);
	fwrite(&kry,sizeof(kry),1,fp);
	fclose(fp);
}

void ReadKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&kry,sizeof(kry),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("KRY%d", kry.id_karyawan);
				gotoxy(10,i);
				printf("%s %s",kry.fname,kry.lname);
				gotoxy(45,i);
				printf("%s", kry.role);
				gotoxy(65,i);
				printf("%s",kry.no_telp);
				i++;	
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayKryData(int id, char fname[], char lname[],char role[],char telp[]){
	printf("KRY%d\n",id);
	printf("%s\n",fname);
	printf("%s\n",lname);
	printf("%s\n",role);
	printf("%s\n",telp);
}

void UpdateDisplayKry(){
	printf("[1]Front Name\n");
	printf("[2]Last Name\n");
	printf("[3]Role\n");
	printf("[4]Telephone\n");
	printf("[5]Back\n");
}

void UpdateFnameKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			DisplayKryData(kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(kry.fname,7);
			strupr(kry.fname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateLnameKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			DisplayKryData(kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			gotoxy(0,2);
			printf("                 ");
			gotoxy(0,2);
			getletter(kry.lname,7);
			strupr(kry.lname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateRoleKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			while(1){
				system("cls");
				DisplayKryData(kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
				gotoxy(0,3);
				printf("                        ");
				gotoxy(0,3);
				getletter(kry.role,15);
				strupr(kry.role);
				if(strcmp(kry.role, "RECEPTIONIST")==0 || strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "CASHIER")==0){
					break;
				}	
			}
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateTelpKry(){
	system("cls");
	fp = fopen("Dat/Karyawan.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,fp)==1){
		if(search==kry.id_karyawan){
			system("cls");
			DisplayKryData(kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			gotoxy(0,4);
			printf("                 ");
			gotoxy(0,4);
			getteksnummin(kry.no_telp,11,13);
			strupr(kry.lname);
			fwrite(&kry,sizeof(kry),1,tmp);
		}else{
			fwrite(&kry,sizeof(kry),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Karyawan.dat");
	rename("Dat/Tmp.dat","Dat/Karyawan.dat");
}

void UpdateMenuKry(){
	while(1){
		system("cls");
		UpdateDisplayKry();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateFnameKry();
		}else if(choose==2){
			UpdateLnameKry();
		}else if(choose==3){
			UpdateRoleKry();
		}else if(choose==4){
			UpdateTelpKry();
		}else if(choose==5){
			break;
		}
	}	
}

void UpdateKry(){
	while(1){
		system("cls");
		found = false;
		printf("Employee's ID\t: KRY");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Karyawan.dat","rb");
			while(fread(&kry,sizeof(kry),1,fp)==1){
				if(search==kry.id_karyawan){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuKry();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteKry(){
	while(1){
		system("cls");
		found = false;
		printf("Employee's ID\t: KRY");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Karyawan.dat","rb");
			while(fread(&kry,sizeof(kry),1,fp)==1){
				if(search==kry.id_karyawan){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Karyawan.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&kry,sizeof(kry),1,fp)==1){
					if(search==kry.id_karyawan){
						while(1){
							system("cls");
							DisplayKryData(kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&kry,sizeof(kry),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&kry,sizeof(kry),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Karyawan.dat");
				rename("Dat/Tmp.dat","Dat/Karyawan.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}


void MenuKaryawan(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateKry();
			break;
			case 2:
				ReadKry();
			break;
			case 3:
				UpdateKry();
			break;
			case 4:
				DeleteKry();
			break;
			case 5:
				//main menu
			break;
		}
	}
}
