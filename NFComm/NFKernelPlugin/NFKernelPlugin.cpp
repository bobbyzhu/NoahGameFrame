// NFKernelPlugin.cpp : Defines the exported functions for the DLL application.
//

#include "NFKernelPlugin.h"
#include "NFCKernelModule.h"
#include "NFCSceneModule.h"
#include "NFCEventModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFKernelPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFKernelPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

const int NFKernelPlugin::GetPluginVersion()
{
    return 0;
}

const std::string NFKernelPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFKernelPlugin)
}

void NFKernelPlugin::Install()
{
    REGISTER_MODULE(pPluginManager, NFISceneModule, NFCSceneModule)
	REGISTER_MODULE(pPluginManager, NFIKernelModule, NFCKernelModule)
	REGISTER_MODULE(pPluginManager, NFIEventModule, NFCEventModule)
}

void NFKernelPlugin::Uninstall()
{
	UNREGISTER_MODULE(pPluginManager, NFIEventModule, NFCEventModule)
	UNREGISTER_MODULE(pPluginManager, NFIKernelModule, NFCKernelModule)
	UNREGISTER_MODULE(pPluginManager, NFISceneModule, NFCSceneModule)
}