#ifndef __MODELS_PIPE_H__
#define __MODELS_PIPE_H__

#include <QtMath>

class Pipe
{
    private:
        static constexpr int CHANNEL_CENTER_UPPER = 210;
        static constexpr int CHANNEL_CENTER_LOWER = 420;
        static constexpr int INIT_CHANNEL_CENTER_X = 450;

    public:
        static constexpr int WIDTH = 78;
        static constexpr int HEIGHT = 480;
        static constexpr int ADD_INTERVAL = 1200;

    public:
        static constexpr int CHANNEL_LARGE_ORIGIN_LEVEL = 300;
        static constexpr int CHANNEL_LARGE_COPPER_LEVEL = 250;
        static constexpr int CHANNEL_LARGE_SILVER_LEVEL = 200;
        static constexpr int CHANNEL_LARGE_GOLDEN_LEVEL = 150;

    private:
        int channelCenterX;
        int channelCenterY;
        int channelLarge;
        bool isThrough;

    private:
        int getRandomChannelCenterY();

    public:
        Pipe(int channelLarge);

    public:
        void moveHorizon(int speed);
        void setIsThrough();

    public:
        bool getIsThrough();
        int getLeftBorder();
        int getRightBorder();
        int getUpperBorder();
        int getLowerBorder();
};
#endif