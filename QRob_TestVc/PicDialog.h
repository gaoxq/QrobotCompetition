#pragma once


// PicDialog 对话框

class PicDialog : public CDialog
{
	DECLARE_DYNAMIC(PicDialog)

public:
	PicDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PicDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
public:
	CDialog *m_pMianDlg;
	void set_dlg(CDialog * parnet_dlg);
	void show();
	
	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	
};
