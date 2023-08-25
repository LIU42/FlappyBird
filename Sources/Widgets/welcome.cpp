#include "welcome.h"
#include "ui_welcome.h"

WelcomeWidget::WelcomeWidget(QWidget *parent): QWidget(parent), ui(new Ui::WelcomeWidget)
{
    ui->setupUi(this);
}

WelcomeWidget::~WelcomeWidget()
{
    delete ui;
}

void WelcomeWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
}

void WelcomeWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
}

void WelcomeWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}

QPushButton* WelcomeWidget::getStartButton()
{
    return ui->pStartButton;
}