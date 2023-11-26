#include "Graphics.h"

GraphicsWidget::GraphicsWidget(QWidget* parent): QStackedWidget(parent)
{
    pWelcomeWidget = new WelcomeWidget(this);
    pReadyWidget = new GetReadyWidget(this);
    pPlayingWidget = new MainLoopWidget(this);
    pGameoverWidget = new GameoverWidget(this);

    setImages();
    addWidgets();
}

GraphicsWidget::~GraphicsWidget()
{
    delete pWelcomeWidget;
    delete pReadyWidget;
    delete pPlayingWidget;
    delete pGameoverWidget;
}

void GraphicsWidget::setImages()
{
    pWelcomeWidget->setImages(&images);
    pReadyWidget->setImages(&images);
    pPlayingWidget->setImages(&images);
    pGameoverWidget->setImages(&images);
}

void GraphicsWidget::addWidgets()
{
    addWidget(pWelcomeWidget);
    addWidget(pReadyWidget);
    addWidget(pPlayingWidget);
    addWidget(pGameoverWidget);
}

void GraphicsWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    pWelcomeWidget->setGame(pGame);
    pReadyWidget->setGame(pGame);
    pPlayingWidget->setGame(pGame);
    pGameoverWidget->setGame(pGame);
}

void GraphicsWidget::setBackground()
{
    pWelcomeWidget->setBackground();
    pReadyWidget->setBackground();
    pPlayingWidget->setBackground();
    pGameoverWidget->setBackground();
}

void GraphicsWidget::setPanelInfo()
{
    pGameoverWidget->setPanelInfo();
}

QPushButton* GraphicsWidget::getStartButton()
{
    return pWelcomeWidget->getStartButton();
}

QPushButton* GraphicsWidget::getRestartButton()
{
    return pGameoverWidget->getRestartButton();
}
