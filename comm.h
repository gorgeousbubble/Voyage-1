/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2019, Gorgeous Bubble, alopex
*     All rights reserved.
*
* @proj     Voyage-1
* @file		comm.h
* @brief	The voyage main frame.
* @author	alopex
* @version	v1.00a
* @date		2019-10-08
*/
#pragma once

#ifndef __COMM_H__
#define __COMM_H__

// Include Windows header file
#include <Windows.h>

// Include CommCtrl header file
#include <CommCtrl.h>

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

// Include Cerasus(DirectX) library header file
#include "DirectCommon.h"
#include "DirectGraphics.h"
#include "DirectGraphics2D.h"
#include "DirectGraphics3D.h"
#include "DirectInput.h"
#include "DirectSound.h"
#include "DirectShow.h"
#include "DirectMesh.h"
#include "DirectTexture.h"
#include "DirectSurface.h"
#include "DirectSprite.h"
#include "DirectFont.h"

#include "CerasusAlgorithm.h"
#include "Cerasusfps.h"
#include "CerasusUnit.h"

#include "SakuraUICommon.h"
#include "SakuraBlend.h"
#include "SakuraElement.h"
#include "SakuraControl.h"
#include "SakuraStatic.h"
#include "SakuraButton.h"
#include "SakuraDialog.h"
#include "SakuraCheckBox.h"
#include "SakuraResource.h"

// Include Window framework header file
#include "proc.h"
#include "utils.h"

// Inlcude Cerasus(DirectX) static library
#pragma comment(lib, "Cerasus.lib")

#endif // !__COMM_H__