QT += core
QT += network
QT -= gui

TARGET = MyFirstServer
CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp \
    myserver.cpp

HEADERS += \
    myserver.h
