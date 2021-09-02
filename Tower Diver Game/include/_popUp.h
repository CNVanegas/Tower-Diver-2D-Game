#ifndef _POPUP_H
#define _POPUP_H
#include <_buttons.h>
#include <_texture.h>

class _popUp
{
    public:
        _popUp();
        virtual ~_popUp();
        void Init(int,int,int);
        void setActive(bool);
        void Draw(int, int);

        _buttons *btns;
        _texture *message;

        bool isActive;

    protected:

    private:
};

#endif // _POPUP_H
