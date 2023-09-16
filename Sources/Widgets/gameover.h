#ifndef __WIDGETS_GAMEOVER_H__
#define __WIDGETS_GAMEOVER_H__

#include <QWidget>
#include <QPainter>
#include <QPushButton>

#include "../Models/flappybird.h"
#include "../Widgets/resource.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class GameoverWidget;
}

QT_END_NAMESPACE

class ScoreWidget : public QWidget
{
    Q_OBJECT

    private:
        static constexpr int SCORE_NUMBER_WIDTH = 13;
        static constexpr int SCORE_NUMBER_BORDER = 3;

    private:
        GameImages* pImages;

    private:
        int scoreInitX;
        int scoreValue;

    private:
        void paintEvent(QPaintEvent*);

    public:
        ScoreWidget(QWidget* parent = nullptr);

    public:
        void setImages(GameImages*);
        void setScoreValue(int);
};

class GameoverWidget : public QWidget
{
    Q_OBJECT

    private:
        Ui::GameoverWidget* ui;

    private:
        MainGame* pGame;
        GameImages* pImages;

    private:
        void setScoreInfo();
        void setMedalInfo();
        void setIsNewRecord();

    public:
        GameoverWidget(QWidget* parent = nullptr);
        ~GameoverWidget();

    public:
        void setGame(MainGame*);
        void setImages(GameImages*);
        void setBackground();
        void setPanelInfo();

    public:
        QPushButton* getRestartButton();
};
#endif