void remove_scrollbar()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);
    COORD bufferSize = {csbi.dwSize.X, 30};
    SetConsoleScreenBufferSize(hOut, bufferSize);
    SMALL_RECT windowSize = {0, 0, csbi.dwSize.X - 1, 19}; // Set the desired height
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);
}
void setFontStyle(int fontFamily) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fontInfo;
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    fontInfo.FontFamily = fontFamily;
    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}

void set_res(){
	DEVMODE dm;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);

    dm.dmPelsWidth = 1280;  // Set your desired width
    dm.dmPelsHeight = 800; // Set your desired height

    LONG result = ChangeDisplaySettings(&dm, 0);
    if (result != DISP_CHANGE_SUCCESSFUL) {
        fprintf(stderr, "Failed to change display settings\n");
        return ;
    }
}

void removeTextCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE; // Set the cursor visibility to FALSE (hidden)
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void setConsoleMode() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hInput, &mode);
    SetConsoleMode(hInput, mode & ~ENABLE_PROCESSED_INPUT);
}

void removeBlinkingCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void getRes(int *screenWidth, int *screenHeight){
	*screenWidth = GetSystemMetrics(SM_CXSCREEN);
    *screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

void fullscreen()
{
	system("color 74");
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
//	HWND hWnd = GetConsoleWindow();
//	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd,GWL_STYLE)&~WS_OVERLAPPEDWINDOW);
//	ShowWindow(hWnd,SW_MAXIMIZE);
	set_res();
	removeTextCursor();
	remove_scrollbar();
	//removeBlinkingCursor();
	setConsoleMode();
}

void default_res(int width, int height){
	DEVMODE dm;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);

    dm.dmPelsWidth = width;  // Set your desired width
    dm.dmPelsHeight = height; // Set your desired height
    LONG result = ChangeDisplaySettings(&dm, 0);
}

void EnterKey(char *press){
	do{
		*press = getch();
	}while(*press != 13);
}

void EnterEsc(char *press){
	do{
		*press = getch();
	}while(*press != 27 && *press != 13);
}

void gotoxy(int x, int y)
 {
 	static HANDLE h = NULL;
 	if(!h)
 	h = GetStdHandle(STD_OUTPUT_HANDLE);
 	COORD c = {x, y};
 	SetConsoleCursorPosition(h,c);
 }
 
void setColor(int foreground, int background) {
    int color = foreground + (background << 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setBlock(int width, int height, int foreground, int background, int x, int y) {
	int i,j,dx;
	dx = x;
    for (i = 0; i < height; i++) {
    	gotoxy(x,y);
        for (j = 0; j < width; j++) {
            // Print '*' for the border
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
            	setColor(foreground, background);
                printf(" ");
            } else {
                // Print a space for the inside of the box
                setColor(foreground, background);
                printf(" ");
            }
            x++;
        }
        // Move to the next line after each row
        x = dx;
        y++;
        printf("\n");
    }
}

void printBorder(int width, int height, int x, int y, int ascii) {
	int i,j,dx;
	dx = x;
    for (i = 0; i < height; i++) {
    	gotoxy(x,y);
        for (j = 0; j < width; j++) {
            // Print '*' for the border
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("%c", ascii);
            } else {
                // Print a space for the inside of the box
                printf(" ");
            }
            x++;
        }
        // Move to the next line after each row
        x = dx;
        y++;
        printf("\n");
    }
}

void drawBox(int x, int y, int width, int height, char topLeft, char horizontal, char topRight, char vertical, char bottomLeft, char bottomRight) {
    int i, j,dx;
    dx = x;
    // Draw the top side of the box
    gotoxy(x,y);
    printf("%c", topLeft);
    for (i = 1; i < width - 1; i++) {
        printf("%c", horizontal);
    }
    printf("%c\n", topRight);
    y++;
    // Draw the sides of the box
    for (i = 1; i < height - 1; i++) {
    	gotoxy(x,y);
        printf("%c", vertical);
        for (j = 1; j < width - 1; j++) {
            printf(" ");
        }
        printf("%c\n", vertical);
        y++;
    }
    // Draw the bottom side of the box
    x = dx;
    gotoxy(x,y);
    printf("%c", bottomLeft);
    for (i = 1; i < width - 1; i++) {
        printf("%c", horizontal);
    }
    printf("%c\n", bottomRight);
}

void customClr(int width, int height, int x, int y){
	int i,j,dx;
	dx = x;
    for (i = 0; i < height; i++) {
    	gotoxy(x,y);
        for (j = 0; j < width; j++) {
            // Print '*' for the border
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf(" ");
            } else {
                printf(" ");
            }
            x++;
        }
        // Move to the next line after each row
        x = dx;
        y++;
        printf("\n");
    }
}


void PrintFile(char file[], int x, int y)
{
	FILE *Text;
	char Data[200];
	if((Text=fopen(file, "r")) == NULL)
	{
		system("cls");
	}
	while(fgets(Data, 200, Text))
	{
		gotoxy(x, y);
		printf("%s", Data);
		y++;
	}
	fclose(Text);
}

void cvrUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void getTime(int *day,int *month, int *year){
	time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    *day = localTime->tm_mday;
    *month = localTime->tm_mon + 1;
    *year = localTime->tm_year + 1900;
}


int compareDates(pDate,pMonth,pYear,nDate,nMonth,nYear) {
    if (pYear < nYear)
        return -1;
    else if (pYear > nYear)
        return 1;
    else {
        // Years are equal, compare months
        if (pMonth < nMonth)
            return -1;
        else if (pMonth > nMonth)
            return 1;
        else {
            // Months are equal, compare days
            if (pDate < nDate)
                return -1;
            else if (pDate > nDate)
                return 1;
            else
                return 0; // Dates are equal
        }
    }
}

int NIK_Check(const char *str_num1, const char *str_num2) {
    // Convert strings to long long
    long long num1 = atoll(str_num1);
    long long num2 = atoll(str_num2);

    // Compare numerical values
    if (num1 == num2) {
        return 0;  // Numbers are equal
    } else if (num1 < num2) {
        return -1; // num1 is less than num2
    } else {
        return 1;  // num1 is greater than num2
    }
}

void setPrsDate(){
	int date,month,year;
	time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    // Get the current day of the week (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
    int currentDayOfWeek = localTime->tm_wday;

    // Array of day names
    char dayNames[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	getTime(&date,&month,&year);
	char months[12][15] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	char pMonth[10];
	strcpy(pMonth,months[month-1]);
	printf("%s, %d %s %d",dayNames[currentDayOfWeek],date,pMonth,year);
}

void clrDb(){
	customClr(116,31,40,17);
}

void clrMenArrow(int height, int x, int y){
	customClr(1,height,x,y);
}

void clrMainMenu(){
	customClr(17,14,12,18);
}
