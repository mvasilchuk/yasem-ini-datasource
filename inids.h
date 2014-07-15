#ifndef INIDS_H
#define INIDS_H

#include "stbprofileplugin.h"
#include "datasourceplugin.h"
#include "inids_global.h"

#include <QSet>

#include <QSettings>

namespace yasem
{

class INIDSSHARED_EXPORT IniDS: public QObject, public virtual Plugin, public virtual DatasourcePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.mvas.yasem.IniDS/1.0" FILE "metadata.json")
    Q_INTERFACES(yasem::Plugin yasem::DatasourcePlugin)

    Q_CLASSINFO("author", "Maxim Vasilchuk")
    Q_CLASSINFO("description", "INI datasource provider implementation for YASEM")
public:
    IniDS();

    // Plugin interface
public:
    PLUGIN_ERROR_CODES initialize();
    PLUGIN_ERROR_CODES deinitialize();


    // DatasourcePlugin interface
public:
    Datasource* getDatasourceForProfile(Profile* profile);

    // Plugin interface
public:
    void register_dependencies();
    void register_roles();
};

}

#endif // INIDS_H
