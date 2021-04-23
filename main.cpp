#include <tchar.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>

#define ID_RADIO_1 0
#define ID_RADIO_2 1
#define ID_RADIO_3 2
#define ID_CHECK 3
#define ID_PUSH 4


using namespace std;


int time=50;
int i=0,score=0;
int scores[3][3];

LPTSTR Answers[4] = {"Care este cea mai buna universitate din MD?",
                     "400 + 20? ","Anul fondarii UTM?", "The End!"};
LPTSTR Response[4][4] = {{"UTM", "ULIM", "Asem"} ,{"10", "420", "-5"} , {"1964" ,"1973"," 1955"}};

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");


HWND *hwndButton= new HWND[10];
HINSTANCE hInstancee;

int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WndProc;
    wincl.style = CS_DBLCLKS |  CS_HREDRAW | CS_VREDRAW ;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) GetStockObject(RGB(125,125,125));

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
            0,
            szClassName,
            _T("Lab 4-5"),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            500,
            600,
            NULL,
            NULL,
            hThisInstance,
            NULL
    );


    ShowWindow (hwnd, nCmdShow);
    UpdateWindow(hwnd);
    SetTimer(hwnd,0,1000,NULL);


    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}


LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    HDC hdc;
    PAINTSTRUCT ps;
    RECT rc;
    HINSTANCE hInstancee;
    char buffer[20];
    LPTSTR str;
    switch (message)
    {

        case WM_TIMER :
            time--;
            InvalidateRect(hwnd,NULL,FALSE);
            break;

        case WM_COMMAND:

            for(int j = 0; j < 3; j++){
                scores[i][j] = (int)SendMessage (hwndButton[j], BM_GETCHECK, 0, 0);
                score = scores[0][0] + scores[1][1] + scores[2][0];
            }

            if(LOWORD(wParam)==ID_PUSH){
                if((int)SendMessage (hwndButton[3], BM_GETCHECK, 0, 0)){
                    time-=10;
                    i+=1;
                    DestroyWindow(hwndButton[0]);
                    DestroyWindow(hwndButton[1]);
                    DestroyWindow(hwndButton[2]);
                    DestroyWindow(hwndButton[3]);
                    DestroyWindow(hwndButton[4]);
                    SendMessage(hwnd,WM_CREATE,wParam,lParam);
                }}
            break;

        case WM_CREATE:
            if(i<3){

                hInstancee = (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE);
                hwndButton[0] = CreateWindowEx(0,"BUTTON", Response[i][0], WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON ,10,50,150,40,hwnd, (HMENU)ID_RADIO_1, hInstancee,NULL);
                hwndButton[1] = CreateWindowEx(0,"BUTTON", Response[i][1], WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,10,90,150,40,hwnd, (HMENU)ID_RADIO_2, hInstancee,NULL);
                hwndButton[2] = CreateWindowEx(0,"BUTTON", Response[i][2], WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,10,130,150,40,hwnd, (HMENU)ID_RADIO_3, hInstancee,NULL);
                hwndButton[3] = CreateWindowEx(0,"BUTTON", "Confirm", WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,10,175,150,20,hwnd, (HMENU)ID_CHECK, hInstancee,NULL);
                hwndButton[4] = CreateWindowEx(0,"BUTTON", "Send", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,10,200,100,20,hwnd, (HMENU)ID_PUSH, hInstancee,NULL);

                InvalidateRect(hwnd,NULL,FALSE);
            }
            else{
                DestroyWindow(hwndButton[0]);
                DestroyWindow(hwndButton[1]);
                DestroyWindow(hwndButton[2]);
                DestroyWindow(hwndButton[3]);
                DestroyWindow(hwndButton[4]);

                SendMessage(hwnd,WM_PAINT,wParam,lParam);
            }
            break;

        case WM_PAINT:

            hdc = BeginPaint(hwnd,&ps);
            GetClientRect(hwnd, &rc);
            SelectObject(hdc, CreateSolidBrush(RGB(255,255,255)));
            SelectObject (hdc, GetStockObject (NULL_PEN));
            Rectangle(hdc,0,0,500,600);

            if(i==3){
                str = "Felicitari!!!";
                TextOut(hdc,0,0,str,strlen(str));
                wsprintfA(buffer,"Scorul tau: %d", score);
                str = buffer;
                TextOut(hdc,0,20,str,strlen(str));
                time=0;
            }


            if(time > 0) {
                SelectObject (hdc, GetStockObject (NULL_PEN));
                Rectangle(hdc,0,0,350,20);
                wsprintfA(buffer,"TIME: %d", time);
                str = buffer;
                TextOut(hdc,0,0,str,strlen(str));
                TextOut(hdc,20,20,Answers[i],strlen(Answers[i]));
            }
            else if(i<3){
                DestroyWindow(hwndButton[0]);
                DestroyWindow(hwndButton[1]);
                DestroyWindow(hwndButton[2]);

                DestroyWindow(hwndButton[3]);
                DestroyWindow(hwndButton[4]);
                str = "Sorry time is up!";
                TextOut(hdc,0,0,str,strlen(str));
                wsprintfA(buffer,"Your score: %d", score);
                LPCSTR str = buffer;
                TextOut(hdc,0,20,str,strlen(str));
            }            DeleteDC(hdc);
            break;

        case WM_DESTROY:
            KillTimer(hwnd,0);
            PostQuitMessage (0);
            return 0 ;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
