

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Tue Nov 26 20:45:08 2013
 */
/* Compiler settings for QRob_TestVc.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_QRob_TestVcLib,0xB617ACD7,0x605E,0x4B20,0xB4,0x56,0xB2,0xA0,0xEA,0x89,0x54,0x44);


MIDL_DEFINE_GUID(IID, DIID__DQRob_TestVc,0xA89314B0,0x2045,0x478B,0xA8,0x20,0x58,0x8F,0x0D,0x3C,0x51,0xD3);


MIDL_DEFINE_GUID(IID, DIID__DQRob_TestVcEvents,0xF34063ED,0x6096,0x4D6C,0xB9,0x3C,0x7C,0x25,0xC1,0xD9,0xBC,0x01);


MIDL_DEFINE_GUID(CLSID, CLSID_QRob_TestVc,0xD81861FC,0x364B,0x44E1,0x8D,0x93,0x5B,0x6E,0x63,0xD1,0x7F,0x63);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



