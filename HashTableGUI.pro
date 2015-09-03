#-------------------------------------------------
#
# Project created by QtCreator 2015-09-01T21:41:49
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashTableGUI
TEMPLATE = app


SOURCES += main.cpp\
        hashmapmaingui.cpp \
    unordermap.cpp

HEADERS  += hashmapmaingui.h \
    unordermap.h

FORMS    += hashmapmaingui.ui
