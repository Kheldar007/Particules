QT       -= gui

TARGET = image
TEMPLATE = lib

DEFINES += IMAGE_LIBRARY

SOURCES +=

HEADERS += \
    imageTemplate.h \
    imageTemplate.hpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
