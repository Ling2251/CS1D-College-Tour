
QT       += core gui
QT       += axcontainer

QT       += core gui sql
 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpage.cpp \
    loginpage.cpp \
    dbmanager.cpp \
    displaycollegewindow.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    plantripwindow.cpp \
    userinterface.cpp

HEADERS += \

    adminpage.h \
    loginpage.h \
    mainwindow.h

FORMS += \
    adminpage.ui \
    loginpage.ui \
    mainwindow.ui
    dbmanager.h \
    displaycollegewindow.h \
    maintenance.h \
    mainwindow.h \
    plantripwindow.h \
    userinterface.h

FORMS += \
    displaycollegewindow.ui \
    maintenance.ui \
    mainwindow.ui \
    plantripwindow.ui \
    userinterface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
