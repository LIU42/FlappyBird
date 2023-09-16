#ifndef __WIDGETS_PROGRESS_H__
#define __WIDGETS_PROGRESS_H__

#include <QWidget>
#include <QPainter>

#include "../Models/flappybird.h"
#include "../Widgets/resource.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class ProgressWidget;
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

class ProgressWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::ProgressWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    public:
        ProgressWidget(QWidget* parent = nullptr);
        ~ProgressWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
};
#endif