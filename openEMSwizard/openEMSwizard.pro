#-------------------------------------------------
#
# Project created by QtCreator 2019-05-17T22:03:13
#
#-------------------------------------------------

QT       += core gui
QT += script
 QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openEMSwizard
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    WizardInit.cpp \
    PageStart.cpp \
    PageResultsSparam.cpp \
    PagePorts.cpp \
    PageGeometry.cpp \
    PageGeneralGeometrySettings.cpp \
    PageBasicSimSetup.cpp \
    VariablesEditor.cpp \
    PageMaterials.cpp

HEADERS += \
    WizardInit.h \
    PageStart.h \
    PageResultsSparam.h \
    PagePorts.h \
    PageGeometry.h \
    PageGeneralGeometrySettings.h \
    PageBasicSimSetup.h \
    VariablesEditor.h \
    PageMaterials.h
