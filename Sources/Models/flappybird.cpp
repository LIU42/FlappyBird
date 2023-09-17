#include "Models/FlappyBird.h"

MainGame::MainGame()
{
    theme = getRandomTheme();
    status = STATUS_WELCOME;
    bestScore = 0;
}

GameStatus MainGame::getStatus()
{
    return status;
}

GameTheme MainGame::getTheme()
{
    return theme;
}

GameMedal MainGame::getMedal()
{
    if (currentScore >= GOLDEN_MEDAL_SCORE)
    {
        return MEDAL_GOLDEN;
    }
    if (currentScore >= SILVER_MEDAL_SCORE)
    {
        return MEDAL_SILVER;
    }
    if (currentScore >= COPPER_MEDAL_SCORE)
    {
        return MEDAL_COPPER;
    }
    return MEDAL_NONE;
}

GameTheme MainGame::getRandomTheme()
{
    return (GameTheme)(rand() % THEME_COUNT);
}

void MainGame::pipeRemove()
{
    if (!pipeList.isEmpty() && pipeList[0].getRightBorder() <= 0)
    {
        pipeList.removeFirst();
    }
}

void MainGame::pipesMove()
{
    for (Pipe& pipe : pipeList)
    {
        pipe.moveHorizon(Bird::FLY_HORIZON_SPEED);
    }
}

void MainGame::birdCrashOnPipes()
{
    int centerX = bird.getCenterX();
    int centerY = bird.getCenterY();

    for (Pipe& pipe : pipeList)
    {
        if (centerX <= pipe.getLeftBorder() || centerX >= pipe.getRightBorder())
        {
            continue;
        }
        if (centerY <= pipe.getUpperBorder() || centerY >= pipe.getLowerBorder())
        {
            bird.setIsCrashed();
        }
    }
}

void MainGame::birdDownOnLand()
{
    if (bird.getCenterY() >= LAND_SURFACE_Y)
    {
        bird.setIsCrashed();
        bird.setIsDown(LAND_SURFACE_Y);
    }
}

void MainGame::birdThroughChannel()
{
    for (Pipe& pipe : pipeList)
    {
        if (bird.getCenterX() >= pipe.getRightBorder() && !pipe.getIsThrough())
        {
            pipe.setIsThrough();
            currentScore += 1;
        }
    }
}

void MainGame::levelUp()
{
    switch (currentScore)
    {
        case COPPER_MEDAL_SCORE: pipeChannelLarge = Pipe::CHANNEL_LARGE_COPPER_LEVEL; break;
        case SILVER_MEDAL_SCORE: pipeChannelLarge = Pipe::CHANNEL_LARGE_SILVER_LEVEL; break;
        case GOLDEN_MEDAL_SCORE: pipeChannelLarge = Pipe::CHANNEL_LARGE_GOLDEN_LEVEL; break;
    }
}

void MainGame::landScroll()
{
    if (bird.getIsAlive())
    {
        landScrollX -= Bird::FLY_HORIZON_SPEED;
        landScrollX %= LAND_SCROLL_MOD;
    }
}

void MainGame::updateBird()
{
    bird.moveVertical();
    bird.gravityDown(GRAVITY_POWER);

    if (bird.getIsAlive())
    {
        birdCrashOnPipes();
        birdThroughChannel();
    }
    birdDownOnLand();
}

void MainGame::updatePipes()
{
    if (bird.getIsAlive())
    {
        pipesMove();
        pipeRemove();
    }
}

int MainGame::getCurrentScore()
{
    return currentScore;
}

int MainGame::getBestScore()
{
    return bestScore;
}

void MainGame::restartGame()
{
    bird.initialize();
    pipeList.clear();
    status = STATUS_PREPARE;
    pipeChannelLarge = Pipe::CHANNEL_LARGE_ORIGIN_LEVEL;
    currentScore = 0;
    landScrollX = 0;
    gameoverWaitTimes = 0;
    isNewRecord = false;
}

void MainGame::updateGame()
{
    if (status == STATUS_MAINLOOP)
    {
        levelUp();
        updateBird();
        updatePipes();
    }
    landScroll();
}

void MainGame::playingGame()
{
    status = STATUS_MAINLOOP;
}

int MainGame::getLandScrollX()
{
    return landScrollX;
}

bool MainGame::getIsNewRecord()
{
    return isNewRecord;
}

void MainGame::addNewPipe()
{
    if (status == STATUS_MAINLOOP && bird.getIsAlive())
    {
        pipeList.append(Pipe(pipeChannelLarge));
    }
}

void MainGame::birdFlying()
{
    if (status == STATUS_PREPARE || status == STATUS_MAINLOOP)
    {
        bird.flying();
    }
}

void MainGame::birdGoingUp()
{
    if (status == STATUS_MAINLOOP && bird.getIsAlive())
    {
        bird.goingUp();
    }
}

bool MainGame::isGameover()
{
    if (bird.getCenterY() < LAND_SURFACE_Y)
    {
        return false;
    }
    if (gameoverWaitTimes >= GAMEOVER_WAIT_TIMES)
    {
        status = STATUS_GAMEOVER;

        if (currentScore > bestScore)
        {
            bestScore = currentScore;
            isNewRecord = true;
        }
        return true;
    }
    gameoverWaitTimes += 1;
    return false;
}

Bird& MainGame::getBird()
{
    return bird;
}

PipeList& MainGame::getPipeList()
{
    return pipeList;
}
