
// MFCApplicationSPC2.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCApplicationSPC2App: 
// �аѾ\��@�����O�� MFCApplicationSPC2.cpp
//

class CMFCApplicationSPC2App : public CWinApp
{
public:
	CMFCApplicationSPC2App();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplicationSPC2App theApp;