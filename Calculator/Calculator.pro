TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parser.cpp \
    calculator.cpp

HEADERS += \
    parser.h \
    calculator.h \
    nconstants.h
