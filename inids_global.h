#ifndef INIDS_GLOBAL_H
#define INIDS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(INIDS_LIBRARY)
#  define INIDSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define INIDSSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // INIDS_GLOBAL_H
