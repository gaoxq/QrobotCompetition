// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "D:\\Program Files\\Qrobot¿ª·¢°æV1.0\\QrobotInterface.dll" no_namespace
// CQrobotController wrapper class

class CQrobotController : public COleDispatchDriver
{
public:
	CQrobotController(){} // Calls COleDispatchDriver default constructor
	CQrobotController(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotController(const CQrobotController& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IQrobotController methods
public:
	BOOL ReadPowerState(BOOL * state)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBOOL ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, state);
		return result;
	}
	BOOL SetDiffEyeImgFromImage(LPUNKNOWN imgLeft, LPUNKNOWN imgRight)
	{
		BOOL result;
		static BYTE parms[] = VTS_UNKNOWN VTS_UNKNOWN ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, imgLeft, imgRight);
		return result;
	}
	BOOL SetSameEyeImgFromImage(LPUNKNOWN imgShow)
	{
		BOOL result;
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, imgShow);
		return result;
	}
	void SetMotionCtrl(LPUNKNOWN mEditer)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, mEditer);
	}
	BOOL DoRobotMove(LPCTSTR strMotionText)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strMotionText);
		return result;
	}
	BOOL IsOrderIdle()
	{
		BOOL result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void SetEyeShowEnable(BOOL showFlag)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, showFlag);
	}
	void SetPartMoveEnable(BOOL moveFlag)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, moveFlag);
	}
	void MotionStop()
	{
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL GetEyeSize(long * Width, long * Height)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Width, Height);
		return result;
	}
	BOOL SetEyeImgFromPath(LPCTSTR strNameL, LPCTSTR strNameR)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strNameL, strNameR);
		return result;
	}
	BOOL UpdateMotorPosition()
	{
		BOOL result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL GetMotorPosition(unsigned long * posArray)
	{
		BOOL result;
		static BYTE parms[] = VTS_PUI4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, posArray);
		return result;
	}

	// IQrobotController properties
public:

};
