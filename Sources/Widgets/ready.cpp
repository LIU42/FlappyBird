#include "ready.h"
#include "ui_ready.h"

ReadyWidget::ReadyWidget(QWidget* parent): QWidget(parent), ui(new Ui::ReadyWidget)
{
    ui->setupUi(this);
}

ReadyWidget::~ReadyWidget()
{
    delete ui;
}

void ReadyWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pAnimate->setGame(pGame);
}

void ReadyWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pAnimate->setImages(pImages);
}

void ReadyWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}
