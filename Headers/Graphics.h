#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <QStackedWidget>
#include <QPushButton>

#include "Models/FlappyBird.h"
#include "Resources/GameImages.h"
#include "Widgets/Welcome.h"
#include "Widgets/GetReady.h"
#include "Widgets/MainLoop.h"
#include "Widgets/Gameover.h"

class GraphicsWidget : public QStackedWidget
{
    Q_OBJECT

    private:
        WelcomeWidget* pWelcomeWidget;
        GetReadyWidget* pReadyWidget;
        MainLoopWidget* pPlayingWidget;
        GameoverWidget* pGameoverWidget;

    private:
        MainGame* pGame;

    private:
        GameImages images;

    private:
        void setImages();
        void addWidgets();

    public:
        GraphicsWidget(QWidget* parent = nullptr);
        ~GraphicsWidget();

    public:
        void setGame(MainGame* pGame);
        void setBackground();
        void setPanelInfo();

    public:
        QPushButton* getStartButton();
        QPushButton* getRestartButton();
};
#endif