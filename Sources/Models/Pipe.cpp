#include "Models/Pipe.h"

Pipe::Pipe(int channelLarge)
{
    this->channelCenterX = INIT_CHANNEL_CENTER_X;
    this->channelCenterY = getRandomChannelCenterY();
    this->channelLarge = channelLarge;
    this->isThrough = false;
}

int Pipe::getRandomChannelCenterY()
{
    return rand() % (CHANNEL_CENTER_LOWER - CHANNEL_CENTER_UPPER) + CHANNEL_CENTER_UPPER;
}

void Pipe::moveHorizon(int speed)
{
    channelCenterX -= speed;
}

void Pipe::setIsThrough()
{
    isThrough = true;
}

bool Pipe::getIsThrough()
{
    return isThrough;
}

int Pipe::getLeftBorder()
{
    return channelCenterX;
}

int Pipe::getRightBorder()
{
    return channelCenterX + WIDTH;
}

int Pipe::getUpperBorder()
{
    return channelCenterY - channelLarge / 2;
}

int Pipe::getLowerBorder()
{
    return channelCenterY + channelLarge / 2;
}
