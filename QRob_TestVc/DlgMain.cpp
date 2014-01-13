// DlgMain.cpp : implementation file
//

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "DlgMain.h"
#include <atlsafe.h>
// CDlgMain dialog

IMPLEMENT_DYNAMIC(CDlgMain, CDialog)

CDlgMain::CDlgMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMain::IDD, pParent)
{
	PicFlag = false;
	LearnFlag = false;

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
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgMain::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgMain::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgMain message handlers
BEGIN_EVENTSINK_MAP(CDlgMain, CDialog)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 1, CDlgMain::InitModuleQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 2, CDlgMain::CreateModuleWindowQroboteventctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 4, CDlgMain::CloudVoiceCmdQroboteventctrl1, VTS_I4 VTS_BSTR)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 10, CDlgMain::ExitModuleQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 9, CDlgMain::DestroyModuleWindowQroboteventctrl1, VTS_NONE)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 5, CDlgMain::LineCommandQroboteventctrl1, VTS_BSTR)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 3, CDlgMain::LocaleVoiceCmdQroboteventctrl1, VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PVARIANT VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 7, CDlgMain::QRobotMsgMotionQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 6, CDlgMain::QRobotMsgNormalQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)
	ON_EVENT(CDlgMain, IDC_QROBOTEVENTCTRL1, 8, CDlgMain::QRobotMsgVoiceQroboteventctrl1, VTS_I4 VTS_I4 VTS_PVARIANT)

END_EVENTSINK_MAP()

int CDlgMain::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	/*
	CDC * pDC = GetDlgItem(IDC_STATIC)->GetDC();
	CImage image;
	image.Load(_T(".\\Skin\\default\\screen_2.png"));
	image.Draw(pDC->m_hDC,366,233);
	*/
	// TODO:  Add your specialized creation code here
	//m_eventCtrl.MoveWindow(CRect(0,0,0,0));
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
	

	if(!m_Talk.CreateDispatch(_T("QrobotInterface.Talk.1")))
	{
		AfxMessageBox(_T("TALK Create Dispach Failed"));
	}
	m_Talk.QroTalkInitial();
	m_Script.CreateDispatch(_T("QrobotInterface.Script.1"));
	
}

void CDlgMain::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
}



void CDlgMain::CreateModuleWindowQroboteventctrl1(long top, long left, long width, long height)
{
	// TODO: Add your message handler code here
	int timeCloudDelay = 6000;
    int recordWaitTime = 20000;
// 	LPCTSTR sceneFileName = _T("normal.xml");
// 	m_Talk.SetRecordTime(recordWaitTime);
// 
// 	if(!m_Talk.ChangScenceFile(sceneFileName))
// 	{
// 		
// 	}
// 	else
// 	{
// 		m_Talk.SetVoiceCloundModule(CLOUND_NORMAL);
// 		m_Talk.SetVoiceCloudDelay(timeCloudDelay);
// 		m_Talk.OpenVoiceClound();
// 	}
	//m_speak.StopAsynPlay();
	//m_speak.ClearPlayList();
	m_speak.SetVoiceLocale(0);
	m_speak.AddTextToPlayList(_T("手语天使欢迎您"), _T(""), TRUE);
	m_speak.StartAsynPlay();
}

void CDlgMain::CloudVoiceCmdQroboteventctrl1(long msgType, LPCTSTR strResult)
{
	
}

void CDlgMain::ExitModuleQroboteventctrl1()
{
	// TODO: Add your message handler code here
	return;
}

void CDlgMain::DestroyModuleWindowQroboteventctrl1()
{
	// TODO: Add your message handler code here
	return;
}

void CDlgMain::LineCommandQroboteventctrl1(LPCTSTR strResult)
{
	// TODO: Add your message handler code here
}

void CDlgMain::LocaleVoiceCmdQroboteventctrl1(long msgType, long sentenceID, long matchScore, long slotNum, VARIANT* slotID, VARIANT* slotText)
{
	// TODO: Add your message handler code here
	//CString strCommand;
	CComSafeArray<BSTR> strList;
	
	if (slotNum <= 0)
    {
        strCommand = _T("识别结果为空");//语音未识别
    }
    else
    {
		strList.Attach(slotText->parray);
        for (int i = 0; i < slotNum; i++)
        {
            strCommand += strList[i];//语音已识别
        }
    }
	//写入文件中
	//file.Open(CString(".\\piclist.txt"),CFile::modeWrite|CFile::modeCreate|CFile::modeNoTruncate,NULL);
	myfile.Open(CString(".\\robotdata.txt"),CFile::modeWrite|CFile::modeCreate|CFile::modeNoTruncate,NULL);
	myfile.SeekToEnd();
	myfile.Write((LPCTSTR)strCommand, strCommand.GetLength()*2);//使用unicode字符时需要长度乘以2
	myfile.Close();
	//std::vector<CString>   piclist;
	/*
	CFileFind   f;
	//CString name(strcat(".\\hand\\"，strCommand));
	
	while(f.FindFile(_T(".\\hand\\你.png")))
	{
		CString picName = f.GetFileTitle();
		piclist.push_back(picName);
		//file.Write("hello",5);
		 //GetDlgItem(IDC_EDIT1)->SetWindowText(_T(picName));
		//if(piclist.size()>0) { 	 file.Write("hello",5);}
		//file.SeekToEnd();
		//file.Write(picName,picName.GetLength()*sizeof( _TCHAR ));
	

		if(!f.FindNextFile())  break;
		
	}
	f.Close();
	//file.Close();
	CString temp;
	for(int i=0;i<strCommand.GetLength();i++)
	{

			temp=strCommand[i];
		for(std::vector<int>::size_type ix=0 ;ix!=piclist.size();ix++)
		{
			//file.SeekToEnd();
			//file.Write(piclist[ix],piclist[ix].GetLength());
		
			if(strcmp( (char*)(LPCTSTR)temp, (char*)(LPCTSTR)piclist[ix])==0)
			{
				CString s1(".\\hand\\");
				 CString s2(".png");
				 path=s1+temp+s2;
			//RobotMove(_T(".\\motion\\dance\\normal\\1.txt"));
			break;
			 }
		}
	}

	 //file.Close();
  
  
///

	CString temp;
	
	for(int i=0;i<strCommand.GetLength();i++)
	{
	   temp=strCommand[i];
	 
	 

	   for(std::vector<int>::size_type ix=0 ;ix!=piclist.size();ix++)
	   {
		   if(strcmp((char*)(LPCTSTR)temp,(char*)(LPCTSTR)(piclist[ix]))==0)
		   {
 //

		   }
	   }
	   //file.Write((LPCTSTR)temp,temp.GetLength()*2);
	   //file.Write("\r\n",sizeof(char)*2);
	}
	
   */
	
	if(LearnFlag)
	{
      
		CString str=strCommand+_T("录入成功");
		m_speak.StopAsynPlay();
		m_speak.ClearPlayList();
		m_speak.AddTextToPlayList(str, str, FALSE);
		m_speak.AddRecToPlayList();
		m_speak.StartAsynPlay();
		LearnFlag = false;
	}
	else if(PicFlag)
	{

	//重复话语，开始录音
		//CString str=strCommand+_T("开始播放");
		//m_speak.StopAsynPlay();
		//m_speak.ClearPlayList();
		//m_speak.AddTextToPlayList(str, str, FALSE);
		//m_speak.AddRecToPlayList();
		//m_speak.StartAsynPlay();
		if(strCommand == _T("识别结果为空"))
		{
		m_speak.StopAsynPlay();
		m_speak.ClearPlayList();
		m_speak.AddTextToPlayList(strCommand, strCommand, FALSE);
		m_speak.AddRecToPlayList();
		m_speak.StartAsynPlay();

		}
		else
		{
		test.show();
		}

		PicFlag = false;
	}

	else
	{

		m_speak.StopAsynPlay();
		m_speak.ClearPlayList();
		m_speak.AddTextToPlayList(strCommand, strCommand, FALSE);
		m_speak.AddRecToPlayList();
		m_speak.StartAsynPlay();
	}
	 //找到图片
/*
	  //眼睛显示
	 
	  //弹框显示
	  
	 
*/
	
    //运动一次       
	RobotMove(_T(".\\motion\\dance\\normal\\1.txt"));
	/*if(PicFlag) 
	{

		m_speak.StopAsynPlay();
	m_speak.ClearPlayList();
	m_speak.AddTextToPlayList(_T(""), _T(""), FALSE);
	m_speak.AddRecToPlayList();
	m_speak.StartAsynPlay();
		
	}*/
}

void CDlgMain::QRobotMsgMotionQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
	switch(static_cast<MotioMsg>(nMsgID))
	{
	case HEAD_TOUCH_DOWM:
		if (!m_Talk.IsRecognizeFinish())
		{
			m_Talk.DisposeCurrentReco();
		}
		break;
	case HEAD_TOUCH_UP:
		m_Talk.StartRecognize(_T("QQRobot"), FALSE);
		break;
	default:
		return;
	}
}

void CDlgMain::QRobotMsgNormalQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
}

void CDlgMain::QRobotMsgVoiceQroboteventctrl1(long nMsgID, long param1, VARIANT* param2)
{
	// TODO: Add your message handler code here
	switch(static_cast<VoiceMsg>(nMsgID))
	{
    case MSG_RECORD_FINISHED:
        {
              RobotMove(_T(".\\motion\\statechange\\停止录音.txt"));
        }
        break;
    case MSG_RECORD_BEGIN:
        {
            RobotMove(_T(".\\motion\\statechange\\常态下触摸脑袋，指令听取状态.txt"));
        }
        break;
    case MSG_PLAY_READYFLAG:
        {

        }
        break;
    case MSG_PLAY_ASYNCSTART:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("Begin Speak Text:{0}\n", strParam);
        }
        break;
    case MSG_PLAY_ASYNCFINISH:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("End Speak Text:{0}\n", strParam);
        }
        break;
    case MSG_PLAY_ASYNCSTOP:
        {
//            string strParam = (string)e.param2;
//            Console.WriteLine("Stop Speak Text\n");
        }
        break;
    case MSG_START_RECORD:
        {
          //  m_Talk.StartRecognize(_T("QQRobot"), FALSE);
        }
        break;
	}

}
BOOL CDlgMain::RobotMove(LPCTSTR strPath)
{
	HRESULT hr;	
	CLSID QrobotControllerCSD={0};
	static CQrobotController m_comclass;
	if(LPDISPATCH(m_comclass)==NULL)
	{
		hr = CLSIDFromProgID(_T("QrobotInterface.Controller.1"),&QrobotControllerCSD);
		if(SUCCEEDED(hr))
		{
			LPDISPATCH pController = NULL; 
			hr =::CoCreateInstance(	QrobotControllerCSD,
									NULL,
									CLSCTX_ALL,
									IID_IDispatch,
									(void**)&pController);
			ATLASSERT(SUCCEEDED(hr));
			m_comclass.AttachDispatch(pController);
		}
		else
			return FALSE;
	}
	if(!m_Script.OpenMotionFile(strPath))
	{
		return FALSE;
	}
	else
	{
		if(m_Script.GetCompiledText())
		{
			m_comclass.SetMotionCtrl(LPUNKNOWN(m_Script));
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;

}
//打开摄像头
void CDlgMain::OnBnClickedButton1()
{
	CameraDlg test;
	test.set_dlg(this);
	m_speak.ClearPlayList();//清空播放列表
	m_speak.AddTextToPlayList(_T("进入手势识别模式"), _T(""), TRUE);
	m_speak.StartAsynPlay();
	test.DoModal();
	
	
	// TODO: 在此添加控件通知处理程序代码
	
}





//语音
void CDlgMain::OnBnClickedButton3()
{
	//path = _T(".\\picture\\1.png");
	
	test.set_dlg(this);
	m_speak.ClearPlayList();//清空播放列表
	m_speak.AddTextToPlayList(_T("进入语音匹配模式"), _T(""), TRUE);
	m_speak.StartAsynPlay();
	test.DoModal();
	
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgMain::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	LearnDlg test;
	test.set_dlg(this);
	m_speak.ClearPlayList();//清空播放列表
	m_speak.AddTextToPlayList(_T("进入学习模式"), _T(""), TRUE);
	m_speak.StartAsynPlay();
	test.DoModal();
	
}
