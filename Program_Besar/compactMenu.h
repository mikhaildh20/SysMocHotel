//menu admin
void AdminMenArr(char uname[]){
	dDashboard(uname);
    PrintAdMen();
    while(1){
    	if(selectedOption==7){
			break;
		}
		Dashboard();
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
		        case 4:
		        	gotoxy(28,24);
		        	printf("%c",174);
		        break;
		        case 5:
		        	gotoxy(28,26);
		        	printf("%c",174);
		        break;
		        case 6:
		        	gotoxy(28,28);
		        	printf("%c",174);
		        break;
		        case 7:
		        	gotoxy(28,30);
		        	printf("%c",174);
		        break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 7) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				MenuKamar();	
			break;
			case 2:
				MenuFasilitas();
			break;
			case 3:
				MenuKaryawan();
			break;
			case 4:
				MenuPaket();
			break;
			case 5:
				MenuMenu();	
			break;
			case 6:
				MenuDenda();
			break;
		}
	}
}

void ChooseReserve(){
	selectedOption = 1;
	clrMainMenu();
	PrintTHotel();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		PrintAdReceptionist();
			break;
		}
		
		ReadKmr();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				Troom();	
			break;
			case 2:
				Tfacil();
			break;
		}
	}
}

void ChooseCheckin(){
	selectedOption = 1;
	clrMainMenu();
	PrintTHotel();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		PrintAdReceptionist();
			break;
		}
		
		ReadKmr();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				CheckinRoom();	
			break;
			case 2:
				CheckinFacility();
			break;
		}
	}
}

void ChooseCheckout(){
	selectedOption = 1;
	clrMainMenu();
	PrintTHotel();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		PrintAdReceptionist();
			break;
		}
		
		ReadKmr();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				CheckoutRoom();	
			break;
			case 2:
				CheckoutFacility();
			break;
		}
	}
}

void ReceptionistArrMen(char uname[]){
	dDashboard(uname);
	strcpy(EmployeeDetail,uname);
    PrintAdReceptionist();
    while(1){
    	clrDb();
    	
    	if(selectedOption==6){
			break;
		}
		
		ReceptionistDb();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
		        case 4:
		        	gotoxy(28,24);
		        	printf("%c",174);
		        break;
		        case 5:
		        	gotoxy(28,26);
		        	printf("%c",174);
		        break;
		        case 6:
		        	gotoxy(28,28);
		        	printf("%c",174);
		        break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 6) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				ChooseReserve();	
			break;
			case 2:
				ChooseCheckin();
			break;
			case 3:
				ChooseCheckout();
			break;
			case 4:
				Tmember();
			break;
			case 5:
				EXmember();	
			break;
		}
	}
}

//menu kasir
void CashierArrMen(char uname[]){
	dDashboard(uname);
	strcpy(EmployeeDetail,uname);
    PrintAdCashier();
    while(1){
    	clrDb();
    	
    	if(selectedOption==4){
			break;
		}
		
		CashierDb();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
		        case 4:
		        	gotoxy(28,24);
		        	printf("%c",174);
		        break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 4) {
		              	    selectedOption++;
		                	Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				Tresto();	
			break;
			case 2:
				Tmember();
			break;
			case 3:
				EXmember();
			break;
		}
	}
}

void RoomReport(){
	selectedOption = 1;
	clrMainMenu();
	PrintChooseReport();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		clrMainMenu();
    		PrintTHotel();
    		selectedOption = 1;
			break;
		}
		
		ViewTroom();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				SortMonthTroom();	
			break;
			case 2:
				SortYearTroom();
			break;
		}
	}
}

void FacilityReport(){
	selectedOption = 1;
	clrMainMenu();
	PrintChooseReport();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		clrMainMenu();
    		PrintTHotel();
    		selectedOption = 1;
			break;
		}
		
		ViewTfacility();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				SortMonthTfacility();	
			break;
			case 2:
				SortYearTfacility();
			break;
		}
	}
}

void ChooseHotelReport(){
	selectedOption = 1;
	clrMainMenu();
	PrintTHotel();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		PrintAdManager();
			break;
		}
		
		ViewTroom();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;	
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				RoomReport();	
			break;
			case 2:
				FacilityReport();	
			break;
		}
	}
} 


void ChooseRestoReport(){
	selectedOption = 1;
	clrMainMenu();
	PrintChooseRReport();
	while(1){
    	clrDb();
    	
    	if(selectedOption==4){
    		clrMainMenu();
    		PrintAdManager();
    		selectedOption = 1;
			break;
		}
		
		ViewTresto();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;	
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
		       	case 4:
		       		gotoxy(28,24);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 4) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				SortMonthTresto();	
			break;
			case 2:
				SortYearTresto();	
			break;
			case 3:
				SortDetailTresto();
			break;
		}
	}
}

void ChooseMemberReport(){
	selectedOption = 1;
	clrMainMenu();
	PrintMemberReport();
	while(1){
    	clrDb();
    	
    	if(selectedOption==3){
    		clrMainMenu();
    		PrintAdManager();
			break;
		}
		
		ViewTmember();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;	
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 3) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				SortTMemberActive();	
			break;
			case 2:
				SortTMemberDeactive();	
			break;
		}
	}
}

void ManagerArrMen(char uname[]){
	dDashboard(uname);
	strcpy(EmployeeDetail,uname);
    PrintAdManager();
    while(1){
    	clrDb();
    	
    	if(selectedOption==4){
			break;
		}
		
		ManagerDb();
		
    	selectedOption = 1;
	    do {
			clrMenArrow(14,28,18);
		    switch(selectedOption){
		        case 1:
		        	gotoxy(28,18);
		        	printf("%c",174);
		       	break;
		       	case 2:
		       		gotoxy(28,20);
		       		printf("%c",174);
		       	break;
		       	case 3:
		       		gotoxy(28,22);
		       		printf("%c",174);
		       	break;
		        case 4:
		        	gotoxy(28,24);
		        	printf("%c",174);
		        break;
			}
		
			key = getch();
			
			switch (key) {
		        case 72: // Up arrow key
		            if (selectedOption > 1) {
		                selectedOption--;
		                Beep(800,125);
		            }
		            break;
		        case 80: // Down arrow key
		        	   if (selectedOption < 4) {
		              	    selectedOption++;
		                    Beep(800,125);
		               }
		            break;
		        }
		} while (key != 13);
		Beep(900,125);
		clrMenArrow(12,28,20);
			
		switch(selectedOption){
			case 1:
				ChooseHotelReport();	
			break;
			case 2:
				ChooseRestoReport();
			break;
			case 3:
				ChooseMemberReport();
			break;
		}
	}
}
