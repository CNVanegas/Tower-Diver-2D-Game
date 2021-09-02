#ifndef _TITLESCREEN_H
#define _TITLESCREEN_H
#include <_scene.h>
#include <_buttons.h>
#include <_menuScreen.h>

class _titleScreen : public _scene
{
    public:
        _titleScreen(std::stack<_scene*>*);
        virtual ~_titleScreen();

        void Init(int,int);
        void Draw();
        void Action(std::string);
        void ScreenResized(int,int);

        _texture *backgrd;
        _buttons *btns;

    protected:

    private:
};

#endif // _TITLESCREEN_H
