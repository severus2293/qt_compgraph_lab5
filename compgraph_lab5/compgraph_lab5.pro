#-------------------------------------------------
#
# Project created by QtCreator 2023-04-03T20:02:35
#
#-------------------------------------------------

QT       += core gui opengl
LIBS += -lOpengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = compgraph_lab5
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

CONFIG += c++11

SOURCES += \
    glwidget.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS += \
    glwidget.h \
    mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shaders/lbf.frag \
    assets/an.jpg \
    assets/fish.jpg \
    assets/boat.jpg \
    assets/fire.jpg \
    assets/candle.jpg \
    assets/butterfly.jpg \
    shaders/lbv.vert
DISTFILES += \
    lab5.fsh \
    shaders/lbf.frag \
    shaders/lbv.vert \
    assets/water.jpg \
    assets/fish.jpg \
    assets/an.png \
    assets/boat.jpg \
    assets/fire.jpg \
    assets/candle.jpg \
    assets/butterfly.jpg


