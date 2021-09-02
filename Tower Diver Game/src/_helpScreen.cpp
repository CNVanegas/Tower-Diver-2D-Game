#include "_helpScreen.h"

_helpScreen::_helpScreen(std::stack<_scene*>* s)
{
    //ctor
    sceneList = s;
    backgrd = new _texture();
    btns = new _buttons();
    kBMs = new _inputs(timer);
    kBMs->initBtns(btns);
}

_helpScreen::~_helpScreen()
{
    //dtor
}

void _helpScreen::Init(int x, int y)
{
    backgrd->loadTexture("images/helpScreen.jpg",1,1);
    btns->Init("images/button_sprite_sheet.png",4,7,0.0,0.0);
    btns->makeButton("Return",RETURN,0.22,0.86,true,screenWidth,screenHeight);
}

void _helpScreen::Draw()
{
    glPushMatrix();
     backgrd->texBind();
     backgrd->Draw(0.0,0.0);
     btns->Update(mouseX,mouseY);
     btns->Draw();
    glPopMatrix();
}

void _helpScreen::Action(std::string act)
{
    if(act == "Return" || act == "KB_R" || act == "KB_Esc")
        sceneList->pop();
}

void _helpScreen::ScreenResized(int screenWidth, int screenHeight)
{
    btns->CalcBorders(screenWidth, screenHeight);
}
