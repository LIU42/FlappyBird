#include "Widgets/Gameover.h"
#include "ui_Gameover.h"

ScoreWidget::ScoreWidget(QWidget* parent): QWidget(parent)
{
    scoreInitX = 0;
    scoreValue = 0;
}

void ScoreWidget::paintEvent(QPaintEvent* pPaintEvent)
{
    Q_UNUSED(pPaintEvent);
    QPainter painter(this);

    painter.setRenderHints(QPainter::SmoothPixmapTransform);

    if (scoreValue == 0)
    {
        painter.drawPixmap(scoreInitX, 0, pImages->numberArray[scoreValue]);
    }
    while (scoreValue > 0)
    {
        painter.drawPixmap(scoreInitX, 0, pImages->numberArray[scoreValue % 10]);

        scoreValue /= 10;
        scoreInitX -= SCORE_NUMBER_WIDTH;
    }
}

void ScoreWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
}

void ScoreWidget::setScoreValue(int scoreValue)
{
    this->scoreValue = scoreValue;
    this->scoreInitX = geometry().width() - SCORE_NUMBER_WIDTH - SCORE_NUMBER_BORDER;
}

GameoverWidget::GameoverWidget(QWidget* parent): QWidget(parent), ui(new Ui::GameoverWidget)
{
    ui->setupUi(this);
}

GameoverWidget::~GameoverWidget()
{
    delete ui;
}

void GameoverWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
}

void GameoverWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pCurrentScoreWidget->setImages(pImages);
    ui->pBestScoreWidget->setImages(pImages);
}

void GameoverWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}

void GameoverWidget::setScoreInfo()
{
    ui->pCurrentScoreWidget->setScoreValue(pGame->getCurrentScore());
    ui->pBestScoreWidget->setScoreValue(pGame->getBestScore());
}

void GameoverWidget::setMedalInfo()
{
    ui->pMedalLabel->setPixmap(pImages->medalArray[pGame->getMedal()]);
}

void GameoverWidget::setIsNewRecord()
{
    ui->pNewRecordLabel->hide();

    if (pGame->getIsNewRecord())
    {
        ui->pNewRecordLabel->show();
    }
}

void GameoverWidget::setPanelInfo()
{
    setScoreInfo();
    setMedalInfo();
    setIsNewRecord();
}

QPushButton* GameoverWidget::getRestartButton()
{
    return ui->pRestartButton;
}