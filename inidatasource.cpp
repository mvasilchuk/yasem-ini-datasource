#include "inidatasource.h"
#include "macros.h"
#include "stbplugin.h"
#include "core.h"
#include "stbprofile.h"

#include <QDebug>
#include <QSettings>

using namespace yasem;

IniDatasource::IniDatasource(Profile *profile)
{
    Q_ASSERT(profile != NULL);
    this->profile = profile;
    QString profilesDir = Core::instance()->settings()->value("ProfilesDir", CONFIG_PROFILES_DIR).toString();

    settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, QString(CONFIG_DIR).append("/").append(profilesDir),
                             profile->getId());

    Q_ASSERT(settings);
}

bool IniDatasource::set(const QString &tag, const QString &name, const int value)
{
    return set(tag, name, QString::number(value));
}

int IniDatasource::get(const QString &tag, const QString &name, const int defaultValue)
{
    return get(tag, name, QString::number(defaultValue)).toInt();
}

bool IniDatasource::set(const QString &tag, const QString &name, const QString &value)
{
    Q_ASSERT(settings);
    Q_ASSERT(name != "");
    settings->setValue(QString("%1/%2").arg(tag).arg(name), value);
    return true;
}

QString IniDatasource::get(const QString &tag, const QString &name, const QString &defaultValue = "")
{
    Q_ASSERT(settings);
    return settings->value(QString("%1/%2").arg(tag).arg(name), defaultValue).toString();
}
