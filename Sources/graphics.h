#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <QStackedWidget>
#include <QPushButton>

#include "Models/flappybird.h"
#include "Widgets/resource.h"
#include "Widgets/welcome.h"
#include "Widgets/ready.h"
#include "Widgets/playing.h"
#include "Widgets/gameover.h"

class GraphicsWidget : public QStackedWidget
{
    Q_OBJECT

    private:
        WelcomeWidget* pWelcomeWidget;
        ReadyWidget* pReadyWidget;
        PlayingWidget* pPlayingWidget;
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
        void setGame(MainGame*);
        void setBackground();
        void setPanelInfo();

    public:
        QPushButton* getStartButton();
        QPushButton* getRestartButton();
};
#endif