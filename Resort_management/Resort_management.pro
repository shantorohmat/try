QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chittagongdialog.cpp \
    ctgadminsavedialog.cpp \
    ctgadminshowdialog.cpp \
    customerbookctgdialog.cpp \
    customerbooksaintdialog.cpp \
    customerbooksajeckdialog.cpp \
    customercaredialog.cpp \
    fivedialog.cpp \
    fourthdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    resortbookctgdialog.cpp \
    resortbooksaintdialog.cpp \
    resortbooksajeckdialog.cpp \
    saintadminsavedialog.cpp \
    saintadminshowdialog.cpp \
    saintmartindialog.cpp \
    sajadminsavedialog.cpp \
    sajeckdialog.cpp \
    sajsdminshowdialog.cpp \
    secdialog.cpp \
    sevendialog.cpp \
    sixdialog.cpp \
    thirddialog.cpp

HEADERS += \
    chittagongdialog.h \
    ctgadminsavedialog.h \
    ctgadminshowdialog.h \
    customerbookctgdialog.h \
    customerbooksaintdialog.h \
    customerbooksajeckdialog.h \
    customercaredialog.h \
    fivedialog.h \
    fourthdialog.h \
    mainwindow.h \
    resortbookctgdialog.h \
    resortbooksaintdialog.h \
    resortbooksajeckdialog.h \
    saintadminsavedialog.h \
    saintadminshowdialog.h \
    saintmartindialog.h \
    sajadminsavedialog.h \
    sajeckdialog.h \
    sajsdminshowdialog.h \
    secdialog.h \
    sevendialog.h \
    sixdialog.h \
    thirddialog.h

FORMS += \
    chittagongdialog.ui \
    ctgadminsavedialog.ui \
    ctgadminshowdialog.ui \
    customerbookctgdialog.ui \
    customerbooksaintdialog.ui \
    customerbooksajeckdialog.ui \
    customercaredialog.ui \
    fivedialog.ui \
    fourthdialog.ui \
    mainwindow.ui \
    resortbookctgdialog.ui \
    resortbooksaintdialog.ui \
    resortbooksajeckdialog.ui \
    saintadminsavedialog.ui \
    saintadminshowdialog.ui \
    saintmartindialog.ui \
    sajadminsavedialog.ui \
    sajeckdialog.ui \
    sajsdminshowdialog.ui \
    secdialog.ui \
    sevendialog.ui \
    sixdialog.ui \
    thirddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
