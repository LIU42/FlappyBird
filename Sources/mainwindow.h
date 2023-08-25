#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QApplication>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>

#include "Models/flappybird.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class GameTimers
{
    friend class MainWindow;

    private:
        static constexpr int GAME_FPS = 60;

    private:
        QTimer mainInterval;
        QTimer birdFlying;
        QTimer addNewPipe;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow* ui;
        MainGame* pGame;

    private:
        GameTimers timers;

    private:
        void mainInterval();
        void setGameBackground();
        void connectButtons();
        void connectTimers();
        void setInterval();
        void startTimers();

    private:
        void gameReadyToPlay();
        void gameBirdFlying();
        void gameAddNewPipe();
        void gameBirdGoingUp();

    private:
        void mousePressEvent(QMouseEvent*);

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    public:
        void setGame(MainGame*);
        void initialize();
};
#endif