// QRob_TestVcPropPage.cpp : Implementation of the CQRob_TestVcPropPage property page class.

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "QRob_TestVcPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_TestVcPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CQRob_TestVcPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CQRob_TestVcPropPage, "QROB_TESTVC.QRob_TestVcPropPage.1",
	0xef4c92ea, 0xf0c0, 0x4318, 0xa1, 0xe0, 0xac, 0x3b, 0x31, 0x6d, 0xda, 0x3d)



// CQRob_TestVcPropPage::CQRob_TestVcPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CQRob_TestVcPropPage

BOOL CQRob_TestVcPropPage::CQRob_TestVcPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_QROB_TESTVC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CQRob_TestVcPropPage::CQRob_TestVcPropPage - Constructor

CQRob_TestVcPropPage::CQRob_TestVcPropPage() :
	COlePropertyPage(IDD, IDS_QROB_TESTVC_PPG_CAPTION)
{
}



// CQRob_TestVcPropPage::DoDataExchange - Moves data between page and properties

void CQRob_TestVcPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CQRob_TestVcPropPage message handlers
