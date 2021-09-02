#include "_popUp.h"

_popUp::_popUp()
{
    //ctor
    message = new _texture();
    btns = new _buttons();
    isActive = false;
}

_popUp::~_popUp()
{
    //dtor
}

void _popUp::Init(int screenWidth, int screenHeight, int popUpType)
{
    switch(popUpType)
    {
        case 1:
            btns->Init("images/button_sprite_sheet.png",4,7);
            btns->makeButton("Accept", YES, 0.5,0.38, false, screenWidth,screenHeight);
            btns->makeButton("InGameHelp",HELP,0.50,0.49,false,screenWidth,screenHeight);
            btns->makeButton("Decline",NO,0.5,0.60, false, screenWidth, screenHeight);
            message->loadTexture("images/menuprompt.png",1,1,0.5,0.0);
            break;

        case 2:
            btns->Init("images/button_sprite_sheet.png", 4, 7);
            btns->makeButton("Accept", YES, 0.5, 0.5, false, screenWidth, screenHeight);
            btns->makeButton("Quit", QUIT, 0.5, 0.585, false, screenWidth, screenHeight);
            message->loadTexture("images/deathscreen.png",1,1,0.5,0.0);
            break;

        case 3:
            btns->Init("images/button_sprite_sheet.png", 4, 7);
            btns->makeButton("Accept", YES, 0.5, 0.65, false, screenWidth, screenHeight);
            message->loadTexture("images/winscreen1.png",1,1,0.5,0.0);
            break;

        case 4:
            btns->Init("images/button_sprite_sheet.png", 4, 7);
            btns->makeButton("Accept", YES, 0.5, 0.65, false, screenWidth, screenHeight);
            message->loadTexture("images/winscreen2.png",1,1,0.5,0.0);
            break;
    }
}

void _popUp::setActive(bool state)
{
    isActive = state;
    btns->setActive(state);
}

void _popUp::Draw(int mouseX, int mouseY)
{
    glPushMatrix();
     message->texBind();
     message->Draw(0.5,0.1);
     btns->Update(mouseX,mouseY);
     btns->Draw();
    glPopMatrix();
}
