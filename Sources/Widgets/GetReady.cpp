#include "Widgets/GetReady.h"
#include "ui_GetReady.h"

GetReadyWidget::GetReadyWidget(QWidget* parent): QWidget(parent), ui(new Ui::GetReadyWidget)
{
    ui->setupUi(this);
}

GetReadyWidget::~GetReadyWidget()
{
    delete ui;
}

void GetReadyWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pScene->setGame(pGame);
}

void GetReadyWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pScene->setImages(pImages);
}

void GetReadyWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}
