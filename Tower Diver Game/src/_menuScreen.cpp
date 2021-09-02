#include "_menuScreen.h"

_menuScreen::_menuScreen(std::stack<_scene*>* s)
{
    //ctor
    sceneList = s;
    backgrd = new _texture();
    btns = new _buttons();
    kBMs = new _inputs(timer);
    kBMs->initBtns(btns);

    snd = new _sound();
    kBMs->initSnd(snd);
}

_menuScreen::~_menuScreen()
{
    //dtor
}

void _menuScreen::Init(int screenWidth, int screenHeight)
{
    backgrd->loadTexture("images/bgMenu_scroll+txt.jpg",1,1);
    snd->initSounds();
    snd->playMusic("sounds/Tower Diver Game_sounds_opening_pages_music.wav");
    btns->Init("images/button_sprite_sheet.png",4,7);
    btns->makeButton("Play", NEWGAME,0.24,0.28,true,screenWidth,screenHeight);
    btns->makeButton("Help", HELP, 0.24, 0.46, true, screenWidth,screenHeight);
    btns->makeButton("Quit", QUIT, 0.24,0.66,true,screenWidth,screenHeight);
    timer->Start();
}

void _menuScreen::Draw()
{
    glPushMatrix();
     backgrd->texBind();
     backgrd->Draw(0.0,0.0);
    glPopMatrix();

    btns->Update(mouseX,mouseY);

    glPushMatrix();
     btns->Draw();
    glPopMatrix();
}

void _menuScreen::Action(std::string act)
{
    if(act == "Play" || act == "KB_N")
    {
        snd->pauseMusic();
        _level *level = new _level(sceneList);
        level->InitGL();
        sceneList->push(level);
    }

    if(act == "Help" || act == "KB_H")
    {
        _helpScreen *helpS = new _helpScreen(sceneList);
        helpS->InitGL();
        sceneList->push(helpS);
    }

    if(act == "Quit" || act == "KB_Q" || act == "KB_Esc")
        sceneList->pop();
    act == "";
}

void _menuScreen::ScreenResized(int screenWidth, int screenHeight)
{
    btns->CalcBorders(screenWidth,screenHeight);
}

