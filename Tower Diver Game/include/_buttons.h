#ifndef _BUTTONS_H
#define _BUTTONS_H

#include <vector>
#include <iostream>
#include <_texture.h>
#include <_sound.h>
enum text {NEWGAME,HELP,QUIT,YES,NO,RETURN,START};
enum style {NORMAL,CLICK,HOVER,BRIGHT};

struct btn
{
    std::string name;
    int type;
    int status;

    float posPX;
    float posPY;

    int left,right,top,bottom;
    bool isActive;
};

class _buttons
{
    public:
        _buttons();
        virtual ~_buttons();

        void Init(char*,int,int,float pX = 0.5,float pY = 0.5);
        void Draw();
        void CalcBorders(int,int);
        void Update(int,int);
        std::string chkclick();
        void setActive(bool);
        void makeButton(string,int,float,float,bool,int,int);

        std::vector<btn*> btns;

        _texture *tex;
        _sound *clk;

        float posPX, posPY;

    protected:

    private:
};

#endif // _BUTTONS_H
