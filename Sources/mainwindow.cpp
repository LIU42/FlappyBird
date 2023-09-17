#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pGraphics->setGame(pGame);
}

void MainWindow::initialize()
{
    setGameBackground();
    connectButtons();
    connectTimers();
    setInterval();
    startTimers();
}

void MainWindow::mainInterval()
{
    if (pGame->getStatus() == STATUS_PREPARE || pGame->getStatus() == STATUS_MAINLOOP)
    {
        pGame->updateGame();

        if (pGame->isGameover())
        {
            ui->pGraphics->setPanelInfo();
            ui->pGraphics->setCurrentIndex(STATUS_GAMEOVER);
        }
        ui->pGraphics->update();
    }
}

void MainWindow::setGameBackground()
{
    ui->pGraphics->setBackground();
}

void MainWindow::connectButtons()
{
    connect(ui->pGraphics->getStartButton(), &QPushButton::clicked, this, &MainWindow::gameReadyToPlay);
    connect(ui->pGraphics->getRestartButton(), &QPushButton::clicked, this, &MainWindow::gameReadyToPlay);
}

void MainWindow::setInterval()
{
    timers.mainInterval.setInterval(1000 / GameTimers::GAME_FPS);
    timers.birdFlying.setInterval(Bird::FLY_INTERVAL);
    timers.addNewPipe.setInterval(Pipe::ADD_INTERVAL);
}

void MainWindow::connectTimers()
{
    connect(&timers.mainInterval, &QTimer::timeout, this, &MainWindow::mainInterval);
    connect(&timers.birdFlying, &QTimer::timeout, this, &MainWindow::gameBirdFlying);
    connect(&timers.addNewPipe, &QTimer::timeout, this, &MainWindow::gameAddNewPipe);
}

void MainWindow::startTimers()
{
    timers.mainInterval.start();
    timers.birdFlying.start();
    timers.addNewPipe.start();
}

void MainWindow::gameReadyToPlay()
{
    pGame->restartGame();
    ui->pGraphics->setCurrentIndex(STATUS_PREPARE);
}

void MainWindow::gameBirdFlying()
{
    pGame->birdFlying();
}

void MainWindow::gameAddNewPipe()
{
    pGame->addNewPipe();
}

void MainWindow::mousePressEvent(QMouseEvent* pMouseEvent)
{
    if (pMouseEvent->button() == Qt::LeftButton)
    {
        if (pGame->getStatus() == STATUS_PREPARE)
        {
            ui->pGraphics->setCurrentIndex(STATUS_MAINLOOP);
            pGame->playingGame();
        }
        else if (pGame->getStatus() == STATUS_MAINLOOP)
        {
            pGame->birdGoingUp();
        }
    }
}
