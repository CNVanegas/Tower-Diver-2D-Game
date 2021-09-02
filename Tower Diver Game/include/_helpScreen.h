#ifndef _HELPSCREEN_H
#define _HELPSCREEN_H
#include <_scene.h>
#include <_buttons.h>

class _helpScreen : public _scene
{
    public:
        _helpScreen(std::stack<_scene*>*);
        virtual ~_helpScreen();

        void Init(int,int);
        void Draw();
        void Action(std::string);
        void ScreenResized(int,int);

        _texture *backgrd;
        _buttons *btns;

    protected:

    private:
};

#endif // _HELPSCREEN_H
