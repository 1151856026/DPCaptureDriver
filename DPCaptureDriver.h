
// DPCaptureDriver.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDPCaptureDriverApp:
// �йش����ʵ�֣������ DPCaptureDriver.cpp
//

class CDPCaptureDriverApp : public CWinApp
{
public:
	CDPCaptureDriverApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDPCaptureDriverApp theApp;