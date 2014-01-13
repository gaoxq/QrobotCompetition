// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "D:\\Program Files\\Qrobot¿ª·¢°æV1.0\\QrobotInterface.dll" no_namespace
// CQrobotScript wrapper class

class CQrobotScript : public COleDispatchDriver
{
public:
	CQrobotScript(){} // Calls COleDispatchDriver default constructor
	CQrobotScript(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotScript(const CQrobotScript& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IQrobotScript methods
public:
	BOOL OpenMotionFile(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL AddMotionFile(LPCTSTR strPath)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strPath);
		return result;
	}
	BOOL GetCompiledText()
	{
		BOOL result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void ClearAllCmds()
	{
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IQrobotScript properties
public:

};
