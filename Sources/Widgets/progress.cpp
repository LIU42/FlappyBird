#include "progress.h"
#include "ui_progress.h"

SceneWidget::SceneWidget(QWidget* parent): QWidget{parent}
{
    pGame = nullptr;
    pImages = nullptr;
}

void SceneWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
}

void SceneWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
}

void SceneWidget::paintBird(QPainter& painter)
{
    Bird& bird = pGame->getBird();

    painter.translate(bird.getCenterX(), bird.getCenterY());
    painter.rotate(bird.getDirectAngle());
    painter.drawPixmap(-Bird::HALF_SIZE, -Bird::HALF_SIZE, pImages->birdMatrix[bird.getColor()][bird.getStatus()]);
    painter.resetTransform();
}

void SceneWidget::paintLand(QPainter& painter)
{
    int landX1 = pGame->getLandScrollX();
    int landX2 = pGame->getLandScrollX() + SCREEN_WIDTH;

    painter.drawPixmap(landX1, LAND_SURFACE_Y, pImages->land);
    painter.drawPixmap(landX2, LAND_SURFACE_Y, pImages->land);
}

void SceneWidget::paintPipes(QPainter& painter)
{
    GameTheme theme = pGame->getTheme();

    for (Pipe& pipe : pGame->getPipeList())
    {
        int upperY = pipe.getUpperBorder() - Pipe::HEIGHT;
        int lowerY = pipe.getLowerBorder();

        painter.drawPixmap(pipe.getLeftBorder(), upperY, pImages->pipeUpperArray[theme]);
        painter.drawPixmap(pipe.getLeftBorder(), lowerY, pImages->pipeLowerArray[theme]);
    }
}

void SceneWidget::paintScore(QPainter& painter)
{
    if (pGame->getStatus() == STATUS_PROGRESS)
    {
        int scoreValue = pGame->getCurrentScore();
        int scoreLength = 0;

        if (scoreValue == 0)
        {
            scoreLength = 1;
        }
        while (scoreValue > 0)
        {
            scoreLength += 1;
            scoreValue /= 10;
        }
        scoreValue = pGame->getCurrentScore();

        for (int i = 1; i <= scoreLength; i++)
        {
            int numberX = SCREEN_WIDTH / 2 + SCORE_WIDTH * ((double)scoreLength / 2 - i);
            int numberIndex = scoreValue % 10;

            painter.drawPixmap(numberX, SCORE_REGION_Y, pImages->scoreArray[numberIndex]);
            scoreValue /= 10;
        }
    }
}

void SceneWidget::paintEvent(QPaintEvent* pPaintEvent)
{
    Q_UNUSED(pPaintEvent);
    QPainter painter(this);

    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    paintPipes(painter);
    paintLand(painter);
    paintBird(painter);
    paintScore(painter);
}


ProgressWidget::ProgressWidget(QWidget *parent): QWidget(parent), ui(new Ui::ProgressWidget)
{
    ui->setupUi(this);
}

ProgressWidget::~ProgressWidget()
{
    delete ui;
}

void ProgressWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
    ui->pScene->setGame(pGame);
}

void ProgressWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
    ui->pScene->setImages(pImages);
}

void ProgressWidget::setBackground()
{
    ui->pBackgroundLabel->setPixmap(pImages->backgroundArray[pGame->getTheme()]);
}
