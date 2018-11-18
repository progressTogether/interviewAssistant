#-------------------------------------------------
#
# Project created by QtCreator 2018-11-17T10:17:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XO
TEMPLATE = app

#调查一下为什么不可以
#配置relseas或者debug
CONFIG +=Debug_and_Debug
CONFIG(debug,Debug|Release){
#生成目标的名字
TARGET= XO
#生成目标的路径
DESTDIR= ./Debug
}else{
TARGET= XO
DESTDIR= ./Release
}

#就是将源码路径和构建路径分开（也就是生成的makefile文件和其他产物都不放到源码路径），以此来保证源码路径的清洁。

SOURCES += main.cpp\
        mainwindow.cpp \
    singleton.cpp \
    WriteInfoToFile.cpp

HEADERS  += mainwindow.h \
    singleton.h \
    commonMsg.h \
    commonType.h \
    WriteInfoToFile.h \
    commonMethod.h

FORMS    += mainwindow.ui

#https://www.cnblogs.com/boright88/p/6264642.html
#在QT中使用qmake自动生成pro文件，如果要自己定制工程选项，则需要自行修改pro文件。

#pro文件有以下关键字：TEMPLATE、TARGET、DESTDIR、DEPENDPATH、INCLUDEPATH、SOURCES、HEADERS、FORMS、LIBS、TRASHLATIONS、RESOURCES、CONFIG、UI_DIR、RCC_DIR、MOC_DIR、OBJECTS_DIR、DEFINES。

#其中：TEMPLATE变量定义了工程的编译模式，默认编译为app。TEMPLATE可以为：app、lib（库）、subdirs（多级目录管理）等。

#TARGET：生成目标的名字。如：TARGET = mylib

#DESTDIR:生成目标的路径。如：DESTDIR = ../bin/ 则目标文件的路径为当前pro文件所在目录的上一级的bin目录下

#DEPENDPATH：工程的依赖路径

#INCLUDEPATH：指定工程要用到的头文件路径，一般包括用户自定义的头文件路径或没有放入系统头文件路径的头文件路径

#SOURCES：工程需要的源文件

#HEADERS：工程所需要的头文件，一般包括用户自定义的头文件或未放入系统头文件路径的头文件

#FORMS：工程要用到的ui文件（ui文件时用QT设计器生成的）

#LIBS：加载动态库文件。如：LIBS+=./mitab/libmitab.so

#TRASHLATIONS：加载要用到的语言翻译*.ts文件

#RESOURCES：加载要用到的资源*.qrc文件

#CONFIG：告诉qmake应用程序的配置信息：这个变量可以用来指定是生成debug模式还是release模式，也可以都生成；也可以用来打开编译器警告(warn_on输出尽可能多的警告信息)或者关闭(warn_off -编译器会输出尽可能少的警告信息)；还可以用来配置要Qt加载库，例如如果要用到Qt的多线程，则：CONFIG+=qt thread再例如配置debug或release模式：
#CONFIG +=debug_and_release
#CONFIG(debug,debug|release){
#TARGET= hello
#DESTDIR= ./debug
#}else{
#TARGET= hello
#DESTDIR= ./release
#}
#如果你要在windows下面运行console：CONFIG +=console

#UI_DIR：UIC将ui转化为头文件所存放的目录

#RCC_DIR：RCC将qrc文件转化为头文件所存放的目录；

#MOC_DIR：MOC命令将含Q_OBJECT的头文件转换为标准的头文件存放的目录；

#OBJECTS_DIR：生成的目标文件存放的目录；

#DEFINES：应用程序所需的额外的预处理程序定义的列表#在.h文件中就可以使用：#ifdefinexx_xx_xxx；

#LIBS += -L folderPath //引入的lib文件的路径 -L：引入路径

#Release:LIBS+= -L folderPath // release 版引入的lib文件路径

#Debug:LIBS+= -L folderPath // Debug 版引入的lib 文件路径

#RC_FILE = xxx.icns //程序中所用到的图片等资源文件；

#QT是跨平台的，所以我们在不同的平台上用同一个pro文件，这要加入有关平台的信息。windows平台是win32，Linux平台是unix。
#例如在Windows和Linux的动态库文件格式是不一样的，一个是lib文件一个是so文件：win32:LIBS+= ./mitab/mitab_i.lib   unix:LiBS+= ./mitab/libmitab.so
#再如：win32{SOURCES+= hello_win.cpp //win平台}   unix{SOURCES+= hello_linux.cpp //unix/linux平台}

#可以通过在其它任何一个变量的变量名前加$$来把这个变量的值分配给当前的变量，例如：MY_DEFINES= $$DEFINE #将DEFINE的值分配给MY_DEFINES
#又如：
#TARGET = myapp
#UI_DIR = ../bin/$$TARGET/ui
#MOC_DIR = ../bin/$$TARGET/moc
#OBJECTS_DIR = ../bin/$$TARGET/objects
#则uic所生成的文件在路径../bin/myapp/ui目录下；moc文件在../bin/myapp/moc目录下；obj目标文件在../bin/myapp/objects目录下。
