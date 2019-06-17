#-------------------------------------------------
#
# Project created by QtCreator 2019-06-15T16:59:01
#
#-------------------------------------------------

QT       -= gui

TARGET = algorithmsandstructureslib
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    domain/book.cpp \
    utility/compare/greater.tpp \
    utility/compare/less.tpp\
    sort/insertion_sorting.tpp \
    event/compare.tpp \
    event/extract.tpp \
    event/move.tpp \
    event/put.tpp \

HEADERS += \
    domain/book.h \
    event/algorithm_event.h \
    event/compare.h \
    event/extract.h \
    event/move.h \
    event/put.h \
    event/responsive_algorithm.h \
    sort/insertion_sorting.h \
    sort/sorting.h \
    utility/compare/comparator.h \
    utility/compare/greater.h \
    utility/compare/less.h \
    utility/hashable.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
