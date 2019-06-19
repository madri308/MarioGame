#-------------------------------------------------
#
# Project created by QtCreator 2019-06-01T20:36:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MarioGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    card.cpp \
    choosecardwindow.cpp \
        main.cpp \
        gamewindow.cpp \
    board.cpp \
    node.cpp \
    startwindow.cpp \
    player.cpp \
    choosewindow.cpp \
    matrixwindow.cpp \
    catwindow.cpp\
    bomberwindow.cpp \
    coinswindow.cpp \
    guesswhowindow.cpp \
    pathwindow.cpp \
    wordsearchwindow.cpp

HEADERS += \
    card.h \
    choosecardwindow.h \
        gamewindow.h \
    board.h \
    node.h \
    startwindow.h \
    player.h \
    choosewindow.h \
    matrixwindow.h \
    catwindow.h\
    bomberwindow.h \
    coinswindow.h \
    guesswhowindow.h \
    pathwindow.h \
    wordsearchwindow.h

FORMS += \
    choosecardwindow.ui \
        gamewindow.ui \
    startwindow.ui \
    choosewindow.ui \
    matrixwindow.ui \
    catwindow.ui\
    bomberwindow.ui \
    coinswindow.ui \
    guesswhowindow.ui \
    mainwindow.ui \
    pathwindow.ui \
    wordsearchwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    extrafiles.qrc\
    bombermario.qrc \
    catchthecat.qrc \
    characters.qrc \
    coins.qrc \
    resource.qrc
