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
	printf("\nHarga Barang\t: Rp");getRp(&brg.harga,4,8,21,2);
	fwrite(&brg,sizeof(brg),1,fp);
	fclose(fp);
}

void ReadBrg(){
	system("cls");
	fp = fopen("Dat/Barang.dat", "rb");
	if(fread(&brg,sizeof(brg),1,fp)==0){
		printf("Belum ada Data");
		getch();
	}else{
		do{
			fread(&brg,sizeof(brg),1,fp);
			if(!feof(fp)){
				rupiah(brg.harga,cvrRp);
				printf("BRG%d\t\t%s\t\tRp%s\n",brg.id_barang,brg.nama,cvrRp);
			}
		}while(!feof(fp));
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
