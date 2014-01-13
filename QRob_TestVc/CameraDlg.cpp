// CameraDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QRob_TestVc.h"
#include "CameraDlg.h"
//#include "afxdialogex.h"
#include "DlgMain.h"

//#include <algorithm>
// CameraDlg 对话框

 

IMPLEMENT_DYNAMIC(CameraDlg, CDialog)

CameraDlg::CameraDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CameraDlg::IDD, pParent)
{
flag=false;
}

CameraDlg::~CameraDlg()
{
}

void CameraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CAMERA1, m_Camera);
}

void CameraDlg::set_dlg(CDialog * parnet_dlg)
{
	m_pMianDlg =parnet_dlg;
}

BEGIN_MESSAGE_MAP(CameraDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CameraDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CameraDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CameraDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CameraDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CameraDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CameraDlg 消息处理程序


void CameraDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	m_Camera.InitCameraDll(); 
	m_Camera.OpenWebCamera(0,480*360);
	(parent_dlg->m_speak).ClearPlayList();//清空播放列表
	(parent_dlg->m_speak).AddTextToPlayList(_T("开始手势录入"), _T(""), TRUE);
	(parent_dlg->m_speak).StartAsynPlay();
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
	
}

void CameraDlg::svmTrain()

{
	int ImgWidht =64;  
    int ImgHeight = 64;  
    vector<string> img_path;  //输入文件名变量  
    vector<int> img_catg;    
    int nLine = 0;    
    string buf;    
    ifstream svm_data( ".\\SVM_DATA.txt" );   //训练样本图片路径 
    unsigned long n;    
    
    while( svm_data )  //将训练样本文件依次读取出来  
    {    
        if( getline( svm_data, buf ) )    
        {    
            nLine ++;    
           
            if( nLine % 2 == 0 )//这里的分类比较有意思，看得出来上面的SVM_DATA.txt文本中应该是一行是文件路径，接着下一行就是该图片的类别，可以设置为0或者1，当然多个也无所谓   
            {    
                 img_catg.push_back( atoi( buf.c_str() ) );//atoi将字符串转换成整型，标志（0,1），注意这里至少要有两个类别，否则会出错    
            }    
            else    
            {    
                img_path.push_back( buf );//图像路径    
            }    
        }    
    }    
    svm_data.close();//关闭文件    
    
    int nImgNum = nLine/2;            //读入样本数量    
    CvMat * FeaturesMat = cvCreateMat(nImgNum, 1764, CV_32FC1);//64*128的训练样本，该矩阵将是totalSample*3780,64*64的训练样本，该矩阵将是totalSample*1764  
    cvSetZero(FeaturesMat);    
    CvMat * LabelMat = cvCreateMat(nImgNum, 1, CV_32FC1);//样本标识    
    cvSetZero(LabelMat);  

    IplImage* src;  
   IplImage*  trainImg=cvCreateImage(cvSize(64,64),8,3);

   for( vector<string>::size_type i = 0; i != img_path.size(); i++ )  //vector<string>的才是用来判断是vector的第几个元素的  
    {    
         
		 src=cvLoadImage(img_path[i].c_str(),1);   
         cvResize(src,trainImg);   //读取图片 
		cv::Mat img(trainImg,0);

        HOGDescriptor hog(cvSize(64,64),cvSize(16,16),cvSize(8,8),cvSize(8,8),9);  //具体意思见参考文章1,2       
        vector<float>  descriptors;//结果数组       
		hog.compute(img, descriptors); //调用计算函数开始计算  
      
        n=0;    
        for(vector<float>::iterator iter=descriptors.begin();iter!=descriptors.end();iter++)    
        {    
            //把HOG存储下来  
		cvmSet(FeaturesMat,i,n,*iter);  
		  n++;    
        }    
       
		  cvmSet(LabelMat, i, 0, img_catg[i] ); 

    }    
                 
    CvSVM svm = CvSVM();  //新建一个SVM
    CvSVMParams param;  //参数  
    CvTermCriteria criteria;      
    criteria = cvTermCriteria( CV_TERMCRIT_EPS, 1000, FLT_EPSILON );      
    param = CvSVMParams( CvSVM::C_SVC, CvSVM::RBF, 10.0, 0.09, 1.0, 10.0, 0.5, 1.0, NULL, criteria );     
      
    /* 
    SVM种类：CvSVM::C_SVC      
    Kernel的种类：CvSVM::RBF      
    degree：10.0（此次不使用）      
    gamma：8.0      
    coef0：1.0（此次不使用）      
    C：10.0      
    nu：0.5（此次不使用）      
    p：0.1（此次不使用）      
    然后对训练数据正规化处理，并放在CvMat型的数组里。      
                                                        */         

   //☆☆☆☆☆☆☆☆☆(5)SVM学习☆☆☆☆☆☆☆☆☆☆☆☆           
    svm.train( FeaturesMat, LabelMat, Mat(), Mat(), param ); //训练      
    //☆☆利用训练数据和确定的学习参数,进行SVM学习☆☆☆☆       
    svm.save( ".\\SVM_DATA.xml" );  
     CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	(parent_dlg->m_speak).ClearPlayList();//清空播放列表
	(parent_dlg->m_speak).AddTextToPlayList(_T("分类器训练成功"), _T(""), TRUE);
	(parent_dlg->m_speak).StartAsynPlay();
	//GetDlgItem(IDC_EDIT1)->SetWindowText(_T(""));
   AfxMessageBox(_T("分类器训练成功！"));

}



void CameraDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	(parent_dlg->m_image).SaveImage(_T(".\\hand.png"));
	m_Camera.CloseWebCamera();
	IplImage* pFrame=cvLoadImage(".\\hand.png",1);
	CString a = svmRecognize(pFrame);
	cvReleaseImage( &pFrame); 
	
	//处理图片
	//语音输出
	//AfxMessageBox(a);
	(parent_dlg->m_speak).AddTextToPlayList(a, _T(""), TRUE);
	(parent_dlg->m_speak).StartAsynPlay();
	//显示文字
	GetDlgItem(IDC_EDIT1)->SetWindowText(a);
	
	
}
BEGIN_EVENTSINK_MAP(CameraDlg, CDialog)
	ON_EVENT(CameraDlg, IDC_CAMERA1, 1, CameraDlg::ImageCaptureCamera, VTS_I4 VTS_I4 VTS_PVARIANT)
END_EVENTSINK_MAP()


void CameraDlg::ImageCaptureCamera(long width, long height, VARIANT* imageData)
{
	// TODO: 在此处添加消息处理程序代码
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	if(!((parent_dlg->m_image).CreateDispatch(_T("QrobotInterface.BasicImage.1"))))
	{    
		AfxMessageBox(_T("Image Create Dispach Failed"));
	}
	// TODO: 在此处添加消息处理程序代码
	(parent_dlg->m_image).CreateImageFromBuffer(width,height,*imageData); 
	(parent_dlg->m_image).ShowImage((_int64)(GetDlgItem(IDC_CAMERA1)->GetDC()->m_hDC),0,0,1.0);
	
}
int CameraDlg::otsu(const IplImage *src_image)
{
	double sum = 0.0;  
    double w0 = 0.0;  
    double w1 = 0.0;  
    double u0_temp = 0.0;  
    double u1_temp = 0.0;  
    double u0 = 0.0;  
    double u1 = 0.0;  
    double delta_temp = 0.0;  
    double delta_max = 0.0;  
  
    //src_image灰度级  
    int pixel_count[256]={0};  
    float pixel_pro[256]={0};  
    int threshold = 0;  
    uchar* data = (uchar*)src_image->imageData;  
    //统计每个灰度级中像素的个数  
    for(int i = 0; i < src_image->height; i++)  
    {  
        for(int j = 0;j < src_image->width;j++)  
        {  
            pixel_count[(int)data[i * src_image->width + j]]++;  
            sum += (int)data[i * src_image->width + j];  
        }  
    }  
    //cout<<"平均灰度："<<sum / ( src_image->height * src_image->width )<<endl;  
    //计算每个灰度级的像素数目占整幅图像的比例  
    for(int i = 0; i < 256; i++)  
    {  
    pixel_pro[i] = (float)pixel_count[i] / ( src_image->height * src_image->width );  
    }  
    //遍历灰度级[0,255],寻找合适的threshold  
    for(int i = 0; i < 256; i++)  
    {  
        w0 = w1 = u0_temp = u1_temp = u0 = u1 = delta_temp = 0;  
        for(int j = 0; j < 256; j++)  
        {  
            if(j <= i)   //背景部分  
            {  
                w0 += pixel_pro[j];  
                u0_temp += j * pixel_pro[j];  
            }  
            else   //前景部分  
            {  
                w1 += pixel_pro[j];  
                u1_temp += j * pixel_pro[j];  
            }  
        }  
        u0 = u0_temp / w0;  
        u1 = u1_temp / w1;  
        delta_temp = (float)(w0 *w1* pow((u0 - u1), 2)) ;  
        if(delta_temp > delta_max)  
        {  
            delta_max = delta_temp;  
            threshold = i;  
        }  
    }  
    return threshold;  
}

CString CameraDlg::svmRecognize( IplImage* src1)
{
	CvSVM svm = CvSVM();//新建一个SVM  
    svm.load(".\\SVM_DATA.xml", 0);  
	
    IplImage* trainImg=cvCreateImage(cvSize(64,64),8,3); 
    char line[512];    
    ofstream predict_txt( ".\\SVM_PREDICT.txt", 1); 

	//IplImage *src1 = cvLoadImage(".\\picture\\1.png",1); 
   
	 cvZero(trainImg);    
      cvResize(src1,trainImg);   //读取图片 
	  cv::Mat img(trainImg,0);

     HOGDescriptor hog(cvSize(64,64),cvSize(16,16),cvSize(8,8),cvSize(8,8),9);  //具体意思见参考文章1,2
    vector<float> descriptors(1764);//结果数组

     hog.compute(img, descriptors); //调用计算函数开始计算   
    
     CvMat* SVMtrainMat=cvCreateMat(1,descriptors.size(),CV_32FC1);     
       int  n=0;    
       for(vector<float>::iterator iter=descriptors.begin();iter!=descriptors.end();iter++)    
       {    
            cvmSet(SVMtrainMat,0,n,*iter);  
            n++;    
       }    
    
        int ret = svm.predict(SVMtrainMat);  //获取最终检测结果  

		CString a;

	if(ret == 0)
		a = "8";
	else if(ret == 1)
		a = "爱";
	else if(ret == 2)
		a = "好";
	else if(ret == 3)
		a = "几";
	else if(ret == 4)
		a = "叫";
	else if(ret == 5)
		a = "么";
	else if(ret == 6)
		a = "你";
	else if(ret == 7)
		a = "什";
	else if(ret == 8)
		a = "岁";
	else if(ret == 9)
		a = "我";
	else 
		a = "小";

	
        std::sprintf( line, "%d\r\n",ret );   
        predict_txt<<line;
		//cvReleaseImage( &src1 );

		  predict_txt.close();
	    cvReleaseImage( &trainImg);    
       return a;		
	  // AfxMessageBox(a);
}



// 遍历给定目录下所有子目录，查找*.txt，放入CStringArray中
void CameraDlg::getFolderDayFile(CString pathStr, CStringArray& arrStrFile)
{
    CString m_cstrFileList=_T(""); 
    CFileFind tempFind; 
    BOOL bFound; //判断是否成功找到文件
    bFound=tempFind.FindFile(_T("D:\\hand\\*.png"));   //修改" "内内容给限定查找文件类型
    CString strTmp;   //如果找到的是文件夹 存放文件夹路径
    while(bFound)      //遍历所有文件
    { 
        bFound=tempFind.FindNextFile(); //第一次执行FindNextFile是选择到第一个文件，以后执行为选择
      
       
            strTmp=tempFind.GetFileTitle(); //保存文件名，包括后缀名
			arrStrFile.Add(strTmp);
			//AfxMessageBox(strTmp);
            // 在此处添加对找到文件的处理
       
    } 
    tempFind.Close(); 
    return; 
}    
const char*  CameraDlg::CStrToChar(CString strSrc)  
{  
#ifdef UNICODE  
    DWORD dwNum = WideCharToMultiByte(CP_OEMCP, NULL, strSrc.GetBuffer(0), -1, NULL, 0, NULL, FALSE);  
    char *psText;  
    psText = new char[dwNum];  
    if (!psText)  
        delete []psText;  
    WideCharToMultiByte(CP_OEMCP, NULL, strSrc.GetBuffer(0), -1, psText, dwNum, NULL, FALSE);  
    return (const char*)psText;  
#else  
    return (LPCTSRT)strSrc;  
#endif  
}




void CameraDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	svmTrain();
}





void CameraDlg::OnBnClickedButton4()
{
	
	USES_CONVERSION;	//格式转换标志



	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;

	bool isChange = true;
	CString a=_T("");
	CString s=_T("");
	for(int i = 1;i<=10;i++)
	{

		if(flag)  break;
		(parent_dlg->m_image).SaveImage(_T(".\\hand.png"));
		IplImage* pFrame=cvLoadImage(".\\hand.png",1);
		cvShowImage("fd", pFrame);

		a = svmRecognize(pFrame);	
		if(a != s)
			isChange = true;
		else 
			isChange = false;
		s = a;
		if(isChange)
		{
			//语音输出
			(parent_dlg->m_speak).AddTextToPlayList(a, _T(""), TRUE);
			(parent_dlg->m_speak).StartAsynPlay();
			//显示文字
			GetDlgItem(IDC_EDIT1)->SetWindowText(a);
		}
		//nNum++;//帧数++
		//CString str;
		//str.Format(_T("D:/hand/%d.png"),nNum);
		//cvSaveImage(T2A(str),pFrame);

		 cvReleaseImage( &pFrame); 
		 //AfxMessageBox(_T("hh"));
		 cvWaitKey(2000);

	
	}

	

}


void CameraDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码

	flag=true;
	CDlgMain *parent_dlg = (CDlgMain *)m_pMianDlg;
	m_Camera.CloseWebCamera();
}
