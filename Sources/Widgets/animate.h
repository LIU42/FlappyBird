#ifndef __WIDGETS_ANIMATE_H__
#define __WIDGETS_ANIMATE_H__

#include <QWidget>
#include <QPainter>

#include "../Models/flappybird.h"
#include "../Widgets/resource.h"

class AnimateWidget : public QWidget
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
        AnimateWidget(QWidget* parent = nullptr);

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
};
#endif