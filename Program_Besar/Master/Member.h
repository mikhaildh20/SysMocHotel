void CreateMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat", "ab+");
	printf("Front Name\t: ");getletter(mbr.fname,7);
	printf("\nLast Name\t: ");getletter(mbr.lname,7);
	strupr(mbr.fname);
	strupr(mbr.lname);
	printf("\nNIK\t\t: ");getteksnummin(mbr.NIK,16,16);
	printf("\nAddress\t\t: ");getteks(mbr.alamat,10);
	getTime(&mbr.expd,&mbr.expm,&mbr.expy);
	mbr.expy+=1;
	mbr.active_status=1;
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
		i=0;
		while(!feof(fp)){
			fread(&mbr,sizeof(mbr),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("%s %s",mbr.fname,mbr.lname);
				gotoxy(20,i);
				printf("%s",mbr.NIK);
				gotoxy(45,i);
				if(mbr.expd<10 && mbr.expm<10){
					printf("0%d/0%d/%d",mbr.expd,mbr.expm,mbr.expy);
				}else if(mbr.expm<10){
					printf("0%d/%d/%d",mbr.expd,mbr.expm,mbr.expy);
				}else if(mbr.expd<10){
					printf("%d/0%d/%d",mbr.expd,mbr.expm,mbr.expy);
				}else{
					printf("%d/%d/%d",mbr.expd,mbr.expm,mbr.expy);
				}
				switch(mbr.active_status){
					case 0:
						strcpy(rStat,"INACTIVE");
					break;
					case 1:
						strcpy(rStat,"ACTIVE");
					break;
				}
				gotoxy(55,i);
				printf("%s",rStat);
				i++;
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
