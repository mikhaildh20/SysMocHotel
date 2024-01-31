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

void getFines(){
	fp = fopen("Dat/Denda.dat","rb");
	i=0;
	while(fread(&dnd,sizeof(dnd),1,fp)==1){
		vth[i].id=dnd.id_denda;
		strcpy(vth[i].nama,dnd.category);
		vth[i].harga=dnd.nominal;
		i++;
	}
	fclose(fp);
}

TransaksiHotel trTemp;
TransaksiHotelf trTempf;
DateTime TglPesan,TglKamar,TglFasil,TglKeluar;

void Troom(){
	clrDb();
	
	while(1){
		getRoom();
		
		reset:
		
		RReserveForm();
		
		next:	
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
		gotoxy(73,24);printf("%03d\n",trh.id);
		strcpy(trh.nama_karyawan,"Zhillan");
		
		invalidDate:
		
		//2 Checkin
		gotoxy(70,26);getnummin(&trh.Checkin.tgl,1,2);if(EscPressed){break;}gotoxy(70,26);printf("%02d",trh.Checkin.tgl);
		gotoxy(75,26);getnummin(&trh.Checkin.bulan,1,2);if(EscPressed){break;}gotoxy(75,26);printf("%02d",trh.Checkin.bulan);
		gotoxy(80,26);getnummin(&trh.Checkin.tahun,4,4);if(EscPressed){break;}
		
		DateTimeNow(&Now);
		
		if(trh.Checkin.tahun<Now.tahun || trh.Checkin.tahun == Now.tahun && trh.Checkin.bulan < Now.bulan || trh.Checkin.tahun == Now.tahun && trh.Checkin.bulan == Now.bulan && trh.Checkin.tgl < Now.tgl || !dateValid(trh.Checkin)){
			gotoxy(70,26);printf("               ");
			gotoxy(70,26);printf("Invalid Date");Beep(900,200);sleep(1);
			gotoxy(70,26);printf("               ");
			gotoxy(69,26);printf("    -    -      ");
			goto invalidDate;
		}
		
		//3 lama
		gotoxy(70,28);getnummin(&trh.LamaSewa,1,2);if(EscPressed){break;}
		
		//4 Checkout
		addDays(trh.Checkin,&trh.Checkout,trh.LamaSewa);
		gotoxy(70,30);printf("%02d",trh.Checkout.tgl);gotoxy(75,30);printf("%02d",trh.Checkout.bulan);gotoxy(80,30);printf("%d",trh.Checkout.tahun);
		
		invalidRoom:
		
		//5 Kamar
		found = false;
		gotoxy(73,32);getnummin(&trh.no_kamar,1,3);gotoxy(73,32);printf("%03d",trh.no_kamar);if(EscPressed){break;}
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
		
		
		
		if(!found){
			gotoxy(70,32);printf("       ");
			gotoxy(70,32);printf("Invalid Room Id");Beep(900,200);sleep(1);
			gotoxy(70,32);printf("               ");
			gotoxy(70,32);printf("KMR");
			sleep(1);
			goto invalidRoom;
		}else{
			fp = fopen("Dat/HotelRoom.dat","rb");
			while(fread(&trTemp,sizeof(trTemp),1,fp)==1){
				if(trTemp.no_kamar==trh.no_kamar && strcmp(trTemp.status,"RESERVED")==0 || trTemp.no_kamar==trh.no_kamar && strcmp(trTemp.status,"CHECKIN")==0){
					for(i=0;i<trh.LamaSewa;i++){
						addDays(trh.Checkin,&TglPesan,i);
						for(j=0;j<trTemp.LamaSewa;j++){
							addDays(trTemp.Checkin,&TglKamar,j);
							if(TglPesan.tgl==TglKamar.tgl && TglPesan.bulan==TglKamar.bulan && TglPesan.tahun==TglKamar.tahun){
								gotoxy(70,32);printf("                   ");
								gotoxy(70,32);printf("ROOM IS UNAVAILABLE");sleep(2);
								selectedOption = 2;
								pressed = 2;
								gotoxy(70,32);printf("             [UP/DOWN]");
								do {
									gotoxy(70,32);printf("            ");
								    switch(selectedOption){
								      	case 1:
								      		gotoxy(70,32);printf("Change Date");
								       	break;
								       	case 2:
								       		gotoxy(70,32);printf("Change Room");
								       	break;
									}
									
									key = getch();
									
									switch (key) {
								        case 72:
								            if (selectedOption > 1) {
								                selectedOption--;
								                Beep(800,125);
								            }
								        break;
								        case 80:
								            if (selectedOption < 2) {
								                selectedOption++;
								                Beep(800,125);
								            }
								        break;
								    }	
								} while (key!=13);
								Beep(900,125);
								gotoxy(70,32);printf("                      ");
								
								if(selectedOption==1){
									clrRReserve();
									goto invalidDate;
								}else{
									gotoxy(70,32);printf("                              ");
									gotoxy(70,32);printf("KMR");
									goto invalidRoom;
								}
							}
						}
					}
				}
			}
			fclose(fp);
		}
		
		gotoxy(70,34);printf("%s",trh.type);
		
		//9 NIK
		found = false;
		gotoxy(70,40);getteksnummin(trh.NIK,16,16);
		
		fp = fopen("Dat/Member.dat","rb");
		while(fread(&trm,sizeof(trm),1,fp)==1){
			if(strcmp(trh.NIK,trm.nik)==0 && trm.status==1){
				found = true;
				//10 NAMA
				strcpy(trh.nama,trm.nama);
				break;
			}
		}
		fclose(fp);
		
		if(!found){
			//10 NAMA non Member
			gotoxy(70,42);getletter(trh.nama,15);
			strupr(trh.nama);
		}else{
			gotoxy(70,42);printf("%s",trh.nama);
			discount = (trh.sisa_harga*15)/100;
			trh.sisa_harga-=discount;
		}
		
		trh.total_harga = trh.sisa_harga;
		
		downpay = (trh.sisa_harga*10)/100;
		gotoxy(120,24);rupiah(trh.sisa_harga,cvrRp);printf("%s",cvrRp);
		gotoxy(120,26);rupiah(downpay,cvrRp);printf("%s",cvrRp);
		
		bayar:
		//11 dp
		gotoxy(121,36);getRp(&trh.dp,1,8,121,36);if(EscPressed){goto reset;}
		gotoxy(121,36);printf("         ");
		gotoxy(120,36);rupiah(trh.dp,cvrRp);printf("%s",cvrRp);
		if(trh.dp<downpay){
			gotoxy(118,36);printf("           ");
			gotoxy(118,36);printf("Not Enough");Beep(900,200);sleep(1);
			gotoxy(118,36);printf("           ");
			gotoxy(118,36);printf("Rp");
			goto bayar;
		}else if(trh.dp==downpay || trh.dp>downpay && trh.dp<trh.sisa_harga){
			trh.sisa_harga-=trh.dp;
			strcpy(trh.pelunasan,"Not Paid Off");
			gotoxy(120,38);rupiah(trh.sisa_harga,cvrRp);printf("%s",cvrRp);
			gotoxy(120,40);printf("0");
		}else if(trh.dp>=trh.sisa_harga){
			kembali = trh.dp;
			trh.dp = trh.sisa_harga;
			kembali-=trh.sisa_harga;
			trh.sisa_harga = 0;
			strcpy(trh.pelunasan,"Paid Off");
			gotoxy(120,38);rupiah(trh.sisa_harga,cvrRp);printf("%s",cvrRp);
			gotoxy(120,40);rupiah(kembali,cvrRp);printf("%s",cvrRp);
		}
		
		gotoxy(118,42);printf("Payment Success!");getch();Beep(900,125);
		gotoxy(118,42);printf("                ");
		//12 pelunasan
		
		//13 status
		strcpy(trh.status,"RESERVED");
		
		fp = fopen("Dat/HotelRoom.dat","ab+");
		fwrite(&trh,sizeof(trh),1,fp);
		fclose(fp);	
		
		clrAllReserve();
		goto next;
	}
}

Tfacil(){
	clrDb();
	
	while(1){
		getFacility();
		
		reset:
		
		FReserveForm();
		
		next:	
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
		gotoxy(73,24);printf("%03d\n",trhf.id);
		strcpy(trhf.nama_karyawan,"Zhillan");
		
		invalidDate:
		
		//2 Checkin
		gotoxy(70,26);getnummin(&trhf.Checkin.tgl,1,2);if(EscPressed){break;}gotoxy(70,26);printf("%02d",trhf.Checkin.tgl);
		gotoxy(75,26);getnummin(&trhf.Checkin.bulan,1,2);if(EscPressed){break;}gotoxy(75,26);printf("%02d",trhf.Checkin.bulan);
		gotoxy(80,26);getnummin(&trhf.Checkin.tahun,4,4);if(EscPressed){break;}
		
		DateTimeNow(&Now);
		
		if(trhf.Checkin.tahun<Now.tahun || trhf.Checkin.tahun == Now.tahun && trhf.Checkin.bulan < Now.bulan || trhf.Checkin.tahun == Now.tahun && trhf.Checkin.bulan == Now.bulan && trhf.Checkin.tgl < Now.tgl || !dateValid(trhf.Checkin)){
			gotoxy(70,26);printf("               ");
			gotoxy(70,26);printf("Invalid Date");Beep(900,200);sleep(1);
			gotoxy(70,26);printf("               ");
			gotoxy(69,26);printf("    -    -      ");
			goto invalidDate;
		}
		
		//3 lama
		gotoxy(70,28);getnummin(&trhf.LamaSewa,1,2);if(EscPressed){break;}
		
		//4 Checkout
		addDays(trhf.Checkin,&trhf.Checkout,trhf.LamaSewa);
		gotoxy(70,30);printf("%02d",trhf.Checkout.tgl);gotoxy(75,30);printf("%02d",trhf.Checkout.bulan);gotoxy(80,30);printf("%d",trhf.Checkout.tahun);
		
		invalidRoom:
		
		//5 Kamar
		found = false;
		gotoxy(73,32);getnummin(&trhf.id_fasilitas,1,3);gotoxy(73,32);printf("%03d",trhf.id_fasilitas);if(EscPressed){break;}
		for(i=0;vth[i].id!=0;i++){
			if(trhf.id_fasilitas==vth[i].id){
				found = true;
				//6 type
				strcpy(trhf.type,vth[i].type);
				//7total harga
				trhf.sisa_harga = vth[i].harga*trhf.LamaSewa;
				break;
			}
		}
		
		
		
		if(!found){
			gotoxy(70,32);printf("       ");
			gotoxy(70,32);printf("Invalid Facility Id");Beep(900,200);sleep(1);
			gotoxy(70,32);printf("                   ");
			gotoxy(70,32);printf("FCL");
			sleep(1);
			goto invalidRoom;
		}else{
			fp = fopen("Dat/HotelFacility.dat","rb");
			while(fread(&trTempf,sizeof(trTempf),1,fp)==1){
				if(trTempf.id_fasilitas==trhf.id_fasilitas && strcmp(trTempf.status,"RESERVED")==0 || trTempf.id_fasilitas==trhf.id_fasilitas && strcmp(trTempf.status,"CHECKIN")==0){
					for(i=0;i<trhf.LamaSewa;i++){
						addDays(trhf.Checkin,&TglPesan,i);
						for(j=0;j<trTempf.LamaSewa;j++){
							addDays(trTempf.Checkin,&TglKamar,j);
							if(TglPesan.tgl==TglKamar.tgl && TglPesan.bulan==TglKamar.bulan && TglPesan.tahun==TglKamar.tahun){
								gotoxy(70,32);printf("                       ");
								gotoxy(70,32);printf("FACILITY IS UNAVAILABLE");sleep(2);
								gotoxy(70,32);printf("                       ");
								selectedOption = 2;
								pressed = 2;
								gotoxy(70,32);printf("             [UP/DOWN]");
								do {
									gotoxy(70,32);printf("            ");
								    switch(selectedOption){
								      	case 1:
								      		gotoxy(70,32);printf("Change Date");
								       	break;
								       	case 2:
								       		gotoxy(70,32);printf("Change Facility");
								       	break;
									}
									
									key = getch();
									
									switch (key) {
								        case 72:
								            if (selectedOption > 1) {
								                selectedOption--;
								                Beep(800,125);
								            }
								        break;
								        case 80:
								            if (selectedOption < 2) {
								                selectedOption++;
								                Beep(800,125);
								            }
								        break;
								    }	
								} while (key!=13);
								Beep(900,125);
								gotoxy(70,32);printf("                      ");
								
								if(selectedOption==1){
									clrRReserve();
									goto invalidDate;
								}else{
									gotoxy(70,32);printf("                              ");
									gotoxy(70,32);printf("FCL");
									goto invalidRoom;
								}
							}
						}
					}
				}
			}
			fclose(fp);
		}
		
		gotoxy(70,34);printf("%s",trhf.type);
		
		//9 NIK
		found = false;
		gotoxy(70,40);getteksnummin(trhf.NIK,16,16);
		
		fp = fopen("Dat/Member.dat","rb");
		while(fread(&trm,sizeof(trm),1,fp)==1){
			if(strcmp(trhf.NIK,trm.nik)==0 && trm.status==1){
				found = true;
				//10 NAMA
				strcpy(trhf.nama,trm.nama);
				break;
			}
		}
		fclose(fp);
		
		if(!found){
			//10 NAMA non Member
			gotoxy(70,42);getletter(trhf.nama,15);
			strupr(trhf.nama);
		}else{
			gotoxy(70,42);printf("%s",trhf.nama);
			discount = (trhf.sisa_harga*15)/100;
			trhf.sisa_harga-=discount;
		}
		
		trhf.total_harga = trhf.sisa_harga;
		
		downpay = (trhf.sisa_harga*10)/100;
		gotoxy(120,24);rupiah(trhf.sisa_harga,cvrRp);printf("%s",cvrRp);
		gotoxy(120,26);rupiah(downpay,cvrRp);printf("%s",cvrRp);
		
		bayar:
		//11 dp
		gotoxy(121,36);getRp(&trhf.dp,1,8,121,36);if(EscPressed){goto reset;}
		gotoxy(121,36);printf("         ");
		gotoxy(120,36);rupiah(trhf.dp,cvrRp);printf("%s",cvrRp);
		if(trhf.dp<downpay){
			gotoxy(118,36);printf("           ");
			gotoxy(118,36);printf("Not Enough");Beep(900,200);sleep(1);
			gotoxy(118,36);printf("           ");
			gotoxy(118,36);printf("Rp");
			goto bayar;
		}else if(trhf.dp==downpay || trhf.dp>downpay && trhf.dp<trhf.sisa_harga){
			trhf.sisa_harga-=trhf.dp;
			strcpy(trhf.pelunasan,"Not Paid Off");
			gotoxy(120,38);rupiah(trhf.sisa_harga,cvrRp);printf("%s",cvrRp);
			gotoxy(120,40);printf("0");
		}else if(trhf.dp>=trhf.sisa_harga){
			kembali = trhf.dp;
			trhf.dp = trhf.sisa_harga;
			kembali-=trhf.sisa_harga;
			trhf.sisa_harga = 0;
			strcpy(trhf.pelunasan,"Paid Off");
			gotoxy(120,38);rupiah(trhf.sisa_harga,cvrRp);printf("%s",cvrRp);
			gotoxy(120,40);rupiah(kembali,cvrRp);printf("%s",cvrRp);
		}
		
		gotoxy(118,42);printf("Payment Success!");getch();Beep(900,125);
		gotoxy(118,42);printf("                ");
		//12 pelunasan
		
		//13 status
		strcpy(trhf.status,"RESERVED");
		
		fp = fopen("Dat/HotelFacility.dat","ab+");
		fwrite(&trhf,sizeof(trhf),1,fp);
		fclose(fp);	
		
		clrAllReserve();
		goto next;
	}
}

void ReadTroom(){
	fp = fopen("Dat/HotelRoom.dat","rb");
	while(fread(&trh,sizeof(trh),1,fp)==1){
		printf("TRK%03d\t%s\tKMR%03d\t%s\t%s\t%02d/%02d/%d\t%s\t%d\tDND%03d\t%d\t%d\t%d\t%s\t%s\n",trh.id,trh.nama_karyawan,trh.no_kamar,trh.NIK,trh.nama,trh.Checkin.tgl,trh.Checkin.bulan,trh.Checkin.tahun,trh.type,trh.LamaSewa,trh.id_denda,trh.dp,trh.sisa_harga,trh.total_harga,trh.status,trh.pelunasan);
	}
	fclose(fp);
}

void ReadTfacil(){
	fp = fopen("Dat/HotelFacility.dat","rb");
	while(fread(&trhf,sizeof(trhf),1,fp)==1){
		printf("TRK%03d\t%s\tFCL%03d\t%s\t%s\t%02d/%02d/%d\t%s\t%d\tDND%03d\t%d\t%d\t%d\t%s\t%s\n",trhf.id,trhf.nama_karyawan,trhf.id_fasilitas,trhf.NIK,trhf.nama,trhf.Checkin.tgl,trhf.Checkin.bulan,trhf.Checkin.tahun,trhf.type,trhf.LamaSewa,trhf.id_denda,trhf.dp,trhf.sisa_harga,trhf.total_harga,trhf.status,trhf.pelunasan);
	}
	fclose(fp);
}

void CheckinRoom(){
	RCheckinForm();
	
	while(1){
		goback:
		
		found = false;	
		gotoxy(73,25);getnummin(&search,1,3);if(EscPressed){break;}gotoxy(73,25);printf("%03d",search);
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
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("RESERVE ID NOT FOUND");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                    ");
			gotoxy(70,25);printf("TRK");
		}else if(strcmp(trh.status,"CHECKOUT")==0 || strcmp(trh.status,"CHECKIN")==0){
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("ALREADY CHECKED IN");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                  ");
			gotoxy(70,25);printf("TRK");
		}else if(strcmp(trh.status,"CANCELLED")==0){
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("RESERVATION CANCELLED");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                     ");
			gotoxy(70,25);printf("TRK");
		}else if(trh.Checkin.tahun==Now.tahun && trh.Checkin.bulan==Now.bulan && trh.Checkin.tgl==Now.tgl){
			fp = fopen("Dat/HotelRoom.dat","rb");
			tmp = fopen("Dat/Tmp.dat","wb");
			while(fread(&trh,sizeof(trh),1,fp)==1){
				if(search==trh.id){
					gotoxy(73,25);printf("%03d",trh.id);
					gotoxy(70,27);printf("%02d",trh.Checkin.tgl);gotoxy(75,27);printf("%02d",trh.Checkin.bulan);gotoxy(80,27);printf("%d",trh.Checkin.tahun);
					gotoxy(70,29);printf("%02d",trh.Checkout.tgl);gotoxy(75,29);printf("%02d",trh.Checkout.bulan);gotoxy(80,29);printf("%d",trh.Checkout.tahun);
					gotoxy(73,31);printf("%03d",trh.no_kamar);
					gotoxy(70,33);printf("%s",trh.type);
					
					gotoxy(70,39);printf("%s",trh.NIK);
					gotoxy(70,41);printf("%s", trh.nama);
					
					gotoxy(120,25);rupiah(trh.total_harga,cvrRp);printf("%s",cvrRp);
					gotoxy(120,27);rupiah(trh.dp,cvrRp);printf("%s",cvrRp);
					gotoxy(120,29);rupiah(trh.sisa_harga,cvrRp);printf("%s",cvrRp);
					gotoxy(118,31);printf("%s",trh.pelunasan);
					
					selectedOption = 1;
					
					do {
						customClr(20,1,102,36);
					       switch(selectedOption){
					       	case 1:
					       		gotoxy(104,36);
					       		printf("%c",42);
					       	break;
					       	case 2:
					       		gotoxy(119,36);
					       		printf("%c",42);
					       	break;
						}
							key = getch();
								
							switch (key) {
					        case 75:
					            if (selectedOption > 1) {
					               selectedOption--;
					        	   Beep(800,125);
					            }
					        break;
					        case 77:
					     	   if (selectedOption < 2) {
					       	        selectedOption++;
					           	    Beep(800,125);
					           	}
					        break;
					    }	
					} while (key!=13);
					Beep(900,125);
					
					if(selectedOption==1){
						fclose(tmp);
						fclose(fp);
						customClr(20,1,102,36);
						clrAllCheckin();
						goto goback;	
					}
					
					DateTimeNow(&trh.CustIn);
					gotoxy(118,39);printf("%02d/%02d/%d %02d:%02d:%02d GMT",trh.CustIn.tgl,trh.CustIn.bulan,trh.CustIn.tahun,trh.CustIn.hour,trh.CustIn.min,trh.CustIn.sec);sleep(2);
					strcpy(trh.status,"CHECKIN");
					clrAllCheckin();
					customClr(20,1,102,36);
					fwrite(&trh,sizeof(trh),1,tmp);
				}else{
					fwrite(&trh,sizeof(trh),1,tmp);
				}
			}
			fclose(tmp);
			fclose(fp);
			remove("Dat/HotelRoom.dat");
			rename("Dat/Tmp.dat","Dat/HotelRoom.dat");	
		}else{
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("PLEASE CHECKIN ON %02d/%02d/%d",trh.Checkin.tgl,trh.Checkin.bulan,trh.Checkin.tahun);Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                              ");
			gotoxy(70,25);printf("TRK");
		}	
		clrAllCheckin();	
	}
}

void CheckinFacility(){
	FCheckinForm();
	
	while(1){
		goback:
		
		found = false;	
		gotoxy(73,25);getnummin(&search,1,3);if(EscPressed){break;}gotoxy(73,25);printf("%03d",search);
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
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("RESERVE ID NOT FOUND");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                    ");
			gotoxy(70,25);printf("TRF");
		}else if(strcmp(trhf.status,"CHECKOUT")==0 || strcmp(trhf.status,"CHECKIN")==0){
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("ALREADY CHECKED IN");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                  ");
			gotoxy(70,25);printf("TRF");
		}else if(strcmp(trhf.status,"CANCELLED")==0){
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("RESERVATION CANCELLED");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                     ");
			gotoxy(70,25);printf("TRF");
		}else if(trhf.Checkin.tahun==Now.tahun && trhf.Checkin.bulan==Now.bulan && trhf.Checkin.tgl==Now.tgl){
			fp = fopen("Dat/HotelFacility.dat","rb");
			tmp = fopen("Dat/Tmp.dat","wb");
			while(fread(&trhf,sizeof(trhf),1,fp)==1){
				if(search==trhf.id){
					gotoxy(73,25);printf("%03d",trhf.id);
					gotoxy(70,27);printf("%02d",trhf.Checkin.tgl);gotoxy(75,27);printf("%02d",trhf.Checkin.bulan);gotoxy(80,27);printf("%d",trhf.Checkin.tahun);
					gotoxy(70,29);printf("%02d",trhf.Checkout.tgl);gotoxy(75,29);printf("%02d",trhf.Checkout.bulan);gotoxy(80,29);printf("%d",trhf.Checkout.tahun);
					gotoxy(73,31);printf("%03d",trhf.id_fasilitas);
					gotoxy(70,33);printf("%s",trhf.type);
					
					gotoxy(70,39);printf("%s",trhf.NIK);
					gotoxy(70,41);printf("%s", trhf.nama);
					
					gotoxy(120,25);rupiah(trhf.total_harga,cvrRp);printf("%s",cvrRp);
					gotoxy(120,27);rupiah(trhf.dp,cvrRp);printf("%s",cvrRp);
					gotoxy(120,29);rupiah(trhf.sisa_harga,cvrRp);printf("%s",cvrRp);
					gotoxy(118,31);printf("%s",trhf.pelunasan);
					
					selectedOption = 2;
					
					do {
						customClr(20,1,102,36);
					       switch(selectedOption){
					       	case 1:
					       		gotoxy(104,36);
					       		printf("%c",42);
					       	break;
					       	case 2:
					       		gotoxy(119,36);
					       		printf("%c",42);
					       	break;
						}
							key = getch();
								
							switch (key) {
					        case 75:
					            if (selectedOption > 1) {
					               selectedOption--;
					        	   Beep(800,125);
					            }
					        break;
					        case 77:
					     	   if (selectedOption < 2) {
					       	        selectedOption++;
					           	    Beep(800,125);
					           	}
					        break;
					    }	
					} while (key!=13);
					Beep(900,125);
					
					if(selectedOption==1){
						fclose(tmp);
						fclose(fp);
						customClr(20,1,102,36);
						clrAllCheckin();
						goto goback;	
					}
					
					DateTimeNow(&trhf.CustIn);
					gotoxy(118,39);printf("%02d/%02d/%d %02d:%02d:%02d GMT",trhf.CustIn.tgl,trhf.CustIn.bulan,trhf.CustIn.tahun,trhf.CustIn.hour,trhf.CustIn.min,trhf.CustIn.sec);sleep(2);
					strcpy(trhf.status,"CHECKIN");
					clrAllCheckin();
					customClr(20,1,102,36);
					fwrite(&trhf,sizeof(trhf),1,tmp);
				}else{
					fwrite(&trhf,sizeof(trhf),1,tmp);
				}
			}
			fclose(tmp);
			fclose(fp);
			remove("Dat/HotelFacility.dat");
			rename("Dat/Tmp.dat","Dat/HotelFacility.dat");	
		}else{
			gotoxy(70,25);printf("          ");
			gotoxy(70,25);printf("PLEASE CHECKIN ON %02d/%02d/%d",trhf.Checkin.tgl,trhf.Checkin.bulan,trhf.Checkin.tahun);Beep(900,200);sleep(2);
			gotoxy(70,25);printf("                              ");
			gotoxy(70,25);printf("TRF");
		}	
		clrAllCheckin();	
	}
}

void CheckoutRoom(){
	//import denda yang tersedia
	getFines();
	RCheckoutForm();
	
	while(1){
		//checkpoint
		checkout:
		
		//id transaksi
		found = false;
		gotoxy(73,25);getnummin(&search,1,3);if(EscPressed){break;}
		fp = fopen("Dat/HotelRoom.dat","rb");
		while(fread(&trh,sizeof(trh),1,fp)==1){
			if(search==trh.id){
				found = true;
				break;
			}
		}
		fclose(fp);
		
		//cek status
		if(found){
			if(strcmp(trh.status,"CHECKIN")!=0){
				if(strcmp(trh.status,"RESERVED")==0){
					gotoxy(70,25);printf("             ");
					gotoxy(70,25);printf("CHECKIN FIRST");Beep(900,200);sleep(2);
					gotoxy(70,25);printf("             ");
				}else{
					gotoxy(70,25);printf("                   ");
					gotoxy(70,25);printf("ALREADY CHECKED OUT");Beep(900,200);sleep(2);
					gotoxy(70,25);printf("                   ");	
				}
				gotoxy(70,25);printf("TRK");
				goto checkout;
			}
			
			fp = fopen("Dat/HotelRoom.dat","rb");
			tmp = fopen("Dat/Tmp.dat","wb");
			while(fread(&trh,sizeof(trh),1,fp)==1){
				if(trh.id==search){
					gotoxy(70,27);printf("%02d",trh.Checkin.tgl);
					gotoxy(75,27);printf("%02d",trh.Checkin.bulan);
					gotoxy(80,27);printf("%d",trh.Checkin.tahun);
					
					gotoxy(70,29);printf("%02d",trh.Checkout.tgl);
					gotoxy(75,29);printf("%02d",trh.Checkout.bulan);
					gotoxy(80,29);printf("%d",trh.Checkout.tahun);
					
					gotoxy(73,31);printf("%03d",trh.no_kamar);
					gotoxy(70,33);printf("%s",trh.type);
					
					hutang = trh.sisa_harga;
					
					lewat = 0;
					//selisih hari
					dayDifference(trh.Checkout.tgl,trh.Checkout.bulan,trh.Checkout.tahun,&lewat);
					
					tTambahan = 0;
					
					//menghitung biaya tambahan jika telat checkout
					if(lewat>0){
						fp = fopen("Dat/Kamar.dat","rb");
						while(fread(&kmr,sizeof(kmr),1,fp)==1){
							if(trh.no_kamar==kmr.no_kamar){
								tTambahan = kmr.harga;
								break;
							}
						}
						fclose(fp);	
						tTambahan*=lewat;
					}else{
						lewat = 0;
					}
					
					gotoxy(70,35);printf("%d",lewat);
					gotoxy(70,37);printf("%s",trh.NIK);
					gotoxy(70,39);printf("%s",trh.nama);
					
					trh.sisa_harga+=tTambahan;
					trh.total_harga+=tTambahan;
					
					//opsi jika ada denda
					selectedOption = 2;
					
					do {
						customClr(20,1,54,40);
					       switch(selectedOption){
					       	case 1:
					       		gotoxy(56,40);
					       		printf("%c",42);
					       	break;
					       	case 2:
					       		gotoxy(72,40);
					       		printf("%c",42);
					       	break;
						}
							key = getch();
								
							switch (key) {
					        case 75:
					            if (selectedOption > 1) {
					               selectedOption--;
					        	   Beep(800,125);
					            }
					        break;
					        case 77:
					     	   if (selectedOption < 2) {
					       	        selectedOption++;
					           	    Beep(800,125);
					           	}
					        break;
					    }	
					} while (key!=13);
					Beep(900,125);
					customClr(20,1,54,40);
					
					//input denda
					if(selectedOption==2){
						trh.nominal_denda = 0;
						
						inputDenda:
					
						found = false;
						gotoxy(121,25);getnummin(&trh.id_denda,1,3);
						gotoxy(121,25);printf("%03d",trh.id_denda);
						for(i=0;vth[i].id!=0;i++){
							if(trh.id_denda==vth[i].id){
								found = true;
								strcpy(trh.nama_dnd,vth[i].nama);
								trh.nominal_denda = vth[i].harga;
								break;	
							}
						}
						
						
						trh.sisa_harga+=trh.nominal_denda;
						trh.total_harga+=trh.nominal_denda;
						
						if(!found){
							gotoxy(118,25);printf("             ");
							gotoxy(118,25);printf("ID Not Found.");Beep(900,200);sleep(2);
							gotoxy(118,25);printf("             ");
							gotoxy(118,25);printf("FNE");
							goto inputDenda;
						}
						
						gotoxy(118,27);printf("%s",trh.nama_dnd);
						gotoxy(121,29);rupiah(trh.nominal_denda,cvrRp);printf("%s",cvrRp);
					}
					
					if(selectedOption!=2){
						gotoxy(118,27);printf("-",trh.nama_dnd);
						gotoxy(121,29);printf("0");	
					}
					
					gotoxy(120,33);rupiah(hutang,cvrRp);printf("%s",cvrRp);
					gotoxy(120,35);rupiah(tTambahan,cvrRp);printf("%s",cvrRp);
					gotoxy(120,37);rupiah(trh.sisa_harga,cvrRp);printf("%s",cvrRp);
					
					//pembayaran jika ada tagihan tambahan seperti denda telat checkout atau dena lain
					if(trh.sisa_harga>0){
						
						pembayaran:
						
						gotoxy(121,39);getRp(&bayar,1,8,121,39);
						gotoxy(121,39);printf("         ");
						gotoxy(120,39);rupiah(bayar,cvrRp);printf("%s",cvrRp);
						if(bayar<trh.sisa_harga){
							gotoxy(118,39);printf("           ");
							gotoxy(118,39);printf("Uang kurang");
							gotoxy(118,39);printf("           ");
							gotoxy(118,39);printf("Rp");
							goto pembayaran;
						}else if(bayar==trh.sisa_harga){
							trh.sisa_harga-=bayar;
							bayar=0;
						}else if(bayar>trh.sisa_harga){
							bayar-=trh.sisa_harga;
							trh.sisa_harga = 0;
						}
						gotoxy(120,41);rupiah(bayar,cvrRp);printf("%s",cvrRp);
					}
					
					sleep(2);
					
					//ubah status menjadi lunas setelah pembayaran
					if(strcmp(trh.pelunasan,"Not Paid Off")==0){
						strcpy(trh.pelunasan,"Paid Off");
					}
					
					DateTimeNow(&trh.CustOut);
					strcpy(trh.status,"CHECKOUT");
					clrAllCheckout();
					
					fwrite(&trh,sizeof(trh),1,tmp);
				}else{
					fwrite(&trh,sizeof(trh),1,tmp);
				}
			}
			fclose(tmp);
			fclose(fp);
			remove("Dat/HotelRoom.dat");
			rename("Dat/Tmp.dat","Dat/HotelRoom.dat");
		}else{
			gotoxy(70,25);printf("            ");
			gotoxy(70,25);printf("ID NOT FOUND");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("            ");
			gotoxy(70,25);printf("TRK");
		}	
	}
}

void CheckoutFacility(){
	//import denda yang tersedia
	getFines();
	FCheckoutForm();
	
	while(1){
		//checkpoint
		checkout:
		
		//id transaksi
		found = false;
		gotoxy(73,25);getnummin(&search,1,3);if(EscPressed){break;}
		fp = fopen("Dat/HotelFacility.dat","rb");
		while(fread(&trhf,sizeof(trhf),1,fp)==1){
			if(search==trhf.id){
				found = true;
				break;
			}
		}
		fclose(fp);
		
		//cek status
		if(found){
			if(strcmp(trhf.status,"CHECKIN")!=0){
				if(strcmp(trhf.status,"RESERVED")==0){
					gotoxy(70,25);printf("             ");
					gotoxy(70,25);printf("CHECKIN FIRST");Beep(900,200);sleep(2);
					gotoxy(70,25);printf("             ");
				}else{
					gotoxy(70,25);printf("                   ");
					gotoxy(70,25);printf("ALREADY CHECKED OUT");Beep(900,200);sleep(2);
					gotoxy(70,25);printf("                   ");	
				}
				gotoxy(70,25);printf("TRF");
				goto checkout;
			}
			
			fp = fopen("Dat/HotelFacility.dat","rb");
			tmp = fopen("Dat/Tmp.dat","wb");
			while(fread(&trhf,sizeof(trhf),1,fp)==1){
				if(trhf.id==search){
					gotoxy(70,27);printf("%02d",trhf.Checkin.tgl);
					gotoxy(75,27);printf("%02d",trhf.Checkin.bulan);
					gotoxy(80,27);printf("%d",trhf.Checkin.tahun);
					
					gotoxy(70,29);printf("%02d",trhf.Checkout.tgl);
					gotoxy(75,29);printf("%02d",trhf.Checkout.bulan);
					gotoxy(80,29);printf("%d",trhf.Checkout.tahun);
					
					gotoxy(73,31);printf("%03d",trhf.id_fasilitas);
					gotoxy(70,33);printf("%s",trhf.type);
					
					hutang = trhf.sisa_harga;
					
					lewat = 0;
					//selisih hari
					dayDifference(trhf.Checkout.tgl,trhf.Checkout.bulan,trhf.Checkout.tahun,&lewat);
					
					tTambahan = 0;
					
					//menghitung biaya tambahan jika telat checkout
					if(lewat>0){
						fp = fopen("Dat/Fasilitas.dat","rb");
						while(fread(&fsl,sizeof(fsl),1,fp)==1){
							if(trhf.id_fasilitas==fsl.id_fasilitas){
								tTambahan = fsl.harga;
								break;
							}
						}
						fclose(fp);	
						tTambahan*=lewat;
					}else{
						lewat = 0;
					}
					
					gotoxy(70,35);printf("%d",lewat);
					gotoxy(70,37);printf("%s",trhf.NIK);
					gotoxy(70,39);printf("%s",trhf.nama);
					
					trhf.sisa_harga+=tTambahan;
					trhf.total_harga+=tTambahan;
					
					//opsi jika ada denda
					selectedOption = 2;
					
					do {
						customClr(20,1,54,40);
					       switch(selectedOption){
					       	case 1:
					       		gotoxy(56,40);
					       		printf("%c",42);
					       	break;
					       	case 2:
					       		gotoxy(72,40);
					       		printf("%c",42);
					       	break;
						}
							key = getch();
								
							switch (key) {
					        case 75:
					            if (selectedOption > 1) {
					               selectedOption--;
					        	   Beep(800,125);
					            }
					        break;
					        case 77:
					     	   if (selectedOption < 2) {
					       	        selectedOption++;
					           	    Beep(800,125);
					           	}
					        break;
					    }	
					} while (key!=13);
					Beep(900,125);
					customClr(20,1,54,40);
					
					//input denda
					if(selectedOption==2){
						trhf.nominal_denda = 0;
						
						inputDenda:
					
						found = false;
						gotoxy(121,25);getnummin(&trhf.id_denda,1,3);
						gotoxy(121,25);printf("%03d",trhf.id_denda);
						for(i=0;vth[i].id!=0;i++){
							if(trhf.id_denda==vth[i].id){
								found = true;
								strcpy(trhf.nama_dnd,vth[i].nama);
								trhf.nominal_denda = vth[i].harga;
								break;	
							}
						}
						
						
						trhf.sisa_harga+=trhf.nominal_denda;
						trhf.total_harga+=trhf.nominal_denda;
						
						if(!found){
							gotoxy(118,25);printf("             ");
							gotoxy(118,25);printf("ID Not Found.");Beep(900,200);sleep(2);
							gotoxy(118,25);printf("             ");
							gotoxy(118,25);printf("FNE");
							goto inputDenda;
						}
						
						gotoxy(118,27);printf("%s",trhf.nama_dnd);
						gotoxy(121,29);rupiah(trhf.nominal_denda,cvrRp);printf("%s",cvrRp);
					}
					
					if(selectedOption!=2){
						gotoxy(118,27);printf("-",trhf.nama_dnd);
						gotoxy(121,29);printf("0");	
					}
					
					gotoxy(120,33);rupiah(hutang,cvrRp);printf("%s",cvrRp);
					gotoxy(120,35);rupiah(tTambahan,cvrRp);printf("%s",cvrRp);
					gotoxy(120,37);rupiah(trhf.sisa_harga,cvrRp);printf("%s",cvrRp);
					
					//pembayaran jika ada tagihan tambahan seperti denda telat checkout atau dena lain
					if(trh.sisa_harga>0){
						
						pembayaran:
						
						gotoxy(121,39);getRp(&bayar,1,8,121,39);
						gotoxy(121,39);printf("         ");
						gotoxy(120,39);rupiah(bayar,cvrRp);printf("%s",cvrRp);
						if(bayar<trhf.sisa_harga){
							gotoxy(118,39);printf("           ");
							gotoxy(118,39);printf("Uang kurang");
							gotoxy(118,39);printf("           ");
							gotoxy(118,39);printf("Rp");
							goto pembayaran;
						}else if(bayar==trhf.sisa_harga){
							trhf.sisa_harga-=bayar;
							bayar=0;
						}else if(bayar>trhf.sisa_harga){
							bayar-=trhf.sisa_harga;
							trhf.sisa_harga = 0;
						}
						gotoxy(120,41);rupiah(bayar,cvrRp);printf("%s",cvrRp);
					}
					
					sleep(2);
					
					//ubah status menjadi lunas setelah pembayaran
					if(strcmp(trhf.pelunasan,"Not Paid Off")==0){
						strcpy(trhf.pelunasan,"Paid Off");
					}
					
					DateTimeNow(&trhf.CustOut);
					strcpy(trhf.status,"CHECKOUT");
					clrAllCheckout();
					
					fwrite(&trhf,sizeof(trh),1,tmp);
				}else{
					fwrite(&trhf,sizeof(trh),1,tmp);
				}
			}
			fclose(tmp);
			fclose(fp);
			remove("Dat/HotelFacility.dat");
			rename("Dat/Tmp.dat","Dat/HotelFacility.dat");
		}else{
			gotoxy(70,25);printf("            ");
			gotoxy(70,25);printf("ID NOT FOUND");Beep(900,200);sleep(2);
			gotoxy(70,25);printf("            ");
			gotoxy(70,25);printf("TRF");
		}	
	}
}
