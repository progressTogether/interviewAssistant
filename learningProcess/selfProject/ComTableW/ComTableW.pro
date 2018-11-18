#-------------------------------------------------
#
# Project created by QtCreator 2018-11-18T10:59:04
#
#-------------------------------------------------

QT       -= gui

TARGET = ComTableW
TEMPLATE = lib

DEFINES += COMTABLEW_LIBRARY

SOURCES += comtablew.cpp

HEADERS += comtablew.h\
        ComTableW_global.h

#配置relseas或者debug
CONFIG +=debug_and_release
CONFIG(debug,debug|release){
#生成目标的路径
DESTDIR= ../XO/Debug
}else{
DESTDIR= ../XO/Release
}

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE9F48FED
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = ComTableW.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
