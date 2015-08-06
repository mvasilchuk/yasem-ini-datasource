#ifndef INDSPLUGINOBJECT_H
#define INDSPLUGINOBJECT_H

#include "datasourceclass.h"

#include <functional>

namespace yasem
{

class IniDsPluginObject: public SDK::DatasourceClass
{
public:
    IniDsPluginObject(SDK::Plugin* plugin);

    // AbstractPluginObject interface
public:
    virtual SDK::PluginObjectResult init();
    virtual SDK::PluginObjectResult deinit();
public slots:
    SDK::Datasource* createDatasource(const SDK::Profile* profile);
};

}

#endif // INDSPLUGINOBJECT_H
