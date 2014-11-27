
TARGET = image
TEMPLATE = lib
CONFIG += staticlib

#INCLUDEPATH +=

#SOURCES += *.cpp
SOURCES += image2grey.cpp \
    gradientsobel.cpp \
    image2rgb.cpp

#HEADERS += *.h *.hpp
HEADERS += imageTemplate.h \
    imageTemplate.hpp \
    image2dTemplate.h \
    image2dTemplate.hpp \
    image2grey.h \
    gradientsobel.h \
    image2rgb.h

DESTDIR = ../lib

QMAKE_CXXFLAGS += -Wall
