#ifndef __RESOURCES_GAMEIMAGES_H__
#define __RESOURCES_GAMEIMAGES_H__

#include <QPixmap>

class GameImages
{
    public:
        static constexpr int THEME_COUNT = 2;
        static constexpr int NUMBER_COUNT = 10;
        static constexpr int MEDAL_COUNT = 4;
        static constexpr int BIRD_COLOR_COUNT = 3;
        static constexpr int BIRD_STATUS_COUNT = 3;

    public:
        QPixmap birdMatrix[BIRD_COLOR_COUNT][BIRD_STATUS_COUNT];
        QPixmap land;

    public:
        QPixmap backgroundArray[THEME_COUNT];
        QPixmap pipeUpperArray[THEME_COUNT];
        QPixmap pipeLowerArray[THEME_COUNT];

    public:
        QPixmap scoreArray[NUMBER_COUNT];
        QPixmap numberArray[NUMBER_COUNT];
        QPixmap medalArray[MEDAL_COUNT];

    public:
        GameImages();
};
#endif