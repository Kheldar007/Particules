
TARGET = csg
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -Wall

INCLUDEPATH += ../vectorMatrix ../image

SOURCES += *.cpp \
    boundingbox.cpp \
    csgtree.cpp \
    csgnode.cpp \
    csgoperation.cpp \
    csgprimitive.cpp \
    csgdisk.cpp \
    csgpolygon.cpp

HEADERS += *.h \
    boundingbox.h \
    csgtree.h \
    csgnode.h \
    csgoperation.h \
    csgprimitive.h \
    csgdisk.h \
    csgpolygon.h

DESTDIR = ../lib

