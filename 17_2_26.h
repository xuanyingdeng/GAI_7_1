
// 17_2_26.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#define DIYI 1
#define DIY2 2
#define DIY9 9
// CMy17_2_26App:
// �йش����ʵ�֣������ 17_2_26.cpp
//

class CMy17_2_26App : public CWinApp
{
public:
	CMy17_2_26App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy17_2_26App theApp;
