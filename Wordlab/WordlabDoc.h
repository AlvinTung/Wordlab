// MyWordDoc.h : interface of the CMyWordDoc class
//
///////////////////////////////////////////////////////////////////////////
#include "afxrich.h"
#if !defined(AFX_WordlabDOC_H__C85C908B_A154_11D2_8E53_006008A82731__INCLUDED_)
#define AFX_WordlabDOC_H__C85C908B_A154_11D2_8E53_006008A82731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CWordlabDoc : public CRichEditDoc
{
protected: // create from serialization only
    CWordlabDoc();
    DECLARE_DYNCREATE(CWordlabDoc)

// Attributes
public:

// Operations
public:

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMyWordDoc)
    public:

    virtual BOOL OnNewDocument();
    virtual void Serialize(CArchive& ar);
    //}}AFX_VIRTUAL
    virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
    virtual ~CWordlabDoc();
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
    //{{AFX_MSG(CMyWordDoc)
       // NOTE - the ClassWizard will add and remove member functions here.
       //    DO NOT EDIT what you see in these blocks of generated code !
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

///////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations 
// immediately before the previous line.

#endif 
// !defined(
//     AFX_MYWORDDOC_H__C85C908B_A154_11D2_8E53_006008A82731__INCLUDED_)