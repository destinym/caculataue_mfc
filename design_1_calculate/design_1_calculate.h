
// design_1_calculate.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cdesign_1_calculateApp:
// �йش����ʵ�֣������ design_1_calculate.cpp
//

class Cdesign_1_calculateApp : public CWinApp
{
public:
	Cdesign_1_calculateApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cdesign_1_calculateApp theApp;