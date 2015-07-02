#ifndef INIDS_H
#define INIDS_H


#include "inids_global.h"
#include "plugin.h"
#include "datasourceplugin.h"

#include <QSet>
#include <QSettings>

namespace yasem
{

class INIDSSHARED_EXPORT IniDsPlugin: public Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.mvas.yasem.IniDS/1.0" FILE "metadata.json")
    Q_INTERFACES(yasem::Plugin)

    Q_CLASSINFO("author", "Maxim Vasilchuk")
    Q_CLASSINFO("description", "INI datasource provider")
    Q_CLASSINFO("version", MODULE_VERSION)
    Q_CLASSINFO("revision", GIT_VERSION)
public:
    explicit IniDsPlugin(QObject* parent = 0);
    virtual ~IniDsPlugin();

    // DatasourcePlugin interface
public:


    // Plugin interface
public:
    void register_dependencies();
    void register_roles();
};

}

#endif // INIDS_H
