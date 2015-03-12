#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T22:43:45
#
#-------------------------------------------------

VERSION = 0.1.0

QT       -= gui

CONFIG += c++11

TARGET = yasem-ini-datasource
TEMPLATE = lib

DEFINES += INIDS_LIBRARY

INCLUDEPATH += ../../yasem-core/
DEPENDPATH += ../../yasem-core/

SOURCES += \
    ../../yasem-core/plugin.cpp \
    inidatasource.cpp \
    inidsplugin.cpp

HEADERS +=\
    inids_global.h \
    inidatasource.h \
    inidsplugin.h \
    ../../yasem-core/plugin.h \
    ../../yasem-core/abstractpluginobject.h \
    ../../yasem-core/datasourcepluginobject.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    metadata.json \
    LICENSE \
    README.md

include(../../common.pri)
DESTDIR = $$DEFAULT_PLUGIN_DIR
