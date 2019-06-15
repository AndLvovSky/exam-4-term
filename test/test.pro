QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    domain/test_book.cpp \
    main_test.cpp

LIBS += -L$$OUT_PWD/../src/debug/ -lalgorithmsandstructureslib

INCLUDEPATH += $$PWD/../src

DEPENDPATH += $$PWD/../src

DESTDIR = $$OUT_PWD/../src/debug/

HEADERS += \
    domain/test_book.h
