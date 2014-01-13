#pragma once
#include "qroboteventctrl1.h"
#include "CQrobotSpeak.h"

// CDlgMain dialog

class CDlgMain : public CDialog
{
	DECLARE_DYNAMIC(CDlgMain)

public:
	CDlgMain(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMain();

// Dialog Data
	enum { IDD = IDD_DIALOG_MAIN };
public:
	CQrobotSpeak m_speak;
	CQrobotTalk m_speak;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void InitModuleQroboteventctrl1();
	CQroboteventctrl1 m_eventCtrl;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	void CreateModuleWindowQroboteventctrl1(long top, long left, long width, long height);
};
