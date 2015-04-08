#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T23:16:13
#
#-------------------------------------------------

QT       += webkit
QT       += webkitwidgets
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnglishHelper
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/control.cpp \
    src/chooseui.cpp \
    src/findui.cpp \
    src/memoryui.cpp \
    src/articleui.cpp \
    src/settingsui.cpp\
    src/word.cpp\
    src/func.cpp

HEADERS  += \
    src/control.h \
    src/chooseui.h \
    src/findui.h \
    src/memoryui.h \
    src/articleui.h \
    src/settingsui.h \
    src/word.h \
    src/func.h

FORMS    += \
    form/control.ui \
    form/chooseui.ui \
    form/findui.ui \
    form/memoryui.ui \
    form/articleui.ui \
    form/settingsui.ui

RESOURCES += \
    res/resource.qrc

