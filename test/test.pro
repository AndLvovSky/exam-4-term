QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    domain/test_book.cpp \
    main_test.cpp \
    runner/test_runner.cpp \
    sort/test_insertion_sorting.cpp \
    sort/test_sorting.cpp \
    utility/compare/test_comparator.cpp

LIBS += -L$$OUT_PWD/../src/debug/ -lalgorithmsandstructureslib

INCLUDEPATH += $$PWD/../src

DEPENDPATH += $$PWD/../src

DESTDIR = $$OUT_PWD/../src/debug/

HEADERS += \
    domain/test_book.h \
    runner/test_runner.h \
    sort/test_insertion_sorting.h \
    sort/test_sorting.h \
    utility/compare/test_comparator.h
