#include "_buttons.h"

_buttons::_buttons()
{
    //ctor
    tex = new _texture();
    clk = new _sound();
}

_buttons::~_buttons()
{
    //dtor
}

void _buttons::Init(char* filename, int x, int y, float pX, float pY)
{
    tex->loadTexture(filename,x,y,pX,pY);
    clk->initSounds();
}

void _buttons::Draw()
{
    tex->texBind();
    for(int i = 0; i < btns.size();i++)
    {
        if(btns[i]->isActive)
        {
            tex->curFrame = btns[i]->type*4+btns[i]->status;
            tex->Draw(btns[i]->posPX,btns[i]->posPY);
        }
    }
}

void _buttons::CalcBorders(int screenWidth, int screenHeight)
{
    float offX = tex->widthP * tex->pivX;
    float offY = tex->heightP * tex->pivY;

    for (int i = 0; i < btns.size(); ++i)
    {
        btns[i]->left = (btns[i]->posPX - offX) * screenWidth;
        btns[i]->right = btns[i]->left + tex->widthP * screenWidth;
        btns[i]->top = (btns[i]->posPY - offY) * screenHeight;
        btns[i]->bottom = btns[i]->top + tex->heightP * screenHeight;
    }
}

void _buttons::Update(int mouseX, int mouseY)
{
    for(int i = 0; i < btns.size(); ++i)
    {
        if(btns[i]->isActive);
        {
            if(mouseX > btns[i]->left && mouseX < btns[i]->right && mouseY > btns[i]->top && mouseY < btns[i]->bottom)
                btns[i]->status = HOVER;
            else
                btns[i]->status = NORMAL;
        }
    }
}

std::string _buttons::chkclick()
{
    string clked = "";
    for(int i = 0; i < btns.size(); ++i)
    {
        if(btns[i]->isActive)
        {
            if(btns[i]->isActive && btns[i]->status == HOVER)
            {
                clk->playSound("sounds/click.wav");
                clked = btns[i]->name;
                return clked;
            }
        }
    }
    return clked;
}

void _buttons::setActive(bool state)
{
    for(int i = 0; i < btns.size(); ++i)
    {
        cout << btns.size() << endl;
        btns[i]->isActive = state;
    }
}

void _buttons::makeButton(string n, int t, float x, float y, bool state, int screenWidth, int screenHeight)
{
    float offSetX = tex->widthP * tex->pivX;
    float offSetY = tex->heightP * tex->pivY;

    btn* button = new btn();
    button->name = n;
    button->type = t;
    button->posPX = x;
    button->posPY = y;
    button->isActive = state;
    button->left = (x-offSetX) * screenWidth;
    button->right = button->left + tex->widthP * screenWidth;
    button->top = (y - offSetY) * screenHeight;
    button->bottom = button->top + tex->heightP * screenHeight;
    btns.push_back(button);

}

