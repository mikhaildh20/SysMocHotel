void CreateFsl(){
	system("cls");
	fp = fopen("Dat/Fasilitas.dat", "ab+");
	if(fread(&fsl,sizeof(fsl),1,fp)==0){
		fsl.id_fasilitas = 1;
	}else{
		while(!feof(fp)){
			fread(&fsl,sizeof(fsl),1,fp);
			if(feof(fp)){
				fsl.id_fasilitas+=1;
			}
		}
	}
	printf("FACILITY ID\t: FSL%d\n",fsl.id_fasilitas);
	printf("FACILITY NAME\t: ");getletter(fsl.nama,15);
	strupr(fsl.nama);
	printf("\nPRICE\t\t: Rp");getRp(&fsl.harga,5,7,21,2);
	fsl.status = 1;
	fwrite(&fsl,sizeof(fsl),1,fp);
	fclose(fp);
}

void ReadFsl(){
	system("cls");
	fp = fopen("Dat/Fasilitas.dat", "rb");
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		while(!feof(fp)){
			fread(&fsl,sizeof(fsl),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("FSL%d",fsl.id_fasilitas);
				gotoxy(10,i);
				printf("%s", fsl.nama);
				rupiah(fsl.harga,cvrRp);
				gotoxy(30,i);
				printf("Rp%s",cvrRp);
				gotoxy(50,i);
				switch(fsl.status){
					case 0:
						strcpy(rStat,"UNAVAILABLE");
					break;
					case 1:
						strcpy(rStat,"AVAILABLE");
					break;
				}
				printf("%s",rStat);
				i++;	
			}
		}
		getch();
	}
	fclose(fp);
}


void MenuFasilitas(){
	while(1){
		system("cls");
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateFsl();
			break;
			case 2:
				ReadFsl();
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
