// LearnDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "LearnDlg.h"
#include "afxdialogex.h"
#include "DlgMain.h"

// LearnDlg 对话框

IMPLEMENT_DYNAMIC(LearnDlg, CDialog)

LearnDlg::LearnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LearnDlg::IDD, pParent)
{

}

LearnDlg::~LearnDlg()
{
}

void LearnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAMERA1, m_CameraLearn);
}


BEGIN_MESSAGE_MAP(LearnDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &LearnDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &LearnDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &LearnDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// LearnDlg 消息处理程序
BEGIN_EVENTSINK_MAP(LearnDlg, CDialog)
	ON_EVENT(LearnDlg, IDC_CAMERA1, 1, LearnDlg::ImageCaptureCamera, VTS_I4 VTS_I4 VTS_PVARIANT)
END_EVENTSINK_MAP()

void LearnDlg::set_dlg(CDialog * parnet_dlg)
{
	m_pMianDlg =parnet_dlg;
}


void LearnDlg::ImageCaptureCamera(long width, long height, VARIANT* imageData)
{
	// TODO: 在此处添加消息处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	if(!((parent_dlg->m_image).CreateDispatch(_T("QrobotInterface.BasicImage.1"))))
	{    
		AfxMessageBox(_T("Image Create Dispach Failed"));
	}
	// TODO: 在此处添加消息处理程序代码
	(parent_dlg->m_image).CreateImageFromBuffer(width,height,*imageData); 
	//m_image.ImageResize(240,180,0);
	(parent_dlg->m_image).ShowImage((_int64)(GetDlgItem(IDC_CAMERA1)->GetDC()->m_hDC),0,0,1.0);

}


void LearnDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	m_CameraLearn.InitCameraDll(); 
	m_CameraLearn.OpenWebCamera(0,480*360);
	(parent_dlg->m_speak).ClearPlayList();//清空播放列表
	(parent_dlg->m_speak).AddTextToPlayList(_T("开始手势录入"), _T(""), TRUE);
	(parent_dlg->m_speak).StartAsynPlay();
	CvVideoWriter *writer = 0;
	int isColor = 1;
	int fps     = 8;  // or 30
	int frameW  = 320; // 744 for firewire cameras
	int frameH  = 240; // 480 for firewire cameras
	//writer=cvCreateVideoWriter("D：/hand/out.avi",CV_FOURCC('D', 'I', 'V', 'X'),fps,cvSize(frameW,frameH),isColor);//初始化视频编写器（MPEG-4编码器）

USES_CONVERSION;	//格式转换标志
	setlocale( LC_ALL, "C" );


	CString path = _T(".\\video\\")+(parent_dlg->strCommand)+_T(".avi");
	//AfxMessageBox(path);
		const char* strOut;
	 char temp[0x100];
	 ::wsprintfA(temp, "%ls", (LPCTSTR)path);
	 strOut = temp;
	
	writer=cvCreateVideoWriter(strOut,-1,fps,cvSize(frameW,frameH),isColor);//初始化视频编写器(自己选择编码器)
	
	//AfxMessageBox(_T("hello"));
	flag = true;
	int nFrames =15;
	
	//while(flag)
	for(int i=0;i<nFrames;i++)
	{

    if(!flag)   break;
  	(parent_dlg->m_image).SaveImage(_T(".\\hand.png"));
	IplImage* img=cvLoadImage(".\\hand.png",1);
	cvShowImage("fd", img);
	cvWriteFrame(writer,img); 
	cvReleaseImage( &img); // add the frame to the file
	  cvWaitKey(1000);
	//Sleep(40);
	}
	
	cvReleaseVideoWriter(&writer);
}


void LearnDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	flag=false;
	//(parent_dlg->m_image).SaveImage(_T(".\\picture\\1.png"));
	m_CameraLearn.CloseWebCamera();
}


void LearnDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	CString sceneFileName ( "hand.xml");
	if (!((parent_dlg->m_Talk).ChangScenceFile(sceneFileName)))
    {
          MessageBox(_T("转换失败"));
    }
	parent_dlg->strCommand=_T("");
	parent_dlg->LearnFlag=true;
	(parent_dlg->m_Talk).StartRecognize(_T("QQRobot"), FALSE);
	//语音输入匹配
}
