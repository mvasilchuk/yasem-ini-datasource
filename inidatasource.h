#ifndef INIDATASOURCE_H
#define INIDATASOURCE_H

#include "datasourceplugin.h"
#include "datasourcepluginobject.h"

#include <QObject>
#include <QSettings>

namespace yasem
{
namespace SDK {
class Profile;
}

class IniDatasource : public SDK::DatasourcePluginObject
{
    Q_OBJECT
public:
    explicit IniDatasource(SDK::Profile *profile, SDK::Plugin* plugin);
    virtual ~IniDatasource();

signals:

public slots:
    bool set(const QString &tag, const QString &name, const int value);
    int get(const QString &tag, const QString &name, const int defaultValue);

    bool set(const QString &tag, const QString &name, const QString &value);
    QString get(const QString &tag, const QString &name, const QString &defaultValue);

protected:
    SDK::Profile* m_profile;
    QSettings* m_settings;

public:
    SDK::PluginObjectResult init();
    SDK::PluginObjectResult deinit();
    SDK::DatasourcePluginObject* getDatasourceForProfile(SDK::Profile* profile);
};

}

#endif // INIDATASOURCE_H
