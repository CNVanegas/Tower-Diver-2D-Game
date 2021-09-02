#ifndef _INPUTS_H
#define _INPUTS_H

#include <windows.h>
#include <_object.h>
#include <_timer.h>
#include <_buttons.h>
#include <_sound.h>

class _inputs
{
    public:
        _inputs(_timer*);
        virtual ~_inputs();

        void initPly(_object*);
        void initBtns(_buttons*);
        void initEnmy(_object*);
        void initSnd(_sound*);

        void keyPress();
        void keyRelease();

        void mouseDown(double, double);
        std::string mouseUp();
        void mouseMove(double,double);

        double prevMouseX, prevMouseY;

        WPARAM wParam;

        _object *ply;
        _object *enmy;
        _buttons *btns;
        _timer *timer;
        _sound *snd;

        int animTime;
        bool attacking;
    protected:

    private:
};

#endif // _INPUTS_H
