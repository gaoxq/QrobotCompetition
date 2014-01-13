#pragma once

// QRob_TestVcPropPage.h : Declaration of the CQRob_TestVcPropPage property page class.


// CQRob_TestVcPropPage : See QRob_TestVcPropPage.cpp for implementation.

class CQRob_TestVcPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CQRob_TestVcPropPage)
	DECLARE_OLECREATE_EX(CQRob_TestVcPropPage)

// Constructor
public:
	CQRob_TestVcPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_QROB_TESTVC };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

