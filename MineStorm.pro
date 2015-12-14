#-------------------------------------------------
#
# Project created by QtCreator 2015-12-14T13:39:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineStorm
TEMPLATE = app

CONFIG+=C++11



SOURCES += main.cpp \
    controller.cpp \
    dummygame.cpp \
    game.cpp \
    gameboard.cpp \
    gameoflife.cpp \
    mainwindow.cpp

HEADERS  += \
    controller.h \
    dummygame.h \
    game.h \
    gameboard.h \
    gameoflife.h \
    mainwindow.h

FORMS    +=
