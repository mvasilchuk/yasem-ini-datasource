#include "inidsplugin.h"
#include "inidatasource.h"

using namespace yasem;

IniDsPlugin::IniDsPlugin(QObject *parent):
    Plugin(parent)
{
    setMultithreading(false);
}

IniDsPlugin::~IniDsPlugin()
{

}

void yasem::IniDsPlugin::register_dependencies()
{
}

void yasem::IniDsPlugin::register_roles()
{
    register_role(ROLE_DATASOURCE, new IniDatasource(NULL, this));
}
