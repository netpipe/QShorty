TEMPLATE = app
TARGET = main
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/include/qt5/QtGui/5.9.4/QtGui
LIBS += -lX11


CONFIG += qxt
QXT = core gui
SOURCES += main.cpp \
    qxtglobalshortcut/qxtglobalshortcut_x11.cpp \
    qxtglobalshortcut/qxtglobalshortcut.cpp

HEADERS += \
    qxtglobalshortcut/qxtglobalshortcut_p.h \
    qxtglobalshortcut/qxtglobalshortcut.h \
    qxtglobalshortcut/xcbkeyboard.h

FORMS += \
    mainwindow.ui
