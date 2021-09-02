#ifndef _PHYSICS_H
#define _PHYSICS_H
#include <_player.h>
#include <_enemy.h>
//#include <vector>

#include <_timer.h>

class _physics
{
    public:
        _physics();
        virtual ~_physics();
        bool checkCollision(_player*, _enemy*);
        bool checkCollision(_enemy*);
        bool checkCollision(_player*);

        void physicsTick(_player*);
        void physicsTick(_enemy*);

        _timer* physTimer = new _timer();
        //void pausePhys();
        //void startPhys();

        float simSpeed;
        bool isSim;

    protected:

    private:
};

#endif // _PHYSICS_H
