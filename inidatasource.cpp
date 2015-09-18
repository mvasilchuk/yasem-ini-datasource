#include "inidatasource.h"
#include "macros.h"
#include "core.h"
#include "stbprofile.h"
#include "datasourcefactory.h"

#include <QDebug>
#include <QSettings>

using namespace yasem;

IniDatasource::IniDatasource(QObject* parent, const SDK::Profile* profile):
    SDK::Datasource(parent),
    m_settings(NULL)
{
    QString profilesDir = SDK::Core::instance()->settings()->value("ProfilesDir", CONFIG_PROFILES_DIR).toString();

    m_settings = new QSettings(
                           SDK::Core::instance()->getConfigDir().append("%1/%2.ini").arg(profilesDir).arg(profile->getId()),
                           QSettings::IniFormat, this
                    );
}

IniDatasource::~IniDatasource()
{
    STUB() << this;
    if(m_settings)
        delete m_settings;
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
    if(m_settings == NULL) return false;
    m_settings->setValue(QString("%1/%2").arg(tag).arg(name), value);
    return true;
}

QString IniDatasource::get(const QString &tag, const QString &name, const QString &defaultValue = "")
{
    if(m_settings == NULL) return "";
    return m_settings->value(QString("%1/%2").arg(tag).arg(name), defaultValue).toString();
}




void IniDatasource::beginGroup(const QString &group)
{
    if(m_settings == NULL) return;
        m_settings->beginGroup(group);
}

void IniDatasource::endGroup()
{
    if(m_settings == NULL) return;
        m_settings->endGroup();
}


void yasem::IniDatasource::setValue(const QString &key, const QVariant &value)
{
    if(m_settings == NULL) return;
        m_settings->setValue(key, value);
}

QVariant yasem::IniDatasource::value(const QString &key, const QVariant &defaultValue) const
{
    if(m_settings == NULL) return defaultValue;
        return m_settings->value(key, defaultValue);
}


QStringList yasem::IniDatasource::allKeys() const
{
    if(m_settings == NULL) return QStringList();
        return m_settings->allKeys();
}
