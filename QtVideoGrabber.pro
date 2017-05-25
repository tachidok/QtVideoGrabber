#-------------------------------------------------
#
# Project created by QtCreator 2017-05-23T16:45:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtVideoGrabber
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/cc_image.cpp \
    src/cc_grabber.cpp

HEADERS  += mainwindow.h \
    src/cc_image.h \
    src/cc_grabber.h

FORMS    += mainwindow.ui
