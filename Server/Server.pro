TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11


SOURCES += \
        db.cpp \
        main.cpp \
        myserver.cpp \
        tcpserver.cpp \
        tcpsocket.cpp \
        thread.cpp \
        user.cpp

HEADERS += \
    db.h \
    myserver.h \
    tcpserver.h \
    tcpsocket.h \
    thread.h \
    user.h

LIBS += -L/usr/local/lib -levent -lpthread -lmysqlclient -ljsoncpp


