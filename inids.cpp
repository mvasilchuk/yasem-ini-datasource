#include "inids.h"
#include "inidatasource.h"

#include "stbplugin.h"

using namespace yasem;

IniDS::IniDS()
{

}

PLUGIN_ERROR_CODES IniDS::initialize()
{
    return PLUGIN_ERROR_NO_ERROR;
}

PLUGIN_ERROR_CODES IniDS::deinitialize()
{
    STUB();
    return PLUGIN_ERROR_NO_ERROR;
}

Datasource *IniDS::getDatasourceForProfile(Profile *profile)
{
    Q_ASSERT(profile != NULL);

    return new IniDatasource(profile);
}


