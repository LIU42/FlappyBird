#ifndef __WIDGETS_MAINLOOP_H__
#define __WIDGETS_MAINLOOP_H__

#include <QWidget>
#include <QPainter>

#include "Models/FlappyBird.h"
#include "Widgets/Resource.h"

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
        void paintBird(QPainter&);
        void paintLand(QPainter&);
        void paintPipes(QPainter&);
        void paintScore(QPainter&);

    private:
        void paintEvent(QPaintEvent*);

    public:
        SceneWidget(QWidget* parent = nullptr);

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
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
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
};
#endif