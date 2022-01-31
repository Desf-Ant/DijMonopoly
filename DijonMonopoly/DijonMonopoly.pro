QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    case.cpp \
    company.cpp \
    cornercase.cpp \
    dice.cpp \
    drawCard.cpp \
    estate.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    popupaddplayer.cpp \
    popupbuyestate.cpp \
    popupbuygare.cpp \
    popuppayrent.cpp \
    taxe.cpp \
    gare.cpp

HEADERS += \
    board.h \
    case.h \
    company.h \
    cornercase.h \
    dice.h \
    drawCard.h \
    enumHelper.h \
    estate.h \
    mainwindow.h \
    player.h \
    popupaddplayer.h \
    popupbuyestate.h \
    popupbuygare.h \
    popuppayrent.h \
    taxe.h \
    gare.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
