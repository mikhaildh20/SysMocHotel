void CreateMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat", "ab+");
	printf("NIK\t\t: ");getteksnummin(mbr.NIK,16,16);
	printf("\nFront Name\t: ");getletter(mbr.fname,7);
	printf("\nLast Name\t: ");getletter(mbr.lname,7);
	strupr(mbr.fname);
	strupr(mbr.lname);
	printf("\nTelephone\t: ");getteksnummin(mbr.telephone,11,13);
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
				printf("%s",mbr.NIK);
				gotoxy(20,i);
				printf("%s %s",mbr.fname,mbr.lname);
				gotoxy(40,i);
				printf("%s",mbr.telephone);
				gotoxy(60,i);
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
				gotoxy(80,i);
				printf("%s",rStat);
				i++;
			}
		}
		getch();
	}
	fclose(fp);
}

void DisplayMbrData(char nik[],char fname[], char lname[], int day, int month, int year, char telephone[]){
	printf("%s\n",nik);
	printf("%s\n",fname);
	printf("%s\n",lname);
	printf("%d/%d/%d\n",day,month,year);
	printf("%s",telephone);
}

void UpdateDisplayMbr(){
	printf("[1]Front Name\n");
	printf("[2]Last Name\n");
	printf("[3]Extend Membership\n");
	printf("[4]Telephone\n");
	printf("[5]Back\n");
}

void UpdateFnameMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mbr,sizeof(mbr),1,fp)==1){
		if(strcmp(sNIK,mbr.NIK)==0){
			system("cls");
			DisplayMbrData(mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy,mbr.telephone);
			gotoxy(0,1);
			printf("          ");
			gotoxy(0,1);
			getletter(mbr.fname,7);
			strupr(mbr.fname);
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}else{
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Member.dat");
	rename("Dat/Tmp.dat","Dat/Member.dat");
}

void UpdateLnameMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mbr,sizeof(mbr),1,fp)==1){
		if(strcmp(sNIK,mbr.NIK)==0){
			system("cls");
			DisplayMbrData(mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy,mbr.telephone);
			gotoxy(0,2);
			printf("          ");
			gotoxy(0,2);
			getletter(mbr.lname,7);
			strupr(mbr.lname);
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}else{
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Member.dat");
	rename("Dat/Tmp.dat","Dat/Member.dat");
}

void UpdateExtendMbr(){
	fp = fopen("Dat/Member.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mbr,sizeof(mbr),1,fp)==1){
		if(strcmp(sNIK,mbr.NIK)==0){
			system("cls");
			DisplayMbrData(mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy,mbr.telephone);
			while(1){
				printf("\nExtend?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
				if(strcmp(confirm,"YES")==0){
					mbr.expy+=1;
					printf("\nExtended!");
					sleep(2);
					break;
				}else if(strcmp(confirm,"NO")==0){
					printf("\nCancelling..");
					sleep(2);
					break;
				}
			}
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}else{
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Member.dat");
	rename("Dat/Tmp.dat","Dat/Member.dat");
}

void UpdateTelephoneMbr(){
	system("cls");
	fp = fopen("Dat/Member.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mbr,sizeof(mbr),1,fp)==1){
		if(strcmp(sNIK,mbr.NIK)==0){
			system("cls");
			DisplayMbrData(mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy,mbr.telephone);
			gotoxy(0,4);
			printf("               ");
			gotoxy(0,4);
			getteksnummin(mbr.telephone,11,13);
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}else{
			fwrite(&mbr,sizeof(mbr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Member.dat");
	rename("Dat/Tmp.dat","Dat/Member.dat");
}

void UpdateMenuMbr(){
	while(1){
		system("cls");
		UpdateDisplayMbr();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateFnameMbr();
		}else if(choose==2){
			UpdateLnameMbr();
		}else if(choose==3){
			UpdateExtendMbr();
		}else if(choose==4){
			UpdateTelephoneMbr();
		}else if(choose==5){
			break;
		}
	}	
}

void UpdateMbr(){
	while(1){
		system("cls");
		found = false;
		printf("Member's NIK\t: ");getteksnummin(sNIK,1,16);
		if(strcmp(sNIK,"0")==0){
			break;
		}else{
			fp = fopen("Dat/Member.dat","rb");
			while(fread(&mbr,sizeof(mbr),1,fp)==1){
				if(strcmp(sNIK,mbr.NIK)==0){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				UpdateMenuMbr();
			}else{
				printf("\nNIK Not Found.");
				getch();
			}	
		}	
	}
}

void DeleteMbr(){
	while(1){
		system("cls");
		found = false;
		printf("Member's NIK\t: ");getteksnummin(sNIK,1,16);
		if(strcmp(sNIK,"0")==0){
			break;
		}else{
			fp = fopen("Dat/Member.dat","rb");
			while(fread(&mbr,sizeof(mbr),1,fp)==1){
				if(strcmp(sNIK,mbr.NIK)==0){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Member.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&mbr,sizeof(mbr),1,fp)==1){
					if(strcmp(sNIK,mbr.NIK)==0){
						while(1){
							system("cls");
							DisplayMbrData(mbr.NIK,mbr.fname,mbr.lname,mbr.expd,mbr.expm,mbr.expy,mbr.telephone);
							printf("\nDelete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&mbr,sizeof(mbr),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&mbr,sizeof(mbr),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Member.dat");
				rename("Dat/Tmp.dat","Dat/Member.dat");
			}else{
				printf("\nNIK Not Found.");
				getch();
			}	
		}	
	}
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
				UpdateMbr();
			break;
			case 4:
				DeleteMbr();
			break;
			case 5:
				//main menu
			break;
		}
	}
}
