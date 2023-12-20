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
        return 1;
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

void fullscreen()
{
	system("color 74");
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	set_res();
	removeTextCursor();
	remove_scrollbar();
	removeBlinkingCursor();
	setConsoleMode();
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

void printBox(int width, int height, int foreground, int background, int x, int y) {
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

void drawBox(int width, int height, char topLeft, char topRight, char bottomLeft, char bottomRight) {
	int i,j;
    // Check if the dimensions are valid
    if (width <= 0 || height <= 0) {
        printf("Invalid dimensions for the box.\n");
        return;
    }

    // Draw the top side of the box
    printf("%c ", topLeft);
    for (i = 1; i < width - 1; i++) {
        printf("* ");
    }
    printf("%c\n", topRight);

    // Draw the sides of the box
    for (i = 1; i < height - 1; i++) {
        printf("*");
        for (j = 1; j < width - 1; j++) {
            printf("  ");
        }
        printf("*\n");
    }

    // Draw the bottom side of the box
    printf("%c ", bottomLeft);
    for (i = 1; i < width - 1; i++) {
        printf("* ");
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

void clrLeft(){
	
}

void clrMidd(){
	
}

void clrRight(){
	
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

//void LRMenu(){
//	while (1) {
//        INPUT_RECORD ir[1];
//        DWORD count;
//
//        if (ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ir, 1, &count)) {
//            if (count && ir[0].EventType == KEY_EVENT && ir[0].Event.KeyEvent.bKeyDown) {
//                if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
//                    printf("Left arrow key pressed!\n");
//                }else if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
//                    printf("Right arrow key pressed!\n");
//                }else if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_RETURN) {
//                    printf("Enter key pressed!\n");
//                }
//            }
//        }
//    }
//}
//
//void UDMenu(){
//	while (1) {
//        INPUT_RECORD ir[1];
//        DWORD count;
//
//        if (ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), ir, 1, &count)) {
//            if (count && ir[0].EventType == KEY_EVENT && ir[0].Event.KeyEvent.bKeyDown) {
//                if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_RETURN) {
//                    printf("Enter key pressed!\n");
//                }else if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_UP) {
//                    printf("Up Arrow key pressed!\n");
//                }else if (ir[0].Event.KeyEvent.wVirtualKeyCode == VK_DOWN) {
//                    printf("Down Arrow key pressed!\n");
//                }
//            }
//        }
//    }
//}

//void UpArrow(char *press){
//	do{
//		*press = getch();
//	}while(*press != 65);
//}
//
//void DownArrow(char *press){
//	do{
//		*press = getch();
//	}while(*press != 66);
//}

//void RightArrow(char *press){
//	do{
//		*press = getch();
//	}while(*press != 67);
//}
//
//void LeftArrow(char *press){
//	do{
//		*press = getch();
//	}while(*press != 66);
//}

//void LRKey(char *press){
//	do{
//		*press = getch();
//	}while(*press != 75 || *press != 77 || *press != 27 || *press != 13);
//}
//
//void UDKey(char *press){
//	do{
//		*press = getch();
//	}while(*press != 72 || *press != 80 || *press != 27 || *press != 13);
//}
//void clrBox(int width, int height, int x, int y) {
//	int i,j,dx;
//	dx = x;
//    for (i = 0; i < height; i++) {
//    	gotoxy(x,y);
//        for (j = 0; j < width; j++) {
//            // Print '*' for the border
//            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
//                printf(" ");
//            } else {
//                // Print a space for the inside of the box
//                printf(" ");
//            }
//            x++;
//        }
//        // Move to the next line after each row
//        x = dx;
//        y++;
//        printf("\n");
//    }
//}
