
QT       += core gui
QT       += axcontainer

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    collegetripwindow.cpp \
    dbmanager.cpp \
    displaycollegewindow.cpp \
    editcollegespage.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    plantripwindow.cpp \
    receiptpage.cpp \
    userinterface.cpp \
    adminpage.cpp \
    loginpage.cpp \

HEADERS += \
    collegetripwindow.h \
    dbmanager.h \
    displaycollegewindow.h \
    editcollegespage.h \
    maintenance.h \
    mainwindow.h \
    plantripwindow.h \
    receiptpage.h \
    userinterface.h \
    adminpage.h \
    loginpage.h \

FORMS += \
    collegetripwindow.ui \
    displaycollegewindow.ui \
    editcollegespage.ui \
    maintenance.ui \
    mainwindow.ui \
    plantripwindow.ui \
    receiptpage.ui \
    userinterface.ui \
    adminpage.ui \
    loginpage.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
