#pragma once
#include "DlgMain.h"
// QRob_TestVcCtrl.h : Declaration of the CQRob_TestVcCtrl ActiveX Control class.


// CQRob_TestVcCtrl : See QRob_TestVcCtrl.cpp for implementation.

class CQRob_TestVcCtrl : public COleControl
{
	DECLARE_DYNCREATE(CQRob_TestVcCtrl)

// Constructor
public:
	CQRob_TestVcCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
public:
	CDlgMain m_dlgMian;
// Implementation
protected:
	~CQRob_TestVcCtrl();

	DECLARE_OLECREATE_EX(CQRob_TestVcCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CQRob_TestVcCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CQRob_TestVcCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CQRob_TestVcCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	};

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual DWORD GetControlFlags();
	virtual BOOL IsSubclassedControl();
};

