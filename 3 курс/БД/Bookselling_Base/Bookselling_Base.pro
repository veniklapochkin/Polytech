#-------------------------------------------------
#
# Project created by QtCreator 2015-12-17T20:16:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bookselling_Base
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customerlogin.cpp \
    courierlogin.cpp \
    adminlogin.cpp \
    adminpage.cpp \
    courierpage.cpp \
    customerpage.cpp \
    makeorder.cpp

HEADERS  += mainwindow.h \
    customerlogin.h \
    courierlogin.h \
    adminlogin.h \
    adminpage.h \
    courierpage.h \
    customerpage.h \
    makeorder.h

FORMS    += mainwindow.ui \
    customerlogin.ui \
    courierlogin.ui \
    adminlogin.ui \
    adminpage.ui \
    courierpage.ui \
    customerpage.ui \
    makeorder.ui
