/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		proc.h
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-12
*/
#pragma once

#ifndef __PROC_H__
#define __PROC_H__

// Include Utils header file
#include "utils.h"

// Include Resource header file
#include "resource.h"

// User definition
#define USER_SCREEN_WIDTH	960
#define USER_SCREEN_HEIGHT	720
#define USER_WINDOW_TITLE	L"Voyage-1"
#define USER_WINDOW_ICON	(WORD)IDI_ICON

// Variable declaration
extern float g_fLastTime;
extern float g_fCurrentTime;
extern float g_fDeltaTime;

// Function declaration
extern T_WndParas* SetWindowParameterCallback();
extern BOOL InitWindowExtraCallback();
extern void ReleaseWindowExtraCallback();
extern void Direct3DRenderCallback();

#endif // !__PROC_H__