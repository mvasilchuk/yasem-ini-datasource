#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T22:43:45
#
#-------------------------------------------------

QT       -= gui

CONFIG += C++11

TARGET = yasem-ini-datasource
TEMPLATE = lib
CONFIG += plugin

DEFINES += INIDS_LIBRARY

INCLUDEPATH += ../yasem-core

SOURCES += inids.cpp \
    inidatasource.cpp

HEADERS += inids.h\
    inids_global.h \
    inidatasource.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    metadata.json \
    LICENSE \
    README.md

include(../common.pri)
DESTDIR = $$DEFAULT_PLUGIN_DIR
