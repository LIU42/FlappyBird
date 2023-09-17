#ifndef __MODELS_BIRD_H__
#define __MODELS_BIRD_H__

#include <QtMath>

enum BirdColor
{
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_RED
};

class Bird
{
    private:
        static constexpr int INIT_POSITION_X = 70;
        static constexpr int INIT_POSITION_Y = 310;
        static constexpr int GOINGUP_POWER = 17;
        static constexpr int GOINGDOWN_ANGLE = 90;
        static constexpr int COLOR_COUNT = 3;
        static constexpr int STANDARD_SPEED = 15;

    private:
        static constexpr int STATUS_ARRAY[] = { 0, 1, 2, 1 };
        static constexpr int STATUS_ARRAY_LENGTH = 4;

    public:
        static constexpr int FLY_HORIZON_SPEED = 3;
        static constexpr int FLY_INTERVAL = 150;
        static constexpr int HALF_SIZE = 20;

    private:
        BirdColor color;
        int positionX;
        int positionY;
        int statusIndex;
        double verticalSpeed;
        bool isAlive;

    private:
        BirdColor getRandomColor();

    public:
        void initialize();
        void flying();
        void goingUp();
        void gravityDown(double);
        void moveVertical();
        void setIsCrashed();
        void setIsDown(int);

    public:
        BirdColor getColor();
        int getCenterX();
        int getCenterY();
        int getStatus();
        double getDirectAngle();
        bool getIsAlive();
};
#endif