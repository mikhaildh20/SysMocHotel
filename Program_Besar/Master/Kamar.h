//Fungsi untuk membuat data kamar baru
void CreateKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat", "ab+"); // membuka atau membuat file biner untuk data kamar
	
	//Membaca data kamar terakhir untuk menentukan nomor kamar berikutnya
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
	//Menampilkan dan Menginput Informasi Kamar
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
	//input Informasi kamar (lantai & tipe)
	printf("\nFLOOR\t\t: ");getnummin(&kmr.lantai,1,1);
	
	//menetapkan harga kamar berdasarkan tipe kamar
	if(strcmp(kmr.tipe_kamar,"STANDARD")==0){
		kmr.harga = 100000;
	}else if(strcmp(kmr.tipe_kamar,"DOUBLE")==0){
		kmr.harga = 250000;
	}else if(strcmp(kmr.tipe_kamar,"SUITE")==0){
		kmr.harga = 400000;
	}else{
		kmr.harga = 600000;
	}
	kmr.status = 1; //menetapkan status kamar sebagai tersedia
	fwrite(&kmr,sizeof(kmr),1,fp); //menulis data kamar ke file
	fclose(fp);//menutup file
}
//Fungsi untuk Membaca data kamar
void ReadKmr(){
	system("cls"); //membersihkan layar konsol
	fp = fopen("Dat/Kamar.dat", "rb"); //membuka file biner untuk dibaca
	
	//memeriksa apakah file tersebut ada
	if(fp==NULL){
		printf("Belum ada Data");
		getch();
	}else{
		found = false;
		i=0;
		//membaca dab menampilkan data kamar samapai akhir
		while(!feof(fp)){
			fread(&kmr,sizeof(kmr),1,fp);
			if(!feof(fp)){
				//menampilkan informasi kamar
				gotoxy(0,i);
				printf("KMR%d",kmr.no_kamar);
				gotoxy(10,i);
				printf("%s",kmr.tipe_kamar);
				gotoxy(30,i);
				printf("%d",kmr.lantai);
				rupiah(kmr.harga,cvrRp);
				gotoxy(35,i);
				printf("Rp%s",cvrRp);
				
				//menampilkan status kamar
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
	fclose(fp); //menutup file
}
//Fungsi untuk menampilkan data kamar
void DisplayKmrData(int id, char tipe[], int harga, int lantai, int status){
	printf("KMR%d\n",id);
	printf("%s\n",tipe);
	rupiah(harga,cvrRp);
	printf("Rp%s\n",cvrRp);
	printf("%d\n",lantai);
	
	//menampilkan status kamar
	switch(status){
		case 0:
			strcpy(rStat,"UNAVAILABLE");
		break;
		case 1:
			strcpy(rStat,"AVAILABLE");
		break;
	}
	printf("%s",rStat);
}
//fungsi untuk menampilkan menu pembaruan data kamar
void UpdateDisplayKmr(){
	printf("[1]Room Type\n");
	printf("[2]Floor\n");
	printf("[3]Back\n");
}

//fungsi untuk memperbarui tipe kamar
void UpdateTypeKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	
	//melakukan perulangan melalui data kamar , memperbarui tipe, dan menulis ulang ke file sementara
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			while(1){
				system("cls");
				DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
				gotoxy(0,1);
				printf("                 ");
				gotoxy(0,1);
				getletter(kmr.tipe_kamar,15);
				strupr(kmr.tipe_kamar);
				//memvalidasi tipe kamar
				if(strcmp(kmr.tipe_kamar,"STANDARD")==0 || strcmp(kmr.tipe_kamar,"DOUBLE")==0 || strcmp(kmr.tipe_kamar,"SUITE")==0 || strcmp(kmr.tipe_kamar,"EXECUTIVE")==0){
					break;			
				}
			}
			//menetapkan harga kamar berdasarkan tipe kamar yang di perbarui
			if(strcmp(kmr.tipe_kamar,"STANDARD")==0){
				kmr.harga = 100000;
			}else if(strcmp(kmr.tipe_kamar,"DOUBLE")==0){
				kmr.harga = 250000;
			}else if(strcmp(kmr.tipe_kamar,"SUITE")==0){
				kmr.harga = 400000;
			}else{
				kmr.harga = 600000;
			}
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}else{
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}
	}	
	fclose(fp);
	fclose(tmp);
	remove("Dat/Kamar.dat");
	rename("Dat/Tmp.dat","Dat/Kamar.dat");
}
//fungsi untuk memperbarui lantai kamar
void UpdateFloorKmr(){
	system("cls");
	fp = fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat", "wb");
	
	//melakukan perulangan melalui data kamar
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		if(search==kmr.no_kamar){
			//menampilkan informasi kamar yang akan diperbarui
			system("cls");
			DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
			//input untuk memperbarui lantai kamar
			gotoxy(0,3);
			printf("                 ");
			gotoxy(0,3);
			getnummin(&kmr.lantai,1,1);
			//menulis data yang sudah diperbarui ke file sementara
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}else{
			//menulis data kamar yang tidak diubah ke file sementara
			fwrite(&kmr,sizeof(kmr),1,tmp);
		}
	}
	//menutup file	
	fclose(fp);
	fclose(tmp);
	//menghapus file kamar lama dan mengganti dengan file sementara
	remove("Dat/Kamar.dat");
	rename("Dat/Tmp.dat","Dat/Kamar.dat");
}

void UpdateMenuKmr(){
	while(1){
		system("cls");
		//menampilkan pilihan pembaruan
		UpdateDisplayKmr();
		printf("Choose: ");getnummin(&choose,1,1);
		//pembaruan type kamar
		if(choose==1){
			UpdateTypeKmr();
		//pembaruan lantai kamar	
		}else if(choose==2){
			UpdateFloorKmr();
		}else if(choose==3){
			break;
		}
	}	
}

//fungsi untuk memperbarui kamar
void UpdateKmr(){
	while(1){
		system("cls");
		found = false;
		//meminta id kamar yang akan di perbarui
		printf("Room's ID\t: KMR");getnummin(&search,1,3);
		if(search==0){
			break;
		}else{
			//membuka file
			fp = fopen("Dat/Kamar.dat","rb");
			//mencari kamar berdasarkan id
			while(fread(&kmr,sizeof(kmr),1,fp)==1){
				if(search==kmr.no_kamar){
					found = true;
					break;
				}
			}
			fclose(fp);
			//jika kamar di temukan tampilkan menu pembaruan
			if(found){
				UpdateMenuKmr();
			}else{
				//menampilkan jika data tidak ada
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}
//fungsi untuk menghapus data kamar
void DeleteKmr(){
	while(1){
		system("cls");
		found = false;
		//meminta input id kamar yang akan dihapus
		printf("Room's ID\t: KMR");getnummin(&search,1,3);   
		if(search==0){
			break;
		}else{
			fp = fopen("Dat/Kamar.dat","rb");
			//mencari kamar berdasarkan id kamar
			while(fread(&kmr,sizeof(kmr),1,fp)==1){
				if(search==kmr.no_kamar){
					found = true;
					break;
				}
			}
			fclose(fp);
			if(found){
				fp = fopen("Dat/Kamar.dat","rb");
				tmp = fopen("Dat/Tmp.dat","wb");
				//menampilkan informasi kamar
				while(fread(&kmr,sizeof(kmr),1,fp)==1){
					if(search==kmr.no_kamar){
						while(1){
							system("cls");
							DisplayKmrData(kmr.no_kamar,kmr.tipe_kamar,kmr.harga,kmr.lantai,kmr.status);
							//meminta konfirmasi penghapusan
							printf("\nDelete?[YES/NO]\n");getletter(confirm,3);strupr(confirm);
							//jika konfirmasi "YES" kamar akan dihapus
							if(strcmp(confirm,"YES")==0){
								printf("\nDeleting..");sleep(2);
								break;
							//jika konfirmasi "NO" penghapusan kamar di batalkan
							}else if(strcmp(confirm,"NO")==0){
								printf("\nCanceling..");sleep(2);
								fwrite(&kmr,sizeof(kmr),1,tmp);
								break;	
							}
						}
					}else{
						fwrite(&kmr,sizeof(kmr),1,tmp);
					}
				}
				fclose(fp);
				fclose(tmp);
				remove("Dat/Kamar.dat");
				rename("Dat/Tmp.dat","Dat/Kamar.dat");
			}else{
				printf("\nID Not Found.");
				getch();
			}	
		}	
	}
}

void MenuKamar(){
	while(1){
		system("cls");
		//menampilkan menu utama
		MainMen();
		getnummin(&choose,1,1);
		switch(choose){
			//pilihan untuk membuat data kamar
			case 1:
			 	CreateKmr();
			break;
			//pilihan untuk membaca dan menampilkan data kamar
			case 2:
				ReadKmr();
			break;
			//pilihan untuk memperbarui data kamar
			case 3:
				UpdateKmr();
			break;
			//pilihan untuk menghapus data kamar
				DeleteKmr();
			break;
			case 5:
				
			break;
		}
	}
}
