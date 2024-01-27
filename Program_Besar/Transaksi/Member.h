void getUnique(){
	//mengambil nik dan telepon untuk cek validasi saat register
	fp = fopen("Dat/Member.dat","rb");
	i=0;
	vtm[0].term = 1;
	while(fread(&trm,sizeof(trm),1,fp)==1){
		strcpy(vtm[i].nik,trm.nik);
		strcpy(vtm[i].telp,trm.telp);
		vtm[i].term++;
		i++;
	}
	fclose(fp);
}

void Tmember(){
	//transaksi selanjutnya
	next:
	
	//import nik & no telp yang terdaftar untuk validasi
	getUnique();
	
	fp = fopen("Dat/Member.dat","ab+");
	if(fread(&trm,sizeof(trm),1,fp)==0){
		trm.id = 1;
	}else{
		while(!feof(fp)){
		fread(&trm,sizeof(trm),1,fp);
			if(feof(fp)){
				trm.id+=1;
			}
		}
	}
	
	printf("ID Member\t: TRM%03d\n",trm.id);
	
	invalidnik:
	
	found = false;	
	printf("NIK\t: ");fflush(stdin);getteksnummin(trm.nik,16,16);
	for(i=0;vtm[i].term!=0;i++){
		if(strcmp(trm.nik,vtm[i].nik)==0){
			found = true;
			break;
		}
	}
	
	if(found){
		printf("\nNIK sudah terdaftar\n");
		goto invalidnik;
	}
	
	invalidtelp:
	
	found = false;
	fflush(stdin);
	printf("\nTelp\t: ");getteksnummin(trm.telp,11,13);
	for(i=0;vtm[i].term!=0;i++){
		if(strcmp(trm.telp,vtm[i].telp)==0){
			found = true;
			break;
		}
	}
	
	if(found){
		printf("\nNomor telpon sudah terdaftar\n");
		goto invalidtelp;
	}
	
	printf("\nNama\t: ");fflush(stdin);getteks(trm.nama,10);
	strupr(trm.nama);
	
	strcpy(trm.nama_karyawan,"Imam");
	getTime(&trm.jdate,&trm.jmonth,&trm.jyear);
	getTime(&trm.xdate,&trm.xmonth,&trm.xyear);
	trm.xyear+=1;
	trm.status=1;
	
	tPayment = 100000;
	trm.total_harga = tPayment;
	
	transaksi:
	
	printf("\nTotal Pembayaran: %d",tPayment);
	printf("\nBayar\t: ");scanf("%d",&bayar);
	if(bayar==0){
		printf("Transaksi dibatalkan");
		getch();
		goto invalidnik;
	}else if(bayar<tPayment){
		printf("Uang Kurang");
		goto transaksi;
	}else if(bayar==tPayment){
		printf("Pembayaran Berhasil!");
	}else if(bayar>tPayment){
		bayar-=tPayment;
		printf("Kembalian\t: %d\n",bayar);
		printf("Pembayaran Berhasil!");
	}
	
	fwrite(&trm,sizeof(trm),1,fp);
	
	fclose(fp);
	goto next;
}

void EXmember(){
	goback:
	tPayment = 50000;
	getUnique();
	
	invalid:
	
	found = false;
	printf("ID Member\t: TRM");getnummin(&search,1,3);
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&trm,sizeof(trm),1,fp)==1){
		if(search==trm.id){
			found = true;
			break;
		}
	}
	fclose(fp);
	
	if(found){
		updconf = false;
		fp = fopen("Dat/Member.dat","rb");
		tmp = fopen("Dat/Tmp.dat","wb");
		while(fread(&trm,sizeof(trm),1,fp)==1){
			if(search==trm.id){
				strcpy(trm.nama_karyawan,"Zhillan");
				printf("\nLama Extend\t: ");getnummin(&lama,1,1);
				trm.xyear+=lama;
				if(trm.status==0){
					trm.status = 1;
				}
				tPayment*=lama;
				trm.total_harga+=tPayment;
				kurang:
				printf("\nTotal Bayar\t: %d\n",tPayment);
				printf("Pembayaran\t: ");scanf("%d",&bayar);
				if(bayar==0){
					printf("Transaksi dibatalkan");
					sleep(1);
					break;
				}else if(bayar<tPayment){
					printf("Uang Kurang");
					goto kurang;
				}else if(bayar==tPayment){
					printf("Pembayaran Berhasil!");
					sleep(1);
					updconf = true;
				}else if(bayar>tPayment){
					updconf = true;
					bayar-=tPayment;
					printf("Kembali\t: %d",bayar);
					sleep(1);
				}
				fwrite(&trm,sizeof(trm),1,tmp);
			}else{
				fwrite(&trm,sizeof(trm),1,tmp);
			}
		}
		fclose(tmp);
		fclose(fp);
		if(updconf){
			remove("Dat/Member.dat");
			rename("Dat/Tmp.dat","Dat/Member.dat");	
		}
	}else{
		printf("\nID Tidak ada\n");
	}
	goto goback;
}

void ReadTmember(){
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&trm,sizeof(trm),1,fp)==1){
		printf("%d\t%s\t%s\t%02d/%02d/%d\t%02d/%02d/%d\t%s\t%d\t%d\t%s\n",trm.id,trm.nama_karyawan,trm.nama,trm.jdate,trm.jmonth,trm.jyear,trm.xdate,trm.xmonth,trm.xyear,trm.telp,trm.total_harga,trm.status,trm.nik);
	}
	fclose(fp);
}
