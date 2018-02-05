TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    AnalysisMediaInfo.cpp

INCLUDEPATH += \
    /usr/local/include

LIBS += -L/usr/local/lib -lmediainfo -ldl

HEADERS += \
    AnalysisMediaInfo.h

