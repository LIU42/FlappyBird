#ifndef __RESOURCES_IMAGES_H__
#define __RESOURCES_IMAGES_H__

#include <QPixmap>

class GameImages
{
    friend class GraphicsWidget;
    friend class SceneWidget;
    friend class WelcomeWidget;
    friend class GetReadyWidget;
    friend class MainLoopWidget;
    friend class GameoverWidget;
    friend class ScoreWidget;

    private:
        static constexpr int THEME_COUNT = 2;
        static constexpr int NUMBER_COUNT = 10;
        static constexpr int MEDAL_COUNT = 4;
        static constexpr int BIRD_COLOR_COUNT = 3;
        static constexpr int BIRD_STATUS_COUNT = 3;

    private:
        QPixmap birdMatrix[BIRD_COLOR_COUNT][BIRD_STATUS_COUNT];
        QPixmap land;

    private:
        QPixmap backgroundArray[THEME_COUNT];
        QPixmap pipeUpperArray[THEME_COUNT];
        QPixmap pipeLowerArray[THEME_COUNT];

    private:
        QPixmap scoreArray[NUMBER_COUNT];
        QPixmap numberArray[NUMBER_COUNT];
        QPixmap medalArray[MEDAL_COUNT];

    private:
        GameImages();
};
#endif