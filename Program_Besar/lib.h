void getinputmin(char input[], int min, int max, int type){
	char strcurrent;
	int i,n,x,m;
	n = 0;
	x=0;
	EscPressed = false;
	do
	{
		strcurrent = getch();

		if(strcurrent == '\b' && n != 0) //backspace
		{
			printf("\b \b");
			n--;
			input[n]='\0';
		}
		//else if(current >= 32 && current <= 122){
		else if(isprint(strcurrent)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else{
				if(type == 3){ //isdigit = hanya angka
					if(isdigit(strcurrent)) {
						printf("%c", strcurrent);
						input[n]=strcurrent;
						n++;
					}
					else printf("\a");
				}
				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
					if(isalpha(strcurrent) || strcurrent == ' ') {
						printf("%c", strcurrent);
						input[n]=strcurrent;
						n++;
					}
					else printf("\a");
				}
				else {
					if(type == 1) // password //0= bebas
					{
						if(strcurrent==35||x>0)
						{
							if(strcurrent==35)
							{
								x=x+1;
								for(m=0;m<n;m++)
								{
									printf("\b \b");
								}
								for(m=0;m<n;m++)
								{
									printf("%c",input[m]);
								}

							}
							else if(strcurrent==64)
							{
								x=0;
								for(m=0;m<n;m++)
								{
									printf("\b \b");
								}
								for(m=0;m<n;m++)
								{
									printf("*");
								}
							}
							else
							{
								printf("%c", strcurrent);
								input[n]=strcurrent;
								n++;
							}
						}
						else
						{
							printf("*");
							input[n]=strcurrent;
							n++;
						}

					}
					else
					{
						printf("%c", strcurrent);
						input[n]=strcurrent;
						n++;
					}
				}
			}
		}
		else if(strcurrent == 13)
		{
			if(n < min) {
				printf("\a");
				strcurrent = 0;
			}
			else input[n]='\0';
		}
		//else if(current == 27) end();
	}
	while(strcurrent != 13 && strcurrent != 27);
	if(strcurrent == 27){
		EscPressed = true;
	}
}

void getinput(char input[], int max, int type){
	getinputmin(input, 1, max, type);
}

void getteks(char input[], int max){
	getinput(input, max, 0);
}

void getnum(int *dest, int max){
	char input[max];
	getinput(input, max, 3);
	*dest = atoi(input);
}

void getnummin(int *dest, int min, int max){
	char input[max];
	getinputmin(input, min, max, 3);
	*dest = atoi(input);
}

void getteksnum(char input[], int max){
	getinput(input, max, 3);
}

void getteksnummin(char input[], int min, int max){
	getinputmin(input, min, max, 3);
}

void getpass(char input[], int max){
	getinput(input, max, 1);
}

void getletter(char input[], int max){
	getinput(input, max, 2);
}

void rupiah(int number, char output[])
{
	// menampilkan Bentuk Rupiah
	if(number < 1000) sprintf(output, "%d", number);
    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
}

void formatID(char tipe[4], int id, char newID[]) {

	if(id < 10) {
		sprintf(newID, "%s00%d", tipe, id);
	} else if(id < 100) {
		sprintf(newID, "%s0%d", tipe, id);
	} else {
		sprintf(newID, "%s%d", tipe, id);
	}
}

void getRp(int *nilai, int min, int max, int x, int y) //input rupiah
{
	char input[255];
	char inpkey;
	int i,n,m;
	n = 0;
	EscPressed = false;
	do
	{
	    inpkey = getch(); // membaca masukan dari keyboard per-karakter //
	    if(inpkey == '\b' && n != 0) /* Hapus karakter */
		{
			n--;
			input[n]='\0';

			m = n % 3;
			if((n-m) % 3 == 0 || n == m)
            {
                printf("\b \b");
				printf("\b \b");
			}
			else
            {
                printf("\b \b");
			}

			gotoxy(x, y);		/* Cetak ulang sesuai format */
			for(i = 0; i < n; i++)
            {
                if((i+1) == m || (i+1-m) % 3 == 0)
                {
                    printf("%c", input[i]);
					if(i != (n-1))
					{
					    printf(".");
					}
				}
				else
                {
					printf("%c", input[i]);
				}
			}
		}
		else if(isprint(inpkey))      /* Karakter yang bisa di print */
        {
            if(n == max)
            {
                continue;
			}
			else
            {
				if(isdigit(inpkey))   /* Print angka */
				{
					gotoxy(x, y);
					input[n]=inpkey;
					n++;
					m = n % 3;
					for(i = 0; i < n; i++)  /* Cetak ulang sesuai format */
					{
						if((i+1) == m || (i+1-m) % 3 == 0)
						{
							printf("%c", input[i]);
							if(i != (n-1))
							{
								printf(".");
							}
						}
						else
                        {
							printf("%c", input[i]);
						}
					}
				}
				else printf("\a"); /* Pemberitahuan suara tidak dapat di input (alert) */
			}
		}
		else if(inpkey == 13)	/* Jika menekan enter sebelum mengisi karakter akan muncul suara tidak dapat diinput (alert) */
		{
			if(n < min)
            {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
	}
	while(inpkey != 13 && inpkey != 27);
	if(inpkey == 27){
		EscPressed = true;
	}

	*nilai = atoi(input);   /* Memasukkan nilai input (char) ke nilai (int) */
}

void textAreaInput(char input[], int min, int max, int x, int y, int maxOneLine)
{
	char inpkey;	
	int i,n,m, oneline;
	oneline = maxOneLine;
	EscPressed = false;
	n = 0;
	do
	{	
		inpkey = getch();  // membaca masukan dari keyboard per-karakter //
		
//---- Menghapus Input ----//
		if(inpkey == '\b' && n != 0) 
		{
			if(n == oneline-maxOneLine) {
				oneline -= maxOneLine;
				y--;
				gotoxy(x+maxOneLine, y);
			}
			printf("\b \b");
			input[n]='\0';
			n--;
		} else if(isprint(inpkey)){ //karakter yang bisa di print
			if(n == max) {
				continue;
			}
			else {
				if(n == oneline) {
					oneline += maxOneLine;
					y++;
					gotoxy(x, y);
				}
				printf("%c", inpkey);
				input[n]=inpkey;
				n++;
			}
		}
		else if(inpkey == 13)
		{
			if(n < min) {
				printf("\a");
				inpkey = 0;
			}
			else input[n]='\0';
		}
	}
	while(inpkey != 13 && inpkey!= 27);
	if(inpkey == 27){
		EscPressed = true;
	}
}

bool dateValid(DateTime Tgl) {
	bool valid;
    //check year
    if(Tgl.tahun>=1900 && Tgl.tahun<=9999)
    {
        //check month
        if(Tgl.bulan>=1 && Tgl.bulan<=12)
        {
            //check days
            if((Tgl.tgl>=1 && Tgl.tgl<=31) && (Tgl.bulan==1 || Tgl.bulan==3 || Tgl.bulan==5 || Tgl.bulan==7 || Tgl.bulan==8 || Tgl.bulan==10 || Tgl.bulan==12))
                valid = true;
            else if((Tgl.tgl>=1 && Tgl.tgl<=30) && (Tgl.bulan==4 || Tgl.bulan==6 || Tgl.bulan==9 || Tgl.bulan==11))
                valid = true;
            else if((Tgl.tgl>=1 && Tgl.tgl<=28) && (Tgl.bulan==2))
                valid = true;
            else if(Tgl.tgl==29 && Tgl.bulan==2 && (Tgl.tahun%400==0 ||(Tgl.tahun%4==0 && Tgl.tahun%100!=0)))
                valid = true;
            else
                valid = false;
        }
        else
        {
            valid = false;
        }
    }
    else
    {
        valid = false;
    }
    
    return valid;
}

bool isLeap(int y) 
{ 
    if (y%100 != 0 && y%4 == 0 || y %400 == 0) 
        return true; 
  
    return false; 
}

// Given a date, returns number of days elapsed 
// from the  beginning of the current year (1st 
// jan). 
int offsetDays(int d, int m, int y) 
{ 
    int offset = d; 
  
    switch (m - 1) 
    { 
    case 11: 
        offset += 30; 
    case 10: 
        offset += 31; 
    case 9: 
        offset += 30; 
    case 8: 
        offset += 31; 
    case 7: 
        offset += 31; 
    case 6: 
        offset += 30; 
    case 5: 
        offset += 31; 
    case 4: 
        offset += 30; 
    case 3: 
        offset += 31; 
    case 2: 
        offset += 28; 
    case 1: 
        offset += 31; 
    } 
  
    if (isLeap(y) && m > 2) 
        offset += 1; 
  
    return offset; 
} 
  
// Given a year and days elapsed in it, finds 
// date by storing results in d and m. 
void revoffsetDays(int offset, int y, int *d, int *m) 
{ 
    int month[13] = { 0, 31, 28, 31, 30, 31, 30, 
                      31, 31, 30, 31, 30, 31 }; 
  
    if (isLeap(y)) 
        month[2] = 29; 
  
    int i; 
    for (i = 1; i <= 12; i++) 
    { 
        if (offset <= month[i]) 
            break; 
        offset = offset - month[i]; 
    } 
  
    *d = offset; 
    *m = i; 
} 

void addDays(DateTime TglInp, DateTime *TglOut, int x) 
{ 
    int offset1 = offsetDays(TglInp.tgl, TglInp.bulan, TglInp.tahun); 
    int remDays = isLeap(TglInp.tahun) ? (366-offset1) : (365-offset1);
  
    // y2 is going to store result year and 
    // offset2 is going to store offset days 
    // in result year. 
    int y2, offset2; 
    if (x <= remDays) { 
        y2 = TglInp.tahun; 
        offset2 = offset1 + x; 
    } else { 
        // x may store thousands of days. 
        // We find correct year and offset 
        // in the year. 
        x -= remDays; 
        y2 = TglInp.tahun + 1; 
        int y2days = isLeap(y2)?366:365; 
        while (x >= y2days) 
        { 
            x -= y2days; 
            y2++; 
            y2days = isLeap(y2)?366:365; 
        } 
        offset2 = x; 
    } 
  
    // Find values of day and month from 
    // offset of result year. 
    int m2, d2; 
    revoffsetDays(offset2, y2, &d2, &m2); 
  	
  	/* Output Date */
  	TglOut->tgl = d2;
  	TglOut->bulan = m2;
  	TglOut->tahun = y2;
}

void DateTimeNow(DateTime *TglOutput) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	TglOutput->tgl = tm.tm_mday;
	TglOutput->bulan = tm.tm_mon+1;
	TglOutput->tahun = tm.tm_year+1900;
	TglOutput->sec = tm.tm_sec;
	TglOutput->min = tm.tm_min;
	TglOutput->hour = tm.tm_hour;
}

int calculateTotalDayDifference(struct tm pastDate, struct tm presentDate) {
    time_t pastTime = mktime(&pastDate);
    time_t presentTime = mktime(&presentDate);

    // Calculate total day difference
    return (int)difftime(presentTime, pastTime) / (60 * 60 * 24);
}

void dayDifference(int dd, int mm, int yy, int *diff){
	struct tm pastDate = {0};  // Initialize to all zeros
    struct tm presentDate = {0};

    // Set past date
    pastDate.tm_year = yy-1900;  // Years since 1900
    pastDate.tm_mon = mm-1;  // January (0-based)
    pastDate.tm_mday = dd;

    // Set present date (current date)
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    presentDate = *localTime;

    // Calculate total day difference
    *diff = calculateTotalDayDifference(pastDate, presentDate);
}
