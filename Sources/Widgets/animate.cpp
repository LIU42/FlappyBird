#include "animate.h"

AnimateWidget::AnimateWidget(QWidget* parent): QWidget{parent}
{
    pGame = nullptr;
    pImages = nullptr;
}

void AnimateWidget::setGame(MainGame* pGame)
{
    this->pGame = pGame;
}

void AnimateWidget::setImages(GameImages* pImages)
{
    this->pImages = pImages;
}

void AnimateWidget::paintBird(QPainter& painter)
{
    BirdColor color = pGame->getBird().getColor();
    int centerX = pGame->getBird().getCenterX();
    int centerY = pGame->getBird().getCenterY();
    int status = pGame->getBird().getStatus();
    double angle = pGame->getBird().getDirectAngle();

    painter.translate(centerX, centerY);
    painter.rotate(angle);
    painter.drawPixmap(-Bird::HALF_SIZE, -Bird::HALF_SIZE, pImages->birdMatrix[color][status]);
    painter.resetTransform();
}

void AnimateWidget::paintLand(QPainter& painter)
{
    int landX1 = pGame->getLandScrollX();
    int landX2 = pGame->getLandScrollX() + SCREEN_WIDTH;

    painter.drawPixmap(landX1, LAND_SURFACE_Y, pImages->land);
    painter.drawPixmap(landX2, LAND_SURFACE_Y, pImages->land);
}

void AnimateWidget::paintPipes(QPainter& painter)
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

void AnimateWidget::paintScore(QPainter& painter)
{
    if (pGame->getStatus() == STATUS_PLAYING)
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

void AnimateWidget::paintEvent(QPaintEvent* pPaintEvent)
{
    Q_UNUSED(pPaintEvent);
    QPainter painter(this);

    painter.setRenderHints(QPainter::SmoothPixmapTransform);
    paintPipes(painter);
    paintLand(painter);
    paintBird(painter);
    paintScore(painter);
}
