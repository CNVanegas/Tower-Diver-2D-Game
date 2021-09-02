#ifndef _BLANKSCREEN_H
#define _BLANKSCREEN_H
#include <_scene.h>

class _blankScreen : public _scene
{
    public:
        _blankScreen(std::stack<_scene*>*);
        virtual ~_blankScreen();

        void Init(int,int);
        void Draw();
        void Action(std::string);
        void ScreenResized(int,int);
    protected:

    private:
};

#endif // _BLANKSCREEN_H
