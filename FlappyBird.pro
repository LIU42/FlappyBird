QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	Sources/Models/bird.cpp \
	Sources/Models/flappybird.cpp \
	Sources/Models/pipe.cpp \
	Sources/Widgets/animate.cpp \
	Sources/Widgets/gameover.cpp \
	Sources/Widgets/playing.cpp \
	Sources/Widgets/ready.cpp \
	Sources/Widgets/resource.cpp \
	Sources/Widgets/welcome.cpp \
	Sources/graphics.cpp \
	Sources/main.cpp \
	Sources/mainwindow.cpp

HEADERS += \
	Sources/Models/bird.h \
	Sources/Models/flappybird.h \
	Sources/Models/pipe.h \
	Sources/Widgets/animate.h \
	Sources/Widgets/gameover.h \
	Sources/Widgets/playing.h \
	Sources/Widgets/ready.h \
	Sources/Widgets/resource.h \
	Sources/Widgets/welcome.h \
	Sources/graphics.h \
	Sources/mainwindow.h

FORMS += \
	Forms/Widgets/welcome.ui \
	Forms/mainwindow.ui \
	Forms/Widgets/ready.ui \
	Forms/Widgets/playing.ui \
	Forms/Widgets/gameover.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	Resources/resources.qrc

RC_ICONS += Resources/Images/icon.ico