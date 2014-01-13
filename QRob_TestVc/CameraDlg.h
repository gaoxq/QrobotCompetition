#pragma once


// CameraDlg 对话框
#include "camera1.h"
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include "minmax.h"
#include <ml.h>    
#include <iostream>    
#include <fstream>    
#include <string>    
#include <vector>  
#include <afxwin.h>

using namespace cv;    
using namespace std;

class CameraDlg : public CDialog
{
	DECLARE_DYNAMIC(CameraDlg)

public:
	CameraDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CameraDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CDialog *m_pMianDlg;
	void set_dlg(CDialog * parnet_dlg);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	static int otsu(const IplImage *src_image);
	void getFolderDayFile(CString pathStr, CStringArray& arrStrFile);
	
	const char*  CStrToChar(CString strSrc)  ;
    CFile file;
	CvSVM svm;
	Mat trainImg;
	void svmTrain();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString svmRecognize( IplImage* src1);
	DECLARE_EVENTSINK_MAP()
	void ImageCaptureCamera(long width, long height, VARIANT* imageData);
	CDQrobotCamera m_Camera;
	afx_msg void OnBnClickedButton5();
	bool flag;
};
