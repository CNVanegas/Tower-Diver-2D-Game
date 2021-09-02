#include "_room.h"

_room::_room()
{
    //ctor
    bricks = new _texture();
    stage1 = new _texture();
    stage2 = new _texture();
    stage3 = new _texture();
    pillar = new _texture();
    pillars = new _texture();
    bottomwall = new _texture();
    carpet = new _texture();
    chandalier = new _texture();
    fence = new _texture();
    platform = new _texture();
    platform2 = new _texture();
    platform3 = new _texture();
    topwall = new _texture();
    walkpaths = new _texture();
    wall2 = new _texture();
    wall3 = new _texture();
    wallcontinue = new _texture();
    woodsupport = new _texture();
    window = new _texture();
}

_room::~_room()
{
    //dtor
}

void _room::movePly(std::string dir)
{
    //if(dir == "N");

}

void _room::makeRoom(int room)
{
    //readLevel(file,1,1);
    if(room == 1)
    {
        bricks->loadTexture("images/bricks.png",1,1);
        stage1->loadTexture("images/stage1.png",1,1);
        //stage2->loadTexture("images/stage2.png",1,1);
        //stage3->loadTexture("images/stage3.png",1,1);
        pillar->loadTexture("images/pillar.png",1,1);
        pillars->loadTexture("images/pillars.png",2,1);
        bottomwall->loadTexture("images/bottomwall.png",1,1);
        carpet->loadTexture("images/carpet.png",1,1);
        chandalier->loadTexture("images/chandalier.png",1,1);
        fence->loadTexture("images/fence.png",1,1);
        platform->loadTexture("images/platform.png",1,1);
        platform2->loadTexture("images/platform2.png",1,1);
        platform3->loadTexture("images/platform3.png",1,1);
        topwall->loadTexture("images/topwall.png",1,1);
        walkpaths->loadTexture("images/walkpaths.png",1,2);
        wall2->loadTexture("images/wall2.png",1,1);
        wall3->loadTexture("images/wall3.png",1,1);
        wallcontinue->loadTexture("images/wallcontinue.png",1,1);
        woodsupport->loadTexture("images/woodsupport.png",1,1);
        window->loadTexture("images/window.png",1,1);



        //backgrounds go here in case cant make stage
        /*
        bricks->loadTexture("images/stage1.png",1,1);
        roofing->loadTexture("images/Tiles.png",10,3);
        floor->loadTexture("images/Tiles.png",10,18);
        pillar->loadTexture("images/Tiles.png",10,3);
        window->loadTexture("images/Background.png",1,1);
        beam->loadTexture("images/tileset.png",16,9);
        star->loadTexture("images/tileset.png",16,9);
        glitter->loadTexture("images/tileset.png",16,9);
        */


    }

    else if (room == 2)
    {
        stage2->loadTexture("images/stage2.png",1,1);
    }

    else if (room == 3)
    {
        stage3->loadTexture("images/stage3.png",1,1);

    }

}

void _room::drawRoom(int levelnum)
{


    float cells = 0.95;
    //background->texBind();
    //background->Draw(0.0,0.0,1.0,1.0);

    if (levelnum == 1)
    {
        stage1->texBind();
        stage1->Draw(0.0,0.0,1.0,1.0);
    }

    else if (levelnum == 2)
    {
        stage2->texBind();
        stage2->Draw(0.0,0.0,1.0,1.0);
    }

    else if (levelnum == 3)
    {
        stage3->texBind();
        stage3->Draw(0.0,0.0,1.0,1.0);
    }
    //bricks->texBind();
    //bricks->Draw(0.5,0.5,7.0,7.0);

    //pillar->texBind();
    //pillar->Draw(0.5,0.5,1.0,1.0);


    /*
    for (float y = 0.0; y <= 0.95; y+=0.05)
    {
        //bricks->curFrame = 21;
        for(float x = 0.0; x <= 1.0; x+=0.05)
            bricks->Draw(x,y,0.5,0.5);
    }*/


    /*
    window->texBind();
    window->Draw(0.32,0.25,2.0,2.0);
    window->Draw(0.55,0.25,2.0,2.0);
    //window->Draw(0.7,0.25,1.60,1.6);

    floor->texBind();
    floor->curFrame = 53;
    floor->Draw(0.50,0.25,2.0,2.0);

    pillar->texBind();
    pillar->curFrame = 6;
    pillar->Draw(0.18,0.35,2.8,2.8);
    pillar->curFrame = 7;
    pillar->Draw(0.22,0.35,2.8,2.8);
    pillar->curFrame = 8;
    pillar->Draw(0.265,0.35,2.8,2.8);
    //bricks->texBind();*/

    for(float y = 0; y <= cells; y+=0.2)
    {
        for(float x = 0; x <= cells; x+=0.2)
        {
            bool mirror = false;
            bool flip = false;
            int curFrame = 10;
            curFrame = 55;
            //bricks->curFrame = curFrame;
            //window->curFrame = 1;

           // bricks->Draw(x, y, 7.0, 7.0, flip, mirror);

        }
    }

    //bricks->texBind();
    //bricks->curFrame = 20;
    //bricks->Draw(0.0,0.18,1.0,1.2);



    //glPushMatrix();
     //bricks->texBind();
     //bricks->Draw(0.1,0.1);
    //glPopMatrix();
}


