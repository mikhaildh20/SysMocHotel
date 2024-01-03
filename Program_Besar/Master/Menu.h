//Fungsi untuk membuat menu baru
void CreateMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat", "ab+");
	//memeriksa apakah file kosong atau tidak
	if(fread(&mnu,sizeof(mnu),1,fp)==0){
		//jika kosong , atur id menu ke -1
		mnu.id_menu = 1;
	}else{
		//jika tidak kosong , temukan ID menu terakhir dan tambahkan dengan 1
		while(!feof(fp)){
			fread(&mnu,sizeof(mnu),1,fp);
			if(feof(fp)){
				mnu.id_menu+=1;
			}
		}
	}
	//tampilkan dan input informasi menu
	printf("MENU ID\t\t: MNU%d\n",mnu.id_menu);
	printf("FOOD NAME\t: ");getletter(mnu.nama,15);
	strupr(mnu.nama);
	//input kategori dan pastikan kategori adalah "MAKANAN" atau "MINUMAN"
	while(1){
		gotoxy(18,2);
		printf("              ");
		gotoxy(0,2);
		printf("CATEGORY\t: ");getletter(mnu.category,10);
		strupr(mnu.category);
		if(strcmp(mnu.category,"FOOD")==0 || strcmp(mnu.category,"DRINK")==0){
			break;
		}
	}
	//input validasi harga
	printf("\nPRICE\t\t: Rp");getRp(&mnu.harga,4,8,21,3);
	//inpu informasi menu ke file
	fwrite(&mnu,sizeof(mnu),1,fp);
	fclose(fp);
}
//fungsi untuk membaca menu
void ReadMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat", "rb");
	//periksa apakah file ada atau tidak
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		//baca data menu dan tampilkan pada layar
		while(!feof(fp)){
			fread(&mnu,sizeof(mnu),1,fp);
			if(!feof(fp)){
				gotoxy(0,i);
				printf("MNU%d",mnu.id_menu);
				gotoxy(10,i);
				printf("%s",mnu.nama);
				gotoxy(30,i);
				printf("%s",mnu.category);
				rupiah(mnu.harga,cvrRp);
				gotoxy(45,i);
				printf("Rp%s",cvrRp);
				i++;
			}
		}
		getch();
	}
	fclose(fp);
}
//fungsi untuk menampilkan data menu
void DisplayMnuData(int id, char nama[],char category[], int harga){
	printf("MNU%d\n",id);
	printf("%s\n",nama);
	printf("%s\n",category);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
}
//fungsi untuk memperbarui display menu
void UpdateDisplayMnu(){
	printf("[1]Menu Name\n");
	printf("[2]Category\n");
	printf("[3]Price\n");
	printf("[4]Back\n");
}
//fungsi untuk memperbarui nama menu
void UpdateNameMnu(){
	system("cls");
	//buka file menu.dat dalam mode baca biner
	fp = fopen("Dat/Menu.dat","rb");
	//buka file sementara untuk menulis hasil pembaruan
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		//temukan menu yang akan di perbarui
		if(search==mnu.id_menu){
			system("cls");
			//tampilkan data menu dan minta input nama baru
			DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
			gotoxy(0,1);
			printf("                 ");
			gotoxy(0,1);
			getletter(mnu.nama,15);
			strupr(mnu.nama);
			//tulis hasil pembaruan ke file sementara
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			//salin menu tanpa perubahan ke file sementara
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	//hapus file asli dan ganti dengan file sementara
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}
//fungsi unruk memperbarui category menu
void UpdateCategoryMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		//temukan menu yang akan diperbarui
		if(search==mnu.id_menu){
			while(1){
				//tampilkan data menu dan minta input kategori baru
				system("cls");
				DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
				gotoxy(0,2);
				printf("                 ");
				gotoxy(0,2);
				getletter(mnu.category,10);
				strupr(mnu.category);
				//pastikan kategori adalah "MAKANAN" atau "MINUMAN"
				if(strcmp(mnu.category,"FOOD")==0 || strcmp(mnu.category,"DRINK")==0){
					break;
				}	
			}
			//tulis menu pembaruan ke file sementara
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	//hapus file asli dan ganti dengan file sementara
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}
//fungsi untuk memperbarui harga menu
void UpdatePriceMnu(){
	system("cls");
	fp = fopen("Dat/Menu.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		//temukan menu yang akan diperbarui
		if(search==mnu.id_menu){
			system("cls");
			//tampilkan data menu dan minta input harga baru
			DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
			gotoxy(0,3);
			printf("                 ");
			gotoxy(0,3);
			printf("Rp ");getRp(&mnu.harga,4,8,3,3);
			//tulis hasil pembaruan ke file sementara
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}else{
			fwrite(&mnu,sizeof(mnu),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	//hapus file asli dan ganti dengan file sementara
	remove("Dat/Menu.dat");
	rename("Dat/Tmp.dat","Dat/Menu.dat");
}
//fungsi untuk memperbarui menu update menu
void UpdateMenuMnu(){
	while(1){
		system("cls");
		//tampilkan opsi pembaruan menu
		UpdateDisplayMnu();
		printf("Choose: ");getnummin(&choose,1,1);
		if(choose==1){
			UpdateNameMnu();
		}else if(choose==2){
			UpdateCategoryMnu();
		}else if(choose==3){
			UpdatePriceMnu();
		}else if(choose==4){
			break;
		}
	}	
}
//fungsi untuk memperbarui menu
void UpdateMnu(){
	while(1){
		system("cls");
		found = false;
		//meminta input ID menu yang akan di perbarui
		printf("Menu's ID\t: MNU");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Menu.dat","rb");
			//cari ID menu yang sesuai
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				//jika ID ditemukan, lanjutkan dengan pembaruan menu
				UpdateMenuMnu();
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}
//fungsi untuk menghapus menu
void DeleteMnu(){
	while(1){
		system("cls");
		found = false;
		//meminta input menu ID yang akan dihapus
		printf("Menu's ID\t: MNU");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Menu.dat","rb");
			//cari ID menu yang sesuai
			while(fread(&mnu,sizeof(mnu),1,fp)==1){
				if(search==mnu.id_menu){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				//jika ID ditemukan , konfirmasi penhapusan
				fp = fopen("Dat/Menu.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				while(fread(&mnu,sizeof(mnu),1,fp)==1){
					if(search==mnu.id_menu){
						while(1){
							//tampilkan data menu dan minta konfirmasi pengguna
							system("cls");
							DisplayMnuData(mnu.id_menu,mnu.nama,mnu.category,mnu.harga);
							printf("Delete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&mnu,sizeof(mnu),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&mnu,sizeof(mnu),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				//hapus file asli dan ganti dengan file sementara
				remove("Dat/Menu.dat");
				rename("Dat/Tmp.dat","Dat/Menu.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}
//fungsi untuk menampilkan pilihan menu
void MenuMenu(){
	while(1){
		system("cls");
		//tampilkan menu utama
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			case 1:
			 	CreateMnu();
			break;
			case 2:
				ReadMnu();
			break;
			case 3:
				UpdateMnu();
			break;
			case 4:
				DeleteMnu();
			break;
			case 5:
	
			break;
		}
	}
}
