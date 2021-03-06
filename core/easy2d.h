/******************************************************
* Easy2D Game Framework
* 
* Website: http://www.easy2d.cn
* Source Code: https://github.com/Nomango/Easy2D
******************************************************/


#pragma once

#ifndef __cplusplus
	#error Easy2D is only for C++
#endif

#if _MSC_VER < 1600
	#error MSVC version is too low
#endif


#include "emacros.h"
#include "ecommon.h"
#include "ebase.h"
#include "emanagers.h"
#include "enodes.h"
#include "elisteners.h"
#include "etools.h"
#include "eactions.h"
#include "etransitions.h"
#include "egeometry.h"


#if defined(DEBUG) || defined(_DEBUG)
	#pragma comment(lib, "Easy2Ddw.lib")
#else
	#pragma comment(lib, "Easy2Dw.lib")
#endif


using namespace e2d;