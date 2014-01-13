#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CDQrobotCamera 包装类

class CDQrobotCamera : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDQrobotCamera)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x2D05F9FA, 0x6FC7, 0x4BF3, { 0xBA, 0xE9, 0x56, 0x68, 0x5F, 0xC3, 0xF3, 0x55 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 特性
public:


// 操作
public:

// _DQrobotCamera

// Functions
//

	BOOL OpenWebCamera(long index, long imageSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, index, imageSize);
		return result;
	}
	BOOL CloseWebCamera()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL InitCameraDll()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL ExitCameraDll()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}

// Properties
//



};
