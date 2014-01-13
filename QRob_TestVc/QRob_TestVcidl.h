

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Fri Dec 06 19:47:16 2013
 */
/* Compiler settings for QRob_TestVc.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __QRob_TestVcidl_h__
#define __QRob_TestVcidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DQRob_TestVc_FWD_DEFINED__
#define ___DQRob_TestVc_FWD_DEFINED__
typedef interface _DQRob_TestVc _DQRob_TestVc;

#endif 	/* ___DQRob_TestVc_FWD_DEFINED__ */


#ifndef ___DQRob_TestVcEvents_FWD_DEFINED__
#define ___DQRob_TestVcEvents_FWD_DEFINED__
typedef interface _DQRob_TestVcEvents _DQRob_TestVcEvents;

#endif 	/* ___DQRob_TestVcEvents_FWD_DEFINED__ */


#ifndef __QRob_TestVc_FWD_DEFINED__
#define __QRob_TestVc_FWD_DEFINED__

#ifdef __cplusplus
typedef class QRob_TestVc QRob_TestVc;
#else
typedef struct QRob_TestVc QRob_TestVc;
#endif /* __cplusplus */

#endif 	/* __QRob_TestVc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_QRob_TestVc_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_QRob_TestVc_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_QRob_TestVc_0000_0000_v0_0_s_ifspec;


#ifndef __QRob_TestVcLib_LIBRARY_DEFINED__
#define __QRob_TestVcLib_LIBRARY_DEFINED__

/* library QRob_TestVcLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_QRob_TestVcLib;

#ifndef ___DQRob_TestVc_DISPINTERFACE_DEFINED__
#define ___DQRob_TestVc_DISPINTERFACE_DEFINED__

/* dispinterface _DQRob_TestVc */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DQRob_TestVc;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A89314B0-2045-478B-A820-588F0D3C51D3")
    _DQRob_TestVc : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DQRob_TestVcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DQRob_TestVc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DQRob_TestVc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DQRob_TestVc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DQRob_TestVc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DQRob_TestVc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DQRob_TestVc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DQRob_TestVc * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DQRob_TestVcVtbl;

    interface _DQRob_TestVc
    {
        CONST_VTBL struct _DQRob_TestVcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DQRob_TestVc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DQRob_TestVc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DQRob_TestVc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DQRob_TestVc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DQRob_TestVc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DQRob_TestVc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DQRob_TestVc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DQRob_TestVc_DISPINTERFACE_DEFINED__ */


#ifndef ___DQRob_TestVcEvents_DISPINTERFACE_DEFINED__
#define ___DQRob_TestVcEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DQRob_TestVcEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DQRob_TestVcEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F34063ED-6096-4D6C-B93C-7C25C1D9BC01")
    _DQRob_TestVcEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DQRob_TestVcEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DQRob_TestVcEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DQRob_TestVcEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DQRob_TestVcEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DQRob_TestVcEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DQRob_TestVcEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DQRob_TestVcEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DQRob_TestVcEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DQRob_TestVcEventsVtbl;

    interface _DQRob_TestVcEvents
    {
        CONST_VTBL struct _DQRob_TestVcEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DQRob_TestVcEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DQRob_TestVcEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DQRob_TestVcEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DQRob_TestVcEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DQRob_TestVcEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DQRob_TestVcEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DQRob_TestVcEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DQRob_TestVcEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_QRob_TestVc;

#ifdef __cplusplus

class DECLSPEC_UUID("D81861FC-364B-44E1-8D93-5B6E63D17F63")
QRob_TestVc;
#endif
#endif /* __QRob_TestVcLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


