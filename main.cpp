/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		main.cpp
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-08
*/
#include "comm.h"

/*
** WinMain(IN HINSTANCE hInstance, IN HINSTANCE hPrevInstance, IN LPSTR lpCmdLine, IN int nCmdShow)
** Purpose:  WinMain
** Para: IN HINSTANCE hInstance
** Para: IN HINSTANCE hPrevInstance
** Para: IN LPSTR lpCmdLine
** Para: IN int nCmdShow
** Return: INT Msg
*/
int WINAPI WinMain(IN HINSTANCE hInstance, IN HINSTANCE hPrevInstance, IN LPSTR lpCmdLine, IN int nCmdShow)
{
	int Msg;
	HRESULT hr;

	hr = InitWinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow, (LPCALLBACKSETWNDPARAFUNC)(&SetWindowParameterCallback), (LPCALLBACKINITWNDEXTRAFUNC)(&InitWindowExtraCallback));
	if (FAILED(hr))
	{
		return -1;
	}

	Msg = WinMainLoop((LPCALLBACKDIRECT3DRENDERFUNC)(&Direct3DRenderCallback), (LPCALLBACKRELEASEWNDEXTRAFUNC)(&ReleaseWindowExtraCallback));

	return Msg;
}