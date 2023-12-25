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
	cvrUpper(&kry.fname);
	printf("\nLast Name\t: ");getletter(kry.lname,10);
	cvrUpper(&kry.lname);
	while(1){
		gotoxy(18,5);
		printf("                             ");
		gotoxy(0,5);
		printf("ROLE\t\t: ");getletter(kry.role,15);
		cvrUpper(&kry.role);
		if(strcmp(kry.role, "RECEPTIONIST")==0 || strcmp(kry.role, "ADMIN")==0 || strcmp(kry.role, "CASHIER")==0){
			break;
		}
	}
	printf("\nTelephone\t: ");getnummin(&kry.no_telp,13,13);
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
		while(!feof(fp)){
			fread(&kry,sizeof(kry),1,fp);
			if(!feof(fp)){
				printf("KRY%d\t\t%s %s\t\t%s\t\t%s\n",kry.id_karyawan,kry.fname,kry.lname,kry.role,kry.no_telp);
			}
		}
		getch();
	}
	fclose(fp);
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
				
			break;
			case 4:
				
			break;
			case 5:
				
			break;
		}
	}
}
