#ifndef __WIDGETS_GAMEOVER_H__
#define __WIDGETS_GAMEOVER_H__

#include <QWidget>
#include <QPainter>
#include <QPushButton>

#include "Models/FlappyBird.h"
#include "Resources/GameImages.h"

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
        void paintEvent(QPaintEvent* pPaintEvent);

    public:
        ScoreWidget(QWidget* parent = nullptr);

    public:
        void setImages(GameImages* pImages);
        void setScoreValue(int scoreValue);
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
        void setGame(MainGame* pGame);
        void setImages(GameImages* pImages);
        void setBackground();
        void setPanelInfo();

    public:
        QPushButton* getRestartButton();
};
#endif