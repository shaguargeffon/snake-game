#-------------------------------------------------
#
# Project created by QtCreator 2022-09-13T00:40:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    widget.cpp \
    application/application.cpp \
    event_handler/event_handler.cpp \
    movement_manger/movement_manager.cpp \
    snake/snake.cpp \
    timer/timer.cpp \
    frame/frame.cpp \
    config/config.cpp


HEADERS += \
    widget.h \
    application/application.h \
    event_handler/event_handler.h \
    movement_manger/movement_manager.h \
    snake/snake.h \
    timer/timer.h \
    frame/frame.h \
    config/config.h


INCLUDEPATH += \
    application \
    event_handler \
    frame \
    layout_configuration \
    movement_manager \
    snake \
    snake_configuration



FORMS += \
        widget.ui
