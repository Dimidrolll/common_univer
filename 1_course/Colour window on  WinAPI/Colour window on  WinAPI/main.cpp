#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <ctime>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HBRUSH brush = CreateSolidBrush(RGB(0,0,255));
void RunNotepad(void)
{
    STARTUPINFO sInfo;
    PROCESS_INFORMATION pInfo;

    ZeroMemory(&sInfo, sizeof(STARTUPINFO));

    puts("Starting Notepad...");
    CreateProcess(_T("C:\\Windows\\Notepad.exe"),
		          NULL, NULL, NULL, FALSE, 0, NULL, NULL, &sInfo, &pInfo);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND hMainWnd;
    MSG msg;
    WNDCLASSEX wc;
 
    wc.cbSize           = sizeof(wc);
    wc.style            = NULL;
    wc.lpfnWndProc      = WndProc;
    wc.cbClsExtra       = 0;
    wc.cbWndExtra       = 0;
    wc.hInstance        = hInstance;
    wc.hIcon            = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor          = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground    = brush;
    wc.lpszMenuName     = NULL;
    wc.lpszClassName    = L"MyClass";
    wc.hIconSm          = LoadIcon(NULL, IDI_APPLICATION);
 
    // регистрируем класс окна
    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, L"Cannot register class", L"Error", MB_OK);
        return 0;
    }

    hMainWnd = CreateWindow(
           L"MyClass",
           L"Colour Window",
           WS_OVERLAPPEDWINDOW, 
           CW_USEDEFAULT,       
           CW_USEDEFAULT,       
           320,                 
           240,                 
           HWND_DESKTOP,        
           NULL,                
           hInstance,       
           NULL                 
           );
    if (!hMainWnd)
    {
        MessageBox(NULL, L"Cannot create main window", L"Error", MB_OK);
        return 0;
    }
 
    ShowWindow(hMainWnd, nCmdShow);   
    
    // Выполняем цикл обработки сообщений до закрытия приложения
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    DeleteObject(brush);
    DestroyWindow(hMainWnd);
    UnregisterClass(L"MyClass", hInstance);
    return 0;
}
 
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        int x,y; //координаты

        case WM_LBUTTONDOWN:{
          x=LOWORD(lParam); //узнаём координаты
          y=HIWORD(lParam);
          RECT coord;
		      GetClientRect(hWnd, &coord);
		      long Ymid = (coord.top + coord.bottom) / 2;
		      long  Xmid = (coord.left + coord.right) / 2;
          
		      if (x >= coord.left && x <= Xmid && y <= Ymid && y >= coord.top)
		      {
            HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));
            
			      SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)hbrush);
            DeleteObject(brush);
			      InvalidateRect(hWnd, NULL, TRUE);
            brush = hbrush;
		      }
		      if (x >= coord.left && x <= Xmid && y <= coord.bottom && y >= Ymid)
		      {
            HBRUSH hbrush = CreateSolidBrush(RGB(0, 255, 0));
            
			      SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)hbrush);
            DeleteObject(brush);
			      InvalidateRect(hWnd, NULL, TRUE);
            brush = hbrush;
		      }
		      if (x >= Xmid && x <= coord.right && y <= Ymid && y >= coord.top)
		      {
            HBRUSH hbrush = CreateSolidBrush(RGB(255, 255, 0));
            
			      SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)hbrush);
            DeleteObject(brush);
			      InvalidateRect(hWnd, NULL, TRUE);
            brush = hbrush;
		      }
		      if (x >= Xmid && x <= coord.right && y <= coord.bottom && y >= Ymid)
		      {
            HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));
            
			      SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)hbrush);
            DeleteObject(brush);
			      InvalidateRect(hWnd, NULL, TRUE);
            brush = hbrush;
            
		      }
          
		      break;
        }
        case WM_KEYDOWN:
          if (wParam == 0x43){
            if (GetKeyState(VK_SHIFT) < 0)
                {
                RunNotepad();
                return(DefWindowProc(hWnd, uMsg, wParam, lParam));
                }
          }
          if (wParam == 0x51){
            if (GetKeyState(VK_CONTROL) < 0)//GetAsyncKeyState
                {
                PostQuitMessage(0);
                return 0;
                }
          }
          if (wParam == VK_ESCAPE){
            PostQuitMessage(0);
            return 0;
          }
          if (wParam == VK_RETURN){
            HBRUSH hbrush = CreateSolidBrush(RGB(rand()%256, rand()%256, rand()%256));
            SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)hbrush);
            DeleteObject(brush);
            InvalidateRect(hWnd, NULL, TRUE);
            brush = hbrush;
            return(DefWindowProc(hWnd, uMsg, wParam, lParam));
          }
          else {
            return(DefWindowProc(hWnd, uMsg, wParam, lParam));
            break;
          }
            /*switch(wParam){
              
              case 0x43: // shift+c
                if (GetKeyState(VK_SHIFT) < 0)
                {
                RunNotepad();
                return(DefWindowProc(hWnd, uMsg, wParam, lParam));
                break;
                }
              case 0x51: // ctrl+q
                if (GetKeyState(VK_CONTROL) < 0)//GetAsyncKeyState
                {
                PostQuitMessage(0);
                return 0;
                }break;
              case VK_ESCAPE: //esc
                PostQuitMessage(0);
                return 0;  
                break;
              case VK_RETURN: //enter
                //srand( time( 0 ) );//
                SetClassLong(hWnd, GCL_HBRBACKGROUND, (long)CreateSolidBrush(RGB(rand()%256, rand()%256, rand()%256)));
                InvalidateRect(hWnd, NULL, TRUE);
                return(DefWindowProc(hWnd, uMsg, wParam, lParam));
                break;
              
              default:
                return(DefWindowProc(hWnd, uMsg, wParam, lParam));               
                //break;
          */

        
        case WM_DESTROY:
          PostQuitMessage(0);
          break;
        
        default:
          return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
          break;
      }
      
     return 0;
}