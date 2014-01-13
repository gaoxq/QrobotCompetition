#pragma once

// QRob_TestVc.h : main header file for QRob_TestVc.DLL

#if !defined( __AFXCTL_H__ )
#error "include 'afxctl.h' before including this file"
#endif

#include "resource.h"       // main symbols


// CQRob_TestVcApp : See QRob_TestVc.cpp for implementation.

class CQRob_TestVcApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

