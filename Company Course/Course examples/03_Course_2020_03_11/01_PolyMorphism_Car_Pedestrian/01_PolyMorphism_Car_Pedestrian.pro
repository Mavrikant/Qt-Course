TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    movingobject.cpp \
    pedestrian.cpp \
    car.cpp

HEADERS += \
    movingobject.h \
    pedestrian.h \
    car.h
