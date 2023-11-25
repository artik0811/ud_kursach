QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autorization.cpp \
    bron.cpp \
    main.cpp \
    mainwindow.cpp \
    personalaccount.cpp \
    registration.cpp \
    sqldb.cpp \
    table.cpp

HEADERS += \
    autorization.h \
    bron.h \
    conf.h \
    mainwindow.h \
    personalaccount.h \
    registration.h \
    sqldb.h \
    table.h

FORMS += \
    autorization.ui \
    bron.ui \
    mainwindow.ui \
    personalaccount.ui \
    registration.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
