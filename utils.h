/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		utils.h
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-08
*/
#pragma once

#ifndef __UTILS_H__
#define __UTILS_H__

// Include Windows header file
#include <Windows.h>

// Include ShellAPI header file
#include <shellapi.h>

// Include C/C++ running header file
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>

// Type Windows parameters
typedef struct T_WndParas {
	int nWndWidth;		// Window Area Width
	int nWndHeight;		// Window Area Height
	LPCWSTR lpszTitle;	// Window Title Name
	WORD wIcon;			// Window Icon Resource Number
} T_WndParas;

// Callback declaration
typedef T_WndParas* (CALLBACK* LPCALLBACKSETWNDPARAFUNC)();			// Init Window Parameter
typedef BOOL		(CALLBACK* LPCALLBACKINITWNDEXTRAFUNC)();		// Init Window Extra
typedef void		(CALLBACK* LPCALLBACKRELEASEWNDEXTRAFUNC)();	// Release Window Extra
typedef void		(CALLBACK* LPCALLBACKDIRECT3DRENDERFUNC)();		// Direct3D Render

// Variable declaration
extern HWND g_hWnd;
extern HINSTANCE g_hInstance;

// Function declaration
extern ATOM MyRegisterClass(HINSTANCE hInstance, T_WndParas* lpsWndPara);
extern BOOL InitWndInstance(HINSTANCE hInstance, int nCmdShow, T_WndParas* lpsWndPara, LPCALLBACKINITWNDEXTRAFUNC pCallBackInitWndExtra);
extern LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
extern HRESULT InitWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow, LPCALLBACKSETWNDPARAFUNC pCallBackSetWndPara, LPCALLBACKINITWNDEXTRAFUNC pCallBackInitWndExtra);
extern int WinMainLoop(LPCALLBACKDIRECT3DRENDERFUNC pCallBackDirect3DRender, LPCALLBACKRELEASEWNDEXTRAFUNC pCallBackReleaseWndExtra);

#endif // !__UTILS_H__