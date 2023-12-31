#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QApplication>
#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>

#include "Models/FlappyBird.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MainWindow;
}

QT_END_NAMESPACE

class GameTimers
{
    public:
        static constexpr int GAME_FPS = 60;

    public:
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
        void mousePressEvent(QMouseEvent* pMouseEvent);

    public:
        MainWindow(QWidget* parent = nullptr);
        ~MainWindow();

    public:
        void setGame(MainGame* pGame);
        void initialize();
};
#endif