void getTresto(){
	i=0;
	fp = fopen("Dat/Tresto.dat","rb");
	while(fread(&Lrr[i],sizeof(Lrr[i]),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void getTroom(){
	i=0;
	fp = fopen("Dat/HotelRoom.dat","rb");
	while(fread(&Lrh[i],sizeof(Lrh[i]),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void getTfacility(){
	i=0;
	fp = fopen("Dat/HotelFacility.dat","rb");
	while(fread(&Lrf[i],sizeof(Lrf[i]),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void getTmember(){
	i=0;
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&Lrm[i],sizeof(Lrm[i]),1,fp)==1){
		i++;
	}
	fclose(fp);
}

void ViewTresto(){
	getTresto();
	
	RestoReportForm();
	
	row = 24;
	prev = 0;
	for(i=0;Lrr[i].id!=0;i++){
		if(Lrr[i].id!=prev){
			gotoxy(42,row);printf("TRR%03d",Lrr[i].id);
			gotoxy(61,row);printf("%s",Lrr[i].nama_karyawan);
			gotoxy(85,row);if(Lrr[i].id_member!=0){
				printf("TRM%03d",Lrr[i].id_member);
			}else{
				printf("  -");
			}
			gotoxy(110,row);printf("%02d/%02d/%d",Lrr[i].day,Lrr[i].month,Lrr[i].year);
			gotoxy(135,row);rupiah(Lrr[i].total_price,cvrRp);printf("Rp%s",cvrRp);
			row++;	
		}
		prev = Lrr[i].id;
	}
}

void SortMonthTresto(){
	getTresto();
	while(1){
		gotoxy(49,19);printf("  ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":    -      (MM/YY)");
		gotoxy(49,19);getnummin(&sMonth,1,2);if(EscPressed){break;}
		if (sMonth >= 1 && sMonth <= 12) {
        break;
        } else {
        gotoxy(49, 19);printf("  ");
        gotoxy(49, 19);printf("INVALID MONTH");
        }
		gotoxy(49,19);printf("%02d",sMonth);
		gotoxy(54,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		prev = 0;
		for(i=0;Lrr[i].id!=0;i++){
			if(Lrr[i].id!=prev && Lrr[i].month == sMonth && Lrr[i].year == sYear){
				gotoxy(42,row);printf("TRR%03d",Lrr[i].id);
				gotoxy(61,row);printf("%s",Lrr[i].nama_karyawan);
				gotoxy(85,row);if(Lrr[i].id_member!=0){
					printf("TRM%03d",Lrr[i].id_member);
				}else{
					printf("  -");
				}
				gotoxy(110,row);printf("%02d/%02d/%d",Lrr[i].day,Lrr[i].month,Lrr[i].year);
				gotoxy(135,row);rupiah(Lrr[i].total_price,cvrRp);printf("Rp%s",cvrRp);
				row++;	
			}
			prev = Lrr[i].id;
		}
		getch();
	}
}

void SortYearTresto(){
	getTresto();
	while(1){
		gotoxy(49,19);printf("    ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":      (YY)");
		gotoxy(49,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		prev = 0;
		for(i=0;Lrr[i].id!=0;i++){
			if(Lrr[i].id!=prev && Lrr[i].year == sYear){
				gotoxy(42,row);printf("TRR%03d",Lrr[i].id);
				gotoxy(61,row);printf("%s",Lrr[i].nama_karyawan);
				gotoxy(85,row);if(Lrr[i].id_member!=0){
					printf("TRM%03d",Lrr[i].id_member);
				}else{
					printf("  -");
				}
				gotoxy(110,row);printf("%02d/%02d/%d",Lrr[i].day,Lrr[i].month,Lrr[i].year);
				gotoxy(135,row);rupiah(Lrr[i].total_price,cvrRp);printf("Rp%s",cvrRp);
				row++;	
			}
			prev = Lrr[i].id;
		}
		getch();
	}
}

void SortDetailTresto(){
	getTresto();
	
	invalidId:
	
	found = false;
	gotoxy(65,19);printf("    ");
	gotoxy(40,19);printf("TRANSACTION ID");gotoxy(60,19);printf(": TRR");
	gotoxy(65,19);getnummin(&search,1,3);gotoxy(65,19);printf("%03d",search);
	for(i=0;Lrr[i].id!=0;i++){
		if(Lrr[i].id == search){
			found = true;
			break;
		}
	}
	
	if(!found){
		goto invalidId;
	}
	
	clrReport();
	RestoDetailForm();
	row = 24;
	prev = 0;
	for(i=0;Lrr[i].id!=0;i++){
		if(Lrr[i].id == search){
			gotoxy(45,row);printf("%s",Lrr[i].item);
			gotoxy(88,row);printf("%d",Lrr[i].qty);
			gotoxy(135,row);rupiah(Lrr[i].price,cvrRp);printf("Rp%s",cvrRp);
			row++;	
		}
		prev = Lrr[i].id;
	}
	getch();
}

void ViewTroom(){
	getTroom();
	
	RoomReportForm();
	
	row = 24;
	for(i=0;Lrh[i].id!=0;i++){
		gotoxy(42,row);printf("TRH%03d",Lrh[i].id);
		gotoxy(57,row);printf("%s",Lrh[i].nama_karyawan);
		gotoxy(74,row);printf("%02d/%02d/%d",Lrh[i].Checkin.tgl,Lrh[i].Checkin.bulan,Lrh[i].Checkin.tahun);
		gotoxy(90,row);printf("%02d/%02d/%d",Lrh[i].Checkout.tgl,Lrh[i].Checkout.bulan,Lrh[i].Checkout.tahun);
		gotoxy(105,row);printf("%s",Lrh[i].status);
		gotoxy(120,row);rupiah(Lrh[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
		gotoxy(140,row);printf("%s",Lrh[i].pelunasan);
		row++;
	}
}

void SortMonthTroom(){
	getTroom();
	
	while(1){
		gotoxy(49,19);printf("  ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":    -      (MM/YY)");
		gotoxy(49,19);getnummin(&sMonth,1,2);if(EscPressed){break;}gotoxy(49,19);printf("%02d",sMonth);
		if (sMonth >= 1 && sMonth <= 12) {
        break;
        } else {
        gotoxy(49, 19);printf("  ");
        gotoxy(49, 19);printf("INVALID MONTH");
        }
		gotoxy(54,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		for(i=0;Lrh[i].id!=0;i++){
			if(Lrh[i].Checkin.bulan == sMonth && Lrh[i].Checkin.tahun == sYear){
				gotoxy(42,row);printf("TRH%03d",Lrh[i].id);
				gotoxy(57,row);printf("%s",Lrh[i].nama_karyawan);
				gotoxy(74,row);printf("%02d/%02d/%d",Lrh[i].Checkin.tgl,Lrh[i].Checkin.bulan,Lrh[i].Checkin.tahun);
				gotoxy(90,row);printf("%02d/%02d/%d",Lrh[i].Checkout.tgl,Lrh[i].Checkout.bulan,Lrh[i].Checkout.tahun);
				gotoxy(105,row);printf("%s",Lrh[i].status);
				gotoxy(120,row);rupiah(Lrh[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
				gotoxy(140,row);printf("%s",Lrh[i].pelunasan);
				row++;	
			}
		}
		getch();
	}
}

void SortYearTroom(){
	getTroom();
	
	while(1){
		gotoxy(49,19);printf("    ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":      (YY)");
		gotoxy(49,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		for(i=0;Lrh[i].id!=0;i++){
			if(Lrh[i].Checkin.tahun == sYear){
				gotoxy(42,row);printf("TRH%03d",Lrh[i].id);
				gotoxy(57,row);printf("%s",Lrh[i].nama_karyawan);
				gotoxy(74,row);printf("%02d/%02d/%d",Lrh[i].Checkin.tgl,Lrh[i].Checkin.bulan,Lrh[i].Checkin.tahun);
				gotoxy(90,row);printf("%02d/%02d/%d",Lrh[i].Checkout.tgl,Lrh[i].Checkout.bulan,Lrh[i].Checkout.tahun);
				gotoxy(105,row);printf("%s",Lrh[i].status);
				gotoxy(120,row);rupiah(Lrh[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
				gotoxy(140,row);printf("%s",Lrh[i].pelunasan);
				row++;	
			}
		}
		getch();
	}
}


void ViewTfacility(){
	getTfacility();
	
	RoomReportForm();
	
	row = 24;
	for(i=0;Lrf[i].id!=0;i++){
		gotoxy(42,row);printf("TRF%03d",Lrf[i].id);
		gotoxy(57,row);printf("%s",Lrf[i].nama_karyawan);
		gotoxy(74,row);printf("%02d/%02d/%d",Lrf[i].Checkin.tgl,Lrf[i].Checkin.bulan,Lrf[i].Checkin.tahun);
		gotoxy(90,row);printf("%02d/%02d/%d",Lrf[i].Checkout.tgl,Lrf[i].Checkout.bulan,Lrf[i].Checkout.tahun);
		gotoxy(105,row);printf("%s",Lrf[i].status);
		gotoxy(120,row);rupiah(Lrh[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
		gotoxy(140,row);printf("%s",Lrf[i].pelunasan);
		row++;
	}
}

void SortMonthTfacility(){
	getTfacility();
	
	while(1){
		gotoxy(49,19);printf("  ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":    -      (MM/YY)");
		gotoxy(49,19);getnummin(&sMonth,1,2);if(EscPressed){break;}gotoxy(49,19);printf("%02d",sMonth);
		gotoxy(54,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		for(i=0;Lrf[i].id!=0;i++){
			if(Lrf[i].Checkin.bulan == sMonth && Lrf[i].Checkin.tahun == sYear){
				gotoxy(42,row);printf("TRF%03d",Lrf[i].id);
				gotoxy(57,row);printf("%s",Lrf[i].nama_karyawan);
				gotoxy(74,row);printf("%02d/%02d/%d",Lrf[i].Checkin.tgl,Lrf[i].Checkin.bulan,Lrf[i].Checkin.tahun);
				gotoxy(90,row);printf("%02d/%02d/%d",Lrf[i].Checkout.tgl,Lrf[i].Checkout.bulan,Lrf[i].Checkout.tahun);
				gotoxy(105,row);printf("%s",Lrf[i].status);
				gotoxy(120,row);rupiah(Lrf[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
				gotoxy(140,row);printf("%s",Lrf[i].pelunasan);
				row++;	
			}
		}
		getch();
	}
}

void SortYearTfacility(){
	getTfacility();
	
	while(1){
		gotoxy(49,19);printf("    ");
		gotoxy(40,19);printf("DATE");gotoxy(47,19);printf(":      (YY)");
		gotoxy(49,19);getnummin(&sYear,4,4);if(EscPressed){break;}
		clrReport();	
		row = 24;
		for(i=0;Lrf[i].id!=0;i++){
			if(Lrf[i].Checkin.tahun == sYear){
				gotoxy(42,row);printf("TRF%03d",Lrf[i].id);
				gotoxy(57,row);printf("%s",Lrf[i].nama_karyawan);
				gotoxy(74,row);printf("%02d/%02d/%d",Lrf[i].Checkin.tgl,Lrf[i].Checkin.bulan,Lrf[i].Checkin.tahun);
				gotoxy(90,row);printf("%02d/%02d/%d",Lrf[i].Checkout.tgl,Lrf[i].Checkout.bulan,Lrf[i].Checkout.tahun);
				gotoxy(105,row);printf("%s",Lrf[i].status);
				gotoxy(120,row);rupiah(Lrf[i].total_harga,cvrRp);printf("Rp%s",cvrRp);
				gotoxy(140,row);printf("%s",Lrf[i].pelunasan);
				row++;	
			}
		}
		getch();
	}
}


void ViewTmember(){
	getTmember();
	
	MemberReportForm();
	
	row = 24;
	for(i=0;Lrm[i].id!=0;i++){
		gotoxy(42,row);printf("TRM%02d",Lrm[i].id);
		gotoxy(55,row);printf("%s",Lrm[i].nik);
		gotoxy(74,row);printf("%s",Lrm[i].nama);
		gotoxy(90,row);printf("%s",Lrm[i].telp);
		gotoxy(105,row);printf("%02d/%02d/%d",Lrm[i].jdate,Lrm[i].jmonth,Lrm[i].jyear);
		gotoxy(120,row);printf("%02d/%02d/%d",Lrm[i].xdate,Lrm[i].xmonth,Lrm[i].xyear);
		gotoxy(140,row);switch(Lrm[i].status){
				case 0:
					printf("INACTIVE");
				break;
				case 1:
					printf("ACTIVE");
				break;
			}
		row++;
	}
}

void SortTMemberActive(){
	getTmember();
	
	MemberReportForm();
	
		clrReport();	
		row = 24;
		for(i=0;Lrm[i].id!=0;i++){
			if(Lrm[i].status=1){
			gotoxy(42,row);printf("TRM%02d",Lrm[i].id);
			gotoxy(55,row);printf("%s",Lrm[i].nik);
			gotoxy(74,row);printf("%s",Lrm[i].nama);
			gotoxy(90,row);printf("%s",Lrm[i].telp);
			gotoxy(105,row);printf("%02d/%02d/%d",Lrm[i].jdate,Lrm[i].jmonth,Lrm[i].jyear);
			gotoxy(120,row);printf("%02d/%02d/%d",Lrm[i].xdate,Lrm[i].xmonth,Lrm[i].xyear);
			gotoxy(140,row);switch(Lrm[i].status){
				case 0:
					printf("INACTIVE");
				break;
				case 1:
					printf("ACTIVE");
				break;
			}
			row++;	
			}
		}
		getch();
}

void SortTMemberDeactive(){
	getTmember();
	
	MemberReportForm();
	
	
		for(i=0;Lrm[i].id!=0;i++){
			if(Lrm[i].status!=1){
			gotoxy(42,row);printf("TRM%02d",Lrm[i].id);
			gotoxy(55,row);printf("%s",Lrm[i].nik);
			gotoxy(74,row);printf("%s",Lrm[i].nama);
			gotoxy(90,row);printf("%s",Lrm[i].telp);
			gotoxy(105,row);printf("%02d/%02d/%d",Lrm[i].jdate,Lrm[i].jmonth,Lrm[i].jyear);
			gotoxy(120,row);printf("%02d/%02d/%d",Lrm[i].xdate,Lrm[i].xmonth,Lrm[i].xyear);
			gotoxy(140,row);switch(Lrm[i].status){
				case 0:
					printf("INACTIVE");
				break;
				case 1:
					printf("ACTIVE");
				break;
			}
			row++;	
			}
		}
		getch();
}
