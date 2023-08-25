#include "bird.h"

BirdColor Bird::getRandomColor()
{
    return (BirdColor)(rand() % COLOR_COUNT);
}

void Bird::initialize()
{
    positionX = INIT_POSITION_X;
    positionY = INIT_POSITION_Y;
    verticalSpeed = 0;
    statusIndex = 0;
    isAlive = true;
    color = getRandomColor();
}

void Bird::flying()
{
    if (isAlive)
    {
        statusIndex += 1;
        statusIndex %= STATUS_ARRAY_LENGTH;
    }
}

void Bird::goingUp()
{
    if (isAlive)
    {
        verticalSpeed -= GOINGUP_POWER;
    }
}

void Bird::gravityDown(double gravityPower)
{
    verticalSpeed += gravityPower;
}

void Bird::moveVertical()
{
    positionY += verticalSpeed;
}

void Bird::setIsCrashed()
{
    isAlive = false;
    verticalSpeed = 0;
}

void Bird::setIsDown(int landSurfaceY)
{
    positionY = landSurfaceY;
}

BirdColor Bird::getColor()
{
    return color;
}

int Bird::getCenterX()
{
    return positionX;
}

int Bird::getCenterY()
{
    return positionY;
}

int Bird::getStatus()
{
    return STATUS_ARRAY[statusIndex];
}

double Bird::getDirectAngle()
{
    if (isAlive)
    {
        return qRadiansToDegrees(qAtan(verticalSpeed / STANDARD_SPEED));
    }
    return GOINGDOWN_ANGLE;
}

bool Bird::getIsAlive()
{
    return isAlive;
}
