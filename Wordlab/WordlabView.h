
// templateView.h : interface of the CWordlabView class
//

#pragma once

#include "resource.h"
class CWordlabView : public CRichEditView
{
protected: // create from serialization only
	CWordlabView();
	DECLARE_DYNCREATE(CWordlabView)

// Attributes
public:
	CWordlabDoc* GetDocument() const;
//	CRichEditCtrl m_RichEditor;
	bool groupMode;
    bool isSpace;
	CString previousWord;


// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CWordlabView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMutateGroup();
	afx_msg BOOL AllSpaces(CString str);
	afx_msg BOOL EndsInNonSpace(CString str);
	afx_msg BOOL BeginsWithNonSpace(CString str);
	afx_msg void AppendText(CString msg);
	afx_msg void OnUpdateMutateGroup(CCmdUI *pCmdUI);
	afx_msg void OnMutateRandomise();
	afx_msg void OnUpdateMutateRandomise(CCmdUI *pCmdUI);
	afx_msg void OnMutateStrip();
	afx_msg void OnUpdateMutateStrip(CCmdUI *pCmdUI);
	afx_msg void OnMutateScatter();
	afx_msg void OnUpdateMutateScatter(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // debug version in templateView.cpp
inline CtemplateDoc* CWordlabView::GetDocument() const
   { return reinterpret_cast<CtemplateDoc*>(m_pDocument); }
#endif

