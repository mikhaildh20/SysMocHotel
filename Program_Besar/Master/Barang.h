void DisplayMBarang(){
	printf("[1]Create\n");
	printf("[2]Read\n");
	printf("[3]Update\n");
	printf("[4]Delete\n");
	printf("[5]Back");
}

void DisplayBarang(){
	printf("[1]Nama\n");
	printf("[2]Harga\n");
	printf("[3]Back");
}

void CreateBrg(){
	system("cls");
	int id = 1,i = 0;
	ArsBrg = fopen("Dat/Barang.dat", "ab+");
	if(ArsBrg != NULL){
		while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
			i++;
		}
	}
	brg.id_barang = id + i;
	printf("ID Barang\t: BRG%d\n", brg.id_barang);
	printf("Nama Barang\t: ");getletter(brg.nama,15);
	printf("\nHarga Barang\t: Rp");getRp(&brg.harga, 4, 7,21,2);
	fwrite(&brg,sizeof(brg),1,ArsBrg);
	MessageBox(NULL,"Data berhasil ditambahkan!","NOTIFICATION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	fclose(ArsBrg);
}

void ReadBrg(){
	system("cls");
	ArsBrg = fopen("Dat/Barang.dat", "rb");
	if(ArsBrg == NULL){
		MessageBoxA(NULL,"Belum ada data!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
			if(!feof(ArsBrg)){
				rupiah(brg.harga, cvrRp);
				printf("BRG%d\t\t\t%s\t\tRp%s\n",brg.id_barang,brg.nama,cvrRp);
			}
		}
		getch();
	}
	fclose(ArsBrg);
}

void UpdateNBrg(){
	found = false;
	system("cls");
	printf("Masukkan ID: BRG");getnummin(&search,1,3);
	ArsBrg = fopen("Dat/Barang.dat", "rb");
	ArsTmp = fopen("Dat/tmp.dat", "wb");
	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
		if(search == brg.id_barang){
			found = true;
			rupiah(brg.harga,cvrRp);
			printf("\nID BARANG\t: BRG%d", brg.id_barang);
			printf("\nHarga\t\t: Rp%s", cvrRp);
			printf("\nNama\t\t: ");getletter(brg.nama,15);
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}else{
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}
	}
	fclose(ArsTmp);
	fclose(ArsBrg);
	if(found){
		remove("Dat/Barang.dat");
		rename("Dat/tmp.dat","Dat/Barang.dat");
		MessageBoxA(NULL,"Berhasil diubah!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}
}

void UpdateHBrg(){
	found = false;
	system("cls");
	printf("Masukkan ID: BRG");getnummin(&search,1,3);
	ArsBrg = fopen("Dat/Barang.dat", "rb");
	ArsTmp = fopen("Dat/tmp.dat", "wb");
	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
		if(search == brg.id_barang){
			found = true;
			printf("\nID BARANG\t: BRG%d", brg.id_barang);
			printf("\nNama\t\t: %s", brg.nama);
			printf("\nHarga\t\t: Rp ");getRp(&brg.harga,4,7,21,3);
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}else{
			fwrite(&brg,sizeof(brg),1,ArsTmp);
		}
	}
	fclose(ArsTmp);
	fclose(ArsBrg);
	if(found){
		remove("Dat/Barang.dat");
		rename("Dat/tmp.dat","Dat/Barang.dat");
		MessageBoxA(NULL,"Berhasil diubah!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}
}

void UpdateBrg(){
	i = 1;
	while(i==1){
		system("cls");
		DisplayBarang();
		printf("\nChoose: ");
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
				UpdateNBrg();
			break;
			case 2: 
				UpdateHBrg();
			break;
			case 3:
				i=0;
			break;
		}
	}
	
}

void DeleteBarang(){
	found = false;
	system("cls");
	printf("Masukkan ID: BRG");getnummin(&search,1,3);
	ArsBrg = fopen("Dat/Barang.dat", "rb");
	ArsTmp = fopen("Dat/tmp.dat", "wb");
	while(fread(&brg,sizeof(brg),1,ArsBrg)==1){
		if(search != brg.id_barang){
			if(search== brg.id_barang){
				found = true;
			}else{
				fwrite(&brg,sizeof(brg),1,ArsTmp);	
			}
		}
	}
	if(!found){
		MessageBoxA(NULL,"Berhasil dihapus!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		MessageBoxA(NULL,"ID Tidak ada!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}
	
	fclose(ArsBrg);
	fclose(ArsTmp);
	remove("Dat/Barang.dat");
	rename("Dat/tmp.dat","Dat/Barang.dat");
}

void ChooseBarang(){
	remove("Dat/tmp.dat");
	j = 1;
	while(j==1){
		system("cls");
		DisplayMBarang();
		printf("\nChoose: ");
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
				DeleteBarang();
			break;
			case 5:
				j=0;
				printf("\nExited.");
			break;
		}	
	}
}
