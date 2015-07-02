#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T22:43:45
#
#-------------------------------------------------

VERSION = 0.1.0
TARGET = yasem-ini-datasource
TEMPLATE = lib

include($${top_srcdir}/common.pri)

QT       -= gui

DEFINES += INIDS_LIBRARY

SOURCES += \
    inidatasource.cpp \
    inidsplugin.cpp

HEADERS +=\
    inids_global.h \
    inidatasource.h \
    inidsplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    metadata.json \
    LICENSE \
    README.md
