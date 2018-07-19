#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T10:37:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SEGYReader
TEMPLATE = app


SOURCES += main.cpp\
    segyfileRevised.cpp \
    traceRevised.cpp \
    mainwindow.cpp \
    segyfileform.cpp \
    mergewizard.cpp \
    mergeintropage.cpp \
    segyfilelittleendian.cpp \
    tracelittleendian.cpp \
    isledialog.cpp \
    segyfilebigendian.cpp \
    tracebigendian.cpp \
    mergefileselection.cpp \
    mergecompareproperties.cpp \
    mergetextualheader.cpp \
    mergetracesort.cpp \
    mergepageresult.cpp \
    merger.cpp

HEADERS  += \
    segyfileRevised.h \
    traceRevised.h \
    mainwindow.h \
    segyfileform.h \
    mergewizard.h \
    mergeintropage.h \
    segyfilelittleendian.h \
    tracelittleendian.h \
    isledialog.h \
    segyfilebigendian.h \
    tracebigendian.h \
    mergefileselection.h \
    mergecompareproperties.h \
    mergetextualheader.h \
    mergetracesort.h \
    mergepageresult.h \
    exceptions.h \
    merger.h

FORMS += \
    mainwindow.ui \
    segyfileform.ui \
    mergewizard.ui \
    mergeintropage.ui \
    isledialog.ui \
    mergefileselection.ui \
    mergecompareproperties.ui \
    mergetextualheader.ui \
    mergetracesort.ui \
    mergepageresult.ui
