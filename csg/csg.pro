
TARGET = csg
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -Wall

INCLUDEPATH += ../vectorMatrix ../image

SOURCES += *.cpp \
    boundingbox.cpp

HEADERS += *.h \
    boundingbox.h

DESTDIR = ../lib

