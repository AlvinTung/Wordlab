// cntritem.cpp : implementation of the CWordPadCntrItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "Wordlab.h"

#include "WordlabDoc.h"
#include "WordlabView.h"
#include "cntritem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWordPadCntrItem implementation

IMPLEMENT_SERIAL(CWordlabCntrItem, CRichEditCntrItem, 0)

CWordlabCntrItem::CWordlabCntrItem(REOBJECT *preo, CWordlabDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
}

/////////////////////////////////////////////////////////////////////////////
// CWordPadCntrItem diagnostics

#ifdef _DEBUG
void CWordlabCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CWordlabCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
