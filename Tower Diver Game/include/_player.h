#ifndef _PLAYER_H
#define _PLAYER_H
#include <_object.h>

class _player : public _object
{
    public:
        _player();
        virtual ~_player();

        void Init(char*,int,int);
        void Actions(int);
        std::string atkCollision(floatPair, floatPair);
        void tP(int);

        int life;
        bool alive;
        bool attacking;

        //_texture *hearts = new _texture();
    protected:

    private:
};

#endif // _PLAYER_H
