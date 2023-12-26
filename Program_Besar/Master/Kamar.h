void CreateKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat", "ab+");
	if(fread(&kmr,sizeof(kmr),1,fp)==0){
		kmr.no_kamar = 1;
	}else{
		while(!feof(fp)){
			fread(&kmr,sizeof(kmr),1,fp);
			if(feof(fp)){
				kmr.no_kamar+=1;
			}
		}
	}
	printf("ROOM NUMBER\t: KMR%d\n",kmr.no_kamar);
	while(1){
		gotoxy(18,1);
		printf("                  ");
		gotoxy(0,1);
		printf("ROOM TYPE\t: ");getletter(kmr.tipe_kamar,15);
		strupr(kmr.tipe_kamar);
		if(strcmp(kmr.tipe_kamar,"STANDARD")==0 || strcmp(kmr.tipe_kamar,"DOUBLE")==0 || strcmp(kmr.tipe_kamar,"SUITE")==0 || strcmp(kmr.tipe_kamar,"EXECUTIVE")==0){
			break;			
		}
	}
	printf("\nFLOOR\t\t: ");getnummin(&kmr.lantai,1,1);
	if(strcmp(kmr.tipe_kamar,"STANDARD")==0){
		kmr.harga = 100000;
	}else if(strcmp(kmr.tipe_kamar,"DOUBLE")==0){
		kmr.harga = 250000;
	}else if(strcmp(kmr.tipe_kamar,"SUITE")==0){
		kmr.harga = 400000;
	}else{
		kmr.harga = 600000;
	}
	kmr.status = 1;
	fwrite(&kmr,sizeof(kmr),1,fp);
	fclose(fp);
}

void ReadKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&kmr,sizeof(kmr),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("KMR%d",kmr.no_kamar);
				gotoxy(10,i);
				printf("%s",kmr.tipe_kamar);
				gotoxy(30,i);
				printf("%d",kmr.lantai);
				rupiah(kmr.harga,cvrRp);
				gotoxy(35,i);
				printf("Rp%s",cvrRp);
				switch(kmr.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
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


void MenuKamar(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateKmr();
			break;
			case 2:
				ReadKmr();
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
