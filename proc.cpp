/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		proc.cpp
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-12
*/
#include "proc.h"
#include "utils.h"

float g_fLastTime = 0.0f;
float g_fCurrentTime = 0.0f;
float g_fDeltaTime = 0.0f;

//------------------------------------------------------------------
// @Function:	 SetWindowParameterCallback()
// @Purpose: WinMain Set Parameter Callback
// @Since: v1.00a
// @Para: None
// @Return: WndPara*
//------------------------------------------------------------------
T_WndParas* SetWindowParameterCallback()
{
	T_WndParas* pWndParas = new T_WndParas;
	pWndParas->nWndWidth = USER_SCREEN_WIDTH;
	pWndParas->nWndHeight = USER_SCREEN_HEIGHT;
	pWndParas->lpszTitle = USER_WINDOW_TITLE;
	pWndParas->wIcon = USER_WINDOW_ICON;
	return pWndParas;
}

//------------------------------------------------------------------
// @Function:	 InitWindowExtraCallback()
// @Purpose: WinMain Init Extra Callback(DirectX Init)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
BOOL InitWindowExtraCallback()
{
	// DirectX Init Extra...
	return TRUE;
}

//------------------------------------------------------------------
// @Function:	 ReleaseWindowExtraCallback()
// @Purpose: WinMain Release Extra Callback(DirectX Release)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void ReleaseWindowExtraCallback()
{
	// DirectX Release Extra...
}

//------------------------------------------------------------------
// @Function:	 Direct3DRenderCallback()
// @Purpose: Direct3D Update & Render Callback(DirectX Update & DirectX Render)
// @Since: v1.00a
// @Para: None
// @Return: None
//------------------------------------------------------------------
void Direct3DRenderCallback()
{
	g_fLastTime = (float)timeGetTime() * 0.001f;

	// DirectX Update & DirectX Render...
	
	g_fCurrentTime = (float)timeGetTime() * 0.001f;
	g_fDeltaTime = g_fCurrentTime - g_fLastTime;
}