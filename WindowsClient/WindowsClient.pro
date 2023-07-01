QT       += core gui network core5compat  quick
QT += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


UI_DIR=./UI



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/Common.cpp \
    DataTypes/QmlModel.cpp \
    DataTypes/mainwindowstate.cpp \
    Services/TcpClient.cpp \
    Services/imagesaver.cpp \
    Services/videothread.cpp \
    Windows/historywindow.cpp \
    Windows/mainwindow.cpp \
    Windows/videowindow.cpp \
    encryption/encryption.cpp \
    main.cpp \


HEADERS += \
    Common/Common.h \
    DataTypes/QmlModel.h \
    DataTypes/mainwindowstate.h \
    Services/TcpClient.h \
    Services/imagesaver.h \
    Services/videothread.h \
    Windows/historywindow.h \
    Windows/mainwindow.h \
    Windows/videowindow.h \
    encryption/encryption.h


FORMS += \
    Windows/historywindow.ui \
    Windows/mainwindow.ui \
    Windows/videowindow.ui


TRANSLATIONS += \
    WindowsClient_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    qml.qrc

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/opencv/lib/ -lopencv_world460
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/opencv/lib/ -lopencv_world460d

INCLUDEPATH += $$PWD/opencv/include
DEPENDPATH += $$PWD/opencv/include

INCLUDEPATH += $$PWD/opencv/include/opencv2
DEPENDPATH += $$PWD/opencv/include/opencv2

LIBS += -ladvapi32 -lws2_32 -luser32 -lcrypt32


win32: LIBS += -L$$PWD/OpenSSL/lib/ -llibcrypto

INCLUDEPATH += $$PWD/OpenSSL/include
DEPENDPATH += $$PWD/OpenSSL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/OpenSSL/lib/libcrypto.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/OpenSSL/lib/liblibcrypto.a

win32: LIBS += -L$$PWD/OpenSSL/lib/ -llibssl

INCLUDEPATH += $$PWD/OpenSSL/include
DEPENDPATH += $$PWD/OpenSSL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/OpenSSL/lib/libssl.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/OpenSSL/lib/liblibssl.a

win32:RC_ICONS += Y:/qt_project/WindowsClient/Image/Aim.ico




