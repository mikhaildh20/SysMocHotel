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
				
			break;
			case 4:
				
			break;
			case 5:
				
			break;
		}
	}
}
