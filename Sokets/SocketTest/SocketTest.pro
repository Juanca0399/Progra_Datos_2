QT += core
QT += network
QT -= gui

TARGET = SocketTest
CONFIG += console
CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += main.cpp \
    sockettest.cpp

HEADERS += \
    sockettest.h
