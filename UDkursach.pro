QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/autorization.cpp \
    sources/bron.cpp \
    sources/journal_delete.cpp \
    sources/main.cpp \
    sources/mainemployee.cpp \
    sources/mainwindow.cpp \
    sources/personalaccount.cpp \
    sources/registration.cpp \
    sources/sqldb.cpp \
    sources/table.cpp \
    sources/table_bron_obor.cpp \
    sources/table_brron.cpp \
    sources/table_client.cpp \
    sources/table_dop_obor.cpp \
    sources/table_employee.cpp \
    sources/table_login.cpp \
    sources/table_sotrudnik.cpp \
    sources/table_usluga.cpp \
    sources/table_zakaz.cpp

HEADERS += \
    includes/autorization.h \
    includes/bron.h \
    includes/conf.h \
    includes/journal_delete.h \
    includes/mainemployee.h \
    includes/mainwindow.h \
    includes/personalaccount.h \
    includes/registration.h \
    includes/sqldb.h \
    includes/table.h \
    includes/table_bron_obor.h \
    includes/table_brron.h \
    includes/table_client.h \
    includes/table_dop_obor.h \
    includes/table_employee.h \
    includes/table_login.h \
    includes/table_sotrudnik.h \
    includes/table_usluga.h \
    includes/table_zakaz.h

FORMS += \
    forms/bron.ui \
    forms/journal_delete.ui \
    forms/mainemployee.ui \
    forms/mainwindow.ui \
    forms/personalaccount.ui \
    forms/registration.ui \
    forms/table.ui \
    forms/table_bron_obor.ui \
    forms/table_brron.ui \
    forms/table_client.ui \
    forms/table_dop_obor.ui \
    forms/table_employee.ui \
    forms/table_login.ui \
    forms/table_sotrudnik.ui \
    forms/table_usluga.ui \
    forms/table_zakaz.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
