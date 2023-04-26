#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

//ID'S FOR BUTTONS
#define ID_BUT1 911
#define ID_BUT2 912
#define ID_BUT3 913
#define ID_BUT4 914
#define ID_BUT5 915
#define ID_BUT6 916
#define ID_BUT7 917
#define ID_BUT8 918
#define ID_BUT9 919
#define ID_BUT0 920
#define ID_BUTent 921
#define ID_BUT_rty 922

//CONST VALUES
#define scr_width 400
#define scr_height 400
#define btn_size 50
#define offset 10
#define pos_x 100
#define pos_y 90

#define password "000000" //Your Password here

int tries = 5;
HWND hTextBox;
HWND butt_1, butt_2, butt_3, butt_4, butt_5, butt_6, butt_7, butt_8, butt_9, butt_0, butt_enter, butt_retry;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const char CLASS_NAME[] = "Pass Lock"; //App Name

	WNDCLASS app = {};

	app.lpfnWndProc   = WindowProc;
    app.hInstance     = hInstance;
    app.lpszClassName = CLASS_NAME;

    RegisterClass(&app);

    HWND appx = CreateWindowEx(0,CLASS_NAME,"ULOCK"/*Display Name*/,WS_OVERLAPPEDWINDOW, 500, 350, scr_width, scr_height,NULL,NULL,hInstance,NULL);

    if (appx == NULL){
    	return 0;
    }

    hTextBox = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
        pos_x, 30, 110, 30, appx, NULL, hInstance, NULL);

   	butt_1 = CreateWindowEx(0,"BUTTON","1",WS_VISIBLE|WS_CHILD, pos_x, pos_y, btn_size, btn_size, appx,(HMENU)ID_BUT1,hInstance,NULL);
    butt_2 = CreateWindowEx(0,"BUTTON","2",WS_VISIBLE|WS_CHILD, pos_x + btn_size + offset, pos_y, btn_size, btn_size, appx,(HMENU)ID_BUT2,hInstance,NULL);
    butt_3 = CreateWindowEx(0,"BUTTON","3",WS_VISIBLE|WS_CHILD, pos_x + 2*(btn_size + offset), pos_y, btn_size, btn_size, appx,(HMENU)ID_BUT3,hInstance,NULL);
    butt_4 = CreateWindowEx(0,"BUTTON","4",WS_VISIBLE|WS_CHILD, pos_x, pos_y + btn_size + offset, btn_size, btn_size, appx,(HMENU)ID_BUT4,hInstance,NULL);
    butt_5 = CreateWindowEx(0,"BUTTON","5",WS_VISIBLE|WS_CHILD, pos_x + btn_size + offset, pos_y + btn_size + offset, btn_size, btn_size, appx,(HMENU)ID_BUT5,hInstance,NULL);
    butt_6 = CreateWindowEx(0,"BUTTON","6",WS_VISIBLE|WS_CHILD, pos_x + 2*(btn_size + offset), pos_y + btn_size + offset, btn_size, btn_size, appx,(HMENU)ID_BUT6,hInstance,NULL);
    butt_7 = CreateWindowEx(0,"BUTTON","7",WS_VISIBLE|WS_CHILD, pos_x, pos_y + 2*(btn_size + offset), btn_size, btn_size, appx,(HMENU)ID_BUT7,hInstance,NULL);
    butt_8 = CreateWindowEx(0,"BUTTON","8",WS_VISIBLE|WS_CHILD, pos_x + btn_size + offset, pos_y + 2*(btn_size + offset), btn_size, btn_size, appx,(HMENU)ID_BUT8,hInstance,NULL);
    butt_9 = CreateWindowEx(0,"BUTTON","9",WS_VISIBLE|WS_CHILD, pos_x + 2*(btn_size + offset), pos_y + 2*(btn_size + offset), btn_size, btn_size, appx,(HMENU)ID_BUT9,hInstance,NULL);
    butt_0 = CreateWindowEx(0,"BUTTON","0",WS_VISIBLE|WS_CHILD, pos_x, pos_y + 3*(btn_size + offset), btn_size, btn_size, appx,(HMENU)ID_BUT0,hInstance,NULL);
    butt_retry = CreateWindowEx(0,"BUTTON","C",WS_VISIBLE|WS_CHILD,pos_x + 110 + offset, 30, btn_size, 30, appx,(HMENU)ID_BUT_rty,hInstance,NULL);
    butt_enter = CreateWindowEx(0,"BUTTON","ENTER",WS_VISIBLE|WS_CHILD, pos_x + btn_size + offset, pos_y + 3*(btn_size + offset), (2*btn_size) + offset, btn_size, appx,(HMENU)ID_BUTent,hInstance,NULL);

    ShowWindow(appx, nCmdShow);

    MSG msg = {};

    while(GetMessage(&msg,NULL,0,0)){
    	TranslateMessage(&msg);
    	DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	switch(uMsg){

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+3));
			EndPaint(hwnd, &ps);
		}
		return 0;

	case WM_COMMAND:
	{	
		if (tries == 1){
			exit(0);
		}
		int text_len = SendMessage(hTextBox,WM_GETTEXTLENGTH,0,0);
		if (text_len<6){

	    if (HIWORD(wParam) == BN_CLICKED)
	    {
	        if (LOWORD(wParam) == ID_BUT1)
	        {	
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"1");
	        }
	        else if (LOWORD(wParam) == ID_BUT2)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"2");
	        }
	        else if (LOWORD(wParam) == ID_BUT3)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"3");
	        }
	        else if (LOWORD(wParam) == ID_BUT4)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"4");
	        }
	        else if (LOWORD(wParam) == ID_BUT5)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"5");
	        }
	        else if (LOWORD(wParam) == ID_BUT6)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"6");
	       	}
	       	else if (LOWORD(wParam) == ID_BUT7)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"7");
	        }
	        else if (LOWORD(wParam) == ID_BUT8)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"8");
	        }
	        else if (LOWORD(wParam) == ID_BUT9)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"9");
	        }
	        else if (LOWORD(wParam) == ID_BUT0)
	        {
	            SendMessage(hTextBox,EM_REPLACESEL, 0, (LPARAM)"0");
	        }
	     }
		}
	    if (HIWORD(wParam) == BN_CLICKED){

	        if (LOWORD(wParam) == ID_BUTent)
	        {
	        	char buffer[256];
	           	GetWindowText(hTextBox, buffer, 256);
	           	std::string bfr_txt(buffer);
	           	if (bfr_txt == password){
	           		SetWindowText(hTextBox, TEXT("CORRECT PASS"));
	           	}
	           	else{
	           		SetWindowText(hTextBox, TEXT("WRONG PASS"));
	           		tries--;
	           		cout << "Tries Left: " << tries << endl;
	           	}
	        }
	        else if (LOWORD(wParam) == ID_BUT_rty){
	        	char buffer[256];
	           	GetWindowText(hTextBox, buffer, 256);
	           	std::string bfr_txt(buffer);
	           	bfr_txt.erase();
	           	const char* bfr = bfr_txt.c_str();
	           	SetWindowText(hTextBox, bfr);	
	        }
    	}
    	break;
	}
 }
return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
