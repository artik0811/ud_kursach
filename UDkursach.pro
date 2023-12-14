QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autorization.cpp \
    bron.cpp \
    journal_delete.cpp \
    main.cpp \
    mainemployee.cpp \
    mainwindow.cpp \
    personalaccount.cpp \
    registration.cpp \
    sqldb.cpp \
    table.cpp \
    table_bron_obor.cpp \
    table_brron.cpp \
    table_client.cpp \
    table_dop_obor.cpp \
    table_employee.cpp \
    table_login.cpp \
    table_sotrudnik.cpp \
    table_usluga.cpp \
    table_zakaz.cpp

HEADERS += \
    autorization.h \
    bron.h \
    conf.h \
    journal_delete.h \
    mainemployee.h \
    mainwindow.h \
    personalaccount.h \
    registration.h \
    sqldb.h \
    table.h \
    table_bron_obor.h \
    table_brron.h \
    table_client.h \
    table_dop_obor.h \
    table_employee.h \
    table_login.h \
    table_sotrudnik.h \
    table_usluga.h \
    table_zakaz.h

FORMS += \
    autorization.ui \
    bron.ui \
    journal_delete.ui \
    mainemployee.ui \
    mainwindow.ui \
    personalaccount.ui \
    registration.ui \
    table.ui \
    table_bron_obor.ui \
    table_brron.ui \
    table_client.ui \
    table_dop_obor.ui \
    table_employee.ui \
    table_login.ui \
    table_sotrudnik.ui \
    table_usluga.ui \
    table_zakaz.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
