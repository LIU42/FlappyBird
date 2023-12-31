#ifndef __WIDGETS_MAINLOOP_H__
#define __WIDGETS_MAINLOOP_H__

#include <QWidget>
#include <QPainter>

#include "Models/FlappyBird.h"
#include "Resources/GameImages.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainLoopWidget;
}

QT_END_NAMESPACE

class SceneWidget : public QWidget
{
    Q_OBJECT

    private:
        static constexpr int SCREEN_WIDTH = 450;
        static constexpr int SCREEN_HEIGHT = 700;
        static constexpr int SCORE_WIDTH = 24;

    private:
        static constexpr int LAND_SURFACE_Y = 630;
        static constexpr int SCORE_REGION_Y = 140;

    private:
        MainGame* pGame;
        GameImages* pImages;

    private:
        void paintBird(QPainter& painter);
        void paintLand(QPainter& painter);
        void paintPipes(QPainter& painter);
        void paintScore(QPainter& painter);

    private:
        void paintEvent(QPaintEvent* pPaintEvent);

    public:
        SceneWidget(QWidget* parent = nullptr);

    public:
        void setGame(MainGame* pGame);
        void setImages(GameImages* pImages);
};

class MainLoopWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::MainLoopWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        MainLoopWidget(QWidget* parent = nullptr);
        ~MainLoopWidget();

    public:
        void setGame(MainGame* pGame);
        void setImages(GameImages* pImages);
        void setBackground();
};
#endif