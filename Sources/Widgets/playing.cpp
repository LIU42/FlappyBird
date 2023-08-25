#include "playing.h"
#include "ui_playing.h"

PlayingWidget::PlayingWidget(QWidget *parent): QWidget(parent), ui(new Ui::PlayingWidget)
{
    ui->setupUi(this);
}

PlayingWidget::~PlayingWidget()
{
    delete ui;
}

void PlayingWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pAnimate->setGame(pGame);
}

void PlayingWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pAnimate->setImages(pImages);
}

void PlayingWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}
