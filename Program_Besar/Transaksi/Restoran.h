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
		clrDb();
		RestoForm();
		getMember();
		//pesanan selanjutnya
		next:	
		 
		row = 28;
		
		remove("Dat/Tmp.dat");
		remove("Dat/fpayment.dat");
		
		//mengambil data menu yang tersedia
		getAvailableFnB();
		
		while(1){
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
		
		//checkpoint untuk menu selanjutnya
		again:
		gotoxy(65,26);printf("%03d",trr.id);
		
		//checkpoint bila menu yang diinput tidak tersedia
		invalid:
			
		found = false;
		gotoxy(62,28);getletter(trr.item,15);if(EscPressed){break;}
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
			gotoxy(62,28);printf("                  ");
			gotoxy(62,28);printf("UNAVAILABLE");Beep(900,200);sleep(1);
			gotoxy(62,28);printf("                  ");
			goto invalid;
		}
		
		gotoxy(62,30);getnummin(&trr.qty,1,2);
		trr.price*=trr.qty;
		
		rupiah(trr.price,cvrRp);
		gotoxy(93,row);printf("%s",trr.item);
		gotoxy(113,row);printf("%d",trr.qty);
		gotoxy(130,row);printf("Rp%s",cvrRp);
		row++;
		
		tmp = fopen("Dat/Tmp.dat","ab");
		fwrite(&trr,sizeof(trr),1,tmp);
		fclose(tmp);
		
		//select member or non
		
		selectedOption = 2;
					
		do {
			customClr(15,1,47,32);
		    switch(selectedOption){
		       	case 1:
		       		gotoxy(48,32);
		      		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(61,32);
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
			
		if(selectedOption!=2){
			gotoxy(65,26);printf("   ");
			gotoxy(62,28);printf("               ");
			gotoxy(62,30);printf("   ");
			customClr(15,1,47,32);
			goto again;
		}
		
		customClr(15,1,47,32);
		
		selectedOption = 2;
					
		do {
			customClr(15,1,47,37);
		    switch(selectedOption){
		       	case 1:
		       		gotoxy(48,37);
		      		printf("%c",42);
		       	break;
		       	case 2:
		       		gotoxy(61,37);
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
		
		customClr(15,1,47,37);
		
		tPayment = 0;
		tmp = fopen("Dat/Tmp.dat","rb");
		while(fread(&trr,sizeof(trr),1,tmp)==1){
			tPayment+=trr.price;
		}
		fclose(tmp);		
		
		getId = 0;
		
		if(selectedOption==1){
			
			invalidId:
			
			while(1){				
				gotoxy(65,40);getnummin(&search,1,3);if(EscPressed){break;}
				gotoxy(65,40);printf("%03d",search);
				found = false;
				fp = fopen("Dat/Member.dat","rb");
				while(fread(&trm,sizeof(trm),1,fp)==1){
					if(search==trm.id){
						found = true;
						getId = trm.id;
						break;
					}
				}	
				fclose(fp);
				if(!found){
					gotoxy(62,40);printf("            ");
					gotoxy(62,40);printf("Id Not Found");Beep(800,200);sleep(1);
					gotoxy(62,40);printf("            ");
					gotoxy(62,40);printf("TRM");
					goto invalidId;
				}else{
					gotoxy(62,42);printf("%s",trm.nik);
					gotoxy(62,44);printf("%s",trm.nama);
					discount = (tPayment*15)/100;
					tPayment-=discount;
				}
				break;	
			}
		}
		
		fp1 = fopen("Dat/Tmp.dat","rb");
		tmp = fopen("Dat/fpayment.dat","wb");
		while(fread(&trr,sizeof(trr),1,fp1)==1){
			strcpy(trr.nama_karyawan,EmployeeDetail);
			trr.id_member = getId;
			trr.total_price = tPayment;
			getTime(&trr.day,&trr.month,&trr.year);
			fwrite(&trr,sizeof(trr),1,tmp);
		}
		fclose(tmp);
		fclose(fp1);
	
		transaksi:
		gotoxy(104,42);rupiah(tPayment,cvrRp);printf("%s",cvrRp);
		gotoxy(104,44);getRp(&bayar,1,8,105,44);
		gotoxy(105,44);printf("          ");
		gotoxy(104,44);rupiah(bayar,cvrRp);printf("%s",cvrRp);
		if(EscPressed){
			remove("Dat/Tmp.dat");
			remove("Dat/fpayment.dat");
			clrAllRestoForm();
			goto next;
		}else if(bayar<tPayment){
			gotoxy(102,44);printf("               ");
			gotoxy(102,44);printf("Not Enough");Beep(800,200);
			gotoxy(102,44);printf("               ");
			gotoxy(102,44);printf("Rp");
			goto transaksi;
		}else if(bayar==tPayment || bayar>tPayment){
			bayar-=tPayment;
		}
		
		gotoxy(138,44);rupiah(bayar,cvrRp);printf("%s",cvrRp);Beep(800,200);sleep(2);

		clrAllRestoForm();
		
		fp = fopen("Dat/Tresto.dat","ab");
		tmp = fopen("Dat/fpayment.dat","rb");
		while(fread(&trr,sizeof(trr),1,tmp)==1){
			fwrite(&trr,sizeof(trr),1,fp);
		}
		fclose(tmp);
		fclose(fp);
		goto next;	
	}
}

void ReadTresto(){
	//int prev;
	fp = fopen("Dat/Tresto.dat","rb");
	while(fread(&trr,sizeof(trr),1,fp)==1){
		printf("%03d\t%s\t%d\t%02d/%02d/%d\t%s %d\t%d\t%d\n",trr.id,trr.nama_karyawan,trr.id_member,trr.day,trr.month,trr.year,trr.item,trr.qty,trr.price,trr.total_price);
	}
	fclose(fp);
}
