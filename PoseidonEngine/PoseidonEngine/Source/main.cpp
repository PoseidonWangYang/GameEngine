
#include <Windows.h>

//ȫ�ֱ�������  
HINSTANCE hInst;  
HBITMAP hbmp;  
HDC     mdc;  
  
//ȫ�ֺ���������  
ATOM                MyRegisterClass(HINSTANCE hInstance);  
BOOL                InitInstance(HINSTANCE, int);  
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);  
void                MyPaint(HDC hdc);  
  
//****�D�DWinmain������������ڵ㺯��**************************************  
int APIENTRY WinMain(HINSTANCE hInstance,  
                     HINSTANCE hPrevInstance,  
                     LPSTR     lpCmdLine,  
                     int       nCmdShow)  
{  
    MSG msg;  
  
    MyRegisterClass(hInstance);  
  
    if (!InitInstance (hInstance, nCmdShow))   
    {  
        return FALSE;  
    }  
  
    //��Ϣѭ��  
    while (GetMessage(&msg, NULL, 0, 0))   
    {  
        TranslateMessage(&msg);  
        DispatchMessage(&msg);  
    }  
      
    return msg.wParam;  
}  
  
//****�w���һ�������࣬��������⣬ʹ�ô��ڽṹ��*************************  
ATOM MyRegisterClass(HINSTANCE hInstance)  
{  
    WNDCLASSEX wcex;  
  
    wcex.cbSize = sizeof(WNDCLASSEX);   
    wcex.style          = CS_HREDRAW | CS_VREDRAW;  
    wcex.lpfnWndProc    = (WNDPROC)WndProc;  
    wcex.cbClsExtra     = 0;  
    wcex.cbWndExtra     = 0;  
    wcex.hInstance      = hInstance;  
    wcex.hIcon          = NULL;  
    wcex.hCursor        = NULL;  
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);  
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);  
    wcex.lpszMenuName   = NULL;  
    wcex.lpszClassName  = L"canvas";  
    wcex.hIconSm        = NULL;  
  
    return RegisterClassEx(&wcex);  
}  
  
//****��ʼ������*************************************  
// 1.�����봰��DC���ݵ��ڴ�DC  
// 2.���ļ�����λͼ�������ڴ�DC��  
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)  
{  
    HWND hWnd;  
    HDC hdc;  
  
    hInst = hInstance;  
  
    hWnd = CreateWindow(L"canvas", L"PoseidonEngine" , WS_OVERLAPPEDWINDOW,  
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);  
  
    if (!hWnd)  
    {  
        return FALSE;  
    }  
  
    MoveWindow(hWnd,10,10,800,600,true);  
    ShowWindow(hWnd, nCmdShow);  
    UpdateWindow(hWnd);  
  
    hdc = GetDC(hWnd);  
    mdc = CreateCompatibleDC(hdc);  
  
    hbmp = (HBITMAP)LoadImage(NULL,L"bg.bmp",IMAGE_BITMAP,800,600,LR_LOADFROMFILE);   
    SelectObject(mdc,hbmp);  
  
    MyPaint(hdc);  
    ReleaseDC(hWnd,hdc);  
  
    return TRUE;  
}  
  
//****�Զ����ͼ����*********************************  
void MyPaint(HDC hdc)  
{  
    BitBlt(hdc,0,0,800,600,mdc,0,0,SRCCOPY);    //����BitBlt������ͼ  
}  
  
//****��Ϣ������**********************************  
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  
{  
    PAINTSTRUCT ps;  
    HDC hdc;  
  
    switch (message)  
    {  
        case WM_PAINT:                      //�����ػ���Ϣ  
            hdc = BeginPaint(hWnd, &ps);  
            MyPaint(hdc);  
            EndPaint(hWnd, &ps);  
            break;  
        case WM_DESTROY:                    //���ڽ�����Ϣ  
            DeleteDC(mdc);  
            DeleteObject(hbmp);  
            PostQuitMessage(0);  
            break;  
        default:                            //������Ϣ  
            return DefWindowProc(hWnd, message, wParam, lParam);  
   }  
   return 0;  
}  