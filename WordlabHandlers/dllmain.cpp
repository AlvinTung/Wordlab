// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "WordlabHandlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CWordlabHandlersModule _AtlModule;

class CWordlabHandlersApp : public CWinApp
{
public:

// Overrides
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CWordlabHandlersApp, CWinApp)
END_MESSAGE_MAP()

CWordlabHandlersApp theApp;

BOOL CWordlabHandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
	return CWinApp::InitInstance();
}

int CWordlabHandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
