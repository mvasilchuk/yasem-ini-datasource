#include "inidsplugin.h"
#include "inidspluginobject.h"

using namespace yasem;

IniDsPlugin::IniDsPlugin(QObject *parent):
    SDK::Plugin(parent)
{
    setMultithreading(false);
}

IniDsPlugin::~IniDsPlugin()
{
    STUB();
}

void IniDsPlugin::register_dependencies()
{
}

void IniDsPlugin::register_roles()
{
    register_role(SDK::ROLE_DATASOURCE, new IniDsPluginObject(this));
}
