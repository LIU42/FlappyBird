#ifndef __MODELS_FLAPPYBIRD_H__
#define __MODELS_FLAPPYBIRD_H__

#include <QList>

#include "Models/Bird.h"
#include "Models/Pipe.h"

using PipeList = QList<Pipe>;

enum GameTheme
{
    THEME_DAY,
    THEME_NIGHT
};

enum GameStatus
{
    STATUS_WELCOME,
    STATUS_PREPARE,
    STATUS_MAINLOOP,
    STATUS_GAMEOVER
};

enum GameMedal
{
    MEDAL_NONE,
    MEDAL_COPPER,
    MEDAL_SILVER,
    MEDAL_GOLDEN
};

class MainGame
{
    private:
        static constexpr int LAND_SURFACE_Y = 630;
        static constexpr int LAND_SCROLL_MOD = 450;
        static constexpr int THEME_COUNT = 2;
        static constexpr int GAMEOVER_WAIT_TIMES = 60;

    private:
        static constexpr int COPPER_MEDAL_SCORE = 20;
        static constexpr int SILVER_MEDAL_SCORE = 50;
        static constexpr int GOLDEN_MEDAL_SCORE = 100;

    private:
        static constexpr double GRAVITY_POWER = 0.4;

    private:
        Bird bird;
        PipeList pipeList;
        GameTheme theme;
        GameStatus status;

    private:
        int currentScore;
        int bestScore;
        int pipeChannelLarge;
        int landScrollX;
        int gameoverWaitTimes;
        bool isNewRecord;

    private:
        GameTheme getRandomTheme();

    private:
        void pipeRemove();
        void pipesMove();
        void birdCrashOnPipes();
        void birdDownOnLand();
        void birdThroughChannel();

    private:
        void levelUp();
        void landScroll();
        void updateBird();
        void updatePipes();

    public:
        MainGame();

    public:
        void restartGame();
        void updateGame();
        void playingGame();
        void addNewPipe();
        void birdFlying();
        void birdGoingUp();
        bool isGameover();

    public:
        GameStatus getStatus();
        GameTheme getTheme();
        GameMedal getMedal();

    public:
        Bird& getBird();
        PipeList& getPipeList();

    public:
        int getCurrentScore();
        int getBestScore();
        int getLandScrollX();
        bool getIsNewRecord();
};
#endif