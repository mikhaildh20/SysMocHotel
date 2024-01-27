void getRoom(){
	//mengambil beberapa detail kamar untuk keperluan validasi
	fp = fopen("Dat/Kamar.dat","rb");
	i=0;
	while(fread(&kmr,sizeof(kmr),1,fp)==1){
		vth[i].id=kmr.no_kamar;
		strcpy(vth[i].nama,kmr.tipe_kamar);
		strcpy(vth[i].type,"ROOM");
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
		strcpy(vth[i].type,"FACILITY");
		vth[i].harga=fsl.harga;
		i++;
	}
	fclose(fp);
}

void Troom(){
	TransaksiHotel trTemp;
	DateTime TglPesan,TglKamar;
	next:
		
	getRoom();
		
	remove("Dat/Tmp.dat");
	
	fp = fopen("Dat/Hotel.dat","rb");
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
	printf("ID Transaksi\t: TRH%03d\n",trh.id);
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
	printf("\nID Kamar\t: ");getnummin(&trh.no_kamar,1,3);
	for(i=0;vth[i].id!=0;i++){
		if(trh.no_kamar==vth[i].id){
			found = true;
			//6 type
			strcpy(trh.type,vth[i].type);
			//7total harga
			trh.total_harga = vth[i].harga*trh.LamaSewa;
			break;
		}
	}
	
	//8 sisa harga
	trh.sisa_harga = trh.total_harga;
	
	if(!found){
		printf("\nRoom ID not found.\n");
		sleep(1);
		goto invalidRoom;
	}else{
		fp = fopen("Dat/Hotel.dat","rb");
		while(fread(&trTemp,sizeof(trTemp),1,fp)==1){
			if(trTemp.no_kamar==trh.no_kamar && strcmp(trTemp.status,"RESERVED")==0 || strcmp(trTemp.status,"ONGOING")==0){
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
		trh.dp-=trh.sisa_harga;
		printf("\nPembayaran berhasil\n");
		printf("\nKembali\t: %d",trh.dp);
		strcpy(trh.pelunasan,"Lunas");
	}
	sleep(2);
	//12 pelunasan
	
	//13 status
	strcpy(trh.status,"RESERVED");
	
	fp = fopen("Dat/Hotel.dat","ab+");
	fwrite(&trh,sizeof(trh),1,fp);
	fclose(fp);
	goto next;
}

ReadTkamar(){
	//
}
