

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Dec 26 02:45:36 2013
 */
/* Compiler settings for WordlabHandlers.idl:
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

MIDL_DEFINE_GUID(IID, IID_IPreview,0x2A1C2256,0xCCBF,0x443E,0xA5,0x77,0x05,0xD5,0x72,0x6F,0x4F,0x93);


MIDL_DEFINE_GUID(IID, IID_IThumbnail,0xC94CEF2B,0x63CF,0x4051,0x90,0xC2,0x1C,0xC5,0xEB,0x77,0xFA,0x82);


MIDL_DEFINE_GUID(IID, IID_ISearch,0xEBC4A79C,0xEFDC,0x4249,0x99,0x5F,0xCD,0x1A,0x60,0x33,0x27,0xFB);


MIDL_DEFINE_GUID(IID, LIBID_WordlabHandlersLib,0x1BDEDA34,0xBB4E,0x4FD9,0xAD,0x2E,0x98,0x15,0xCD,0xDE,0x19,0xFA);


MIDL_DEFINE_GUID(CLSID, CLSID_Preview,0x6CEE1020,0x3894,0x46DF,0xB4,0xA5,0x75,0xE2,0xFC,0x0D,0x23,0x4C);


MIDL_DEFINE_GUID(CLSID, CLSID_Thumbnail,0x73C35499,0xB4CF,0x4F5A,0xA6,0xDF,0xEF,0x96,0x24,0x0B,0x7E,0xB9);


MIDL_DEFINE_GUID(CLSID, CLSID_Search,0xD24D8476,0x4F51,0x4828,0x86,0x3A,0x2E,0x1E,0xED,0x7C,0x58,0xF2);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



