#ifndef INIDATASOURCE_H
#define INIDATASOURCE_H

#include "datasource.h"

#include <QObject>
#include <QSettings>

namespace yasem {

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
    bool set(const QString &tag, const QString &name, const int value) Q_DECL_OVERRIDE;
    int get(const QString &tag, const QString &name, const int defaultValue) Q_DECL_OVERRIDE;

    bool set(const QString &tag, const QString &name, const QString &value) Q_DECL_OVERRIDE;
    QString get(const QString &tag, const QString &name, const QString &defaultValue) Q_DECL_OVERRIDE;

    void beginGroup(const QString &group) Q_DECL_OVERRIDE;
    void endGroup() Q_DECL_OVERRIDE;

    void setValue(const QString &key, const QVariant &value) Q_DECL_OVERRIDE;
    QVariant value(const QString &key, const QVariant &defaultValue) const Q_DECL_OVERRIDE;

    QStringList allKeys() const Q_DECL_OVERRIDE;

protected:
    QSettings* m_settings;
};

}

#endif // INIDATASOURCE_H
