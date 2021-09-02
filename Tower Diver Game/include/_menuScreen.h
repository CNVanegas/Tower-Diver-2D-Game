#ifndef _MENUSCREEN_H
#define _MENUSCREEN_H
#include <_scene.h>
#include <_helpScreen.h>
#include <_buttons.h>
#include <_level.h>

class _menuScreen : public _scene
{
    public:
        _menuScreen(std::stack<_scene*>*);
        virtual ~_menuScreen();

        void Init(int,int);
        void Draw();
        void Action(std::string);
        void ScreenResized(int,int);

        _texture *backgrd;
        _buttons *btns;
        _sound *snd;

    protected:

    private:
};

#endif // _MENUSCREEN_H
