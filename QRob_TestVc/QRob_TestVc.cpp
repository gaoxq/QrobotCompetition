// QRob_TestVc.cpp : Implementation of CQRob_TestVcApp and DLL registration.

#include "stdafx.h"
#include "QRob_TestVc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CQRob_TestVcApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xB617ACD7, 0x605E, 0x4B20, { 0xB4, 0x56, 0xB2, 0xA0, 0xEA, 0x89, 0x54, 0x44 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CQRob_TestVcApp::InitInstance - DLL initialization

BOOL CQRob_TestVcApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CQRob_TestVcApp::ExitInstance - DLL termination

int CQRob_TestVcApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
