TEMPLATE = app
CONFIG += console
QT -= gui
QT += testlib

include(../qtattodatetime.pri)

INCLUDEPATH +=                              \
    src                                     \

SOURCES +=                                  \
    src/test_main.cpp                       \
    src/test_qtattotimedelta.cpp            \
    src/test_qtattodatetime.cpp             \

HEADERS +=                                  \
    src/test_qtattotimedelta.h              \
    src/test_qtattodatetime.h               \
