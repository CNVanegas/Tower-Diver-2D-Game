#include "_titleScreen.h"

_titleScreen::_titleScreen(std::stack<_scene*>* s)
{
    //ctor
    sceneList = s;
    backgrd = new _texture();
    btns = new _buttons();
    kBMs = new _inputs(timer);
    kBMs->initBtns(btns);
}

_titleScreen::~_titleScreen()
{
    //dtor
}

void _titleScreen::Init(int screenWidth, int screenHeight)
{
    backgrd->loadTexture("images/bgLanding_scroll+txt.jpg",1,1);
    btns->Init("images/button_sprite_sheet.png",4,7);
    btns->makeButton("Begin", START, 0.25,0.65,true,screenWidth,screenHeight);
}

void _titleScreen::Draw()
{
    glPushMatrix();
     backgrd->texBind();
     backgrd->Draw(0.0,0.0);
     btns->Update(mouseX,mouseY);
     btns->Draw();
    glPopMatrix();
}

void _titleScreen::Action(std::string act)
{
    if(act == "Begin" || act == "KB_Enter" || act == "KB_B")
    {
        sceneList->pop();
        _menuScreen *menuS = new _menuScreen(sceneList);
        menuS->InitGL();
        sceneList->push(menuS);
    }

    if(act == "KB_Esc")
        sceneList->pop();
}

void _titleScreen::ScreenResized(int screenWidth, int screenHeight)
{
    btns->CalcBorders(screenWidth,screenHeight);
}
