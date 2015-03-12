#ifndef INIDATASOURCE_H
#define INIDATASOURCE_H

#include "datasourceplugin.h"
#include "datasourcepluginobject.h"

#include <QObject>
#include <QSettings>

namespace yasem
{
class Profile;

class IniDatasource : public DatasourcePluginObject
{
    Q_OBJECT
public:
    explicit IniDatasource(Profile *profile, Plugin* plugin);
    virtual ~IniDatasource();

signals:

public slots:
    bool set(const QString &tag, const QString &name, const int value);
    int get(const QString &tag, const QString &name, const int defaultValue);

    bool set(const QString &tag, const QString &name, const QString &value);
    QString get(const QString &tag, const QString &name, const QString &defaultValue);

protected:
    Profile* m_profile;
    QSettings* m_settings;

public:
    PluginObjectResult init();
    PluginObjectResult deinit();
    DatasourcePluginObject* getDatasourceForProfile(Profile* profile);
};

}

#endif // INIDATASOURCE_H
