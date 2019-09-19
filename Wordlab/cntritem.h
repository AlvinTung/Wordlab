// cntritem.h : interface of the CWordPadCntrItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
#include "afxrich.h"
// #include "Resource.h"
class CWordlabDoc;
class CWordlabView;

class CWordlabCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CWordlabCntrItem)

// Constructors
public:
	CWordlabCntrItem(REOBJECT* preo = NULL, CWordlabDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CWordlabDoc* GetDocument()
		{ return dynamic_cast<CWordlabDoc*>(COleClientItem::GetDocument()); }
	CWordlabView* GetActiveView()
		{ return (CWordlabView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordPadCntrItem)
	public:
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

/////////////////////////////////////////////////////////////////////////////
