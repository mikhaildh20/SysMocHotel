void DisplayMKaryawan(){
	printf("[1]Create\n");
	printf("[2]Read\n");
	printf("[3]Update\n");
	printf("[4]Delete\n");
	printf("[5]Back");
}

void DisplayKaryawan(){
	printf("[1]Role\n");
	printf("[2]Front Name\n");
	printf("[3]Last Name\n");
	printf("[4]Telephone\n");
	printf("[5]Back\n");
}

void CreateKry(){
	system("cls");
	int id = 1,i = 0;
	ArsKry = fopen("Dat/Karyawan.dat", "ab+");
	if(ArsKry != NULL){
		while(fread(&kry,sizeof(kry),1,ArsKry)==1){
			i++;
		}
	}
	kry.id_karyawan = id + i;
	printf("ID KARYAWAN\t: KRY%d\n", kry.id_karyawan);
	printf("Username\t: ");getteks(kry.username,10);
	printf("\nPassword\t: ");getpass(kry.password,10);
	while(1){
		gotoxy(0,2);
		printf("\nRole\t\t: ");getteks(kry.role,15);
		cvrUpper(kry.role);
		if(strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "RECEPTIONIST")==0){
			break;
		}else{
			gotoxy(0,3);
			printf("                                        ");
		}
	}
	printf("\nFront Name\t: ");getletter(kry.fname,10);
	printf("\nLast Name\t: ");getletter(kry.lname,10);
	printf("\nTelephone\t: ");getteksnum(kry.no_telp,13);
	fwrite(&kry,sizeof(kry),1,ArsKry);
	fclose(ArsKry);
	MessageBox(NULL,"Data berhasil ditambahkan!","NOTIFICATION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
}

void ReadKry(){
	system("cls");
	ArsKry = fopen("Dat/Karyawan.dat", "rb");
	if(ArsKry != NULL){
		while(fread(&kry,sizeof(kry),1,ArsKry)==1){
			if(!feof(ArsKry)){
				printf("KRY%d\t%s %s\t\t\t%s\t%s\n",kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			}
		}
		getch();
	}else{
		MessageBoxA(NULL,"Belum ada data!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}
	fclose(ArsBrg);
}

void UpdateRKry(){
	found = false;
	system("cls");
	printf("Masukkan ID: KRY");getnummin(&search,1,3);
	ArsKry = fopen("Dat/Karyawan.dat", "rb");
	ArsTmp = fopen("Dat/tmp.dat", "wb");
	while(fread(&kry,sizeof(kry),1,ArsKry)==1){
		if(search == kry.id_karyawan){
			found = true;
			while(1){
			gotoxy(0,2);
			printf("\nRole\t\t: ");getteks(kry.role,15);
			cvrUpper(kry.role);
				if(strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "RECEPTIONIST")==0){
					break;
				}else{
					gotoxy(0,3);
					printf("                                        ");
				}	
			}
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}else{
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}
	}
	fclose(ArsTmp);
	fclose(ArsKry);
	if(found){
		remove("Dat/Karyawan.dat");
		rename("Dat/tmp.dat","Dat/Karyawan.dat");
		MessageBoxA(NULL,"Berhasil diubah!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}
}

void UpdateKry(){
	while(i==1){
		system("cls");
		DisplayKaryawan();
		printf("\nChoose: ");
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
				UpdateRKry();
			break;
			case 2:
				//UpdateFKry();
			break;
			case 3:
				//UpdateLKry();
			break;
			case 4:
				//UpdateTKry();
			break;
			case 5:
				i=0;
			break;
		}
	}
}

void ChooseKaryawan(){
	remove("Dat/tmp.dat");
	j = 1;
	while(j==1){
		system("cls");
		DisplayMKaryawan();
		printf("\nChoose: ");
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
				CreateKry();	
			break;
			case 2:
				ReadKry();
			break;
			case 3:
				//UpdateKry();
			break;
			case 4:
				//DeleteKry();
			break;
			case 5:
				j=0;
				printf("\nExited.");
			break;
		}	
	}
}
