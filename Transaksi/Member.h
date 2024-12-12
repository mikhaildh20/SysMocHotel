void getMember(){
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
	clrDb();
	RegMemberForm();
	
	while(1){
		next:
		//import nik & no telp yang terdaftar untuk validasi
		getMember();
		
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
		
		gotoxy(82,27);printf("%03d",trm.id);
		
		invalidnik:
		
		found = false;	
		fflush(stdin);gotoxy(79,31);getteksnummin(trm.nik,16,16);if(EscPressed){break;}
		for(i=0;vtm[i].term!=0;i++){
			if(strcmp(trm.nik,vtm[i].nik)==0){
				found = true;
				break;
			}
		}
		
		if(found){
			gotoxy(79,31);printf("                ");
			gotoxy(79,31);printf("ALREADY REGISTER");Beep(900,200);sleep(1);
			gotoxy(79,31);printf("                ");
			goto invalidnik;
		}
		
		invalidtelp:
		
		found = false;
		fflush(stdin);gotoxy(79,35);getteksnummin(trm.telp,11,13);
		for(i=0;vtm[i].term!=0;i++){
			if(strcmp(trm.telp,vtm[i].telp)==0){
				found = true;
				break;
			}
		}
		
		if(found){
			gotoxy(79,35);printf("                ");
			gotoxy(79,35);printf("ALREADY REGISTER");Beep(900,200);sleep(1);
			gotoxy(79,35);printf("                ");
			goto invalidtelp;
		}
		
		fflush(stdin);gotoxy(79,39);getletter(trm.nama,15);
		strupr(trm.nama);
		
		strcpy(trm.nama_karyawan,"Imam");
		getTime(&trm.jdate,&trm.jmonth,&trm.jyear);
		getTime(&trm.xdate,&trm.xmonth,&trm.xyear);
		trm.xyear+=1;
		gotoxy(115,27);printf("%02d",trm.xdate);gotoxy(120,27);printf("%02d",trm.xmonth);gotoxy(125,27);printf("%d",trm.xyear);
		trm.status=1;
		
		tPayment = 100000;
		trm.total_harga = tPayment;
		
		transaksi:
		
		gotoxy(117,31);rupiah(tPayment,cvrRp);printf("%s",cvrRp);
		gotoxy(117,35);getRp(&bayar,1,8,118,35);gotoxy(118,35);printf("            ");
		gotoxy(117,35);rupiah(bayar,cvrRp);printf("%s",cvrRp);
		if(EscPressed){
			gotoxy(116,35);printf("               ");
			gotoxy(116,35);printf("Cancelled");sleep(2);
			gotoxy(116,35);printf("               ");
			gotoxy(116,35);printf("Rp");
			goto invalidnik;
		}else if(bayar<tPayment){
			gotoxy(116,35);printf("               ");
			gotoxy(116,35);printf("Not Enough");sleep(2);
			gotoxy(116,35);printf("               ");
			gotoxy(116,35);printf("Rp");
			goto transaksi;
		}else if(bayar==tPayment || bayar>tPayment){
			bayar-=tPayment;
		}
		
		gotoxy(117,39);rupiah(bayar,cvrRp);printf("%s",cvrRp);Beep(900,200);sleep(2);
		
		fwrite(&trm,sizeof(trm),1,fp);
		clrAllReg();
		fclose(fp);
		goto next;	
	}
}

void EXmember(){
	clrDb();
	
	ExtMemberForm();
	
	while(1){
		goback:
		tPayment = 50000;
		getMember();
		
		invalid:
		
		found = false;
		gotoxy(82,27);getnummin(&search,1,3);if(EscPressed){break;}gotoxy(82,27);printf("%03d",search);
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
					gotoxy(79,29);printf("%s",trm.nik);
					gotoxy(79,31);printf("%s",trm.telp);
					gotoxy(79,33);printf("%s",trm.nama);
					gotoxy(79,35);printf("%02d",trm.jdate);gotoxy(84,35);printf("%02d",trm.jmonth);gotoxy(89,35);printf("%d",trm.jyear);
					gotoxy(79,37);printf("%02d",trm.xdate);gotoxy(84,37);printf("%02d",trm.xmonth);gotoxy(89,37);printf("%d",trm.xyear);
					gotoxy(79,39);getnummin(&lama,1,1);
					trm.xyear+=lama;
					gotoxy(115,27);printf("%02d",trm.xdate);gotoxy(120,27);printf("%02d",trm.xmonth);gotoxy(125,27);printf("%d",trm.xyear);
					if(trm.status==0){
						trm.status = 1;
					}
					
					tPayment*=lama;
					trm.total_harga+=tPayment;
					
					gotoxy(117,29);rupiah(tPayment,cvrRp);printf("%s",cvrRp);
					
					kurang:
					gotoxy(117,31);getRp(&bayar,1,8,118,31);
					gotoxy(118,31);printf("          ");
					gotoxy(117,31);rupiah(bayar,cvrRp);printf("%s",cvrRp);
					if(EscPressed){
						gotoxy(115,31);printf("               ");
						gotoxy(115,31);printf("Cancelled");Beep(900,200);sleep(2);
						gotoxy(115,31);printf("               ");
						gotoxy(115,31);printf("Rp");
						clrAllExt();
						break;
					}else if(bayar<tPayment){
						gotoxy(115,31);printf("               ");
						gotoxy(115,31);printf("Not Enough");Beep(900,200);sleep(2);
						gotoxy(115,31);printf("               ");
						gotoxy(115,31);printf("Rp");
						goto kurang;
					}else if(bayar==tPayment || bayar>tPayment){
						bayar-=tPayment;
						updconf = true;
					}
					
					gotoxy(117,33);rupiah(bayar,cvrRp);printf("%s",cvrRp);Beep(800,200);sleep(2);
					
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
			gotoxy(79,27);printf("            ");
			gotoxy(79,27);printf("ID NOT FOUND");Beep(900,200);sleep(2);
			gotoxy(79,27);printf("            ");
			gotoxy(79,27);printf("MBR");
		}
		
		clrAllExt();
		
		goto goback;	
	}
}

void ReadTmember(){
	fp = fopen("Dat/Member.dat","rb");
	while(fread(&trm,sizeof(trm),1,fp)==1){
		printf("%d\t%s\t%s\t%02d/%02d/%d\t%02d/%02d/%d\t%s\t%d\t%d\t%s\n",trm.id,trm.nama_karyawan,trm.nama,trm.jdate,trm.jmonth,trm.jyear,trm.xdate,trm.xmonth,trm.xyear,trm.telp,trm.total_harga,trm.status,trm.nik);
	}
	fclose(fp);
}
