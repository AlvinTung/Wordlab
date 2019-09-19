// MyWordDoc.cpp : implementation of the CMyWordDoc class
//

#include "stdafx.h"
#include "Wordlab.h"

#include "WordlabDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

extern BOOL AFXAPI AfxFullPath(LPTSTR lpszPathOut, LPCTSTR lpszFileIn);
extern UINT AFXAPI AfxGetFileTitle(LPCTSTR lpszPathName, LPTSTR lpszTitle, UINT nMax);

#ifndef OFN_EXPLORER
#define OFN_EXPLORER 0x00080000L
#endif

#include "cntritem.h"

///////////////////////////////////////////////////////////////////////////
// CMyWordDoc

IMPLEMENT_DYNCREATE(CWordlabDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CWordlabDoc, CRichEditDoc)
    //{{AFX_MSG_MAP(CMyWordDoc)
        // NOTE - the ClassWizard will add and remove mapping macros here.
        //    DO NOT EDIT what you see in these blocks of generated code!
    //}}AFX_MSG_MAP
    // Enable default OLE container implementation
    ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, 
        CRichEditDoc::OnUpdateEditLinksMenu)
    ON_COMMAND(ID_OLE_EDIT_LINKS, CRichEditDoc::OnEditLinks)
    ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, 
        ID_OLE_VERB_LAST, CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////
// CMyWordDoc construction/destruction

CWordlabDoc::CWordlabDoc()
{
}

CWordlabDoc::~CWordlabDoc()
{
}

BOOL CWordlabDoc::OnNewDocument()
{
    if (!CRichEditDoc::OnNewDocument())
        return FALSE;
    return TRUE;
}
CRichEditCntrItem* CWordlabDoc::CreateClientItem(REOBJECT* preo) const
{
    return new CWordlabCntrItem(preo, (CWordlabDoc*) this);
}

///////////////////////////////////////////////////////////////////////////
// CMyWordDoc serialization

void CWordlabDoc::Serialize(CArchive& ar)
{
    CRichEditDoc::Serialize(ar);
}

///////////////////////////////////////////////////////////////////////////
// CMyWordDoc diagnostics

#ifdef _DEBUG
void CWordlabDoc::AssertValid() const
{
    CRichEditDoc::AssertValid();
}

void CWordlabDoc::Dump(CDumpContext& dc) const
{
    CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

///////////////////////////////////////////////////////////////////////////
// CMyWordDoc commands