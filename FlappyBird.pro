QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/Headers/

SOURCES += \
	Sources/Models/Bird.cpp \
	Sources/Models/FlappyBird.cpp \
	Sources/Models/Pipe.cpp \
	Sources/Widgets/Gameover.cpp \
	Sources/Widgets/MainLoop.cpp \
	Sources/Widgets/Prepare.cpp \
	Sources/Widgets/Resource.cpp \
	Sources/Widgets/Welcome.cpp \
	Sources/Graphics.cpp \
	Sources/Main.cpp \
	Sources/MainWindow.cpp

HEADERS += \
	Headers/Models/Bird.h \
	Headers/Models/FlappyBird.h \
	Headers/Models/Pipe.h \
	Headers/Widgets/Gameover.h \
	Headers/Widgets/MainLoop.h \
	Headers/Widgets/Prepare.h \
	Headers/Widgets/Resource.h \
	Headers/Widgets/Welcome.h \
	Headers/Graphics.h \
	Headers/MainWindow.h

FORMS += \
	Forms/Widgets/Gameover.ui \
	Forms/Widgets/MainLoop.ui \
	Forms/Widgets/Prepare.ui \
	Forms/Widgets/Welcome.ui \
	Forms/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	Resources/Resources.qrc

RC_ICONS += Resources/Images/icon.ico