void getRoom(){
	//mengambil beberapa detail kamar untuk keperluan validasi
	fp = fopen("Dat/Kamar.dat","rb");
	i=0;
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		vth[i].id=kmr.no_kamar;
		strcpy(vth[i].nama,kmr.tipe_kamar);
		strcpy(vth[i].type,kmr.tipe_kamar);
		vth[i].harga=kmr.harga;
		i++;
	}
	fclose(fp);
}

void getFacility(){
	//mengambil beberapa detail fasilitas untuk keperluan validasi
	fp = fopen("Dat/Fasilitas.dat","rb");
	i=0;
	while(fread(&fsl,sizeof(fsl),1,fp)==1){
		vth[i].id=fsl.id_fasilitas;
		strcpy(vth[i].nama,fsl.nama);
		strcpy(vth[i].type,fsl.nama);
		vth[i].harga=fsl.harga;
		i++;
	}
	fclose(fp);
}

TransaksiHotel trTemp;
TransaksiHotelf trTempf;
DateTime TglPesan,TglKamar,TglFasil;

void Troom(){
	next:
		
	getRoom();
		
	remove("Dat/Tmp.dat");
	
	fp = fopen("Dat/HotelRoom.dat","rb");
	if(fread(&trh,sizeof(trh),1,fp)==0){
		trh.id = 1;
	}else{
		while(!feof(fp)){
		fread(&trh,sizeof(trh),1,fp);
			if(feof(fp)){
				trh.id+=1;
			}
		}
	}
	fclose(fp);
	
	//1 ID
	printf("ID Transaksi\t: TRK%03d\n",trh.id);
	strcpy(trh.nama_karyawan,"Zhillan");
	
	invalidDate:
	
	//2 Checkin
	printf("Tgl Checkin\t: ");
	getnummin(&trh.Checkin.tgl,1,2);printf(" - ");
	getnummin(&trh.Checkin.bulan,1,2);printf(" - ");
	getnummin(&trh.Checkin.tahun,4,4);
	
	DateTimeNow(&Now);
	
	if(trh.Checkin.tahun<Now.tahun || trh.Checkin.tahun == Now.tahun && trh.Checkin.bulan < Now.bulan || trh.Checkin.tahun == Now.tahun && trh.Checkin.bulan == Now.bulan && trh.Checkin.tgl < Now.tgl || !dateValid(trh.Checkin)){
		printf("\nTanggal tidak valid!\n");
		goto invalidDate;
	}
	
	//3 lama
	printf("\nLama sewa\t: ");getnummin(&trh.LamaSewa,1,2);
	
	//4 Checkout
	addDays(trh.Checkin,&trh.Checkout,trh.LamaSewa);
	printf("\nTgl Checkout\t: %02d - %02d - %d\n",trh.Checkout.tgl,trh.Checkout.bulan,trh.Checkout.tahun);
	
	invalidRoom:
	
	//5 Kamar
	found = false;
	printf("\nID Kamar\t: KMR");getnummin(&trh.no_kamar,1,3);
	for(i=0;vth[i].id!=0;i++){
		if(trh.no_kamar==vth[i].id){
			found = true;
			//6 type
			strcpy(trh.type,vth[i].type);
			//7total harga
			trh.sisa_harga = vth[i].harga*trh.LamaSewa;
			break;
		}
	}
	
	//8 sisa harga
	
	
	if(!found){
		printf("\nRoom ID not found.\n");
		sleep(1);
		goto invalidRoom;
	}else{
		fp = fopen("Dat/HotelRoom.dat","rb");
		while(fread(&trTemp,sizeof(trTemp),1,fp)==1){
			if(trTemp.no_kamar==trh.no_kamar && strcmp(trTemp.status,"RESERVED")==0 || strcmp(trTemp.status,"CHECKIN")==0){
				for(i=0;i<trh.LamaSewa;i++){
					addDays(trh.Checkin,&TglPesan,i);
					for(j=0;j<trTemp.LamaSewa;j++){
						addDays(trTemp.Checkin,&TglKamar,j);
						if(TglPesan.tgl==TglKamar.tgl && TglPesan.bulan==TglKamar.bulan && TglPesan.tahun==TglKamar.tahun){
							printf("\nKamar tidak tersedia\n");
							printf("[1]Ganti Tanggal [2]Ganti Kamar? \n");
							while(1){
								printf("pilih: ");scanf("%d",&choose);
								if(choose==1){
									goto invalidDate;
								}else if(choose==2){
									goto invalidRoom;
								}
							}
						}
					}
				}
			}
		}
		fclose(fp);
	}
	
	//9 NIK
	found = false;
	printf("\nNIK\t: ");getteksnummin(trh.NIK,16,16);
	
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&trm,sizeof(trm),1,fp)==1){
		if(strcmp(trh.NIK,trm.nik)==0){
			found = true;
			//10 NAMA
			strcpy(trh.nama,trm.nama);
			break;
		}
	}
	fclose(fp);
	
	if(!found){
		//10 NAMA non Member
		printf("\nNama\t: ");getletter(trh.nama,15);
	}else{
		printf("\nNama\t: %s",trh.nama);
		discount = (trh.sisa_harga*15)/100;
		trh.sisa_harga-=discount;
	}
	
	trh.total_harga = trh.sisa_harga;
	
	downpay = (trh.sisa_harga*10)/100;
	printf("\nTotal Harga\t: %d",trh.sisa_harga);
	printf("\nMinimum DP\t: %d",downpay);
	
	bayar:
	//11 dp
	printf("\nPembayaran\t: ");scanf("%d",&trh.dp);
	if(trh.dp<downpay){
		printf("\nUang kurang.");
		sleep(1);
		goto bayar;
	}else if(trh.dp==downpay || trh.dp>downpay && trh.dp<trh.sisa_harga){
		printf("\nPembayaran berhasil\n");
		trh.sisa_harga-=trh.dp;
		strcpy(trh.pelunasan,"Belum Lunas");
	}else if(trh.dp>=trh.sisa_harga){
		kembali = trh.dp;
		trh.dp = trh.sisa_harga;
		kembali-=trh.sisa_harga;
		trh.sisa_harga = 0;
		printf("\nPembayaran berhasil\n");
		printf("\nKembali\t: %d",kembali);
		strcpy(trh.pelunasan,"Lunas");
	}
	sleep(2);
	//12 pelunasan
	
	//13 status
	strcpy(trh.status,"RESERVED");
	
	fp = fopen("Dat/HotelRoom.dat","ab+");
	fwrite(&trh,sizeof(trh),1,fp);
	fclose(fp);
	goto next;
}

Tfacil(){
	next:
		
	getFacility();
		
	remove("Dat/Tmp.dat");
	
	fp = fopen("Dat/HotelFacility.dat","rb");
	if(fread(&trhf,sizeof(trhf),1,fp)==0){
		trhf.id = 1;
	}else{
		while(!feof(fp)){
		fread(&trhf,sizeof(trhf),1,fp);
			if(feof(fp)){
				trhf.id+=1;
			}
		}
	}
	fclose(fp);
	
	//1 ID
	printf("ID Transaksi\t: TRF%03d\n",trhf.id);
	strcpy(trhf.nama_karyawan,"Zhillan");
	
	invalidDate:
	
	//2 Checkin
	printf("Tgl Checkin\t: ");
	getnummin(&trhf.Checkin.tgl,1,2);printf(" - ");
	getnummin(&trhf.Checkin.bulan,1,2);printf(" - ");
	getnummin(&trhf.Checkin.tahun,4,4);
	
	DateTimeNow(&Now);
	
	if(trhf.Checkin.tahun<Now.tahun || trhf.Checkin.tahun == Now.tahun && trhf.Checkin.bulan < Now.bulan || trhf.Checkin.tahun == Now.tahun && trhf.Checkin.bulan == Now.bulan && trhf.Checkin.tgl < Now.tgl || !dateValid(trhf.Checkin)){
		printf("\nTanggal tidak valid!\n");
		goto invalidDate;
	}
	
	//3 lama
	printf("\nLama sewa\t: ");getnummin(&trhf.LamaSewa,1,2);
	
	//4 Checkout
	addDays(trhf.Checkin,&trhf.Checkout,trhf.LamaSewa);
	printf("\nTgl Checkout\t: %02d - %02d - %d\n",trhf.Checkout.tgl,trhf.Checkout.bulan,trhf.Checkout.tahun);
	
	invalidFacility:
	
	//5 Fasilitas
	found = false;
	printf("\nID Fasilitas\t: FCL");getnummin(&trhf.id_fasilitas,1,3);
	for(i=0;vth[i].id!=0;i++){
		if(trhf.id_fasilitas==vth[i].id){
			found = true;
			//6 type
			strcpy(trhf.type,vth[i].type);
			//7sisa harga
			trhf.sisa_harga = vth[i].harga*trhf.LamaSewa;
			break;
		}
	}
	
	//8 total harga
	
	
	if(!found){
		printf("\nRoom ID not found.\n");
		sleep(1);
		goto invalidFacility;
	}else{
		fp = fopen("Dat/HotelFacility.dat","rb");
		while(fread(&trTempf,sizeof(trTempf),1,fp)==1){
			if(trTempf.id_fasilitas==trhf.id_fasilitas && strcmp(trTempf.status,"RESERVED")==0 || strcmp(trTempf.status,"CHECKIN")==0){
				for(i=0;i<trhf.LamaSewa;i++){
					addDays(trhf.Checkin,&TglPesan,i);
					for(j=0;j<trTempf.LamaSewa;j++){
						addDays(trTempf.Checkin,&TglFasil,j);
						if(TglPesan.tgl==TglFasil.tgl && TglPesan.bulan==TglFasil.bulan && TglPesan.tahun==TglFasil.tahun){
							printf("\nFasilitas tidak tersedia\n");
							printf("[1]Ganti Tanggal [2]Ganti Fasilitas? \n");
							while(1){
								printf("pilih: ");scanf("%d",&choose);
								if(choose==1){
									goto invalidDate;
								}else if(choose==2){
									goto invalidFacility;
								}
							}
						}
					}
				}
			}
		}
		fclose(fp);
	}
	
	//9 NIK
	found = false;
	printf("\nNIK\t: ");getteksnummin(trhf.NIK,16,16);
	
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&trm,sizeof(trm),1,fp)==1){
		if(strcmp(trhf.NIK,trm.nik)==0){
			found = true;
			//10 NAMA
			strcpy(trhf.nama,trm.nama);
			break;
		}
	}
	fclose(fp);
	
	if(!found){
		//10 NAMA non Member
		printf("\nNama\t: ");getletter(trhf.nama,15);
	}else{
		printf("\nNama\t: %s",trhf.nama);
		discount = (trhf.sisa_harga*15)/100;
		trhf.sisa_harga-=discount;
	}
	
	trhf.total_harga = trhf.sisa_harga;
	
	downpay = (trhf.sisa_harga*10)/100;
	printf("\nTotal Harga\t: %d",trhf.sisa_harga);
	printf("\nMinimum DP\t: %d",downpay);
	
	bayar:
	//11 dp
	printf("\nPembayaran\t: ");scanf("%d",&trhf.dp);
	if(trhf.dp<downpay){
		printf("\nUang kurang.");
		sleep(1);
		goto bayar;
	}else if(trhf.dp==downpay || trhf.dp>downpay && trhf.dp<trhf.sisa_harga){
		printf("\nPembayaran berhasil\n");
		trhf.sisa_harga-=trhf.dp;
		strcpy(trhf.pelunasan,"Belum Lunas");
	}else if(trhf.dp>=trhf.sisa_harga){
		kembali = trhf.dp;
		trhf.dp = trhf.sisa_harga;
		kembali-=trhf.sisa_harga;
		trhf.sisa_harga = 0;
		printf("\nPembayaran berhasil\n");
		printf("\nKembali\t: %d",kembali);
		strcpy(trh.pelunasan,"Lunas");
	}
	sleep(2);
	//12 pelunasan
	
	//13 status
	strcpy(trhf.status,"RESERVED");
	
	fp = fopen("Dat/HotelFacility.dat","ab+");
	fwrite(&trhf,sizeof(trhf),1,fp);
	fclose(fp);
	goto next;
}

void ReadTroom(){
	fp = fopen("Dat/HotelRoom.dat","rb");
	while(fread(&trh,sizeof(trh),1,fp)==1){
		printf("TRK%03d\t%s\tKMR%03d\t%s\t%s\t%02d/%02d/%d\t%s\t%d\tDND%03d\t%d\t%d\t%d\t%s\t%s\n",trh.id,trh.nama_karyawan,trh.no_kamar,trh.NIK,trh.nama,trh.Checkin.tgl,trh.Checkin.bulan,trh.Checkin.tahun,trh.type,trh.LamaSewa,trh.denda,trh.dp,trh.sisa_harga,trh.total_harga,trh.status,trh.pelunasan);
	}
	fclose(fp);
}

void ReadTfacil(){
	fp = fopen("Dat/HotelFacility.dat","rb");
	while(fread(&trhf,sizeof(trhf),1,fp)==1){
		printf("TRK%03d\t%s\tFCL%03d\t%s\t%s\t%02d/%02d/%d\t%s\t%d\tDND%03d\t%d\t%d\t%d\t%s\t%s\n",trhf.id,trhf.nama_karyawan,trhf.id_fasilitas,trhf.NIK,trhf.nama,trhf.Checkin.tgl,trhf.Checkin.bulan,trhf.Checkin.tahun,trhf.type,trhf.LamaSewa,trhf.denda,trhf.dp,trhf.sisa_harga,trhf.total_harga,trhf.status,trhf.pelunasan);
	}
	fclose(fp);
}

void CheckinRoom(){
	goback:
	
	found = false;	
	printf("\nID Transaksi: TRK");getnummin(&search,1,3);
	fp = fopen("Dat/HotelRoom.dat","rb");
	while(fread(&trh,sizeof(trh),1,fp)==1){
		if(search==trh.id && strcmp(trh.status,"RESERVED")==0 || search==trh.id && strcmp(trh.status,"CHECKOUT")==0 || search==trh.id && strcmp(trh.status,"CHECKIN")==0){
			found = true;
			break;
		}
	}
	fclose(fp);
	
	DateTimeNow(&Now);
	
	if(!found){
		printf("\nID Transaksi tidak ada");
		goto goback;
	}else if(strcmp(trh.status,"CHECKOUT")==0 || strcmp(trh.status,"CHECKIN")==0){
		printf("\nTransaksi sudah dilakukan");
		goto goback;
	}else if(strcmp(trh.status,"BATAL")==0){
		printf("\nTransaksi telah batal");
		goto goback;
	}else if(trh.Checkin.tahun==Now.tahun && trh.Checkin.bulan==Now.bulan && trh.Checkin.tgl==Now.tgl){
		fp = fopen("Dat/HotelRoom.dat","rb");
		tmp = fopen("Dat/Tmp.dat","wb");
		while(fread(&trh,sizeof(trh),1,fp)==1){
			if(search==trh.id){
				DateTimeNow(&trh.CustIn);
				printf("\nCheckin dilakukan pada %02d:%02d:%02d WIB %02d/%02d/%d",trh.CustIn.hour,trh.CustIn.min,trh.CustIn.sec,trh.CustIn.tgl,trh.CustIn.bulan,trh.CustIn.tahun);
				strcpy(trh.status,"CHECKIN");
				fwrite(&trh,sizeof(trh),1,tmp);
			}else{
				fwrite(&trh,sizeof(trh),1,tmp);
			}
		}
		fclose(tmp);
		fclose(fp);
		remove("Dat/HotelRoom.dat");
		rename("Dat/Tmp.dat","Dat/HotelRoom.dat");	
		goto goback;
	}else{
		printf("\nHarap Checkin sesuai tanggal yang ditentukan!");
		goto goback;
	}	
}

void CheckinFacility(){
	goback:
	
	found = false;	
	printf("\nID Transaksi: TRF");getnummin(&search,1,3);
	fp = fopen("Dat/HotelFacility.dat","rb");
	while(fread(&trhf,sizeof(trhf),1,fp)==1){
		if(search==trhf.id && strcmp(trhf.status,"RESERVED")==0 || search==trhf.id && strcmp(trhf.status,"CHECKOUT")==0 || search==trhf.id && strcmp(trhf.status,"CHECKIN")==0){
			found = true;
			break;
		}
	}
	fclose(fp);
	
	DateTimeNow(&Now);
	
	if(!found){
		printf("\nID Transaksi tidak ada");
		goto goback;
	}else if(strcmp(trhf.status,"CHECKOUT")==0 || strcmp(trhf.status,"CHECKIN")==0){
		printf("\nTransaksi sudah dilakukan");
		goto goback;
	}else if(strcmp(trhf.status,"BATAL")==0){
		printf("\nTransaksi telah batal");
		goto goback;
	}else if(trhf.Checkin.tahun==Now.tahun && trhf.Checkin.bulan==Now.bulan && trhf.Checkin.tgl==Now.tgl){
		fp = fopen("Dat/HotelFacility.dat","rb");
		tmp = fopen("Dat/Tmp.dat","wb");
		while(fread(&trhf,sizeof(trhf),1,fp)==1){
			if(search==trhf.id){
				DateTimeNow(&trhf.CustIn);
				printf("\nCheckin dilakukan pada %02d:%02d:%02d WIB %02d/%02d/%d",trhf.CustIn.hour,trhf.CustIn.min,trhf.CustIn.sec,trhf.CustIn.tgl,trhf.CustIn.bulan,trhf.CustIn.tahun);
				strcpy(trhf.status,"CHECKIN");
				fwrite(&trhf,sizeof(trhf),1,tmp);
			}else{
				fwrite(&trhf,sizeof(trhf),1,tmp);
			}
		}
		fclose(tmp);
		fclose(fp);
		remove("Dat/HotelFacility.dat");
		rename("Dat/Tmp.dat","Dat/HotelFacility.dat");	
		goto goback;
	}else{
		printf("\nHarap Checkin sesuai tanggal yang ditentukan!");
		goto goback;
	}
}
