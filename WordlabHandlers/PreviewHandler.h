// PreviewHandler.h : Declaration of the preview handler

#pragma once
#include "resource.h"       // main symbols

#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include <afxext.h>
#include "..\Wordlab\WordlabDoc.h"
#include "..\Wordlab\WordlabView.h"
#include "WordlabHandlers_i.h"

using namespace ATL;

// CPreviewHandler

class ATL_NO_VTABLE CPreviewHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPreviewHandler, &CLSID_Preview>,
	public CPreviewHandlerImpl <CPreviewHandler>
{
public:
	CPreviewHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PREVIEW_HANDLER)
DECLARE_NOT_AGGREGATABLE(CPreviewHandler)

BEGIN_COM_MAP(CPreviewHandler)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IOleWindow)
	COM_INTERFACE_ENTRY(IInitializeWithStream)
	COM_INTERFACE_ENTRY(IPreviewHandler)
	COM_INTERFACE_ENTRY(IPreviewHandlerVisuals)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		CPreviewHandlerImpl<CPreviewHandler>::FinalRelease();
	}

protected:
	virtual IPreviewCtrl* CreatePreviewControl()
	{
		// create your preview control here
		CMFCPreviewCtrlImpl *pPreviewCtrl = NULL;
		ATLTRY(pPreviewCtrl = new CMFCPreviewCtrlImpl());
		return pPreviewCtrl;
	}

	DECLARE_DOCUMENT(CWordlabDoc)

public:
	virtual HRESULT InitializeDocumentPreview(HWND hWndParent, RECT* prc)
	{
		m_pPreviewCtrl = CreatePreviewControl();
		CMFCPreviewCtrlImpl* pCtrl = DYNAMIC_DOWNCAST(CMFCPreviewCtrlImpl, (CObject*) m_pPreviewCtrl);
		if (pCtrl == NULL)
		{
			ATLTRACE2(atlTraceGeneral, 4, L"InitializeDocumentPreview: pointer to preview control is NULL.\n");
			return E_POINTER;
		}

		ASSERT_VALID(pCtrl);

		CCreateContext ctx;
		ctx.m_pNewViewClass = RUNTIME_CLASS(CWordlabView);

		m_pDocument = CreateDocument();

		if (m_pDocument == NULL) 
		{
			ATLTRACE2(atlTraceGeneral, 4, L"InitializeDocumentPreview: pointer to document is NULL.\n");
			return E_POINTER;
		}

		m_pDocument->AddRef();
		ctx.m_pCurrentDoc = DYNAMIC_DOWNCAST(CWordlabDoc, (CObject*) m_pDocument->GetContainer());

		if (!pCtrl->Create(hWndParent, prc, &ctx))
		{
			ATLTRACE2(atlTraceGeneral, 4, L"InitializeDocumentPreview: preview control creation failed. Error Code: %d\n", GetLastError());
			return E_FAIL;
		}
		return S_OK;
	}
};

OBJECT_ENTRY_AUTO(__uuidof(Preview), CPreviewHandler)
