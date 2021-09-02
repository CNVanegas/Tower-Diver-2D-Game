#include "_player.h"

_player::_player()
{
    //ctor
    dirFlag = 0;

    walkSpeed = 0.02;
    runSpeed = 0.03;
    xPos = 0.1;
    yPos = 0.2;
    life = 5;
    tex->flip = true;
    alive = true;
    attacking = false;
}

_player::~_player()
{
    //dtor
}

void _player::Init(char* filename, int x, int y)
{
    std::cout << "Player Initialization" << std::endl;
    tex->loadTexture(filename,x,y,0.7,0.7);
    //tex->makeAnimation("WalkLeft",0,10);
    //tex->makeAnimation("WalkRight",10,10);
    tex->makeAnimation("WalkLeft",45,9);
    tex->makeAnimation("WalkRight",45,9);
    tex->makeAnimation("Attack",1,9);
    tex->makeAnimation("IdleLeft", 27,6);
    tex->makeAnimation("IdleRight",27,6);
    tex->makeAnimation("Jump",38,7);

    //tex->makeAnimation("IdleLeft", 3,1);
    //tex->makeAnimation("IdleRight",12,1);
}

void _player::Actions(int input)
{
    dirFlag += input;

    if(input == 1)
    {
        tex->flip = false;
        tex->setAnimation("WalkLeft",true,true,0);
        idleAnim = "IdleLeft";
    }

    else if (input == 8)
    {
        tex->setAnimation("Jump",true,true,0);
        if(tex->flip == false)
            idleAnim = "IdleLeft";
        else
            idleAnim = "IdleRight";
    }

    else if (input == 7)
    {
        tex->setAnimation("Attack",true,true,0);
        if(tex->flip == false)
            idleAnim = "IdleLeft";
        else
            idleAnim = "IdleRight";
    }

    else if(input == 4)
    {
        tex->flip = true;
        tex->setAnimation("WalkRight",true,true,0);
        idleAnim = "IdleRight";
    }

    if(dirFlag == 0)
        tex->setAnimation(idleAnim, true, true, 0);
}

void _player::tP(int level)
{
    if(level == 2)
    {
        xPos = 0.1;
        yPos = 0.79;
    }

    else if (level == 3)
    {
        xPos = 0.1;
        yPos = 0.81;
    }

}

std::string _player::atkCollision(floatPair enmy, floatPair player)
{
    if(alive)
    {
        if(player.first > enmy.first - 0.03 && player.first < enmy.first + 0.03)
    {
        return "hitEnemy";
    }
    }

    return "";
}

