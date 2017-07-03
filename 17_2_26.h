
// 17_2_26.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#define DIYI 1
#define DIY2 2
#define DIY9 9
// CMy17_2_26App:
// 有关此类的实现，请参阅 17_2_26.cpp
//

class CMy17_2_26App : public CWinApp
{
public:
	CMy17_2_26App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMy17_2_26App theApp;
