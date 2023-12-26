void CreateMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat", "ab");
	printf("NIK\t\t: ");getteksnummin(mbr.NIK,16,16);
	printf("\nFront Name\t: ");getletter(mbr.fname,10);
	strupr(mbr.fname);
	printf("\nLast Name\t: ");getletter(mbr.lname,10);
	strupr(mbr.lname);
	printf("\nTelephone\t: ");getteksnummin(mbr.no_telp,11,13);
	getTime(&mbr.hari,&mbr.bulan,&mbr.tahun);
	getTime(&mbr.expd,&mbr.expm,&mbr.expy);
	mbr.expy+=1;
	mbr.active_status = 1;
	fwrite(&mbr,sizeof(mbr),1,fp);
	fclose(fp);
}

void ReadMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		while(!feof(fp)){
			fread(&mbr,sizeof(mbr),1,fp);
			if(!feof(fp)){
				if(mbr.expd<10 && mbr.expm<10){
					printf("%s\t\t%s %s\t\t0%d/0%d/%d\n",mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy);
				}else if(mbr.expd<10){
					printf("%s\t\t%s %s\t\t0%d/%d/%d\n",mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy);
				}else if(mbr.expm<10){
					printf("%s\t\t%s %s\t\t%d/0%d/%d\n",mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy);
				}else{
					printf("%s\t\t%s %s\t\t%d/%d/%d\n",mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy);	
				}
			}
		}
		getch();
	}
	fclose(fp);
}


void MenuMember(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateMbr();
			break;
			case 2:
				ReadMbr();
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
