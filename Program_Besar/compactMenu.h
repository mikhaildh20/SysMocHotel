//menu admin
void AdminMenArr(char uname[]){
	dDashboard(uname);
    PrintAdMen();
    while(1){
    	if(selectedOption==7){
			break;
		}
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
