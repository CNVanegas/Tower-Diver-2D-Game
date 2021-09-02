#include "_enemy.h"

_enemy::_enemy()
{
    //ctor
    dirFlag = 0;
    walkSpeed = 0.01;
    runSpeed = 0.02;
    xPos = 0.7;
    yPos = 0.2;
    alive = true;
    hp = 3;
    enemyType = 1;
    enemyCollision = false;
    deathDone = false;
}

_enemy::~_enemy()
{
    //dtor
}

void _enemy::Init(char* filename, int x, int y)
{
    if (enemyType = 1)
    {
        tex->loadTexture(filename,x,y,1.0,1.0);
        tex->makeAnimation("WalkLeft",23,3);
        tex->makeAnimation("WalkRight",23,3);
        tex->makeAnimation("IdleRight",1,10);
        tex->makeAnimation("IdleLeft",1,10);
        tex->makeAnimation("Death",11,10);
        tex->setAnimation("IdleLeft",true,true,0);
        deathDone = false;
    //tex->makeAnimation
    //tex->makeAnimation

    }

    else if (enemyType = 2)
    {
        //tex->texBind();
        tex->loadTexture(filename,x,y,1.0,1.0);
        tex->makeAnimation("WalkLeft",27,9);
        tex->makeAnimation("WalkRight",27,9);
        tex->makeAnimation("IdleRight",37,4);
        tex->makeAnimation("IdleLeft",37,4);
        tex->makeAnimation("Death",14,13);
        tex->setAnimation("IdleLeft",true,true,0);
        deathDone = false;
        std::cout << "Enemy 2" << std::endl;
    }

    else if (enemyType = 3)
    {
        //tex->texBind();
        tex->loadTexture(filename,x,y,1.0,1.0);
        tex->makeAnimation("WalkLeft",40,4);
        tex->makeAnimation("WalkRight",40,4);
        tex->makeAnimation("IdleRight",40,2);
        tex->makeAnimation("IdleLeft",40,2);
        tex->makeAnimation("Death",1,18);
        tex->setAnimation("IdleLeft",true,true,0);
        deathDone = false;
        std::cout << "Enemy 3" << std::endl;
    }

}

void _enemy::Actions(int dir)
{
    dirFlag += dir;

    if(dir == 1)
    {
        tex->setAnimation("WalkLeft",true,true,0);
        tex->flip = false;
        idleAnim = "IdleLeft";

    }

    else if(dir == 4)
    {
        tex->setAnimation("WalkRight",true,true,0);
        tex->flip = true;
        idleAnim = "IdleRight";
    }
    if(dirFlag == 0)
        tex->setAnimation(idleAnim,true,true,0);
}

std::string _enemy::collision(floatPair enemy, floatPair player)
{
    if(alive)
    {
        if(player.first < enemy.first +0.02 && player.first > enemy.first - 0.02)
    {
        enemyCollision = true;
        return "EnemyHits";
    }
    }

    return "";
}
