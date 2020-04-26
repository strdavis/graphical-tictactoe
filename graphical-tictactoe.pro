TEMPLATE = app
TARGET = graphical-tictactoe

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += sdk_no_version_check

INCLUDEPATH += \
    $$PWD/src \
    $$PWD/include

SOURCES += \
    src/button.cpp \
    src/computer-player.cpp \
    src/custom-qlabel.cpp \
    src/custom-qmovie.cpp \
    src/custom-qwidget.cpp \
    src/diff-select-screen.cpp \
    src/game-screen.cpp \
    src/grid.cpp \
    src/main.cpp \
    src/square.cpp \
    src/tictactoe.cpp \
    src/title-screen.cpp \
    src/window.cpp

HEADERS += \
    include/button.h \
    include/computer-player.h \
    include/custom-qlabel.h \
    include/custom-qmovie.h \
    include/custom-qwidget.h \
    include/diff-select-screen.h \
    include/game-screen.h \
    include/grid.h \
    include/square.h \
    include/tictactoe.h \
    include/title-screen.h \
    include/window.h

RESOURCES += \
    resources.qrc

DISTFILES +=
