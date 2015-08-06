#ifndef INIDATASOURCE_H
#define INIDATASOURCE_H

#include "datasource.h"

#include <QObject>
#include <QSettings>

namespace yasem
{
namespace SDK {
class Profile;
}

class IniDatasource : public SDK::Datasource
{
    Q_OBJECT
public:
    explicit IniDatasource(QObject* parent, const SDK::Profile* profile);
    virtual ~IniDatasource();

signals:

public slots:
    bool set(const QString &tag, const QString &name, const int value);
    int get(const QString &tag, const QString &name, const int defaultValue);

    bool set(const QString &tag, const QString &name, const QString &value);
    QString get(const QString &tag, const QString &name, const QString &defaultValue);

protected:
    QSettings* m_settings;
};

}

#endif // INIDATASOURCE_H
