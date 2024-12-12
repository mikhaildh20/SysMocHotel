void RTVroom(){
	fp1= fopen("Dat/Kamar.dat","rb");
	tmp = fopen("Dat/Tmp.dat","wb");
		
	while(fread(&kmr,sizeof(kmr),1,fp1)==1){
		fp = fopen("Dat/HotelRoom.dat","rb");
		while(fread(&trh,sizeof(trh),1,fp)==1){
			if(kmr.no_kamar==trh.no_kamar && strcmp(trh.status,"CHECKIN")==0){
				kmr.status = 0;
			}else{
				kmr.status = 1;
			}
		}
		fwrite(&kmr,sizeof(kmr),1,tmp);
		fclose(fp);
	}
	
	fclose(tmp);
	fclose(fp1);
	
	remove("Dat/Kamar.dat");
	rename("Dat/Tmp.dat","Dat/Kamar.dat");
}

void RTVfacility(){
	fp1= fopen("Dat/Fasilitas.dat","rb");
	tmp = fopen("Dat/Tmp.dat","wb");
		
	while(fread(&fsl,sizeof(fsl),1,fp1)==1){
		fp = fopen("Dat/HotelFacility.dat","rb");
		while(fread(&trhf,sizeof(trhf),1,fp)==1){
			if(fsl.id_fasilitas==trhf.id_fasilitas && strcmp(trhf.status,"CHECKIN")==0){
				fsl.status = 0;
			}else{
				fsl.status = 1;
			}
		}
		fwrite(&fsl,sizeof(fsl),1,tmp);
		fclose(fp);
	}
	
	fclose(tmp);
	fclose(fp1);
	
	remove("Dat/Fasilitas.dat");
	rename("Dat/Tmp.dat","Dat/Fasilitas.dat");
}

void validateAvailable(){
	RTVroom();
	RTVfacility();
}

void RTVmember(){
	fp = fopen("Dat/Member.dat","rb");
	tmp = fopen("Dat/Tmp.dat","wb");
	
	DateTimeNow(&Now);
	
	while(fread(&trm,sizeof(trm),1,fp)==1){
		rValidate = compareDates(trm.xdate,trm.xmonth,trm.xyear,Now.tgl,Now.bulan,Now.tahun);
		if(rValidate == -1){
			trm.status = 0;
		}else{
			trm.status = 1;
		}
		fwrite(&trm,sizeof(trm),1,tmp);
	}
	fclose(fp);
	fclose(tmp);

	remove("Dat/Member.dat");
	rename("Dat/Tmp.dat","Dat/Member.dat");
}

void validateRRoom(){
	fp = fopen("Dat/HotelRoom.dat","rb");
	tmp = fopen("Dat/Tmp.dat","wb");
	
	DateTimeNow(&Now);
	
	while(fread(&trh,sizeof(trh),1,fp)==1){
		rValidate = compareDates(trh.Checkin.tgl,trh.Checkin.bulan,trh.Checkin.tahun,Now.tgl,Now.bulan,Now.tahun);
		if(rValidate == -1 && strcmp(trh.status,"RESERVED")==0){
			strcpy(trh.status,"CANCELLED");
		}
		fwrite(&trh,sizeof(trh),1,tmp);
	}
	
	fclose(fp);
	fclose(tmp);
	
	remove("Dat/HotelRoom.dat");
	rename("Dat/Tmp.dat","Dat/HotelRoom.dat");
}

void validateRFacility(){
	fp = fopen("Dat/HotelFacility.dat","rb");
	tmp = fopen("Dat/Tmp.dat","wb");
	
	DateTimeNow(&Now);
	
	while(fread(&trhf,sizeof(trhf),1,fp)==1){
		rValidate = compareDates(trhf.Checkin.tgl,trhf.Checkin.bulan,trhf.Checkin.tahun,Now.tgl,Now.bulan,Now.tahun);
		if(rValidate == -1 && strcmp(trhf.status,"RESERVED")==0){
			strcpy(trh.status,"CANCELLED");
		}
		fwrite(&trhf,sizeof(trh),1,tmp);
	}
	
	fclose(fp);
	fclose(tmp);
	
	remove("Dat/HotelFacility.dat");
	rename("Dat/Tmp.dat","Dat/HotelFacility.dat");
}

void ValidateAllTransaction(){
	RTVmember();
	validateRRoom();
	validateRFacility();
}
