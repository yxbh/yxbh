TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TARGET      = LibBH tests
TEMPLATE    = app

CONFIG   += c++11

#
# Configure release & debug build directories.
#
BUILDDIRWIN32DBG = build/KTracker-Win32-Debug
BUILDDIRWIN32REL = build/KTracker-Win32-Release
BUILDDIRUNIXDBG  = build/KTracker-Unix-Debug
BUILDDIRUNIXREL  = build/KTracker-Unix-Release
CONFIG(debug, debug|release) { # Debug build dirs
    win32:  DESTDIR     = $${BUILDDIRWIN32DBG}/
    win32:  OBJECTS_DIR = $${BUILDDIRWIN32DBG}/obj
    win32:  MOC_DIR     = $${BUILDDIRWIN32DBG}/moc
    win32:  RCC_DIR     = $${BUILDDIRWIN32DBG}/rsc
    win32:  UI_DIR      = $${BUILDDIRWIN32DBG}/ui
    unix:   DESTDIR     = $${BUILDDIRUNIXDBG}/obj
    unix:   OBJECTS_DIR = $${BUILDDIRUNIXDBG}/obj
    unix:   MOC_DIR     = $${BUILDDIRUNIXDBG}/moc
    unix:   RCC_DIR     = $${BUILDDIRUNIXDBG}/rsc
    unix:   UI_DIR      = $${BUILDDIRUNIXDBG}/ui
} else { # Release build dirs
    win32:  DESTDIR     = $${BUILDDIRWIN32REL}/
    win32:  OBJECTS_DIR = $${BUILDDIRWIN32REL}/obj
    win32:  MOC_DIR     = $${BUILDDIRWIN32REL}/moc
    win32:  RCC_DIR     = $${BUILDDIRWIN32REL}/rsc
    win32:  UI_DIR      = $${BUILDDIRWIN32REL}/ui
    unix:   DESTDIR     = $${BUILDDIRUNIXREL}/
    unix:   OBJECTS_DIR = $${BUILDDIRUNIXREL}/obj
    unix:   MOC_DIR     = $${BUILDDIRUNIXREL}/moc
    unix:   RCC_DIR     = $${BUILDDIRUNIXREL}/rsc
    unix:   UI_DIR      = $${BUILDDIRUNIXREL}/ui
}
#

#
# Library include paths
#
INCLUDEPATH += \
    ../../include/ \
#

#
# Boost lib dir & file
# set your Boost library path here.
#
BOOST_LIB_DIR = ../
exists( D:/LIBS/boost/boost_1_55_0_mingw32_481/boost_1_55_0/stage/lib/ ) {
    BOOST_LIB_DIR = D:/LIBS/boost/boost_1_55_0_mingw32_481/boost_1_55_0/stage/lib/
}
exists( $$PWD/../../../boost_1_55_0/stage/lib/ ) {
    BOOST_LIB_DIR = $$PWD/../../../boost_1_55_0/stage/lib/
}

win32:CONFIG(release, debug|release) {
    LIBS += -L$${BOOST_LIB_DIR} -lboost_unit_test_framework-mgw48-mt-1_55
}
else:win32:CONFIG(debug, debug|release) {
    LIBS += -L$${BOOST_LIB_DIR} -lboost_unit_test_framework-mgw48-mt-d-1_55
}
else:unix: LIBS += -L$${BOOST_LIB_DIR} -lboost_unit_test_framework-mgw48-mt-1_55

INCLUDEPATH += $$PWD/../../../boost_1_55_0/
INCLUDEPATH += D:/LIBS/boost/boost_1_55_0/
DEPENDPATH += $$PWD/../../../boost_1_55_0/stage
#


SOURCES += \
    ../main.cpp \
    ../test_macros.cpp \
    ../test_ScopeFunc.cpp

HEADERS  += \

FORMS    += \
