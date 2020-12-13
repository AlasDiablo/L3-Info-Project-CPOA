QT += gui
QT += widgets
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        admin.cpp \
        controller.cpp \
        controllerpc.cpp \
        datadb.cpp \
        main.cpp \
        mainwindow.cpp \
        order.cpp \
        pc.cpp \
        product.cpp \
        productor.cpp \
        user.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    admin.h \
    controller.h \
    controllerpc.h \
    datadb.h \
    mainwindow.h \
    order.h \
    pc.h \
    product.h \
    productor.h \
    user.h

DISTFILES += \
    class.qmodel
