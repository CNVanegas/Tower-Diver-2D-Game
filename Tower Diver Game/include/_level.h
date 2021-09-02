#ifndef _LEVEL_H
#define _LEVEL_H
#include <_scene.h>
#include <_buttons.h>
#include <_helpScreen.h>
#include <_room.h>
#include <_popUp.h>

class _level : public _scene
{
    public:
        _level(std::stack<_scene*>*);
        virtual ~_level();

        void Init(int,int);
        void Draw();
        void Action(std::string);
        void ScreenResized(int,int);
        void newLevel();
        void checkChanges();

        _helpScreen *h;
        _player *ply;
        _sound *snd;
        _popUp *popup;
        _popUp *winPopup;
        _popUp *winPopup2;
        _popUp *deathPopup;
        _room *room;
        _enemy *enmy;

        int levelnum;
        int frameCount;
        int deathFrames;
        int footstepSpace;
        bool levelEnd;
        _texture *hearts;

    protected:

    private:
};

#endif // _LEVEL_H
