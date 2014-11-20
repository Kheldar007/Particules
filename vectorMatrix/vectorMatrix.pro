
TARGET = vectorMatrix
TEMPLATE = lib
CONFIG += staticlib

#INCLUDEPATH +=

#SOURCES += *.cpp
SOURCES += vectCalc.cpp

#HEADERS += *.h *.hpp
HEADERS += vecttempl.h vectCalc.h \
    arrayTemplate.h \
    arrayTemplate.hpp \
    vectorTemplate.h \
    vectorTemplate.hpp

DESTDIR = ../lib

QMAKE_CXXFLAGS += -Wall

