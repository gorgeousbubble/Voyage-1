/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		utils.cpp
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-08
*/
#include "utils.h"
#include "resource.h"

HWND g_hWnd;
HINSTANCE g_hInstance;

//------------------------------------------------------------------
// @Function:	 MyRegisterClass(HINSTANCE hInstance)
// @Purpose: Win32 Register Class
// @Since: v1.00a
// @Para: HINSTANCE hInstance		// Window Instance
// @Para: T_WndParas* lpsWndPara	// Window Parameters
// @Return: ATOM(DWORD)				// Window ATOM Struct
//------------------------------------------------------------------
ATOM MyRegisterClass(HINSTANCE hInstance, T_WndParas* lpsWndPara)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(lpsWndPara->wIcon));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = MAKEINTRESOURCE(lpsWndPara->wIcon);
	wcex.lpszClassName = L"WinClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(lpsWndPara->wIcon));
	return RegisterClassEx(&wcex);
}

//------------------------------------------------------------------
// @Function:	 InitWndInstance(HINSTANCE hInstance, int nCmdShow)
// @Purpose: Win32 Initial Window Instance
// @Since: v1.00a
// @Para: HINSTANCE hInstance		// Window Instance
// @Para: int nCmdShow				// Command Code
// @Para: T_WndParas* lpsWndPara	// Window Parameters
// @Para: pCallBackInitWndExtra		// Window Callback
// @Return: BOOL					// Window Initial Result
//------------------------------------------------------------------
BOOL InitWndInstance(HINSTANCE hInstance, int nCmdShow, T_WndParas* lpsWndPara, LPCALLBACKINITWNDEXTRAFUNC pCallBackInitWndExtra)
{
	HWND hWnd;
	RECT Rect;

	// Set Window Rect & Adjust Window Property
	SetRect(&Rect, 0, 0, lpsWndPara->nWndWidth, lpsWndPara->nWndHeight);
	AdjustWindowRect(&Rect, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, false);
	// Create Window
	hWnd = CreateWindow(L"WinClass", lpsWndPara->lpszTitle, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, CW_USEDEFAULT, 0, (Rect.right - Rect.left), (Rect.bottom - Rect.top), NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		return FALSE;
	}

	// Global Variable Storage
	g_hWnd = hWnd;
	g_hInstance = hInstance;
	
	WINDOWINFO WindowInfo = { 0 };
	int nPosX = 0;
	int nPosY = 0;
	int nWindowWidth = 0;
	int nWindowHeight = 0;
	int nScreenWidth = 0;
	int nScreenHeight = 0;

	// Move Window to Screen Center
	GetWindowInfo(hWnd, &WindowInfo);
	nWindowWidth = Rect.right - Rect.left;
	nWindowHeight = Rect.bottom - Rect.top;
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	if (nScreenWidth > nWindowWidth && nScreenHeight > nWindowHeight)
	{
		nPosX = (nScreenWidth - nWindowWidth) >> 1;
		nPosY = (nScreenHeight - nWindowHeight) >> 1;
		SetWindowPos(hWnd, HWND_BOTTOM, nPosX, nPosY, 0, 0, SWP_NOSIZE);
	}

	// Jump to Execute Initial Window Extra function
	if (pCallBackInitWndExtra != NULL)
	{
		if (!(*pCallBackInitWndExtra)())
		{
			return FALSE;
		}
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//-----------------------------------------------------------------------------
// @Function:	 WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
// @Purpose: Win32 Initial Window Instance
// @Since: v1.00a
// @Para: HWND hWnd
// @Para: UINT message
// @Para: WPARAM wParam
// @Para: LPARAM lParam
// @Return: LRESULT
//-----------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		break;
	case WM_ERASEBKGND:
		break;
	case WM_KEYDOWN:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//-------------------------------------------------------------------------------------------------------
// @Function:	 InitWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// @Purpose: Win32 Initial WinMain
// @Since: v1.00a
// @Para: HINSTANCE hInstance
// @Para: HINSTANCE hPrevInstance
// @Para: LPSTR lpCmdLine
// @Para: int nCmdShow
// @Para: LPCALLBACKSETWNDPARAFUNC pCallBackSetWndPara
// @Para: LPCALLBACKINITWNDEXTRAFUNC pCallBackInitWndExtra
// @Return: HRESULT
//-------------------------------------------------------------------------------------------------------
HRESULT InitWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow, LPCALLBACKSETWNDPARAFUNC pCallBackSetWndPara, LPCALLBACKINITWNDEXTRAFUNC pCallBackInitWndExtra)
{
	T_WndParas* lpWndPara = NULL;
	BOOL bState;

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	lpWndPara = (*pCallBackSetWndPara)();
	MyRegisterClass(hInstance, lpWndPara);

	bState = InitWndInstance(hInstance, nCmdShow, lpWndPara, pCallBackInitWndExtra);
	if (!bState) return E_FAIL;
	
	bState = SetProcessDPIAware();
	if (!bState) return E_FAIL;

	return S_OK;
}

//-------------------------------------------------------------------------------------------------------
// @Function:	 WinMainLoop()
// @Purpose: Win32 WinMain Loop
// @Since: v1.00a
// @Para: LPCALLBACKDIRECT3DRENDERFUNC pCallBackDirect3DRender
// @Para: LPCALLBACKRELEASEWNDEXTRAFUNC pCallBackReleaseWndExtra
// @Return: None
//-------------------------------------------------------------------------------------------------------
int WinMainLoop(LPCALLBACKDIRECT3DRENDERFUNC pCallBackDirect3DRender, LPCALLBACKRELEASEWNDEXTRAFUNC pCallBackReleaseWndExtra)
{
	MSG msg;

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			(*pCallBackDirect3DRender)();
		}
	}

	if (pCallBackReleaseWndExtra != NULL)
	{
		(*pCallBackReleaseWndExtra)();
	}

	return (int)msg.wParam;
}