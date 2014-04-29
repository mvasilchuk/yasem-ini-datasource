#ifndef INIDATASOURCE_H
#define INIDATASOURCE_H

#include "datasource.h"

#include <QObject>
#include <QSettings>

namespace yasem
{
class Profile;
class IniDatasource : public QObject, public Datasource
{
    Q_OBJECT
public:
    explicit IniDatasource(Profile *profile);

signals:

public slots:
    bool set(const QString &tag, const QString &name, const int value);
    int get(const QString &tag, const QString &name, const int defaultValue);

    bool set(const QString &tag, const QString &name, const QString &value);
    QString get(const QString &tag, const QString &name, const QString &defaultValue);

protected:
    QSettings* settings;
    Profile* profile;

    // Datasource interface
public:

};

}

#endif // INIDATASOURCE_H
