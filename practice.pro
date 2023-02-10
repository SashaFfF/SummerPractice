QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basic_questionnaire.cpp \
    food_questionnaire.cpp \
    goals_questionnaire.cpp \
    goalwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    physical_questionnaire.cpp \
    recommendation.cpp \
    recommendationwindow.cpp \
    sleep_questionnaire.cpp \
    stylehelper.cpp \
    testwindow.cpp \
    testwindow2.cpp \
    testwindow3.cpp \
    testwindow4.cpp \
    testwindow5.cpp \
    water_questionnaire.cpp

HEADERS += \
    basic_questionnaire.h \
    food_questionnaire.h \
    goals_questionnaire.h \
    goalwindow.h \
    mainwindow.h \
    physical_questionnaire.h \
    recommendation.h \
    recommendationwindow.h \
    sleep_questionnaire.h \
    stylehelper.h \
    testwindow.h \
    testwindow2.h \
    testwindow3.h \
    testwindow4.h \
    testwindow5.h \
    water_questionnaire.h

FORMS += \
    goalwindow.ui \
    mainwindow.ui \
    recommendationwindow.ui \
    testwindow.ui \
    testwindow2.ui \
    testwindow3.ui \
    testwindow4.ui \
    testwindow5.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
