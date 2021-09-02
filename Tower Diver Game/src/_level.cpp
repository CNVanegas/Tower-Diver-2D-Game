#include "_level.h"

_level::_level(std::stack<_scene*>* s)
{
    //ctor
    sceneList = s;
    h = new _helpScreen(sceneList);
    ply = new _player();
    snd = new _sound();
    enmy = new _enemy();
    popup = new _popUp();
    winPopup = new _popUp();
    //winPopup2 = new _popUp();
    deathPopup = new _popUp();
    kBMs = new _inputs(timer);
    kBMs->initPly(ply);
    kBMs->initBtns(popup->btns);
    kBMs->initSnd(snd);
    kBMs->initEnmy(enmy);
    room = new _room();
    hearts = new _texture();

    footstepSpace = 0;
    levelnum = 1;
    levelEnd = false;
    deathFrames = 10;
    frameCount = 0;
}

_level::~_level()
{
    //dtor
}

void _level::Init(int screenWidth, int screenHeight)
{
    h->Init(screenWidth,screenHeight);
    ply->Init("images/knightspritesheet_scaled.png",9,7);
    hearts->loadTexture("images/heart.png",1, 1);
    enmy->Init("images/enemy1.png",10,3);
    ply->PositionObject(std::make_pair(0.07,0.789)); //sets player position
    enmy->PositionObject(std::make_pair(0.85,0.82));
    popup->Init(screenWidth,screenHeight,1);
    deathPopup->Init(screenWidth,screenHeight,2);
    winPopup->Init(screenWidth,screenHeight,3);
    //winPopup2->Init(screenWidth,screenHeight,4);
    room->makeRoom(levelnum);
    snd->initSounds();

    snd->playMusic("sounds/in_game_orchestra-loop.wav");
    levelnum = 1;
    //room->makeRoom("level1.txt");
    timer->Start();
}

void _level::Draw()
{
    if (!timer->isPaused() && levelnum < 4)
    {
        checkChanges();
        if(levelEnd)
        {

            levelnum++;
            enmy->enemyType++;
            levelEnd = false;
            room->makeRoom(levelnum);
            if (levelnum == 2)
            {
               // enmy->tex->flip = true;
                //enmy->Init("images/enemy2_scale.png",13,5);
                enmy->yPos = 0.87;
                enmy->xPos = 0.90;
                enmy->tex->loadTexture("images/enemy2_scale.png",13,5,1.0,1.0);
                enmy->tex->makeAnimation("WalkLeft",27,12);
                enmy->tex->makeAnimation("WalkRight",27,12);
                enmy->tex->makeAnimation("IdleRight",34,4);
                enmy->tex->makeAnimation("IdleLeft",34,4);
                enmy->tex->makeAnimation("Death",14,13);
                enmy->tex->setAnimation("IdleLeft",true,true,0);
                enmy->tex->flip = true;
                enmy->alive = true;
                enmy->deathDone = false;
                enmy->hp = 4;
                deathFrames = 13;
            }

            else if (levelnum == 3)
            {
                //enmy->tex->flip = true;
                //enmy->Init("images/enemy3_scale.png",10,5);
                enmy->yPos = 0.88;
                enmy->xPos = 0.90;
                enmy->tex->loadTexture("images/enemy3_scale.png",10,5,1.0,1.0);
                enmy->tex->makeAnimation("WalkLeft",40,4);
                enmy->tex->makeAnimation("WalkRight",40,4);
                enmy->tex->makeAnimation("IdleRight",40,3);
                enmy->tex->makeAnimation("IdleLeft",40,3);
                enmy->tex->makeAnimation("Death",1,18);
                enmy->tex->setAnimation("IdleLeft",true,true,0);
                enmy->tex->flip = true;
                enmy->alive = true;
                enmy->deathDone = false;
                enmy->hp = 5;
                deathFrames = 18;
            }

            ply->tP(levelnum);
        }
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    if(levelnum < 4 && ply->alive)
    {
            glPushMatrix();
         room->drawRoom(levelnum);
         if(!enmy->deathDone)
            enmy->DrawObject();
         if (ply->life > 0)
         {
             hearts->texBind();
             float spacing = 0.01;
             for(int i = 0; i < ply->life; i++)
             {
                 hearts->Draw(spacing,0.05,0.2,0.2);
                 spacing+=0.026;
             }
         }
         ply->DrawObject();
         kBMs->animTime--;
        glPopMatrix();
    }

    if(timer->isPaused())
    {
        if(popup->isActive)
            popup->Draw(mouseX,mouseY);
        else if(winPopup->isActive)
        {
            winPopup->Draw(mouseX,mouseY);
           // winPopup->setActive(false);
           // winPopup2->setActive(true);
        }

        else if(deathPopup->isActive)
            deathPopup->Draw(mouseX,mouseY);
       // else if(winPopup2->isActive)
           // winPopup2->Draw(mouseX,mouseY);

    }
}

void _level::Action(std::string act)
{
    std::cout << "Action: " << act << std::endl;

    if(act == "KB_Esc" || act == "Decline")
    {
        if(timer->isPaused() && popup->isActive)
        {
            ply->tex->playAnim = true;
            ply->tex->loopAnim = true;
            //ply->tex->
            popup->setActive(false);
            snd->resumeMusic();
            timer->Resume();
        }
        else if(!timer->isPaused())
        {
            ply->tex->playAnim = false;
            ply->tex->loopAnim = false;
            ply->tex->setAnimation("IdleLeft",false,false,0);
            timer->Pause();
            snd->pauseMusic();
            kBMs->initBtns(popup->btns);
            popup->setActive(true);
        }
    }
    else if(act == "Accept")
    {
        sceneList->pop();
        //snd->playMusic("sounds/Tower Diver Game_sounds_opening_pages_music.wav");
    }

    else if(act == "InGameHelp")
        sceneList->push(h);
    else if(act == "Quit")
    {
        while(sceneList->size() > 1)
        {
            sceneList->pop();
        }
    }
}

void _level::ScreenResized(int screenWidth, int screenHeight)
{
    popup->btns->CalcBorders(screenWidth,screenHeight);
}

void _level::newLevel()
{

}

void _level::checkChanges()
{
    floatPair newXYCoord = ply->GetNextXY();

    ply->PositionObject(newXYCoord);

    if(ply->alive)
    {
        if (enmy->alive)
        {
            floatPair enmyXYCoord = enmy->EnemGetNextXY(newXYCoord);
            enmy->PositionObject(enmyXYCoord);
            std::string plyAttack = ply->atkCollision(enmyXYCoord,newXYCoord);
            std::string enmyPlyCollision = enmy->collision(enmyXYCoord,newXYCoord);
            //std::cout << "Is attacking? " << ply->isAttacking << endl;
                if(ply->isAttacking)
                {
                    if(plyAttack == "hitEnemy")
                    {
                        if(snd)
                            snd->playSound("sounds/Tower Diver Game_sounds_sword-slash-1.wav");
                        enmy->hp--;
                        if(enmy->hp == 0)
                        {
                            enmy->alive = false;
                            enmy->tex->setAnimation("Death",true,true,0);
                        }

                        enmyXYCoord.first += 0.15;
                        enmy->PositionObject(enmyXYCoord);
                    }
                }

            if(enmyPlyCollision == "EnemyHits")
            {
                ply->life--;
                newXYCoord.first -= 0.1;
                enmyXYCoord.first += 0.12;
                ply->PositionObject(newXYCoord);
                enmy->PositionObject(enmyXYCoord);
                if(ply->life == 0)
                    ply->alive = false;
            }

        }


        if(!enmy->alive && frameCount!=deathFrames)
            frameCount++;
        if(frameCount==deathFrames)
            enmy->deathDone = true;
        if(frameCount == deathFrames)
            enmy->tex->setAnimation("Death",false,false,deathFrames);


        if (ply->xPos >= 0.92)
        {
            levelEnd = true;
            if(levelnum == 3)
            {
                snd->pauseMusic();
                timer->Pause();
                kBMs->initBtns(winPopup->btns);
                winPopup->setActive(true);
            }
        }


        if(ply->dirFlag != 0)
        {
            if(footstepSpace == 0)
            {
                footstepSpace = 3;
                if(snd)
                    snd->playSound("sounds/walking.mp3");
            }
            else
                footstepSpace--;
        }
    }
    else    //if player is dead
    {
        snd->pauseMusic();
        timer->Pause();
        kBMs->initBtns(deathPopup->btns);
        deathPopup->setActive(true);
    }

}

