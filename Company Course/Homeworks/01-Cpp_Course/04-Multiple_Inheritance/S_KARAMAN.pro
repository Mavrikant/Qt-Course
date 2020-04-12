TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    human.cpp \
    worker.cpp \
    teacher.cpp

HEADERS += \
    human.h \
    worker.h \
    teacher.h
