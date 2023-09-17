#include "Widgets/Prepare.h"
#include "ui_Prepare.h"

PrepareWidget::PrepareWidget(QWidget* parent): QWidget(parent), ui(new Ui::PrepareWidget)
{
    ui->setupUi(this);
}

PrepareWidget::~PrepareWidget()
{
    delete ui;
}

void PrepareWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pScene->setGame(pGame);
}

void PrepareWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pScene->setImages(pImages);
}

void PrepareWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}
