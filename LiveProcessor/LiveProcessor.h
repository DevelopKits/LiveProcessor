
// LiveProcessor.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLiveProcessorApp: 
// �йش����ʵ�֣������ LiveProcessor.cpp
//

class CLiveProcessorApp : public CWinApp
{
public:
	CLiveProcessorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLiveProcessorApp theApp;