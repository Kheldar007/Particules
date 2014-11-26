QT       -= gui

TARGET = image
TEMPLATE = lib

DEFINES += IMAGE_LIBRARY

SOURCES += \
    image2grey.cpp \
    gradientsobel.cpp \
    image2rgb.cpp

HEADERS += \
    imageTemplate.h \
    imageTemplate.hpp \
    image2dTemplate.h \
    image2dTemplate.hpp \
    image2grey.h \
    gradientsobel.h \
    image2rgb.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
