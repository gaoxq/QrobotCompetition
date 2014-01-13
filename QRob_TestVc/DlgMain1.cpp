// DlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "DlgMain.h"


// CDlgMain dialog

IMPLEMENT_DYNAMIC(CDlgMain, CDialog)

CDlgMain::CDlgMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMain::IDD, pParent)
{

}

CDlgMain::~CDlgMain()
{
}

void CDlgMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_QROBOTEVENTCTRL1, m_eventCtrl);
}


BEGIN_MESSAGE_MAP(CDlgMain, CDialog)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgMain::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDlgMain message handlers
BEGIN_EVENTSINK_MAP(CDlgMain, CDialog)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 1, CDlgMain::InitModuleQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 2, CDlgMain::CreateModuleWindowQroboteventctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
END_EVENTSINK_MAP()

int CDlgMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	// TODO:  Add your specialized creation code here
	m_eventCtrl.MoveWindow(CRect(0,0,0,0));
	return 0;
}

void CDlgMain::InitModuleQroboteventctrl1()
{
	// TODO: Add your message handler code here
	if(!m_speak.CreateDispatch(_T("QrobotInterface.Speak.1")))
	{
		AfxMessageBox(_T("Create Dispach Failed"));
	}
	m_speak.QroSpeakInitial();
}

void CDlgMain::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgMain::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}

void CDlgMain::CreateModuleWindowQroboteventctrl1(long top, long left, long width, long height)
{
	// TODO: Add your message handler code here
	m_speak.AddTextToPlayList(_T("你好，我是小扣"), _T(""), TRUE);
	m_speak.StartAsynPlay();
}
