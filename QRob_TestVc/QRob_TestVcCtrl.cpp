// QRob_TestVcCtrl.cpp : Implementation of the CQRob_TestVcCtrl ActiveX Control class.

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "QRob_TestVcCtrl.h"
#include "QRob_TestVcPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CQRob_TestVcCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CQRob_TestVcCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CQRob_TestVcCtrl, COleControl)
	DISP_FUNCTION_ID(CQRob_TestVcCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CQRob_TestVcCtrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CQRob_TestVcCtrl, 1)
	PROPPAGEID(CQRob_TestVcPropPage::guid)
END_PROPPAGEIDS(CQRob_TestVcCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CQRob_TestVcCtrl, "QROB_TESTVC.QRob_TestVcCtrl.1",
	0xd81861fc, 0x364b, 0x44e1, 0x8d, 0x93, 0x5b, 0x6e, 0x63, 0xd1, 0x7f, 0x63)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CQRob_TestVcCtrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID BASED_CODE IID_DQRob_TestVc =
		{ 0xA89314B0, 0x2045, 0x478B, { 0xA8, 0x20, 0x58, 0x8F, 0xD, 0x3C, 0x51, 0xD3 } };
const IID BASED_CODE IID_DQRob_TestVcEvents =
		{ 0xF34063ED, 0x6096, 0x4D6C, { 0xB9, 0x3C, 0x7C, 0x25, 0xC1, 0xD9, 0xBC, 0x1 } };



// Control type information

static const DWORD BASED_CODE _dwQRob_TestVcOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CQRob_TestVcCtrl, IDS_QROB_TESTVC, _dwQRob_TestVcOleMisc)



// CQRob_TestVcCtrl::CQRob_TestVcCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CQRob_TestVcCtrl

BOOL CQRob_TestVcCtrl::CQRob_TestVcCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_QROB_TESTVC,
			IDB_QROB_TESTVC,
			afxRegApartmentThreading,
			_dwQRob_TestVcOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CQRob_TestVcCtrl::CQRob_TestVcCtrl - Constructor

CQRob_TestVcCtrl::CQRob_TestVcCtrl()
{
	InitializeIIDs(&IID_DQRob_TestVc, &IID_DQRob_TestVcEvents);
	// TODO: Initialize your control's instance data here.
}



// CQRob_TestVcCtrl::~CQRob_TestVcCtrl - Destructor

CQRob_TestVcCtrl::~CQRob_TestVcCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CQRob_TestVcCtrl::OnDraw - Drawing function

void CQRob_TestVcCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
// 	if (!pdc)
// 		return;
// 	// TODO: Replace the following code with your own drawing code.
// 	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
// 	pdc->Ellipse(rcBounds);
	if (!pdc)
		return;
	DoSuperclassPaint(pdc, rcBounds);
	m_dlgMian.MoveWindow(rcBounds, TRUE);
	CBrush brBackGnd(TranslateColor(AmbientBackColor()));
	pdc->FillRect(rcBounds, &brBackGnd);
}



// CQRob_TestVcCtrl::DoPropExchange - Persistence support

void CQRob_TestVcCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CQRob_TestVcCtrl::OnResetState - Reset control to default state

void CQRob_TestVcCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CQRob_TestVcCtrl::AboutBox - Display an "About" box to the user

void CQRob_TestVcCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_QROB_TESTVC);
	dlgAbout.DoModal();
}


// CQRob_TestVcCtrl message handlers

int CQRob_TestVcCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	AfxEnableControlContainer();
	AfxOleInit();
	CoInitialize(NULL);
	//COleObjectFactory::RegisterAll(); 
	// TODO:  Add your specialized creation code here
	if(!m_dlgMian.Create(IDD_DIALOG_MAIN, this))
	{
		AfxMessageBox(_T("Create Window Failed"));
	}
	m_dlgMian.ShowWindow(SW_SHOW);
	return 0;
}

BOOL CQRob_TestVcCtrl::IsSubclassedControl()
{
	return TRUE;
}

DWORD CQRob_TestVcCtrl::GetControlFlags()
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD dwFlags = COleControl::GetControlFlags();
	dwFlags |= noFlickerActivate;
	return dwFlags;
}

