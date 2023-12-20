void DisplayMMember(){
	printf("[1]Create\n");
	printf("[2]Read\n");
	printf("[3]Update\n");
	printf("[4]Delete\n");
	printf("[5]Back");
}

void DisplayMember(){
	printf("[1]Front Name\n");
	printf("[2]Last Name\n");
	printf("[3]Telephone\n");
	printf("[4]Extend Period\n");
	printf("[5]Back");
}

void CreateMbr(){
	system("cls");
	ArsMbr = fopen("Dat/Member.dat", "ab");
	printf("NIK\t: ");getinputmin(mbr.NIK,16,16,3);
	fflush(stdin);
	printf("\nFront Name\t: ");getteks(mbr.fname,10);
	printf("\nLast Name\t: ");getteks(mbr.lname,10);
	printf("\nTelephone\t: ");getteksnummin(mbr.no_telp,13,13);
	getTime(&mbr.hari,&mbr.bulan,&mbr.tahun);
	fwrite(&mbr,sizeof(mbr),1,ArsMbr);
	MessageBox(NULL,"Data berhasil ditambahkan!","NOTIFICATION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	fclose(ArsMbr);
}

void ReadMbr(){
	system("cls");
	ArsMbr = fopen("Dat/Member.dat", "rb");
	if(ArsMbr == NULL){
		MessageBoxA(NULL,"Belum ada data!","ATTENTION",MB_OK | MB_DEFAULT_DESKTOP_ONLY);
	}else{
		while(fread(&mbr,sizeof(mbr),1,ArsMbr)==1){
			if(!feof(ArsMbr)){
				printf("%s\t\t%s %s\t\t%s\t%d/%d/%d\n",mbr.NIK,mbr.fname,mbr.lname,mbr.no_telp,mbr.hari,mbr.bulan,mbr.tahun);
			}
		}
		getch();
	}
	fclose(ArsMbr);
}

void ChooseMember(){
	remove("Dat/tmp.dat");
	j = 1;
	while(j==1){
		system("cls");
		DisplayMMember();
		printf("\nChoose: ");
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
				CreateMbr();	
			break;
			case 2:
				ReadMbr();
			break;
			case 3:
				//UpdateMbr();
			break;
			case 4:
				//DeleteBarang();
			break;
			case 5:
				j=0;
				printf("\nExited.");
			break;
		}	
	}
}
