#include "_physics.h"

_physics::_physics()
{
    //ctor
    physTimer->startTime();
    simSpeed = 0.5;
    isSim = false;
}

_physics::~_physics()
{
    //dtor
}

bool _physics::checkCollision(_player* player, _enemy* enemy)
{
    player->xPos = player->xPos;
    player->yPos = player->yPos;
    enemy->xPos = enemy->xPos;
    enemy->yPos = enemy->yPos;
    bool collideX = player->xPos + 0.05 >= enemy->xPos && enemy->xPos + 0.05 >= player->xPos;    //instead of harcoded pixel value can get scale of player
    bool collideY = player->yPos + 0.05 >= enemy->yPos && enemy->yPos + 0.05 >= player->xPos;
    return collideX && collideY;
}



void _physics::physicsTick(_player* player)
{
    float timeElapsed = 0;
    //if(isSim)
    timeElapsed = physTimer->getTicks() / (float) CLOCKS_PER_SEC;
    //timer->startTimer();

    player->yPos -= timeElapsed*simSpeed;
    bool isColliding = false;
//check for collisions with ground and player                                   FIXME
////////    for(int i = 0; i < vector.size(); i++)
////////    {
////////        if(checkCollision(player, vector<objects*>.at(i)))
////////            isColliding = true;
////////    }
//if colliding, then revert move
    if(isColliding)
    {
        player->yPos += timeElapsed*simSpeed;
    }
}

void _physics::physicsTick(_enemy* enemy)
{

    float timeElapsed = 0;
    if(isSim)
        timeElapsed = physTimer->getTicks() / (float) CLOCKS_PER_SEC;
/*
    timer->startTime();
    for(int i = 0; i < enemies.size(); i++)
    {
        enemies.at(i)->posE.y -= timeElapsed*simSpeed;
    }
*/
}

/*
void _physics::pausePhys()
{
    isSim = false;
}

void _physics::startPhys()
{
    isSim = true;
    physTimer->startTime();
}
*/
