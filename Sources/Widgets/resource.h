#ifndef __WIDGETS_RESOURCE_H__
#define __WIDGETS_RESOURCE_H__

#include <QPixmap>

class GameImages
{
    friend class GraphicsWidget;
    friend class AnimateWidget;
    friend class WelcomeWidget;
    friend class ReadyWidget;
    friend class PlayingWidget;
    friend class GameoverWidget;
    friend class ScoreNumberWidget;

    private:
        static constexpr int THEME_COUNT = 2;
        static constexpr int NUMBER_COUNT = 10;
        static constexpr int MEDAL_COUNT = 4;
        static constexpr int BIRD_COLOR_COUNT = 3;
        static constexpr int BIRD_STATUS_COUNT = 3;

    private:
        QPixmap birdMatrix[BIRD_COLOR_COUNT][BIRD_STATUS_COUNT];

    private:
        QPixmap backgroundArray[THEME_COUNT];
        QPixmap pipeUpperArray[THEME_COUNT];
        QPixmap pipeLowerArray[THEME_COUNT];

    private:
        QPixmap land;

    private:
        QPixmap scoreArray[NUMBER_COUNT];
        QPixmap numberArray[NUMBER_COUNT];

    private:
        QPixmap medalArray[MEDAL_COUNT];

    private:
        GameImages();
};
#endif