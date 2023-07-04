TEMPLATE = app


UI_DIR  = obj/Gui
MOC_DIR = obj/Moc
OBJECTS_DIR = obj/Obj

TARGET = ../lib/HikCameraTest
QT +=	core \
        gui \
        opengl \
        widgets


unix {
LIBS += -L../lib/ -Wl,-rpath=./:./HCNetSDKCom:../lib -lhcnetsdk -lPlayCtrl -lAudioRender -lSuperRender
}

HEADERS += ../../mainwindow.h \
    ../../hikcamera.h
     
SOURCES += ../../mainwindow.cpp \
    ../../main.cpp \
    ../../hikcamera.cpp
	  
FORMS += ../../mainwindow.ui


INCLUDEPATH += ../../includeCn


