QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    specialdate.cpp \
    tst_special_date.cpp

HEADERS += \
    specialdate.h
