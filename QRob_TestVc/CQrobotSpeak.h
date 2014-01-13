// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "D:\\Program Files\\Qrobot¿ª·¢°æV1.0\\QrobotInterface.dll" no_namespace
// CQrobotSpeak wrapper class

class CQrobotSpeak : public COleDispatchDriver
{
public:
	CQrobotSpeak(){} // Calls COleDispatchDriver default constructor
	CQrobotSpeak(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotSpeak(const CQrobotSpeak& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IQrobotSpeak methods
public:
	BOOL QroSpeakInitial()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetPlayMode(long mode)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, mode);
	}
	void PlayText(LPCTSTR strWords, BOOL flagchange)
	{
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strWords, flagchange);
	}
	void PlayWaveFile(LPCTSTR path)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, path);
	}
	void PlayPcmFile(LPCTSTR path, BOOL flagchange)
	{
		static BYTE parms[] = VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, path, flagchange);
	}
	void AddWaveToPlayList(LPCTSTR path, LPCTSTR strReturn)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, path, strReturn);
	}
	void AddPcmToPlayList(LPCTSTR path, LPCTSTR strReturn, BOOL flagchange)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, path, strReturn, flagchange);
	}
	void AddTextToPlayList(LPCTSTR strText, LPCTSTR strReturn, BOOL flagchange)
	{
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BOOL ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strText, strReturn, flagchange);
	}
	void StartAsynPlay()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void StopAsynPlay()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ClearPlayList()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL IsPlayerIdle()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetVoiceLocale(long vLocale)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, vLocale);
	}
	void SetVoiceSex(long vSex)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, vSex);
	}
	void SetVoiceRole(long vRole)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, vRole);
	}
	void SetVoiceSpeed(long vSpeed)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, vSpeed);
	}
	long GetVoiceLocale()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetVoiceSex()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetVoiceRole()
	{
		long result;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetVoiceSpeed()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void AddWaitToPlayList(long timeWait, LPCTSTR strReturn)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms, timeWait, strReturn);
	}
	void AddRecToPlayList()
	{
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IQrobotSpeak properties
public:

};
