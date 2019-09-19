// dllmain.h : Declaration of module class.

class CWordlabHandlersModule : public ATL::CAtlDllModuleT< CWordlabHandlersModule >
{
public :
	DECLARE_LIBID(LIBID_WordlabHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_WordlabHANDLERS, "{3211FD4D-F4C3-49A4-BDA9-38810A6464EC}")
};

extern class CWordlabHandlersModule _AtlModule;
