#-------------------------------------------------
#
# Project created by QtCreator 2015-03-31T23:16:13
#
#-------------------------------------------------

QT       += webkit
QT       += webkitwidgets
QT       += core gui
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnglishHelper
TEMPLATE = app

CONFIG  +=axcontainer

SOURCES += \
    src/main.cpp \
    src/control.cpp \
    src/chooseui.cpp \
    src/findui.cpp \
    src/memoryui.cpp \
    src/articleui.cpp \
    src/settingsui.cpp\
    src/word.cpp\
    src/func.cpp \
    src/aboutui.cpp \
    src/user.cpp

HEADERS  += \
    src/control.h \
    src/chooseui.h \
    src/findui.h \
    src/memoryui.h \
    src/articleui.h \
    src/settingsui.h \
    src/word.h \
    src/func.h \
    src/aboutui.h \
    src/user.h

FORMS    += \
    form/control.ui \
    form/chooseui.ui \
    form/findui.ui \
    form/memoryui.ui \
    form/articleui.ui \
    form/settingsui.ui \
    form/aboutui.ui

RESOURCES += \
    res/resource.qrc \

DISTFILES += \
    res/dictionary/dictionary.txt

macx{
    copy_dictionary.path=$$OUT_PWD/EnglishHelper.app/Contents/MacOS/
}
copy_dictionary.files += res/dictionary/dictionary.txt

INSTALLS += \
    copy_dictionary
