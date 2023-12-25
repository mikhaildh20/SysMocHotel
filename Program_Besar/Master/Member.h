void CreateMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat", "ab+");
	if(fread(&mbr,sizeof(mbr),1,fp)==0){
		mbr.id_member = 1;
	}else{
		while(!feof(fp)){
			fread(&mbr,sizeof(mbr),1,fp);
			if(feof(fp)){
				mbr.id_member+=1;
			}
		}
	}
	printf("ID Member\t: MBR%d\n",mbr.id_member);
	printf("NIK\t\t: ");getteksnummin(mbr.NIK,16,16);
	printf("\nFront Name\t: ");getletter(mbr.fname,10);
	cvrUpper(&mbr.fname);
	printf("\nLast Name\t: ");getletter(mbr.lname,10);
	cvrUpper(&mbr.fname);
	printf("\nTelephone: ");getteksnummin(mbr.no_telp,13,13);
	getTime(&mbr.hari,&mbr.bulan,&mbr.tahun);
	getTime(&mbr.expd,&mbr.expm,&mbr.expy+1);
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
				printf("MBR%d\n",);
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
