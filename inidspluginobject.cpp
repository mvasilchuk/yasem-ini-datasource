#include "inidspluginobject.h"
#include "inidatasource.h"
#include "datasourcefactory.h"

using namespace yasem;

IniDsPluginObject::IniDsPluginObject(SDK::Plugin* plugin):
    SDK::DatasourceClass(plugin)
{

}

SDK::PluginObjectResult yasem::IniDsPluginObject::init()
{
    SDK::DatasourceFactory::instance()->registerDatasourceClass(this);
    return SDK::PLUGIN_OBJECT_RESULT_OK;
}

SDK::PluginObjectResult yasem::IniDsPluginObject::deinit()
{
    return SDK::PLUGIN_OBJECT_RESULT_OK;
}

SDK::Datasource *IniDsPluginObject::createDatasource(const SDK::Profile* profile)
{
    return new IniDatasource(this, profile);
}
