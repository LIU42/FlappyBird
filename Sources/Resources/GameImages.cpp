#include "Resources/GameImages.h"

GameImages::GameImages()
{
    for (int i = 0; i < BIRD_COLOR_COUNT; i++)
    {
        for (int j = 0; j < BIRD_STATUS_COUNT; j++)
        {
            birdMatrix[i][j].load(QString(":/Images/bird%1_%2.png").arg(i).arg(j));
        }
    }
    for (int i = 0; i < THEME_COUNT; i++)
    {
        backgroundArray[i].load(QString(":/Images/background%1.png").arg(i));
        pipeUpperArray[i].load(QString(":/Images/pipe%1_upper.png").arg(i));
        pipeLowerArray[i].load(QString(":/Images/pipe%1_lower.png").arg(i));
    }
    for (int i = 0; i < NUMBER_COUNT; i++)
    {
        scoreArray[i].load(QString(":/Images/score_%1.png").arg(i));
        numberArray[i].load(QString(":/Images/number_%1.png").arg(i));
    }
    for (int i = 0; i < MEDAL_COUNT; i++)
    {
        medalArray[i].load(QString(":/Images/medals_%1.png").arg(i));
    }
    land.load(":/Images/land.png");
}
