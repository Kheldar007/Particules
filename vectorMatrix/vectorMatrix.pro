
TARGET = vectorMatrix
TEMPLATE = lib
CONFIG += staticlib

#INCLUDEPATH +=

#SOURCES += *.cpp
SOURCES += vectCalc.cpp \
    vec2f.cpp \
    vec3f.cpp \
    matrix33f.cpp

#HEADERS += *.h *.hpp
HEADERS += vecttempl.h vectCalc.h \
    arrayTemplate.h \
    arrayTemplate.hpp \
    vectorTemplate.h \
    vectorTemplate.hpp \
    vec2f.h \
    vec3f.h \
    matrix33f.h

DESTDIR = ../lib

QMAKE_CXXFLAGS += -Wall

