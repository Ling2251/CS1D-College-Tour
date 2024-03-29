
QT       += core gui
QT       += axcontainer

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    displaycollegewindow.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    plantripwindow.cpp \
    souveniraddandedit.cpp \
    userinterface.cpp \
    loginpage.cpp \
    inputcollege.cpp \

HEADERS += \
    dbmanager.h \
    displaycollegewindow.h \
    maintenance.h \
    mainwindow.h \
    plantripwindow.h \
    souveniraddandedit.h \
    userinterface.h \
    loginpage.h \
    inputcollege.h \
    global.h \
    
FORMS += \
    displaycollegewindow.ui \
    maintenance.ui \
    mainwindow.ui \
    plantripwindow.ui \
    souveniraddandedit.ui \
    userinterface.ui \
    loginpage.ui \
    inputcollege.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
