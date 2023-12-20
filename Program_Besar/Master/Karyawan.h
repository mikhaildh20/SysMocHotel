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
	printf("[3]Last Name");
	printf("[4]Telephone");
	printf("[5]Back");
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
	printf("ID Karyawan\t: KRY%d\n", kry.id_karyawan);
	printf("Username\t: ");getteks(kry.username,10);
	printf("\nPassword\t: ");getpass(kry.password,10);
	printf("\nFront Name\t: ");getletter(kry.fname,10);
	printf("\nLast Name\t: ");getletter(kry.lname,10);
	printf("\n");
	while(1){
		gotoxy(0,5);
		printf("Role\t\t: ");getletter(kry.role,15);
		cvrUpper(&kry.role);
		if(strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "RECEPTIONIST")==0){
			break;
		}else{
			gotoxy(10,5);
			printf("                    ");
		}
	}
	printf("\nTelephone\t: ");getinputmin(kry.no_telp,13,13,3);
	fflush(stdin);
	fwrite(&kry,sizeof(kry),1,ArsKry);
	MessageBox(NULL,"Data berhasil ditambahkan!","NOTIFICATION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	fclose(ArsKry);
}

void ReadKry(){
	system("cls");
	ArsKry = fopen("Dat/Karyawan.dat", "rb");
	if(ArsKry == NULL){
		MessageBoxA(NULL,"Belum ada data!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		while(fread(&kry,sizeof(kry),1,ArsKry)==1){
			if(!feof(ArsKry)){
				printf("KRY%d\t\t%s %s\t\t%s\t\t%s\n",kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			}
		}
		getch();
	}
	fclose(ArsKry);
}
//
//void UpdateNBrg(){
//	found = false;
//	system("cls");
//	printf("Masukkan ID: BRG");getnummin(&search,1,3);
//	ArsBrg = fopen("Dat/Barang.dat", "rb");
//	ArsTmp = fopen("Dat/tmp.dat", "wb");
//	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
//		if(search == brg.id_barang){
//			found = true;
//			rupiah(brg.harga,cvrRp);
//			printf("\nID BARANG\t: BRG%d", brg.id_barang);
//			printf("\nHarga\t\t: Rp%s", cvrRp);
//			printf("\nNama\t\t: ");getletter(brg.nama,15);
//			fwrite(&brg,sizeof(brg),1,ArsTmp);
//		}else{
//			fwrite(&brg,sizeof(brg),1,ArsTmp);
//		}
//	}
//	fclose(ArsTmp);
//	fclose(ArsBrg);
//	if(found){
//		remove("Dat/Barang.dat");
//		rename("Dat/tmp.dat","Dat/Barang.dat");
//		MessageBoxA(NULL,"Berhasil diubah!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}else{
//		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}
//}
//
//void UpdateHBrg(){
//	found = false;
//	system("cls");
//	printf("Masukkan ID: BRG");getnummin(&search,1,3);
//	ArsBrg = fopen("Dat/Barang.dat", "rb");
//	ArsTmp = fopen("Dat/tmp.dat", "wb");
//	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
//		if(search == brg.id_barang){
//			found = true;
//			printf("\nID BARANG\t: BRG%d", brg.id_barang);
//			printf("\nNama\t\t: %s", brg.nama);
//			printf("\nHarga\t\t: Rp ");getRp(&brg.harga,4,7,21,3);
//			fwrite(&brg,sizeof(brg),1,ArsTmp);
//		}else{
//			fwrite(&brg,sizeof(brg),1,ArsTmp);
//		}
//	}
//	fclose(ArsTmp);
//	fclose(ArsBrg);
//	if(found){
//		remove("Dat/Barang.dat");
//		rename("Dat/tmp.dat","Dat/Barang.dat");
//		MessageBoxA(NULL,"Berhasil diubah!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}else{
//		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}
//}
//
//void UpdateBrg(){
//	i = 1;
//	while(i==1){
//		system("cls");
//		DisplayBarang();
//		printf("\nChoose: ");
//		getnummin(&choose,1,1);
//		switch(choose){
//			case 1:
//				UpdateNBrg();
//			break;
//			case 2: 
//				UpdateHBrg();
//			break;
//			case 3:
//				i=0;
//			break;
//		}
//	}
//	
//}
//
//void DeleteBarang(){
//	found = false;
//	system("cls");
//	printf("Masukkan ID: BRG");getnummin(&search,1,3);
//	ArsBrg = fopen("Dat/Barang.dat", "rb");
//	ArsTmp = fopen("Dat/tmp.dat", "wb");
//	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
//		if(search != brg.id_barang){
//			if(search== brg.id_barang){
//				found = true;
//			}else{
//				fwrite(&brg,sizeof(brg),1,ArsTmp);	
//			}
//		}
//	}
//	if(!found){
//		MessageBoxA(NULL,"Berhasil dihapus!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}else{
//		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
//	}
//	
//	fclose(ArsBrg);
//	fclose(ArsTmp);
//	remove("Dat/Barang.dat");
//	rename("Dat/tmp.dat","Dat/Barang.dat");
//}

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
//				UpdateBrg();
			break;
			case 4:
//				DeleteBarang();
			break;
			case 5:
				j=0;
				printf("\nExited.");
			break;
		}	
	}
}
