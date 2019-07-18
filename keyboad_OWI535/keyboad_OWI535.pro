#-------------------------------------------------
#
# Project created by QtCreator 2019-07-13T17:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = keyboad_OWI535
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += /usr/local/Cellar/libusb/1.0.22/include/
LIBS += -L/usr/local/Cellar/libusb/1.0.22/lib -lusb-1.0

#for my windows host
#INCLUDEPATH += C:\Users\cslay\Downloads\20190715\github\libusb-1.0.22.7\include
#LIBS += -LC:\Users\cslay\Downloads\20190715\github\libusb-1.0.22.7\MS64\dll\ -llibusb-1.0





SOURCES += \
        main.cpp \
        mainwidget.cpp \
    control.cpp \
    commander.cpp

HEADERS += \
        mainwidget.h \
    control.h \
    commander.h

FORMS += \
        mainwidget.ui
