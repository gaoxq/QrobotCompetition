// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "D:\\Program Files\\Qrobot¿ª·¢°æV1.0\\QrobotInterface.dll" no_namespace
// CQrobotBasicImage wrapper class

class CQrobotBasicImage : public COleDispatchDriver
{
public:
	CQrobotBasicImage(){} // Calls COleDispatchDriver default constructor
	CQrobotBasicImage(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CQrobotBasicImage(const CQrobotBasicImage& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IQrobotBasicImage methods
public:
	void CreateImage(long Width, long Height)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Width, Height);
	}
	BOOL OpenImage(LPCTSTR strName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strName);
		return result;
	}
	BOOL SaveImage(LPCTSTR strName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strName);
		return result;
	}
	void ShowImage(__int64 pDC, long ptStartX, long ptStartY, double showRate)
	{
		static BYTE parms[] = VTS_I8 VTS_I4 VTS_I4 VTS_R8 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pDC, ptStartX, ptStartY, showRate);
	}
	void ReleaseMem()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long GetImageWidth()
	{
		long result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetImageHeight()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long GetLineBytes()
	{
		long result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void ImageScale(double rate, long scaleMode)
	{
		static BYTE parms[] = VTS_R8 VTS_I4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, rate, scaleMode);
	}
	void ImageResize(long newWidth, long newHeight, long resizeMode)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, newWidth, newHeight, resizeMode);
	}
	void BeginDraw()
	{
		InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void DrawImageText(LPCTSTR strText, long ptBeginX, long ptBeginY, unsigned long fontColor, unsigned short fontHeight, LPCTSTR fontName)
	{
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 VTS_UI4 VTS_UI2 VTS_BSTR ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, strText, ptBeginX, ptBeginY, fontColor, fontHeight, fontName);
	}
	void DrawImageLine(long ptBeginX, long ptBeginY, long ptEndX, long ptEndY, unsigned short lineWidth, unsigned long lineColor)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_UI2 VTS_UI4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_EMPTY, NULL, parms, ptBeginX, ptBeginY, ptEndX, ptEndY, lineWidth, lineColor);
	}
	void EndDraw()
	{
		InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	unsigned __int64 GetImageHDC()
	{
		unsigned __int64 result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_UI8, (void*)&result, NULL);
		return result;
	}
	void CloneImage(LPUNKNOWN orgImage)
	{
		static BYTE parms[] = VTS_UNKNOWN ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, parms, orgImage);
	}
	VARIANT GetImageData()
	{
		VARIANT result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void CreateImageFromBuffer(long Width, long Height, VARIANT& pBuffer)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_VARIANT ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Width, Height, &pBuffer);
	}

	// IQrobotBasicImage properties
public:

};
