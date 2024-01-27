void getAvailableFnB(){
	//validasi menu yang tersedia
	fp = fopen("Dat/Menu.dat","rb");
	i=0;
	while(fread(&mnu,sizeof(mnu),1,fp)==1){
		if(mnu.status==1){
			strcpy(vtr[i].nama,mnu.nama);
			vtr[i].harga = mnu.harga;
		}
		i++;
	}
	fclose(fp);
	
	//validasi paket yang tersedia
	fp = fopen("Dat/Paket.dat","rb");
	while(fread(&pkt,sizeof(pkt),1,fp)==1){
		if(pkt.status==1){
			strcpy(vtr[i].nama,pkt.nama);
			vtr[i].harga = pkt.harga;
		}
		i++;
	}
	fclose(fp);
}

void Tresto(){
	int bayar,kembali;
	//pesanan selanjutnya
	next:	
	remove("Dat/Tmp.dat");
	remove("Dat/fpayment.dat");
	
	//mengambil data menu yang tersedia
	getAvailableFnB();
	
	
	//membuka file transaksi untuk menghitung id
	fp = fopen("Dat/Tresto.dat","rb");
	if(fread(&trr,sizeof(trr),1,fp)==0){
		trr.id = 1;
	}else{
		while(!feof(fp)){
		fread(&trr,sizeof(trr),1,fp);
			if(feof(fp)){
				trr.id+=1;
			}
		}
	}
	fclose(fp);
	
	system("cls");
	tmp = fopen("Dat/Tmp.dat","wb");
	//checkpoint untuk menu selanjutnya
	again:
	printf("ID\t: TRR%03d\n",trr.id);
	
	//checkpoint bila menu yang diinput tidak tersedia
	invalid:
		
	found = false;
	printf("Nama\t: ");getletter(trr.item,20);
	strupr(trr.item);
	//looping validasi menu yang tersedia
	for(i=0;vtr[i].harga!=0;i++){
		if(strcmp(trr.item,vtr[i].nama)==0){
			found = true;
			trr.price = vtr[i].harga;
			break;
		}
	}
	//indicator menu tidak tersedia
	if(!found){
		printf("Menu tidak tersedia!");
		sleep(1);
		system("cls");
		printf("ID\t: TRR%03d\n",trr.id);
		goto invalid;
	}
	printf("\nQty\t: ");getnummin(&trr.qty,1,2);
	trr.price*=trr.qty;
	
	fwrite(&trr,sizeof(trr),1,tmp);
	
	printf("\nLagi??[0]no[1]yes: ");getnummin(&choose,1,1);
	while(1){
		if(choose ==1){
			goto again;
		}else if(choose == 0){
			fclose(tmp);
			break;	
		}	
	}
	
	
	tPayment = 0;
	tmp = fopen("Dat/Tmp.dat","rb");
	while(fread(&trr,sizeof(trr),1,tmp)==1){
		tPayment+=trr.price;
	}
	fclose(tmp);		
	
	fp1 = fopen("Dat/Tmp.dat","rb");
	tmp = fopen("Dat/fpayment.dat","wb");
	while(fread(&trr,sizeof(trr),1,fp1)==1){
		strcpy(trr.nama_karyawan,"Imam");
		trr.total_price = tPayment;
		trr.day = 27;
		trr.month = 1;
		trr.year = 2024;
		fwrite(&trr,sizeof(trr),1,tmp);
	}
	fclose(tmp);
	fclose(fp1);
	
	fp = fopen("Dat/Tmp.dat","rb");
	printf("Menu\t\tQty\t\tHarga\n");
	while(fread(&trr,sizeof(trr),1,fp)==1){
		printf("%s\t\t%d\t\t%d\n",trr.item,trr.qty,trr.price);
	}
	fclose(fp);	

	transaksi:
	printf("Total Pembayaran\t: Rp%d\n",tPayment);
	printf("Nominal Bayar\t: ");scanf("%d",&bayar);
	if(bayar==0){
		printf("Transaksi dibatalkan");
		getch();
		goto next;
	}else if(bayar<tPayment){
		printf("Uang kurang");
		goto transaksi;
	}else if(bayar==tPayment){
		printf("Pembayaran berhasil");
	}else if(bayar>tPayment){
		bayar-=tPayment;
		printf("Kembalian\t: %d\nPembayaran Berhasil",bayar);
	}
	getch();
	
	fp = fopen("Dat/Tresto.dat","ab");
	tmp = fopen("Dat/fpayment.dat","rb");
	while(fread(&trr,sizeof(trr),1,tmp)==1){
		fwrite(&trr,sizeof(trr),1,fp);
	}
	fclose(tmp);
	fclose(fp);
	goto next;
}

void ReadTresto(){
	//int prev;
	fp = fopen("Dat/Tresto.dat","rb");
	while(fread(&trr,sizeof(trr),1,fp)==1){
		printf("%03d\t%s\t%d\t%02d/%02d/%d\t%s %d\t%d\t%d\n",trr.id,trr.nama_karyawan,trr.id_member,trr.day,trr.month,trr.year,trr.item,trr.qty,trr.price,trr.total_price);
	}
	fclose(fp);
}
